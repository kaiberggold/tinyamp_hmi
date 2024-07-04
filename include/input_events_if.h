#ifndef INPUT_EVENTS_IF_H
#define INPUT_EVENTS_IF_H

#include <iostream>

enum class InputEventType
{
    TOGGLE_BUTTON_1_SHORT,
    TOGGLE_BUTTON_1_LONG,
    // ...
    TOGGLE_BUTTON_1_2_LONG,
    // ...
    ROTARY_ENCODER_1_LEFT_SLOW,
    ROTARY_ENCODER_1_RIGHT_SLOW,
    ROTARY_ENCODER_1_LEFT_FAST,
    ROTARY_ENCODER_1_RIGHT_FAST,
    // ...
};

class InputEventsIf
{
public:
    virtual ~InputEventsIf() = default;
    virtual void setInputEvent(InputEventType inputEvent) = 0;
};

#endif // INPUT_EVENTS_IF_H
