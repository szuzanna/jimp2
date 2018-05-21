//
// Created by Zuzanna on 16.05.2018.
//

#include "Scheduler.h"
#include <algorithm>

namespace academia {

    int SchedulingItem::CourseId() const {
        return course_id;
    }

    int SchedulingItem::TeacherId() const {
        return teacher_id;
    }

    int SchedulingItem::RoomId() const {
        return room_id;
    }

    int SchedulingItem::TimeSlot() const {
        return time_slot;
    }

    int SchedulingItem::Year() const {
        return year;
    }

    SchedulingItem Schedule::operator[](int number) const {
        return items_[number];
    }

    SchedulingItem::SchedulingItem(int course_id, int teacher_id, int room_id, int time_slot, int year) : course_id(
            course_id), teacher_id(teacher_id), room_id(room_id), time_slot(time_slot), year(year) {}

    void SchedulingItem::setCourse_id(int course_id) {
        SchedulingItem::course_id = course_id;
    }

    void SchedulingItem::setTeacher_id(int teacher_id) {
        SchedulingItem::teacher_id = teacher_id;
    }

    void SchedulingItem::setRoom_id(int room_id) {
        SchedulingItem::room_id = room_id;
    }

    void SchedulingItem::setTime_slot(int time_slot) {
        SchedulingItem::time_slot = time_slot;
    }

    void SchedulingItem::setYear(int year) {
        SchedulingItem::year = year;
    }

    Schedule Schedule::OfTeacher(int teacher_id) const {
        Schedule tmp;
        for (const auto &n : items_) {
            if (n.TeacherId() == teacher_id) {
                tmp.InsertScheduleItem(n);
            }
        }
        return tmp;
    }

    Schedule Schedule::OfRoom(int room_id) const {
        Schedule tmp;
        for (const auto &n : items_) {
            if (n.RoomId() == room_id) {
                tmp.InsertScheduleItem(n);
            }
        }
        return tmp;
    }

    Schedule Schedule::OfYear(int year) const {
        Schedule tmp;
        for (auto it : items_) {
            if (it.Year() == year) tmp.InsertScheduleItem(it);
        }
        return tmp;
    }

    Schedule Schedule::OfCourse(const int course) const {
        Schedule tmp;
        for (auto it : items_) {
            if (it.CourseId() == course) tmp.InsertScheduleItem(it);
        }
        return tmp;
    }

    std::vector<int> Schedule::AvailableTimeSlots(int n_time_slots) const {
        std::vector<int> tmp;
        bool exists;
        for (int i = 1; i <= n_time_slots; ++i) {
            exists = false;
            for (auto j : items_) {
                if (j.TimeSlot() == i) exists = true;
            }
            if (!exists) tmp.push_back(i);
        }
        return tmp;
    }

    size_t Schedule::Size() const {
        return items_.size();
    }

    void Schedule::InsertScheduleItem(const SchedulingItem &item) {
        items_.emplace_back(item);
    }

    Schedule GreedyScheduler::PrepareNewSchedule(const std::vector<int> &rooms,
                                                 const std::map<int, std::vector<int>> &teacher_courses_assignment,
                                                 const std::map<int, std::set<int>> &courses_of_year,
                                                 int n_time_slots) {
        Schedule tmp;
        bool addedRoomTime;
        bool Unavailable[rooms.size()][n_time_slots];
        std::vector<int> freeTimes;

        for (auto teacher : teacher_courses_assignment) {
            for (auto course : teacher.second) {
                tmp.InsertScheduleItem(SchedulingItem(course, teacher.first, 0, 0, 0));
            }
        }


        for (auto &item : tmp.items_) {
            for (auto year : courses_of_year) {
                for (auto course : year.second) {
                    if (item.CourseId() == course) item.setYear(year.first);
                }
            }
        }

        for (auto &i : tmp.items_) {
            Intersection(n_time_slots, tmp, freeTimes, i, addedRoomTime);

            for (int room = 0; room < rooms.size(); ++room) {
                for (auto time : freeTimes) {
                    if (!Unavailable[room][time] && !addedRoomTime) {
                        i.setRoom_id(rooms[room]);
                        i.setTime_slot(time);
                        addedRoomTime = true;
                        Unavailable[room][time] = true;
                    }
                }
            }
            if (!addedRoomTime) throw NoViableSolutionFound();
        }
        return tmp;
    }

    void GreedyScheduler::Intersection(int n_time_slots, const Schedule &result, std::vector<int> &freeTimes,
                                       const SchedulingItem &i, bool &addedRoomTime) const {
        freeTimes.clear();
        std::vector<int> freeTimesTeacher = result.OfTeacher(i.TeacherId()).AvailableTimeSlots(n_time_slots);
        std::vector<int> freeTimesCourse = result.OfCourse(i.CourseId()).AvailableTimeSlots(n_time_slots);
        set_intersection(freeTimesTeacher.begin(), freeTimesTeacher.end(),
                         freeTimesCourse.begin(), freeTimesCourse.end(), back_inserter(freeTimes));
        addedRoomTime = false;
    }
}