#ifndef H_USER_FUNCTIONS_INCLUDED
#define H_USER_FUNCTIONS_INCLUDED

#define MAX_LENGTH 50

#include "user_data.h"
#include "agenda.h"

int setUserEntryInAgenda(UserData *, Agenda **);
UserData *getNewUserEntry();
char *getSearchedUser();
void displayUserByName(char *, Agenda *);
char getSearchedInitial();
void displayUserByInitial(char, Agenda *);

#endif // H_USER_FUNCTIONS_INCLUDED
