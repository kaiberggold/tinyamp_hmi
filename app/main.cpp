#include <iostream>
#include <thread>
#include <chrono>
#include "hmi.h"
#include "input_events_impl.h"
#include "input_actuators_impl.h"
#include "timer_service.h"
#include "timer_service_if.h"

int main()
{
    Hmi hmi;

    TimerService tim_srv;
    InputEventsImpl input_events(&hmi, &tim_srv);
    InputActuatorsImpl input_actuators(&input_events);

    // Simulate button events
    // input_actuators.simulateActuatorEvent(InputActuatorEventType::BUTTON_RISING_EDGE);
    // input_actuators.simulateActuatorEvent(InputActuatorEventType::BUTTON_FALLING_EDGE);
    // input_actuators.simulateActuatorEvent(InputActuatorEventType::BUTTON_RISING_EDGE);
    // input_actuators.simulateActuatorEvent(InputActuatorEventType::BUTTON_FALLING_EDGE);

    const std::chrono::milliseconds interval(10); // 10ms interval
    std::cout << "Start" << std::endl;
    for (int i = 0; i < 500; i++)
    {
        auto next_execution_time = std::chrono::steady_clock::now() + interval;
        tim_srv.step();
        std::this_thread::sleep_until(next_execution_time);
        if ((i % 100) == 0)
            std::cout << "i:" << i << std::endl;
        if (i == 100)
            input_actuators.simulateActuatorEvent(InputActuatorEventType::BUTTON_RISING_EDGE);
        if (i == 200)
            input_actuators.simulateActuatorEvent(InputActuatorEventType::BUTTON_FALLING_EDGE);
    }
    return 0;
}