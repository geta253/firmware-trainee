#include "user_data.h"
#include "agenda_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int hasAllocatedUserDataMemory(struct UserData *p_userData)
{
    p_userData->age = malloc(sizeof *(p_userData->age));
    if(p_userData->age == NULL) return 0;
    p_userData->name = malloc(sizeof *(p_userData->name) * MAX_LENGTH);
    if(p_userData->name == NULL) return 0;
    //...
    return 1;
}

void askForAge(struct UserData *p_userData)
{
    printf("Age: ");
    scanf("%d", p_userData->age);
    getchar();
}

void askForName(struct UserData *p_userData)
{
    printf("\nName: ");
    int nameLength = sizeof *(p_userData->name) * MAX_LENGTH;
    fgets(p_userData->name, nameLength, stdin);

}

void freeAll(struct UserData *userData)
{
    free(userData->age);
    free(userData->name);
    //...
    free(userData);
}

struct UserData *getNewUserEntry()
{
    struct UserData *userData = malloc(sizeof *(userData));
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

void displayUserByName(char *searchedName) //name
{
    if(agenda == NULL) return;
    int numberOfUsersFound = 0;
    struct Agenda *currentInLoop = agenda;
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
    return (char)fgetc(stdin);;
}

void displayUserByInitial(char initial)
{
    if(agenda == NULL) return;
    int numberOfUsersFound = 0;
    struct Agenda *currentInLoop = agenda;

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
