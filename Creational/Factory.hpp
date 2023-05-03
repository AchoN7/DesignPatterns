#pragma once

/*
    The Factory design pattern is a creational design pattern 
    that provides an interface for creating objects in a superclass, 
    but allows subclasses to alter the type of objects that will be created.
*/

#include <iostream>
using namespace std;

// Abstract class for Product
class Product {
public:
    virtual void use() = 0;
};

// Concrete Product A
class ConcreteProductA : public Product {
public:
    void use() override {
        cout << "Using Concrete Product A\n";
    }
};

// Concrete Product B
class ConcreteProductB : public Product {
public:
    void use() override {
        cout << "Using Concrete Product B\n";
    }
};

// Abstract Factory class
class Factory {
public:
    virtual Product* createProduct() = 0;
};

// Concrete Factory for Product A
class ConcreteFactoryA : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductA();
    }
};

// Concrete Factory for Product B
class ConcreteFactoryB : public Factory {
public:
    Product* createProduct() override {
        return new ConcreteProductB();
    }
};