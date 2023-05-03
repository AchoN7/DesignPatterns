#pragma once

/*
    The Composite design pattern is like a tree structure, 
    where each branch can have either leaves or more branches, 
    and all the leaves and branches can be treated uniformly as if they were individual objects, 
    even though they are part of a larger composition.
*/

#include <iostream>
#include <vector>

class Component {
public:
    virtual void operation() = 0;
};

class Leaf : public Component {
public:
    void operation() override {
        std::cout << "Leaf operation\n";
    }
};

class Composite : public Component {
public:
    void add(Component* component) {
        m_components.push_back(component);
    }

    void operation() override {
        std::cout << "Composite operation\n";
        for (const auto& component : m_components) {
            component->operation();
        }
    }

private:
    std::vector<Component*> m_components;
};