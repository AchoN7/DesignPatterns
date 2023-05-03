#pragma once

/*
    The Builder design pattern is a creational design pattern that separates 
    the construction of a complex object from its representation, 
    allowing the same construction process to create different representations.
*/

#include <iostream>
#include <string>
#include <vector>

// Product class
class Pizza {
public:
    void setDough(const std::string& dough) {
        m_dough = dough;
    }

    void setSauce(const std::string& sauce) {
        m_sauce = sauce;
    }

    void setToppings(const std::vector<std::string>& toppings) {
        m_toppings = toppings;
    }

    void printPizza() const {
        std::cout << "Pizza with " << m_dough << " dough, " << m_sauce << " sauce, and the following toppings: ";
        for (const auto& topping : m_toppings) {
            std::cout << topping << " ";
        }
        std::cout << std::endl;
    }

private:
    std::string m_dough;
    std::string m_sauce;
    std::vector<std::string> m_toppings;
};

// Builder interface
class PizzaBuilder {
public:
    virtual ~PizzaBuilder() {}

    virtual void buildDough() = 0;
    virtual void buildSauce() = 0;
    virtual void buildToppings() = 0;
    virtual Pizza* getPizza() = 0;
};

// ConcreteBuilder implementation
class HawaiianPizzaBuilder : public PizzaBuilder {
public:
    HawaiianPizzaBuilder() {
        m_pizza = new Pizza();
    }

    ~HawaiianPizzaBuilder() {
        delete m_pizza;
    }

    void buildDough() override {
        m_pizza->setDough("cross");
    }

    void buildSauce() override {
        m_pizza->setSauce("mild");
    }

    void buildToppings() override {
        m_pizza->setToppings({ "ham", "pineapple" });
    }

    Pizza* getPizza() override {
        return m_pizza;
    }

private:
    Pizza* m_pizza;
};

// Director class
class Cook {
public:
    void makePizza(PizzaBuilder* builder) {
        builder->buildDough();
        builder->buildSauce();
        builder->buildToppings();
    }
};