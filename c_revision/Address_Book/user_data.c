#include "user_data.h"
#include <stdio.h>
#include <stdlib.h>

int allocateUserDataMemory(struct UserData *p_userData)
{
    p_userData->age = malloc(sizeof *(p_userData->age));
    if(p_userData->age == NULL) return 0;
    //...
    return 1;
}

void askForAge(struct UserData *p_userData)
{
    printf("Age: ");
    scanf("%d", p_userData->age);
}

void freeAll(struct UserData *userData)
{
    free(userData->age);
    //...
    free(userData);
}

struct UserData *getNewUserEntry()
{
    struct UserData *userData = malloc(sizeof *(userData));
    if(userData == NULL) return NULL;
    if(allocateUserDataMemory(userData) == UNSUCCESSFUL)
    {
        freeAll(userData);
        return NULL;
    }
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    askForAge(userData);
    //...
    return userData;
}
