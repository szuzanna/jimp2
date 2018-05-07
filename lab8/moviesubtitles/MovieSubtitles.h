//
// Created by Zuzanna on 07.05.2018.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iostream>
#include <stdexcept>

namespace moviesubs {
    class MovieSubtitles {
    public:
        virtual void
        ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in, std::ostream *out)=0;

        virtual ~MovieSubtitles() {};
    };


    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        void ShiftAllSubtitlesBy(int offset_in_micro_seconds, int frame_per_second, std::istream *in,
                                 std::ostream *out) override;
    };


    class SubtitlesException : public std::invalid_argument {
    public:
        SubtitlesException(int err_line_number, std::string text) : invalid_argument(text) {};
    };


    class NegativeFrameAfterShift : public SubtitlesException {
    public:
        NegativeFrameAfterShift(int err_line_number, std::string text) : SubtitlesException(err_line_number, text) {};
    };


    class SubtitleEndBeforeStart : public SubtitlesException {
    public:
        SubtitleEndBeforeStart(int err_line_number, std::string text) : SubtitlesException(
                err_line_number, "At line " +
                                 std::to_string(err_line_number) +
                                 ": " + text),
                                                                        line_{err_line_number} {};

        int LineAt() const;

    private:
        int line_;
    };


    class InvalidSubtitleLineFormat : public SubtitlesException {
    public:
        InvalidSubtitleLineFormat(int err_line_number, std::string text) : SubtitlesException(err_line_number, text) {};
    };


    class OutOfOrderFrames : public SubtitlesException {
        OutOfOrderFrames(int err_line_number, std::string text) : SubtitlesException(err_line_number, text) {};
    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
