#include "states.h"

static State state = 0;

void setState(State userState)
{
    state = userState;
}

State getState()
{
    return state;
}
