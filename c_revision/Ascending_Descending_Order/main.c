#include "hAtv1.h"

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
