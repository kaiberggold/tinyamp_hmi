# hmi (human machine interface)

## abstraction layers for inputs from  lowest level to highest. Obeys dependency inversion, so the higher levels do not know about the lower levels.

* actuator level : creates actuator events from  actuators
 , e.g. switch button changes from off to on
* input event levels: creates virtual input events. Denouncing takes place here. 
* hmi: Input state machine. Dependent on stae the input events create different actions