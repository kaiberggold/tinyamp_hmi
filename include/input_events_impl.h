#ifndef INPUT_EVENTS_IMPL_H
#define INPUT_EVENTS_IMPL_H

#include <iostream>
#include "input_events_if.h"
#include "input_actuators_events_if.h"
#include "timer_service_if.h"
#include "button_state.h"

class InputEventsImpl : public InputActuatorsEventsIf
{
private:
    InputEventsIf *_input_events;
    TimerServiceIf *_timer_service;
    bool _state = false;
    ButtonStateChart button;

public:
    InputEventsImpl(InputEventsIf *ie, TimerServiceIf *t)
        : _input_events(ie), _timer_service(t), button(ButtonState::OFF, t)

    {
    }

    void setInputActuatorEvent(InputActuatorEventType inputActuatorEvent) override
    {
        std::cout << "reveived actuator Event " << static_cast<int>(inputActuatorEvent) << std::endl;
        button.setNewActuatorEvent(inputActuatorEvent);
    }
};

#endif // INPUT_EVENTS_IMPL_H
