#include "agenda_data.h"
#include <stdlib.h>
#include <stdio.h>

int isAgendaEmpty(struct Agenda *user_agenda)
{
    if(user_agenda == NULL) return 1;
    return 0;
}

static struct Agenda *allocateEntry()
{
    struct Agenda *new_entry = malloc(sizeof *new_entry);
    return new_entry;
};

static int linkEntryToEndOfAgenda(struct Agenda **user_agenda, struct Agenda *user_entry)
{
    if(isAgendaEmpty(*user_agenda))
    {
        *user_agenda = user_entry;
    }
    else
    {
        struct Agenda *current_in_loop = *user_agenda;
        while(current_in_loop->next_entry != NULL)
        {
            current_in_loop = current_in_loop->next_entry;
        }
        current_in_loop->next_entry = user_entry;
    }
    return 1;
}

int insertEntry(struct Agenda **user_agenda, struct UserData *d)
{
    struct Agenda *new_entry;
    new_entry = allocateEntry();
    if(new_entry == NULL) return 0;
    new_entry->current_entry = *d;
    new_entry->next_entry = NULL;
    linkEntryToEndOfAgenda(user_agenda, new_entry);
    return 1;
}

void printEntireAgenda(struct Agenda *user_agenda)
{
    struct Agenda *current_in_loop = user_agenda;
    while(current_in_loop != NULL)
    {
        printf("%d\n", *(current_in_loop->current_entry.age));
        current_in_loop = current_in_loop->next_entry;
    }
}

int clearAgenda(struct Agenda **user_agenda)
{
    struct Agenda *current_in_loop = *user_agenda;
    struct Agenda *auxiliar = current_in_loop;
    while(current_in_loop != NULL)
    {
        auxiliar = auxiliar->next_entry;
        free(current_in_loop);
        current_in_loop = auxiliar;
    }
    *user_agenda = NULL;
    return 1;
}
