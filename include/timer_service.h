#ifndef TIMER_SERVICE
#define TIMER_SERVICE

#include <iostream>
#include "timer_service_if.h"
#include <array>

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

        for (int i = 0; i < 10; i++)
        {
            if (_events[i].time != 0)
            {
                _events[i].time--;
                if (_events[i].time == 0)
                {
                    _events[i].callback(i);
                }
            }
        }
    }

    int register_event(int time, CallbackFunc callback) override
    {
        int id = 0;
        while (_events[id].time > 0)
        {
            id++;
        }
        _events[id].time = time;
        _events[id].callback = callback;
        return id;
    }

    void delete_event(int id) override
    {
        std::cout << "Deleted Event" << id << std::endl;
        _events[id].time = 0;
    }
};

#endif
