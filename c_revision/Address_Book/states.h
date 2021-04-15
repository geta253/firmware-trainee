#ifndef H_STATES_INCLUDED
#define H_STATES_INCLUDED

#include "act2_states.h"

typedef enum States State;

void setState(State);
State getState();

#endif // H_STATES_INCLUDED
