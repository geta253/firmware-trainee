#ifndef H_USER_DATA_INCLUDED
#define H_USER_DATA_INCLUDED

#include <stdint.h>

typedef struct UserData
{
    uint8_t *name;
    uint8_t *address;
    uint8_t *phone;
    uint64_t *CEP;
}UserData;

#endif // H_USER_DATA_INCLUDED
