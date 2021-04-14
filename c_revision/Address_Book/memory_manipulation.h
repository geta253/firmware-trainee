#ifndef H_MEMORY_MANIPULATION_INCLUDED
#define H_MEMORY_MANIPULATION_INCLUDED

#include "agenda.h"
#include "user_data.h"

int hasAllocatedAgendaEntry(Agenda **);
int hasLinkedAgendaEntryToEndOfAgenda(Agenda **, Agenda *);
int hasAllocatedUserDataMemory(UserData *);
void reallocateUserDataMemory(UserData *);
void freeAll(UserData *);

#endif // H_MEMORY_MANIPULATION_INCLUDED
