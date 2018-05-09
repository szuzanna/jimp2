//
// Created by Zuzanna on 07.05.2018.
//

#include "Serialization.h"
#include <regex>

namespace academia {

    Serializer::Serializer(std::ostream *out) {
        out_ = out;
    }

    Room::Room(int room_id, std::string room_name, Room::Type type) {
        room_id_ = room_id;
        room_name_ = room_name;
        type_ = type;
    }

    void Room::Serialize(Serializer *serializer) const {
        serializer->Header("room");
        serializer->IntegerField("no", room_id_);
        serializer->StringField("name", room_name_);
        serializer->StringField("type", getTyp(type_));
        serializer->Footer("\\room");
    }

    std::string Room::getTyp(Room::Type type) const {
        switch (type) {
            case COMPUTER_LAB:
                return "COMPUTER_LAB";
            case LECTURE_HALL:
                return "LECTURE_HALL";
            case CLASSROOM:
                return "CLASSROOM";
        }

    }

    Building::Building(int building_id, std::string building_name,
                       const std::vector<Room> &rooms) {
        building_id_ = building_id;
        building_name_ = std::move(building_name);
        rooms_ = rooms;
    }

    void Building::Serialize(Serializer *serializer) const {
        serializer->Header("{");
        serializer->IntegerField("building id", building_id_);
        serializer->StringField("name", building_name_);
        std::vector<std::reference_wrapper<const Serializable>> serializer_rooms_;
        for (auto &room: rooms_) {
            serializer_rooms_.emplace_back(room);
        }
        serializer->ArrayField("rooms", serializer_rooms_);
        serializer->Footer("}");
    }

/////////////JSON
    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "\"id\": " << value;
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << ", \"" << field_name << "\": \"" << value + "\"";
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {

    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_ << ", \"" << field_name << "\": [";
        int i = 0;

        for (const Serializable &room : value) {
            if (i != 0) {
                *out_ << ", ";
            }
            room.Serialize(this);
            ++i;
        }

        *out_ << "]";
    }

    void JsonSerializer::Header(const std::string &object_name) {
        *out_ << "{";
    }

    void JsonSerializer::Footer(const std::string &object_name) {
        *out_ << "}";
    }

}