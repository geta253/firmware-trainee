#include "user_functions.h"
#include "user_data.h"
#include "agenda.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdint.h>
#include <inttypes.h>

//Private Declarations
int hasAllocatedAgendaEntry(Agenda **);
int hasLinkedAgendaEntryToEndOfAgenda(Agenda **, Agenda *);
int hasAllocatedUserDataMemory(UserData *);
void askForName(UserData *);
void askForAddress(UserData *);
void askForPhone(UserData *);
void askForCEP(UserData *);
void reallocateUserDataMemory(UserData *);
void freeAll(UserData *);
void displayUserEntryAddedInAgendaMessage();

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
    askForName(userData);
    askForAddress(userData);
    askForPhone(userData);
    askForCEP(userData);
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

void askForName(UserData *userData)
{
    printf("\nName: ");
    int nameLength = sizeof *(userData->name) * MAX_LENGTH;
    fgets((char*)userData->name, nameLength, stdin);
}

void askForAddress(UserData *userData)
{
    printf("Address: ");
    int addressLength = sizeof *(userData->address) * MAX_LENGTH;
    fgets((char*)userData->address, addressLength, stdin);
}
void askForPhone(UserData *userData)
{
    printf("Phone: ");
    int phoneLength = sizeof *(userData->phone) * MAX_LENGTH;
    fgets((char*)userData->phone, phoneLength, stdin);
}
void askForCEP(UserData *userData)
{
    printf("CEP: ");
    scanf("%"SCNu64, userData->CEP);
    getchar();
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

void displayUserEntryAddedInAgendaMessage()
{
    printf("\nUser successfully added in Agenda!");
    printf("\nPress any key to return\n");
    getch();
}
