#pragma once

#include <iostream>

/* 
    Command pattern is a behavioral design pattern that 
    turns requests or simple operations into objects. 
    This allows for deferred or remote execution
    of commands, storing command history, etc.
*/

class Character {
public:
    void jump() {
        std::cout << "Character jumped.\n";
    }
};

// Abstract Command class
class Command {
public:
    virtual ~Command() {}
    virtual void execute() = 0;
};

// Concrete Command: JumpCommand
class JumpCommand : public Command {
public:
    JumpCommand(Character& characterRef) : m_characterRef(characterRef) {}

    void execute() override {
        m_characterRef.jump();
    }

private:
    Character& m_characterRef;
};