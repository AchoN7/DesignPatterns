#pragma once

/*
    The Adapter design pattern allows objects with incompatible interfaces 
    to work together by creating a wrapper object that acts as a bridge between them, 
    enabling reuse of existing code and simplifying the integration 
    of third-party libraries or components.
*/

// Third-party library with incompatible interface
class IncompatibleClass {
public:
    void incompatibleMethod() {
        // Code that does not match the expected interface
    }
};

// Target interface expected by the client
class TargetInterface {
public:
    virtual void targetMethod() = 0;
};

// Adapter class that adapts the incompatible interface to the target interface
class Adapter : public TargetInterface {
public:
    Adapter(IncompatibleClass* incompatible) : m_incompatible(incompatible) {}
    void targetMethod() override {
        // Call the incompatible method through the adapter
        m_incompatible->incompatibleMethod();
    }

private:
    IncompatibleClass* m_incompatible;
};