#include "agenda.h"
#include "user_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Agenda *newAgenda()
{
    return NULL;
}

int isAgendaEmpty(struct Agenda *agenda)
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
