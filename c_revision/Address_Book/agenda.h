#ifndef H_AGENDA_INCLUDED
#define H_AGENDA_INCLUDED

#include "user_data.h"

struct Agenda
{
    struct UserData currentEntry;
    struct Agenda *nextEntry;
};//public

struct Agenda *newAgenda();

int isAgendaEmpty(); //public

int hasAllocatedAgendaEntry(struct Agenda **); //private

int hasLinkedAgendaEntryToEndOfAgenda(struct Agenda **, struct Agenda *); //private

#endif // H_AGENDA_INCLUDED
