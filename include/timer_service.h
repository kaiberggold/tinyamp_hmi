#ifndef TIMER_SERVICE
#define TIMER_SERVICE

#include <iostream>
#include "timer_service_if.h"
#include <array>
#include <algorithm>

struct TimerEvent
{
    CallbackFunc callback;
    int time;
};

class TimerService : public TimerServiceIf
{
private:
    // CallbackFuns;
    std::array<TimerEvent, 10> _events;

public:
    TimerService()
    {
        for (auto &event : _events)
        {
            event.time = 0;
        }
    }
    void step() override
    {
        for (size_t i = 0; i < _events.size(); ++i)
        {
            auto &event = _events[i];
            if (event.time > 0)
            {
                event.time--;
                if (event.time == 0)
                {
                    std::cout << "Callback " << i << " triggered\n";
                    event.callback(i);
                }
            }
        }
    }

    int register_event(int time, CallbackFunc callback) override
    {
        for (size_t id = 0; id < _events.size(); ++id)
        {
            if (_events[id].time == 0)
            {
                _events[id].time = time;
                _events[id].callback = callback;
                return id;
            }
        }
        std::cerr << "Error: No available slots to register event." << std::endl;
        return -1;
    }

    void delete_event(int id) override
    {
        if (id >= 0 && id < _events.size())
        {
            std::cout << "Deleted Event " << id << std::endl;
            _events[id].time = 0;
        }
        else
        {
            std::cerr << "Error: Invalid event id " << id << std::endl;
        }
    }
};

#endif
