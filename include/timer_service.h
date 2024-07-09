#ifndef TIMER_SERVICE
#define TIMER_SERVICE

#include <iostream>
#include "timer_service_if.h"

class TimerService : public TimerServiceIf
{
private:
    CallbackFunc _callback;
    int _time;
    int _id = 0;

public:
    void step() override
    {
        if (_time > 0)
        {
            _time--;
            if (_time == 0)
            {
                _callback(_id);
            }
        }
    }

    int register_event(int time, CallbackFunc callback) override
    {
        _id++;
        std::cout << "New Timer Event" << _id << std::endl;
        _time = time;
        _callback = callback;
        return _id;
    }

    void delete_event(int id) override
    {
        std::cout << "Deleted Event" << id << std::endl;
    }
};

#endif
