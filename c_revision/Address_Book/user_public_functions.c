#include "user_public_functions.h"
#include "memory_manipulation.h"
#include "user_io.h"
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
    showUserSearchedMessage();
    while(currentInLoop != NULL)
    {
        if(stringsAreEqual((char*)currentInLoop->currentEntry.name, (char*)searchedName))
        {
            showUserFound(&currentInLoop->currentEntry);
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
    showUsersFoundByInitialMessage();
    while(currentInLoop != NULL)
    {
        if(currentInLoop->currentEntry.name[0] == initial)
        {
            showUserFound(&currentInLoop->currentEntry);
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

void printAllEntriesInAgenda(Agenda *agenda)
{
    if(agenda == NULL) return;
    Agenda *currentInLoop = agenda;
    showAllUsersInAgendaMessage();
    while(currentInLoop != NULL)
    {
        showUserFound(&currentInLoop->currentEntry);
        currentInLoop = currentInLoop->nextEntry;
    }
}

int clearAllEntriesInAgenda(Agenda **agenda)
{
    if(*agenda == NULL) return 0;
    Agenda *currentInLoop = *agenda;
    Agenda *auxiliar = currentInLoop;
    while(currentInLoop != NULL)
    {
        auxiliar = auxiliar->nextEntry;
        freeAllDataAllocatedForAgendaEntry(currentInLoop);
        currentInLoop = auxiliar;
    }
    *agenda = NULL;
    return 1;
}
