#include "user_functions.h"
#include "user_data.h"
#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Private Declarations
int hasAllocatedAgendaEntry(Agenda **);
int hasLinkedAgendaEntryToEndOfAgenda(Agenda **, Agenda *);
int hasAllocatedUserDataMemory(UserData *);
void askForAge(UserData *);
void askForName(UserData *);
void freeAll(UserData *);
void displayUserEntryAddedInAgendaMessage();

//Public Definitions
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

UserData *getNewUserEntry()
{
    UserData *userData = malloc(sizeof *(userData));
    if(userData == NULL) return NULL;
    if(!hasAllocatedUserDataMemory(userData))
    {
        freeAll(userData);
        return NULL;
    }
    askForName(userData);
    askForAge(userData);
    //...
    return userData;
}

char *getSearchedUser()
{
    //char *p = fgets(name, sizeof name, stdin) for name[MAX]
    char *searchedName = malloc(sizeof *searchedName * MAX_LENGTH);
    printf("\nSearch by a name: ");
    return fgets(searchedName, sizeof *searchedName * MAX_LENGTH, stdin);
}

void displayUserByName(char *searchedName, Agenda *agenda)
{
    if(agenda == NULL) return;
    int numberOfUsersFound = 0;
    Agenda *currentInLoop = agenda;
    while(currentInLoop != NULL)
    {
        if(!strcmp(currentInLoop->currentEntry.name, searchedName)) //if equal
        {
            printf("\nUser searched:\n");
            printf("Name: %s", currentInLoop->currentEntry.name);
            printf("Age: %d\n", *(currentInLoop->currentEntry.age));

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

char getSearchedInitial()
{
    //char *p = fgets(name, sizeof name, stdin) for name[MAX]
    printf("\nSearch by an initial:");
    return (char)fgetc(stdin);
}

void displayUserByInitial(char initial, Agenda *agenda)
{
    if(agenda == NULL) return;
    int numberOfUsersFound = 0;
    Agenda *currentInLoop = agenda;

    printf("\nUsers found:\n");
    while(currentInLoop != NULL)
    {
        if(currentInLoop->currentEntry.name[0] == initial)
        {
            //print name..
            printf("\nName: %s", currentInLoop->currentEntry.name);
            printf("Age: %d\n", *(currentInLoop->currentEntry.age));

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

//Private definitions
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

int hasAllocatedUserDataMemory(UserData *p_userData)
{
    p_userData->age = malloc(sizeof *(p_userData->age));
    if(p_userData->age == NULL) return 0;
    p_userData->name = malloc(sizeof *(p_userData->name) * MAX_LENGTH);
    if(p_userData->name == NULL) return 0;
    //...
    return 1;
}

void askForName(UserData *p_userData)
{
    printf("\nName: ");
    int nameLength = sizeof *(p_userData->name) * MAX_LENGTH;
    fgets(p_userData->name, nameLength, stdin);

}

void askForAge(UserData *p_userData)
{
    printf("Age: ");
    scanf("%d", p_userData->age);
    getchar();
}

void freeAll(UserData *userData)
{
    free(userData->age);
    free(userData->name);
    //...
    free(userData);
}

void displayUserEntryAddedInAgendaMessage()
{
    printf("\nUser successfully added in Agenda!");
    printf("\nPress any key to return\n");
    getch();
}
