#ifndef H_USER_DATA_INCLUDED
#define H_USER_DATA_INCLUDED

#define MAX_LENGTH 50

struct UserData
{
    int *age;
    char *name;
    /*
    uint8_t *address;
    uint8_t *phone;
    uint64_t *CEP;
    */
};

int allocateUserDataMemory(struct UserData *);

void askForAge(struct UserData *);

void freeAll(struct UserData *);

struct UserData *getNewUserEntry();

char *getSearchedUser();

void displayUserByName(char *);

char getSearchedInitial();

void displayUserByInitial(char);

void printEntireAgenda();

int clearAgenda();

#endif // H_USER_DATA_INCLUDED
