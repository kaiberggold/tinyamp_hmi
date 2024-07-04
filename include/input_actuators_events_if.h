#ifndef INPUT_ACTUATORS_EVENTS_IF_H
#define INPUT_ACTUATORS_EVENTS_IF_H

enum class InputActuatorEventType
{
    BUTTON_FALLING_EDGE,
    BUTTON_RISING_EDGE,
    ROTARY_ENCODER_LEFT,
    ROTARY_ENCODER_RIGHT
};

class InputActuatorsEventsIf
{
public:
    virtual void setInputActuatorEvent(InputActuatorEventType inputActuatorEvent) = 0;
};

#endif // INPUT_ACTUATORS_EVENTS_IF_H
