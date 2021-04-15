#include "memory_manipulation.h"
#include <stdlib.h>
#include <string.h>

Agenda *createAgendaEntry()
{
    return NULL;
}

void freeAgendaEntry(Agenda *agendaEntry)
{
    free(agendaEntry);
}

void allocateAgendaEntryMemory(Agenda **agendaEntry)
{
    *agendaEntry = malloc(sizeof **(agendaEntry));
}

int hasAllocatedAgendaEntry(Agenda *newAgendaEntry)
{
    if(newAgendaEntry != NULL) return 1;
    free(newAgendaEntry);
    return 0;
}

int linkAgendaEntryToEndOfAgenda(Agenda **agenda, Agenda *agendaEntry)
{
    if(isAgendaEmpty(*agenda))
    {
        *agenda = agendaEntry;
    }
    else
    {
        Agenda *currentInLoop = *agenda;
        while(currentInLoop->nextEntry != NULL)
        {
            currentInLoop = currentInLoop->nextEntry;
        }
        currentInLoop->nextEntry = agendaEntry;
    }
    return 1;
}

void freeAllDataAllocatedForAgendaEntry(Agenda *agendaEntry)
{
    free(agendaEntry->currentEntry.name);
    free(agendaEntry->currentEntry.address);
    free(agendaEntry->currentEntry.phone);
    free(agendaEntry->currentEntry.CEP);
    free(agendaEntry);
}

UserData *createUserEntry()
{
    return NULL;
}

void freeUserEntry(UserData *userEntry)
{
    free(userEntry);
}

void allocateUserDataMemory(UserData **userData)
{
    *userData = malloc(sizeof **(userData));
    (*userData)->name = malloc(sizeof *((*userData)->name) * MAX_LENGTH);
    (*userData)->address = malloc(sizeof *((*userData)->address) * MAX_LENGTH);
    (*userData)->phone = malloc(sizeof *((*userData)->phone) * MAX_LENGTH);
    (*userData)->CEP = malloc(sizeof *((*userData)->CEP));
}

int hasAllocatedUserDataMemory(UserData *userData)
{
    if(   (userData->name == NULL)
       || (userData->address == NULL)
       || (userData->phone == NULL)
       || (userData->CEP == NULL)    )
    {
        return 0;
    }
    return 1;
}

void reallocateUserDataMemory(UserData *userData)
{
    uint8_t *name = realloc(userData->name, strlen((char*) userData->name));
    if(name != NULL) userData->name = name;
    uint8_t *address = realloc(userData->address, strlen((char*) userData->address));
    if(address != NULL) userData->address = address;
    uint8_t *phone = realloc(userData->phone, strlen((char*) userData->phone));
    if(phone != NULL) userData->phone = phone;
}

void freeAllDataAllocatedForUser(UserData *userData)
{
    free(userData->name);
    free(userData->address);
    free(userData->phone);
    free(userData->CEP);
    free(userData);
}
