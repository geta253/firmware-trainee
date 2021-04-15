#include "user_public_functions.h"
#include "memory_manipulation.h"
#include "user_interaction.h"
#include "user_data.h"
#include "agenda.h"
#include <stdint.h>

//Public Definitions
UserData *getNewUserEntry()
{
    UserData *userEntry = createUserEntry();
    allocateUserDataMemory(&userEntry);
    if(!hasAllocatedUserDataMemory(userEntry))
    {
        freeAllDataAllocatedForUser(userEntry);
        return NULL;
    }
    askForUserInfo(userEntry);
    reallocateUserDataMemory(userEntry);
    return userEntry;
}

int setUserEntryInAgenda(UserData *newUserEntry, Agenda **agenda)
{
    if(newUserEntry != NULL)
    {
        Agenda *newAgendaEntry = createAgendaEntry();
        allocateAgendaEntryMemory(&newAgendaEntry);
        if(!hasAllocatedAgendaEntry(newAgendaEntry))
        {
            freeAgendaEntry(newAgendaEntry);
            return 0;
        }
        newAgendaEntry->currentEntry = *newUserEntry;
        newAgendaEntry->nextEntry = NULL;
        freeUserEntry(newUserEntry);
        linkAgendaEntryToEndOfAgenda(agenda, newAgendaEntry);
        showUserEntryAddedInAgendaMessage();
        return 1;
    }
    return 0;
}

uint8_t *getSearchedUser()
{
    uint8_t *searchedName = getNameFromInput();
    return searchedName;
}

void displayUserByName(uint8_t *searchedName, Agenda *agenda)
{
    if(agenda == NULL) return;
    int numberOfUsersFound = 0;
    Agenda *currentInLoop = agenda;
    while(currentInLoop != NULL)
    {
        if(stringsAreEqual((char*)currentInLoop->currentEntry.name, (char*)searchedName))
        {
            showSearchedUser(&currentInLoop->currentEntry);
            numberOfUsersFound++;
        }
        currentInLoop = currentInLoop->nextEntry;
    }
    if(numberOfUsersFound == 0)
    {
        showNoUsersFoundMessage();
    }
    waitForKeyPress();
}

uint8_t getSearchedInitial()
{
    uint8_t initialSearched = getInitialFromInput();
    return initialSearched;
}

void displayUserByInitial(uint8_t initial, Agenda *agenda)
{
    if(agenda == NULL) return;
    int numberOfUsersFound = 0;
    Agenda *currentInLoop = agenda;
    while(currentInLoop != NULL)
    {
        if(currentInLoop->currentEntry.name[0] == initial)
        {
            showSearchedUser(&currentInLoop->currentEntry);
            numberOfUsersFound++;
        }
        currentInLoop = currentInLoop->nextEntry;
    }
    if(numberOfUsersFound == 0)
    {
        showNoUsersFoundMessage();
    }
    waitForKeyPress();
}
