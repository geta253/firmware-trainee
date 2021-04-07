#ifndef H_AGENDA_DATA_INCLUDED
#define H_AGENDA_DATA_INCLUDED

#include <stdint.h>


struct UserData
{
    int *age;
    /*
    uint8_t *name;
    uint8_t *address;
    uint8_t *phone;
    uint64_t *CEP;
    */
};

struct Agenda
{
    struct UserData current_entry;
    struct Agenda *next_entry;
};

int isAgendaEmpty(struct Agenda *);

int insertEntry(struct Agenda **, struct UserData *);

void printEntireAgenda(struct Agenda *);
int clearAgenda(struct Agenda **);

int getSearchedUser();
uint8_t getSearchedInitial();
void askForNewEntry();
struct UserData *getNewEntry();

#endif // H_AGENDA_DATA_INCLUDED
