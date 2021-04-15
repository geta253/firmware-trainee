#ifndef H_USER_INTERACTION_INCLUDED
#define H_USER_INTERACTION_INCLUDED

#include "user_data.h"

void askForUserInfo(UserData *);
void displayUserEntryAddedInAgendaMessage();

uint8_t *getNameFromInput();
int stringsAreEqual(char *, char *);
void showSearchedUser(UserData *);
void showNoUsersFoundMessage();
void waitForKeyPress();
uint8_t getInitialFromInput();
void showUsersFoundTitle();
void showUserWithInitial(UserData *);

#endif // H_USER_INTERACTION_INCLUDED
