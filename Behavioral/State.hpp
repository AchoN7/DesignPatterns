#pragma once

/*
    The State design pattern is a behavioral design pattern that 
    allows an object to alter its behavior when its internal state changes. 
    The pattern separates the behavior of an object into different states 
    and allows the object to change its behavior by changing its current state.
*/

class Player;

// Abstract State class
class PlayerState {
public:
    virtual void handleInput(Player* player) = 0;
    virtual void update(Player* player) = 0;
    virtual void enter(Player* player) = 0;
    virtual void exit(Player* player) = 0;
};

// Concrete State classes
class StandingState : public PlayerState {
public:
    void handleInput(Player* player) override {
        if (player->isJumping()) {
            player->setState(new JumpingState());
        }
        else if (player->isMoving()) {
            player->setState(new RunningState());
        }
    }

    void update(Player* player) override {
        // Update standing animation and physics
    }

    void enter(Player* player) override {
        // Set standing animation and physics
    }

    void exit(Player* player) override {
        // Clean up standing animation and physics
    }
};

class RunningState : public PlayerState {
public:
    void handleInput(Player* player) override {
        if (player->isJumping()) {
            player->setState(new JumpingState());
        }
        else if (!player->isMoving()) {
            player->setState(new StandingState());
        }
    }

    void update(Player* player) override {
        // Update running animation and physics
    }

    void enter(Player* player) override {
        // Set running animation and physics
    }

    void exit(Player* player) override {
        // Clean up running animation and physics
    }
};

class JumpingState : public PlayerState {
public:
    void handleInput(Player* player) override {
        // Cannot change state while jumping
    }

    void update(Player* player) override {
        // Update jumping animation and physics
    }

    void enter(Player* player) override {
        // Set jumping animation and physics
    }

    void exit(Player* player) override {
        // Clean up jumping animation and physics
    }
};

// Context class
class Player {
public:
    Player() : m_state(new StandingState()) {}

    void handleInput() {
        m_state->handleInput(this);
    }

    void update() {
        m_state->update(this);
    }

    void setState(PlayerState* state) {
        m_state->exit(this);
        delete m_state;
        m_state = state;
        m_state->enter(this);
    }

    bool isJumping() const {
        // Return true if player is jumping
    }

    bool isMoving() const {
        // Return true if player is moving
    }

private:
    PlayerState* m_state;
};