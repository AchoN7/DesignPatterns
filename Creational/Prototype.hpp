#pragma once

#include <iostream>
#include <string>

/*
    The Prototype design pattern is a creational design pattern 
    that allows creating new objects by copying an existing object, 
    which serves as a prototype, and customizing it with different properties as needed.
*/

class Vehicle {
public:
    virtual ~Vehicle() {}
    virtual Vehicle* clone() const = 0;
    virtual void displayInfo() const = 0;
};

class Car : public Vehicle {
public:

    Car(const std::string& make, const std::string& model, int year)
        : m_make(make), m_model(model), m_year(year) {}

    Vehicle* clone() const override {
        return new Car(*this);
    }

    void displayInfo() const override {
        std::cout << "Make: " << m_make << ", Model: " << m_model << ", Year: " << m_year << std::endl;
    }

private:

    std::string m_make;
    std::string m_model;
    int m_year;

};

//class VehicleFactory {
//public:
//
//    VehicleFactory(Vehicle* prototype)
//        : m_prototype(prototype)
//    {}
//
//    Vehicle* spawnMonster() {
//        return m_prototype->clone();
//    }
//
//private:
//    Vehicle* m_prototype;
//};

class Assembler {
public:
    virtual ~Assembler() {}
    virtual Vehicle* assembleVehicle() = 0;
};

template <class T>
class AssemblerFor : public Assembler {
public:
    virtual Vehicle *assembleVehicle() { return new T(); }
};
