#include "agenda.h"
#include "user_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//Public Definitions
Agenda *newAgenda()
{
    return NULL;
}

int isAgendaEmpty(Agenda *agenda)
{
    if(agenda != NULL) return 0;
    return 1;
}
/*
void printAllEntriesInAgenda(Agenda *agenda)
{
    Agenda *currentInLoop = agenda;
    while(currentInLoop != NULL)
    {
        printf("\n%s", currentInLoop->currentEntry.name);
        printf("%d", *(currentInLoop->currentEntry.age));
        //...
        currentInLoop = currentInLoop->nextEntry;
    }
}

int clearAllEntriesInAgenda(Agenda **agenda)
{
    Agenda *currentInLoop = *agenda;
    Agenda *auxiliar = currentInLoop;
    while(currentInLoop != NULL)
    {
        auxiliar = auxiliar->nextEntry;
        free(currentInLoop->currentEntry.name);
        free(currentInLoop->currentEntry.age);
        //...
        free(currentInLoop);
        currentInLoop = auxiliar;
    }
    *agenda = NULL;
    return 1;
}
*/
