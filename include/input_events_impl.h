#ifndef INPUT_EVENTS_IMPL_H
#define INPUT_EVENTS_IMPL_H

#include "input_events_if.h"
#include "input_actuators_events_if.h"
#include <iostream>

class InputEventsImpl : public InputActuatorsEventsIf
{
private:
    InputEventsIf *_input_events;
    bool _state = false;

public:
    InputEventsImpl(InputEventsIf *ie) : _input_events(ie)
    {
    }

    void setInputActuatorEvent(InputActuatorEventType inputActuatorEvent) override
    {
        std::cout << "reveived actuator Event " << static_cast<int>(inputActuatorEvent) << std::endl;
        if (_state)
        {
            if (inputActuatorEvent == InputActuatorEventType::BUTTON_FALLING_EDGE)
            {
                _state = false;
                _input_events->setInputEvent(InputEventType::ROTARY_ENCODER_1_LEFT_SLOW);
            }
        }
        else
        {
            if (inputActuatorEvent == InputActuatorEventType::BUTTON_RISING_EDGE)
            {
                _state = true;
            }
        }
    }
};

#endif // INPUT_EVENTS_IMPL_H
