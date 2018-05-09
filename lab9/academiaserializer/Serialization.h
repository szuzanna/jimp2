//
// Created by Zuzanna on 07.05.2018.
//

#ifndef JIMP_EXERCISES_SERIALIZATION_H
#define JIMP_EXERCISES_SERIALIZATION_H

#include <iostream>
#include <vector>
#include <functional>


namespace academia {
    class Serializable;


    class Serializer {
    public:
        Serializer(std::ostream *out);

        virtual void IntegerField(const std::string &field_name, int value)=0;

        virtual void DoubleField(const std::string &field_name, double value)=0;

        virtual void StringField(const std::string &field_name, const std::string &value)=0;

        virtual void BooleanField(const std::string &field_name, bool value)=0;

        virtual void SerializableField(const std::string &field_name, const academia::Serializable &value)=0;

        virtual void ArrayField(const std::string &field_name,
                                const std::vector<std::reference_wrapper<const academia::Serializable>> &value)=0;

        virtual void Header(const std::string &object_name)=0;

        virtual void Footer(const std::string &object_name)=0;

    public:
        std::ostream *out_;
    };


    class Serializable {
    public:
        virtual void Serialize(Serializer *serializer) const = 0;
    };


    class Room : public Serializable {
    public:
        enum Type {
            COMPUTER_LAB,
            LECTURE_HALL,
            CLASSROOM,
        };

        Room(int room_id, std::string room_name, Type type);

        void Serialize(Serializer *serializer) const override;

        std::string getTyp(enum Type type) const;

    private:
        int room_id_;
        std::string room_name_;
        Type type_;
    };


    class Building : public Serializable {
    public:
        Building(int room_id, std::string room_name, const std::vector<Room> &rooms);

        void Serialize(Serializer *serializer) const override;

    public:
        int building_id_;
        std::string building_name_;
        std::vector<Room> rooms_;
    };


//    class XmlSerializer : public Serializer {
//
//    };

    class JsonSerializer : public Serializer {
    public:
        JsonSerializer(std::ostream *out) : Serializer(out) {};

        void IntegerField(const std::string &field_name, int value) override;

        void DoubleField(const std::string &field_name, double value) override;

        void StringField(const std::string &field_name, const std::string &value) override;

        void BooleanField(const std::string &field_name, bool value) override;

        void SerializableField(const std::string &field_name, const academia::Serializable &value) override;

        void ArrayField(const std::string &field_name,
                        const std::vector<std::reference_wrapper<const academia::Serializable>> &value) override;

        void Header(const std::string &object_name) override;

        void Footer(const std::string &object_name) override;

    };
}


#endif //JIMP_EXERCISES_SERIALIZATION_H
