#include "user_public_functions.h"
#include "memory_manipulation.h"
#include "user_interaction.h"
#include "user_data.h"
#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdint.h>
#include <inttypes.h>

//Public Definitions
UserData *getNewUserEntry()
{
    UserData *userData = malloc(sizeof *(userData));
    if(userData == NULL) return NULL;
    if(!hasAllocatedUserDataMemory(userData))
    {
        freeAll(userData);
        return NULL;
    }
    askForUserInfo(userData);
    reallocateUserDataMemory(userData);
    return userData;
}

int setUserEntryInAgenda(UserData *newUserEntry, Agenda **agenda)
{
    if(newUserEntry != NULL)
    {
        Agenda *newAgendaEntry;
        if(!hasAllocatedAgendaEntry(&newAgendaEntry)) return 0;
        newAgendaEntry->currentEntry = *newUserEntry;
        free(newUserEntry);
        newAgendaEntry->nextEntry = NULL;
        if(hasLinkedAgendaEntryToEndOfAgenda(agenda, newAgendaEntry))
        {
            displayUserEntryAddedInAgendaMessage();
        }
        return 1;
    }
    return 0;
}

uint8_t *getSearchedUser()
{
    //uint8_t *p = fgets(name, sizeof name, stdin) for name[MAX]
    uint8_t *searchedName = malloc(sizeof *searchedName * MAX_LENGTH);
    printf("\nSearch by a name: ");
    return (uint8_t*)fgets((char*)searchedName, sizeof *searchedName * MAX_LENGTH, stdin);
}

void displayUserByName(uint8_t *searchedName, Agenda *agenda)
{
    if(agenda == NULL) return;
    int numberOfUsersFound = 0;
    Agenda *currentInLoop = agenda;
    while(currentInLoop != NULL)
    {
        if(!strcmp((char*)currentInLoop->currentEntry.name, (char*)searchedName)) //if equal
        {
            printf("\nUser searched:\n");
            printf("Name: %s", (char*)currentInLoop->currentEntry.name);
            printf("Address: %s", (char*)currentInLoop->currentEntry.address);
            printf("Phone: %s", (char*)currentInLoop->currentEntry.phone);
            printf("CEP: %"SCNu64"\n", *(currentInLoop->currentEntry.CEP));

            numberOfUsersFound++;
        }
        currentInLoop = currentInLoop->nextEntry;
    }
    if(numberOfUsersFound == 0)
    {
        printf("\nNo entry found");
    }

    printf("\nPress any key to return\n");
    getch();
}

uint8_t getSearchedInitial()
{
    //uint8_t *p = fgets(name, sizeof name, stdin) for name[MAX]
    printf("\nSearch by an initial:");
    return (uint8_t)fgetc(stdin);
}

void displayUserByInitial(uint8_t initial, Agenda *agenda)
{
    if(agenda == NULL) return;
    int numberOfUsersFound = 0;
    Agenda *currentInLoop = agenda;

    printf("\nUsers found:\n");
    while(currentInLoop != NULL)
    {
        if(currentInLoop->currentEntry.name[0] == initial)
        {
            printf("\nName: %s", (char*)currentInLoop->currentEntry.name);
            printf("Address: %s", (char*)currentInLoop->currentEntry.address);
            printf("Phone: %s", (char*)currentInLoop->currentEntry.phone);
            printf("CEP: %"SCNu64"\n", *(currentInLoop->currentEntry.CEP));

            numberOfUsersFound++;
        }
        currentInLoop = currentInLoop->nextEntry;
    }
    if(numberOfUsersFound == 0)
    {
        printf("No entry found\n");
    }
    printf("\nPress any key to return\n");
    getch();
}
