#include "agenda.h"
#include "user_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Public Definitions
Agenda *newAgenda()
{
    return NULL;
}

int isAgendaEmpty(Agenda *agenda)
{
    if(agenda != NULL) return 0;
    return 1;
}
