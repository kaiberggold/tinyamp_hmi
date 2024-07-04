#ifndef INPUT_ACTUATORS_IMPL_H
#define INPUT_ACTUATORS_IMPL_H

#include "input_actuators_events_if.h"
#include <iostream>

class InputActuatorsImpl
{
private:
    InputActuatorsEventsIf *_input_events;

public:
    InputActuatorsImpl(InputActuatorsEventsIf *ie) : _input_events(ie) {}
    void simulateActuatorEvent(InputActuatorEventType inputActuatorEvent)
    {
        _input_events->setInputActuatorEvent(inputActuatorEvent);
    }
};

#endif // INPUT_ACTUATORS_IMPL_H