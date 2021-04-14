#include "user_interaction.h"
#include "user_data.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

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
