#ifndef H_USER_FUNCTIONS_INCLUDED
#define H_USER_FUNCTIONS_INCLUDED

#define MAX_LENGTH 50

#include "user_data.h"
#include "agenda.h"

struct UserData *getNewUserEntry(); //public

char *getSearchedUser(); //public

void displayUserByName(char *, struct Agenda *); //public

char getSearchedInitial(); //public

void displayUserByInitial(char, struct Agenda *); //public

void printAllEntriesInAgenda(struct Agenda *); //public

int clearAllEntriesInAgenda(struct Agenda **); //public

int setUserEntryInAgenda(struct UserData *, struct Agenda **); //public

#endif // H_USER_FUNCTIONS_INCLUDED
