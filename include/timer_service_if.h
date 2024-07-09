#ifndef TIMER_SERVICE_IF
#define TIMER_SERVICE_IF

#include <iostream>
#include <functional>

typedef std::function<void(int)> CallbackFunc;

class TimerServiceIf
{
public:
    virtual ~TimerServiceIf() = default; // Add a virtual destructor
    virtual void step() = 0;
    virtual int register_event(int time, CallbackFunc callback) = 0;
    virtual void delete_event(int id) = 0;
};

#endif
