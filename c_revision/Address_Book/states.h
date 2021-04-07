#ifndef H_STATES_INCLUDED
#define H_STATES_INCLUDED
#include "act2_states.h"

typedef enum States state_t;

void setState(state_t);
state_t getState();

#endif // H_STATES_INCLUDED
