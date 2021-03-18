#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ASC_ORDER 0
#define DSC_ORDER 1

#define VECTOR_LEN 5

int INTEGER_VECTOR[VECTOR_LEN];

enum
{
    STATE_USR_INPUT ,
    STATE_ORDER_VALUES ,
    STATE_PRINT_VALUES ,
}StateMachineControl = STATE_USR_INPUT;

void usr_input(int *V)
{
    for(int i=0; i<VECTOR_LEN; i++)
    {
        printf("\r\nDigite o %do valor:", i+1);
        scanf("%d", &V[i]);
    }
}

int order_values(int *V)
{
    int i = 0, j = 0, temp = 0, ORDER = 0;
    char order_c = 'a';

    printf("Ascending or Descending? (a/d):");
    scanf(" %c", &order_c);

    if( (order_c == 'a') || (order_c == 'A') )
        ORDER = ASC_ORDER;
    else if ( (order_c == 'd') || (order_c == 'D') )
        ORDER = DSC_ORDER;
    else
    {
        printf("Error, please type a valid format");
        StateMachineControl = STATE_ORDER_VALUES;
        return 0;
    }
    for(i=1; i<VECTOR_LEN; i++)
    {
        j=i;
        while(j>0)
        {
            if( ((ORDER==ASC_ORDER) && (V[j]<V[j-1])) ||
            ((ORDER==DSC_ORDER) && (V[j]>V[j-1]))    )
            {
                temp=V[j];
                V[j]=V[j-1];
                V[j-1]=temp;
                j--;
            }
            else j=0;
        }
    }
}

void print_values(int *V)
{
    int i = 0;
    for(i=0; i<VECTOR_LEN; i++)
        printf("\t%d",V[i]);
}

int main()
{
    while(1)
    {
        switch(StateMachineControl)
        {
            case STATE_USR_INPUT:
                usr_input(INTEGER_VECTOR);
                StateMachineControl = STATE_ORDER_VALUES;
            break;

            case STATE_ORDER_VALUES:
                StateMachineControl = STATE_PRINT_VALUES; //Declared first in case it's not typed a/d. See order_values()
                order_values(INTEGER_VECTOR);
            break;

            case STATE_PRINT_VALUES:
                print_values(INTEGER_VECTOR);
                StateMachineControl = STATE_USR_INPUT;
            break;
        }
    }
    return 0;
}
