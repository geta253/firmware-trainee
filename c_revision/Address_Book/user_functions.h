#ifndef H_USER_FUNCTIONS_INCLUDED
#define H_USER_FUNCTIONS_INCLUDED

#define MAX_LENGTH 50

#include "user_data.h"

int allocateUserDataMemory(struct UserData *);

void askForAge(struct UserData *);

void freeAll(struct UserData *);

struct UserData *getNewUserEntry();

char *getSearchedUser();

void displayUserByName(char *);

char getSearchedInitial();

void displayUserByInitial(char);

void printEntireAgenda();

int clearAgenda();

#endif // H_USER_FUNCTIONS_INCLUDED
