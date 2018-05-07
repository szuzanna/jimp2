//
// Created by Zuzanna on 07.05.2018.
//

#include "MovieSubtitles.h"
#include <regex>

namespace moviesubs {

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                                std::ostream *out) {

        if (frame_per_second < 1) throw SubtitlesException(frame_per_second, "incorrect ");

        int shift_by = offset_in_micro_seconds * frame_per_second / 1000;

        std::regex pattern(R"(\{(\d+)\}\{(\d+)\}(.+))");
        int line_number = 1;
        char tmp[1000];

        while (in->getline(tmp, sizeof(tmp))) {
            std::cmatch line;
            if (std::regex_match(tmp, line, pattern)) {
                int begin = std::stoi(line[1]) + shift_by;
                int end = std::stoi(line[2]) + shift_by;
                if (begin < 0 || end < 0) throw NegativeFrameAfterShift(line_number, line[0]);
                if (begin - end > 0) throw SubtitleEndBeforeStart(line_number, line[0]);
                (*out) << "{" << begin << "}{" << end << "}" << line[3] << "\n";
            } else throw InvalidSubtitleLineFormat(line_number, line[0]);
            ++line_number;
        }
    }

    int SubtitleEndBeforeStart::LineAt() const {
        return line_;
    }
}