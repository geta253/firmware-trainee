#include <stdio.h>
#include "states.h"

static state_t state = 0;

void setState(state_t userState)
{
    state = userState;
}

state_t getState()
{
    return state;
}
