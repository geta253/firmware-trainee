#ifndef ATV1_BASE_H
#define ATV1_BASE_H

#define VECTOR_LEN 5

extern int INTEGER_VECTOR[VECTOR_LEN];

enum STATE
{
    STATE_USR_INPUT ,
    STATE_ORDER_VALUES ,
    STATE_PRINT_VALUES ,
};

extern enum STATE StateMachineControl;

extern void usr_input(int*);

extern int ask_order(int*);

extern int order_values(int*);

extern void print_values(int*);

#endif // ATV1_BASE_H
