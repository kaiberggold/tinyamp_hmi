#ifndef HMI_H
#define HMI_H

#include <iostream>
#include "input_events_if.h"


class Hmi : public InputEventsIf
{
public:
    void setInputEvent(InputEventType inputEvent) override
    {
        std::cout << "Event: " << std::to_string(static_cast<int>(inputEvent)) << " received" << std::endl;
    }
};

#endif // HMI_H
