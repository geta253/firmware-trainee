#ifndef H_AGENDA_INCLUDED
#define H_AGENDA_INCLUDED

#include "user_data.h"

typedef struct Agenda
{
    struct UserData currentEntry;
    struct Agenda *nextEntry;
}Agenda;

Agenda *newAgenda();

int isAgendaEmpty(Agenda *);

#endif // H_AGENDA_INCLUDED
