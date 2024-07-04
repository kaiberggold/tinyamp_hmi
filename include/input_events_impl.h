#ifndef INPUT_EVENTS_IMPL_H
#define INPUT_EVENTS_IMPL_H

#include "input_events_if.h"
#include "input_actuators_events_if.h"
#include <iostream>

class InputEventsImpl : public InputActuatorsEventsIf
{
private:
    InputEventsIf *_input_events;

public:
    InputEventsImpl(InputEventsIf *ie) : _input_events(ie) {}

    void setInputActuatorEvent(InputActuatorEventType inputActuatorEvent) override
    {
        std::cout << "setInputActuatorEvent" << std::endl;
        _input_events->setInputEvent(InputEventType::ROTARY_ENCODER_1_LEFT_FAST);
    }
};

#endif // INPUT_EVENTS_IMPL_H
