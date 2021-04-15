#ifndef H_USER_INTERACTION_INCLUDED
#define H_USER_INTERACTION_INCLUDED

#include "user_data.h"

void askForUserInfo(UserData *);

uint8_t *getNameFromInput();
void showSearchedUser(UserData *);
int stringsAreEqual(char *, char *);

uint8_t getInitialFromInput();
void showUserWithInitial(UserData *);

void showUserEntryAddedInAgendaMessage();
void showNoUsersFoundMessage();
void waitForKeyPress();

void clearScreen();
void printMenuOptions();
int getInputedMenuOption();
void showInvalidOptionMessage();

#endif // H_USER_INTERACTION_INCLUDED
