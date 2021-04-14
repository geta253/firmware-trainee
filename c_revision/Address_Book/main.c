#include "states.h"
#include "act2_states.h"
#include "agenda.h"
#include "menu.h"
#include "user_public_functions.h"
#include "user_data.h"
#include <stdio.h>

/*
STATES:
    DISPLAY_MENU    ,
    INSERT_USER     ,
    SEARCH_USER     ,
    LIST_BY_INITIAL ,
    END             ,
*/

int main()
{
    Agenda *agenda = newAgenda();
    while(getState() != END)
    {
        switch(getState())
        {
        case DISPLAY_MENU:
            showMenu();
            setState(getMenuInput());
            break;

        case INSERT_USER:
            setUserEntryInAgenda(getNewUserEntry(), &agenda);
            setState(DISPLAY_MENU);
            break;

        case SEARCH_USER:
            displayUserByName(getSearchedUser(), agenda);
            setState(DISPLAY_MENU);
            break;

        case LIST_BY_INITIAL:
            displayUserByInitial(getSearchedInitial(), agenda);
            setState(DISPLAY_MENU);
            break;

        case END:
            break;
        }
    }
    return 0;
}
