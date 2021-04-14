#include "memory_manipulation.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int hasAllocatedAgendaEntry(Agenda **newAgendaEntry)
{
    *newAgendaEntry = malloc(sizeof **newAgendaEntry);
    if(newAgendaEntry != NULL) return 1;
    free(newAgendaEntry);
    return 0;
}

int hasLinkedAgendaEntryToEndOfAgenda(Agenda **agenda, Agenda *agendaEntry)
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

int hasAllocatedUserDataMemory(UserData *userData)
{
    userData->name = malloc(sizeof *(userData->name) * MAX_LENGTH);
    if(userData->name == NULL) return 0;
    userData->address = malloc(sizeof *(userData->address) * MAX_LENGTH);
    if(userData->address == NULL) return 0;
    userData->phone = malloc(sizeof *(userData->phone) * MAX_LENGTH);
    if(userData->phone == NULL) return 0;
    userData->CEP = malloc(sizeof *(userData->CEP));
    if(userData->CEP == NULL) return 0;
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

void freeAll(UserData *userData)
{
    free(userData->name);
    free(userData->address);
    free(userData->phone);
    free(userData->CEP);
    free(userData);
}
