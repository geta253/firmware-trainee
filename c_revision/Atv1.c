#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define ASC_ORDER 0
#define DSC_ORDER 1

int main()
{
    int VECTOR_LEN = 5;
    int V[VECTOR_LEN];
    int i = 0;
    int x = 0;
    int ORDER = DSC_ORDER;
    static enum
    {
        STATE_USR_INPUT ,
        STATE_ORDER_VALUES ,
        STATE_PRINT_VALUES ,
    }StateMachineControl = STATE_USR_INPUT;

    while(1)
    {
        switch(StateMachineControl)
        {
            case STATE_USR_INPUT:
                printf("\r\nDigite o tamanho do vetor:");
                scanf("%d", &VECTOR_LEN);
                for(i=0; i<VECTOR_LEN; i++)
                {
                    printf("\r\nDigite o %do valor:", i+1);
                    scanf("%d", &V[i]);
                }
                StateMachineControl = STATE_ORDER_VALUES;
            break;

            case STATE_ORDER_VALUES:
                for(i=1; i<VECTOR_LEN; i++)
                {
                    int j=i;
                    while(j>0)
                    {
                        if( ((ORDER=ASC_ORDER) && (V[j]<V[j-1])) ||
                            ((ORDER=DSC_ORDER) && (V[j]>V[j-1]))    )
                        {
                            x=V[j];
                            V[j]=V[j-1];
                            V[j-1]=x;
                            j--;
                        }
                        else j=0;
                    }
                }
            StateMachineControl = STATE_PRINT_VALUES;
            break;

            case STATE_PRINT_VALUES:
                for(i=0; i<VECTOR_LEN; i++)
                    printf("\t%d",V[i]);
                StateMachineControl = STATE_USR_INPUT;
            break;
        }
    }
    return 0;
}
