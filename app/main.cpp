#include <iostream>
#include "hmi.h"
#include "input_events_impl.h"
#include "input_actuators_impl.h"

int main()
{
    Hmi hmi;
    InputEventsImpl input_events(&hmi);
    InputActuatorsImpl input_actuators(&input_events);

    // Simulate button events
    input_actuators.simulateActuatorEvent(InputActuatorEventType::BUTTON_RISING_EDGE);
    input_actuators.simulateActuatorEvent(InputActuatorEventType::BUTTON_FALLING_EDGE);
    input_actuators.simulateActuatorEvent(InputActuatorEventType::BUTTON_RISING_EDGE);
    input_actuators.simulateActuatorEvent(InputActuatorEventType::BUTTON_FALLING_EDGE);
    return 0;
}
