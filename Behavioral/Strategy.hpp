#pragma once

/*
    The Strategy pattern is a behavioral design pattern that allows you 
    to define a family of algorithms, encapsulate each one as an object, 
    and make them interchangeable at runtime.
*/

#include <iostream>

// Abstract base class for physics models
class PhysicsModel {
public:
    virtual void simulate() const = 0;
};

// Concrete physics model for rigid bodies
class RigidBodyModel : public PhysicsModel {
public:
    void simulate() const override {
        std::cout << "Simulating rigid body physics" << std::endl;
    }
};

// Concrete physics model for soft bodies
class SoftBodyModel : public PhysicsModel {
public:
    void simulate() const override {
        std::cout << "Simulating soft body physics" << std::endl;
    }
};

// Game object that uses a physics model
class GameObject {
public:
    GameObject(PhysicsModel* physicsModel) : m_physicsModel(physicsModel) {}

    void updatePhysics() const {
        m_physicsModel->simulate();
    }

private:
    PhysicsModel* m_physicsModel;
};