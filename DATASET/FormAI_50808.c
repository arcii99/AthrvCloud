//FormAI DATASET v1.0 Category: Traffic Light Controller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define RED      0
#define YELLOW   1
#define GREEN    2

#define NS_ROADWAY RED
#define EW_ROADWAY GREEN

bool isEmergencyVehicleComing = false;

void signal_controller(int *ns_signal, int *ew_signal)
{
    static int ns_state = GREEN;
    static int ew_state =  RED;
  
    if(isEmergencyVehicleComing)
    {
        ns_state = YELLOW;
        ew_state = YELLOW;
    }
    else
    {   
        if (ns_state == GREEN)
        {
            ns_state = YELLOW;
            ew_state = GREEN;
        }
        else if (ns_state == YELLOW)
        {
            ns_state = RED;
            ew_state = GREEN;
        }
        else if (ns_state == RED)
        {
            ns_state = GREEN;
            ew_state = RED;
        }
    }
  
    *ns_signal = ns_state;
    *ew_signal = ew_state;
}
 
int main()
{
    int ns_signal, ew_signal;
 
    // Normal traffic flow
    while(1)
    {
        signal_controller(&ns_signal, &ew_signal);
        printf("NS Signal: %d, EW Signal: %d\n", ns_signal, ew_signal);
        sleep(5);
    }
 
    // Emergency Vehicle
    isEmergencyVehicleComing = true;
    signal_controller(&ns_signal, &ew_signal);
    printf("NS Signal: %d, EW Signal: %d\n", ns_signal, ew_signal);
    sleep(10);

    //Continue with normal traffic flow
    isEmergencyVehicleComing = false;
    while(1)
    {
        signal_controller(&ns_signal, &ew_signal);
        printf("NS Signal: %d, EW Signal: %d\n", ns_signal, ew_signal);
        sleep(5);
    }
 
    return 0;
}