#include "agenda_data.h"
#include <stdio.h>
#include <stdlib.h>

static struct Agenda *agenda = NULL;

int setUserEntryInAgenda(struct UserData *newUserEntry)
{
    if(newUserEntry != NULL)
    {
        insertUserEntryInAgenda(&agenda, newUserEntry);
        return 1;
    }
    return 0;
}

int isAgendaEmpty()
{
    if(agenda != NULL) return 0;
    return 1;
}

int allocateAgendaEntry(struct Agenda **p_newEntry)
{
    *p_newEntry = malloc(sizeof **p_newEntry);
    if(p_newEntry != NULL) return 1;
    free(p_newEntry);
    return 0;
}

int linkAgendaEntryToEndOfAgenda(struct Agenda **agenda, struct Agenda *agendaEntry)
{
    if(isAgendaEmpty(*agenda))
    {
        *agenda = agendaEntry;
    }
    else
    {
        struct Agenda *currentInLoop = *agenda;
        while(currentInLoop->nextEntry != NULL)
        {
            currentInLoop = currentInLoop->nextEntry;
        }
        currentInLoop->nextEntry = agendaEntry;
    }
    return 1;
}

int insertUserEntryInAgenda(struct Agenda **agenda, struct UserData *userDataEntry)
{
    struct Agenda *newAgendaEntry;
    if(allocateAgendaEntry(&newAgendaEntry) == UNSUCCESSFUL) return 0;
    newAgendaEntry->currentEntry = *userDataEntry;
    free(userDataEntry);
    newAgendaEntry->nextEntry = NULL;
    linkAgendaEntryToEndOfAgenda(agenda, newAgendaEntry);
    return 1;
}

void printEntireAgenda()
{
    struct Agenda *currentInLoop = agenda;
    while(currentInLoop != NULL)
    {
        printf("%d\n", *(currentInLoop->currentEntry.age));
        currentInLoop = currentInLoop->nextEntry;
    }
}

int clearAgenda()
{
    struct Agenda *currentInLoop = agenda;
    struct Agenda *auxiliar = currentInLoop;
    while(currentInLoop != NULL)
    {
        auxiliar = auxiliar->nextEntry;
        free(currentInLoop->currentEntry.age);
        //...
        free(currentInLoop);
        currentInLoop = auxiliar;
    }
    agenda = NULL;
    return 1;
}
