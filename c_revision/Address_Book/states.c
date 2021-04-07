#include <stdio.h>
#include "states.h"

static state_t state = 0;

void setState(state_t user_state)
{
    state = user_state;
}

state_t getState()
{
    return state;
}
