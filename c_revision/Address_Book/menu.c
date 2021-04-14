#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

static int menuInput = 0;

void showMenu()
{
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    printf("\tAddress Book Menu\n");
    printf("Please select what would you like to do:\n");
    printf("1 - Add a new entry\n");
    printf("2 - Search for a user and print their info (exact match)\n");
    printf("3 - Search for users based on initial typed (case sensitive)\n");
    printf("4 - End program\n\n");

    printf("Select an option (1-4): ");
    scanf("%d", &menuInput);
    getchar();
    if( (menuInput<1) || (menuInput>4) )
    {
        printf("Please type a valid option\n");
        menuInput = 0;
    }
}

state_t getMenuInput()
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
