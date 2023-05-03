#pragma once

/*
    The Observer pattern allows users to subscribe themselves to a particular subject,
    thus becoming an "observer" of it. And when the subject does something, it notifies 
    all of its observers by calling their update function in this particular example.
*/

#include <iostream>
#include <vector>

// Subject (observable) class
class Subject {
public:
    void attach(class Observer* observer);
    void detach(class Observer* observer);
    void notify();
private:
    std::vector<class Observer*> m_observers;
    int m_state;
};

// Observer (subscriber) class
class Observer {
public:
    Observer(Subject* subject) : m_subject(subject) {
        m_subject->attach(this);
    }
    virtual ~Observer() {
        m_subject->detach(this);
    }
    virtual void update() = 0;
protected:
    Subject* m_subject;
};

void Subject::attach(Observer* observer) {
    m_observers.push_back(observer);
}

void Subject::detach(Observer* observer) {
    auto it = std::find(m_observers.begin(), m_observers.end(), observer);
    if (it != m_observers.end()) {
        m_observers.erase(it);
    }
}

void Subject::notify() {
    for (auto observer : m_observers) {
        observer->update();
    }
}

// Concrete observer classes
class ConcreteObserverA : public Observer {
public:
    ConcreteObserverA(Subject* subject) : Observer(subject) {}
    void update() override {
        std::cout << "ConcreteObserverA received update: " << m_subject->m_state << std::endl;
    }
};

class ConcreteObserverB : public Observer {
public:
    ConcreteObserverB(Subject* subject) : Observer(subject) {}
    void update() override {
        std::cout << "ConcreteObserverB received update: " << m_subject->m_state << std::endl;
    }
};