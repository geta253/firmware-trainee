#include "hAtv1.h"
#include <stdio.h>
#include <stdint.h>

#define ASC_ORDER 0
#define DSC_ORDER 1

int INTEGER_VECTOR[VECTOR_LEN];

enum STATE StateMachineControl = STATE_USR_INPUT;

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
    int ORDER;
    if( !ask_order(&ORDER) ) return 0;

    for(int i=1; i<VECTOR_LEN; i++)
    {
        int j=i;
        while(j>0)
        {
            if( ((ORDER==ASC_ORDER) && (V[j]<V[j-1])) ||
            ((ORDER==DSC_ORDER) && (V[j]>V[j-1]))    )
            {
                int temp=V[j];
                V[j]=V[j-1];
                V[j-1]=temp;
                j--;
            }
            else j=0;
        }
    }
    return 1;
}

int ask_order(int* p_ORDER)
{
    char order_c = 'a';
    printf("\nAscending or Descending? (a/d):");
    scanf(" %c", &order_c);

    if( (order_c == 'a') || (order_c == 'A') )
        *p_ORDER = ASC_ORDER;
    else if ( (order_c == 'd') || (order_c == 'D') )
        *p_ORDER = DSC_ORDER;
    else
    {
        printf("\nError, please type a valid format");
        StateMachineControl = STATE_ORDER_VALUES;
        return 0;
    }
    return 1;
}

void print_values(int *V)
{
    int i = 0;
    for(i=0; i<VECTOR_LEN; i++)
        printf("\t%d",V[i]);
}

