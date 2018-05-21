//
// Created by Zuzanna on 16.05.2018.
//

#ifndef JIMP_EXERCISES_SCHEDULER_H
#define JIMP_EXERCISES_SCHEDULER_H

#include <vector>
#include <cstddef>
#include <map>
#include <set>
#include <stdexcept>

namespace academia {
    class SchedulingItem {

    public:
        SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year);

        int CourseId() const;

        int TeacherId() const;

        int RoomId() const;

        int TimeSlot() const;

        int Year() const;

    private:
    public:
        void setCourse_id(int course_id);

        void setTeacher_id(int teacher_id);

        void setRoom_id(int room_id);

        void setTime_slot(int time_slot);

        void setYear(int year);

    private:
        int course_id{};
        int teacher_id{};
        int room_id{};
        int time_slot{};
        int year{};
    };


    class Schedule {
    public:
        Schedule OfTeacher(int teacher_id) const;

        Schedule OfRoom(int room_id) const;

        Schedule OfYear(int year) const;

        std::vector<int> AvailableTimeSlots(int n_time_slots) const;

        void InsertScheduleItem(const SchedulingItem &item);

        size_t Size() const;

        SchedulingItem operator[](int number) const;

        std::vector<SchedulingItem> items_;

        Schedule OfCourse(const int course) const;
    };


    class Scheduler {
    public:
        virtual Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                            const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                            const std::map<int, std::set<int>> &courses_of_year, int n_time_slots)=0;

        ~Scheduler() {};
    };


    class GreedyScheduler : public Scheduler {
    public:
        Schedule PrepareNewSchedule(const std::vector<int> &rooms,
                                    const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                    const std::map<int, std::set<int>> &courses_of_year, int n_time_slots) override;


        void Intersection(int n_time_slots, const Schedule &result, std::vector<int> &freeTimes,
                          const SchedulingItem &i, bool &addedRoomTime) const;
    };


    class NoViableSolutionFound : public std::invalid_argument {
    public:
        NoViableSolutionFound(const std::string &message = "sth went wrong!") : std::invalid_argument(message) {};
    };
}

#endif //JIMP_EXERCISES_SCHEDULER_H
