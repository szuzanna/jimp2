//
// Created by Zuzanna on 07.05.2018.
//
#include "Serialization.h"
#include <regex>
#include <experimental/optional>

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
        serializer->IntegerField("id", room_id_);
        serializer->StringField("name", room_name_);
        serializer->StringField("type", getTyp(type_));
        serializer->Footer("room");
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
        serializer->Header("building");
        serializer->IntegerField("id", building_id_);
        serializer->StringField("name", building_name_);
        std::vector<std::reference_wrapper<const Serializable>> serializer_rooms_;
        for (auto &room: rooms_) {
            serializer_rooms_.emplace_back(room);
        }
        serializer->ArrayField("rooms", serializer_rooms_);
        serializer->Footer("building");
    }

    int Building::Id() const {
        return building_id_;
    }

/////////////JSON
    void JsonSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "\"" << field_name << "\": " << value<<", ";
    }

    void JsonSerializer::DoubleField(const std::string &field_name, double value) {

    }

    void JsonSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "\"" << field_name << "\": \"" << value + "\"";
        if(field_name != "type"){
            *out_<<", ";
        }
    }

    void JsonSerializer::BooleanField(const std::string &field_name, bool value) {

    }

    void JsonSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        value.Serialize(this);
        *out_<<", ";
    }

    void JsonSerializer::ArrayField(const std::string &field_name,
                                    const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {

        *out_ << "\"" << field_name << "\": [";
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
    ////////////////////XML

    void XmlSerializer::IntegerField(const std::string &field_name, int value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::DoubleField(const std::string &field_name, double value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name <<">";
    }

    void XmlSerializer::StringField(const std::string &field_name, const std::string &value) {
        *out_ << "<" << field_name << ">" << value << "<\\" << field_name << ">";
    }

    void XmlSerializer::BooleanField(const std::string &field_name, bool value) {
        *out_ << "<" << field_name << ">" << value<< "<\\" << field_name << ">";
    }

    void XmlSerializer::SerializableField(const std::string &field_name, const academia::Serializable &value) {
        *out_ << "<" + field_name + ">";
        value.Serialize(this);
        *out_ << "<\\" + field_name + ">";
    }

    void XmlSerializer::ArrayField(const std::string &field_name,
                                   const std::vector<std::reference_wrapper<const academia::Serializable>> &value) {
        *out_ << "<" << field_name << ">";
        for (const Serializable &room : value) {
            room.Serialize(this);
        }
        *out_ << "<\\" << field_name << ">";
    }

    void XmlSerializer::Header(const std::string &object_name) {
        *out_ << "<" << object_name << ">";
    }

    void XmlSerializer::Footer(const std::string &object_name) {
        *out_ << "<\\" << object_name << ">";
    }

///////////BuildingRepository
    void BuildingRepository::Add(const Building &builiding_object) {
        buildings_.emplace_back(builiding_object);
    }

    void BuildingRepository::StoreAll(Serializer *serializer) const {
        serializer->Header("building_repository");
        std::vector<std::reference_wrapper<const Serializable>> tmp;
        for (auto &n : buildings_) {
            tmp.emplace_back(std::cref(n));
        }
        serializer->ArrayField("buildings", tmp);
        serializer->Footer("building_repository");
    }

    BuildingRepository::BuildingRepository(const std::initializer_list<Building> &sample_building) {
        for (auto &b: sample_building) {
            buildings_.emplace_back(b);
        }
    }

    std::experimental::optional<Building> BuildingRepository::operator[](int id) const {
        for (auto &n : buildings_) {
            if (n.Id() == id) {
                return std::experimental::make_optional(n);
            }
        }
    }

    BuildingRepository::BuildingRepository() {
        buildings_.clear();
    }
}