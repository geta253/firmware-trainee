#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Agenda *agenda = NULL;

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

int hasAllocatedAgendaEntry(struct Agenda **p_newEntry)
{
    *p_newEntry = malloc(sizeof **p_newEntry);
    if(p_newEntry != NULL) return 1;
    free(p_newEntry);
    return 0;
}

int hasLinkedAgendaEntryToEndOfAgenda(struct Agenda **agenda, struct Agenda *agendaEntry)
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

void displayUserEntryAddedInAgendaMessage()
{
    printf("\nUser successfully added in Agenda!");
    printf("\nPress any key to return\n");
    getch();
}

int insertUserEntryInAgenda(struct Agenda **agenda, struct UserData *userDataEntry)
{
    struct Agenda *newAgendaEntry;
    if(!hasAllocatedAgendaEntry(&newAgendaEntry)) return 0;
    newAgendaEntry->currentEntry = *userDataEntry;
    free(userDataEntry);
    newAgendaEntry->nextEntry = NULL;
    if(hasLinkedAgendaEntryToEndOfAgenda(agenda, newAgendaEntry))
    {
        displayUserEntryAddedInAgendaMessage();
    }
    return 1;
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
