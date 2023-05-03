#pragma once

#include <string>

/*
	The Decorator pattern is a structural design pattern that allows 
	behavior to be added to an individual object, either statically or dynamically, 
	without affecting the behavior of other objects in the same class. 

    In this example, a ConcreteCar can be wrapped in a GPSNavigationDecorator to give it
    the property of having a GPS.
*/

class Car {
public:
	virtual std::string getDescription() = 0;
	virtual double getRentalPrice() = 0;
};

class ConcreteCar : public Car {

public:
    ConcreteCar(std::string make, std::string model, int year, double rentalPrice) {
        this->m_make = make;
        this->m_model = model;
        this->m_year = year;
        this->m_rentalPrice = rentalPrice;
    }
    std::string getDescription() override {
        return m_make + " " + m_model + " (" + std::to_string(m_year) + ")";
    }
    double getRentalPrice() override {
        return m_rentalPrice;
    }

private:
    std::string m_make;
    std::string m_model;
    int m_year;
    double m_rentalPrice;
};

class GPSNavigationDecorator : public Car {

public:
    GPSNavigationDecorator(Car* car) {
        this->m_car = car;
        this->m_rentalPrice = 5.0;
    }
    std::string getDescription() override {
        return m_car->getDescription() + ", with GPS navigation";
    }
    double getRentalPrice() override {
        return m_car->getRentalPrice() + m_rentalPrice;
    }

private:
    Car* m_car;
    double m_rentalPrice;
};