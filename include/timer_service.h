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

        std::for_each(arr.begin(), arr.end(), [&arr](int& element){
        if (element.time > 0) {
            element.time--;
            const int index = std::distance(arr.begin(), &element);
            if (element.time == 0) {
                element.callback(index);
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
