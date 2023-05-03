#pragma once

/*
    Bridge is a design pattern that decouples an abstraction from its implementation, 
    allowing them to vary independently while providing a way to connect them at runtime.

    In the following example, the GameObject doesn't care what implementation the renderer has.
*/

#include <iostream>

// Implementor class interface
class Renderer {
public:
    virtual void render() = 0;
};

// Concrete Implementor A
class DirectXRenderer : public Renderer {
public:
    void render() override {
        std::cout << "Rendering using DirectX\n";
    }
};

// Concrete Implementor B
class OpenGLRenderer : public Renderer {
public:
    void render() override {
        std::cout << "Rendering using OpenGL\n";
    }
};

// Abstraction class interface
class GameObject {
protected:
    Renderer* m_renderer;

public:
    GameObject(Renderer* renderer) : m_renderer(renderer) {}

    virtual void update() = 0;
};

// Refined Abstraction
class PlayerObject : public GameObject {
public:
    PlayerObject(Renderer* renderer) : GameObject(renderer) {}

    void update() override {
        std::cout << "Updating player object\n";
        m_renderer->render();
    }
};

