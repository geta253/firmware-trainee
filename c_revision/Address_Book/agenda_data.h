#ifndef H_AGENDA_DATA_INCLUDED
#define H_AGENDA_DATA_INCLUDED

#include "user_data.h"

struct Agenda
{
    struct UserData currentEntry;
    struct Agenda *nextEntry;
};

int setUserEntryInAgenda(struct UserData *);

int isAgendaEmpty();

int allocateAgendaEntry(struct Agenda **);

int linkAgendaEntryToEndOfAgenda(struct Agenda **, struct Agenda *);

int insertUserEntryInAgenda(struct Agenda **, struct UserData *); //private

void printEntireAgenda();

int clearAgenda();



#endif // H_AGENDA_DATA_INCLUDED
