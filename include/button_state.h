#include <iostream>
#include "input_actuators_events_if.h"
#include "timer_service_if.h"

enum class ButtonState
{
    OFF,
    ON_TRANSIENT,
    OFF_TRANSIENT_SHORT,
    ON_SHORT,
    ON_LONG,
    OFF_TRANSIENT_LONG
};

const int DEBOUNCE_TIME_ON = 2;  // example debounce time in milliseconds
const int DEBOUNCE_TIME_OFF = 2; // example debounce time in milliseconds
const int TIME_LONG = 10;        // example time to consider as long press in milliseconds

class ButtonStateChart
{
private:
    ButtonState _state;
    TimerServiceIf *_tim;
    int _id_deb_on;
    int _id_deb_off;

public:
    ButtonStateChart(ButtonState s, TimerServiceIf *t) : _state(s), _tim(t)
    {
    }

    void setNewActuatorEvent(InputActuatorEventType event)
    {
        switch (_state)
        {
        case ButtonState::OFF:
            if (event == InputActuatorEventType::BUTTON_RISING_EDGE)
                transition(ButtonState::ON_TRANSIENT);
            std::cout << "register_deb_on\n";
            _id_deb_on = _tim->register_event(DEBOUNCE_TIME_ON, [this](int id)
                                              { timer_service_call_back(id); });

        case ButtonState::ON_TRANSIENT:
            if (event == InputActuatorEventType::BUTTON_FALLING_EDGE)
            {
                _tim->delete_event(_id_deb_on);
                transition(ButtonState::OFF_TRANSIENT_SHORT);
                std::cout << "register_deb_off\n";

                _id_deb_off = _tim->register_event(DEBOUNCE_TIME_OFF, [this](int id)
                                                   { timer_service_call_back(id); });
            }
            break;

        case ButtonState::OFF_TRANSIENT_SHORT:
            if (event == InputActuatorEventType::BUTTON_RISING_EDGE)
            {
                transition(ButtonState::ON_SHORT);
            }
            break;

        case ButtonState::ON_SHORT:
            if (event == InputActuatorEventType::BUTTON_FALLING_EDGE)
            {
                std::cout << "ON_SHORT ->OFF_TRANSIENT_SHORT\n";
                transition(ButtonState::OFF_TRANSIENT_SHORT);
                std::cout << "register_deb_off\n";

                _id_deb_off = _tim->register_event(DEBOUNCE_TIME_OFF, [this](int id)
                                                   { timer_service_call_back(id); });
            }
            break;

        case ButtonState::ON_LONG:
            if (event == InputActuatorEventType::BUTTON_FALLING_EDGE)
            {
                transition(ButtonState::OFF_TRANSIENT_LONG);
            }
            break;

        case ButtonState::OFF_TRANSIENT_LONG:
            if (event == InputActuatorEventType::BUTTON_RISING_EDGE)
            {
                transition(ButtonState::ON_LONG);
            }
            break;
        }
    }

    void event_short()
    {
        std::cout << "Short event triggered" << std::endl;
    }

    void event_long()
    {
        std::cout << "Long event triggered" << std::endl;
    }

    void transition(ButtonState newState)
    {
        std::cout << "Transition from " << static_cast<int>(_state) << " to " << static_cast<int>(newState) << std::endl;
        _state = newState;
    }

    void timer_service_call_back(int id)
    {
        std::cout << "Callback: " << id << " executed" << std::endl;
        switch (_state)
        {
        case ButtonState::ON_TRANSIENT:
            if (id == _id_deb_on)
            {
                transition(ButtonState::ON_SHORT);
                event_short();
            }
            break;

        case ButtonState::OFF_TRANSIENT_SHORT:
            if (id == _id_deb_off)
            {
                transition(ButtonState::OFF);
            }
            break;

        case ButtonState::ON_SHORT:
            if (id == 2)
            {
                transition(ButtonState::ON_LONG);
                event_long();
            }
            break;

        case ButtonState::OFF_TRANSIENT_LONG:
            if (id == 2)
            {
                transition(ButtonState::OFF);
            }
            break;
        }
    }
};

// int main() {
//     StateMachine fsm;

//     while (true) {
//         // Simulate raw signal changes
//         // For testing purposes only, replace with actual input reading logic
//         std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate a delay

//         // Update the FSM with the current _state of the raw signal
//         fsm.update();

//         // For testing, toggle the raw signal manually
//         // In practice, this would be tied to a hardware input
//         static bool toggle = false;
//         toggle = !toggle;
//         raw = toggle;
//     }

//     return 0;
// }
