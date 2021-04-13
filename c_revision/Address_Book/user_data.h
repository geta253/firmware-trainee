#ifndef H_USER_DATA_INCLUDED
#define H_USER_DATA_INCLUDED

enum
{
    UNSUCCESSFUL    ,
    SUCCESSFUL      ,
};

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

int allocateUserDataMemory(struct UserData *);

void askForAge(struct UserData *);

void freeAll(struct UserData *);

struct UserData *getNewUserEntry();

#endif // H_USER_DATA_INCLUDED
