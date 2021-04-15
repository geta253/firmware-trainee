#include "user_interaction.h"
#include "user_data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <conio.h>

void askForName(UserData *);
void askForAddress(UserData *);
void askForPhone(UserData *);
void askForCEP(UserData *);


void askForUserInfo(UserData *userData)
{
    askForName(userData);
    askForAddress(userData);
    askForPhone(userData);
    askForCEP(userData);
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

void displayUserEntryAddedInAgendaMessage()
{
    printf("\nUser successfully added in Agenda!");
    printf("\nPress any key to return\n");
    getch();
}

uint8_t *getNameFromInput()
{
    printf("\nSearch by a name: ");
    uint8_t *inputedName = malloc(sizeof *inputedName * MAX_LENGTH);
    return (uint8_t*)fgets((char*)inputedName, sizeof *inputedName * MAX_LENGTH, stdin);
}

int stringsAreEqual(char *string1, char *string2)
{
    if(!strcmp(string1, string2)) return 1;
    return 0;
}

void showSearchedUser(UserData *userData)
{
    printf("\nName: %s", (char*)userData->name);
    printf("Address: %s", (char*)userData->address);
    printf("Phone: %s", (char*)userData->phone);
    printf("CEP: %"SCNu64"\n", *(userData->CEP));
}

void showNoUsersFoundMessage()
{
    printf("\nNo entry found");
}

void waitForKeyPress()
{
    printf("\nPress any key to return\n");
    getch();
}

uint8_t getInitialFromInput()
{
    printf("\nSearch by an initial:");
    uint8_t inputedInitial = (uint8_t)fgetc(stdin);
    return inputedInitial;
}

void showUserWithInitial(UserData *userData)
{
    showSearchedUser(userData);
}
