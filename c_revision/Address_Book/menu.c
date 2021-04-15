#include "menu.h"
#include "user_io.h"

static int menuInput = 0;

void showMenu()
{
    clearScreen();
    printMenuOptions();
    menuInput = getInputedMenuOption();
    if( (menuInput<1) || (menuInput>4) )
    {
        showInvalidOptionMessage();
        menuInput = 0;
    }
}

State getMenuInput()
{
    switch(menuInput)
    {
    case 1:  return INSERT_USER;
    case 2:  return SEARCH_USER;
    case 3:  return LIST_BY_INITIAL;
    case 4:  return END;
    default: return DISPLAY_MENU;
    }
}
