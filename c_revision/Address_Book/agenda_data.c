#include "agenda_data.h"
#include <stdlib.h>
#include <stdio.h>

static struct Agenda *agenda = NULL;

void allocateDataMemory(struct UserData *p_entry_data)
{
    p_entry_data->age = malloc(sizeof *(p_entry_data->age));
}

void askForAge(struct UserData *p_entry_data)
{
    printf("Age: ");
    scanf("%d", p_entry_data->age);
}

int askForNewEntry()
{
    struct UserData entry_data;
    allocateDataMemory(&entry_data);
    if(entry_data.age == NULL
       /*||entry_data.name...*/)
        {
            return 0;
        }
    //Change return type to include if(NULL)
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
    askForAge(&entry_data);
    //...
    insertEntry(&agenda, &entry_data);
    return 1;
}

int isAgendaEmpty()
{
    if(agenda == NULL) return 1;
    return 0;
}

void allocateEntry(struct Agenda **p_new_entry)
{
    *p_new_entry = malloc(sizeof **p_new_entry);
}

static int linkEntryToEndOfAgenda(struct Agenda **agenda, struct Agenda *user_entry)
{
    if(isAgendaEmpty(*agenda))
    {
        *agenda = user_entry;
    }
    else
    {
        struct Agenda *current_in_loop = *agenda;
        while(current_in_loop->next_entry != NULL)
        {
            current_in_loop = current_in_loop->next_entry;
        }
        current_in_loop->next_entry = user_entry;
    }
    return 1;
}

int insertEntry(struct Agenda **agenda, struct UserData *user_data)
{
    struct Agenda *new_entry;
    allocateEntry(&new_entry);
    if(new_entry == NULL) return 0;
    new_entry->current_entry = *user_data;
    new_entry->next_entry = NULL;
    linkEntryToEndOfAgenda(agenda, new_entry);
    return 1;
}

void printEntireAgenda()
{
    struct Agenda *current_in_loop = agenda;
    while(current_in_loop != NULL)
    {
        printf("%d\n", *(current_in_loop->current_entry.age));
        current_in_loop = current_in_loop->next_entry;
    }
}

int clearAgenda()
{
    struct Agenda *current_in_loop = agenda;
    struct Agenda *auxiliar = current_in_loop;
    while(current_in_loop != NULL)
    {
        auxiliar = auxiliar->next_entry;
        free(current_in_loop->current_entry.age);
        //...
        free(current_in_loop);
        current_in_loop = auxiliar;
    }
    agenda = NULL;
    return 1;
}
