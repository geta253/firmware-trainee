#include "states.h"
#include "act2_states.h"
#include "agenda_data.h"
#include "menu.h"

/*
STATES:
    DISPLAY_MENU    ,
    INSERT_USER     ,
    SEARCH_USER     ,
    LIST_BY_INITIAL ,
    END             ,
*/

int main(void)
{
    struct Agenda *agenda = NULL;
    while(getState() != END)
    {
        switch(getState())
        {
        case DISPLAY_MENU:
            showMenu();
            state_t inputed_state = getMenuInput();
            setState(inputed_state);
            break; //menu.h

        case INSERT_USER:
            askForNewEntry();
            struct UserData *entry = getNewEntry();
            setAgendaEntry(agenda, entry);
            displayAddedMessage();
            setState(DISPLAY_MENU);
            break; //agenda_data.h

        case SEARCH_USER:
            askForUser();
            uint8_t *searched_user = getSearchedUser();
            displayUserData(searched_user); //wait press for return
            setState(DISPLAY_MENU);
            break; //agenda_data.h

        case LIST_BY_INITIAL:
            askForInitial();
            uint8_t searched_initial = getSearchedInitial();
            displayDataByInitial(searched_initial);
            setState(DISPLAY_MENU);
            break; //agenda_data.h
        }
    }
    return 0;
}
