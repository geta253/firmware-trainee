#ifndef H_USER_FUNCTIONS_INCLUDED
#define H_USER_FUNCTIONS_INCLUDED

#define MAX_LENGTH 50

#include "user_data.h"
#include "agenda.h"
#include <stdint.h>

UserData *getNewUserEntry();
int setUserEntryInAgenda(UserData *, Agenda **);
uint8_t *getSearchedUser();
void displayUserByName(uint8_t *, Agenda *);
uint8_t getSearchedInitial();
void displayUserByInitial(uint8_t, Agenda *);

#endif // H_USER_FUNCTIONS_INCLUDED
