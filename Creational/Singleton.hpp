#pragma once

#include <mutex>
#include <memory>
#include <iostream>

/*
    Example Singleton implementation for an InputManager class.
    Thread safe, one globally accessible instance.
*/

class InputManager {
public:

    static InputManager& getInstance() {
        std::call_once(InputManager::m_onceFlag, []() {

            std::lock_guard<std::mutex> lock(m_mutex);
            InputManager::m_instance.reset(new InputManager);
            std::cout << "InputManager is being created for the first time.\n";

            });

        std::cout << "Returning InputManager instance.\n";
        return *(InputManager::m_instance);
    }

    void handleInput() {
        std::lock_guard<std::mutex> lock(m_mutex);
        //handle input..

        std::cout << "Input is being handled..\n";
    }

private:

    InputManager() {}

    //explicit deletion of compiler generated constructors and operators
    //to ensure Singleton function
    InputManager(InputManager const&) = delete;
    void operator=(InputManager const&) = delete;
    InputManager(InputManager&&) = delete;
    InputManager& operator=(InputManager&&) = delete;

    static std::unique_ptr<InputManager> m_instance;
    static std::once_flag m_onceFlag;
    static std::mutex m_mutex;

};

std::unique_ptr<InputManager> InputManager::m_instance;
std::once_flag InputManager::m_onceFlag;
std::mutex InputManager::m_mutex;
