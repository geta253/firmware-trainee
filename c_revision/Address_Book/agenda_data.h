#ifndef H_AGENDA_DATA_INCLUDED
#define H_AGENDA_DATA_INCLUDED

#include "user_data.h"

struct Agenda
{
    struct UserData currentEntry;
    struct Agenda *nextEntry;
};
extern struct Agenda *agenda;

int setUserEntryInAgenda(struct UserData *);

int isAgendaEmpty();

int hasAllocatedAgendaEntry(struct Agenda **);

int hasLinkedAgendaEntryToEndOfAgenda(struct Agenda **, struct Agenda *);

int insertUserEntryInAgenda(struct Agenda **, struct UserData *); //private


#endif // H_AGENDA_DATA_INCLUDED
