#ifndef H_MEMORY_MANIPULATION_INCLUDED
#define H_MEMORY_MANIPULATION_INCLUDED

#include "agenda.h"
#include "user_data.h"

Agenda *createAgendaEntry();
void allocateAgendaEntryMemory(Agenda **);
void freeAgendaEntry(Agenda *agendaEntry);
int hasAllocatedAgendaEntry(Agenda *);
int linkAgendaEntryToEndOfAgenda(Agenda **, Agenda *);

UserData *createUserEntry();
void freeUserEntry(UserData *userEntry);
void allocateUserDataMemory(UserData **);
int hasAllocatedUserDataMemory(UserData *);
void reallocateUserDataMemory(UserData *);
void freeAllDataAllocatedForUser(UserData *);

#endif // H_MEMORY_MANIPULATION_INCLUDED
