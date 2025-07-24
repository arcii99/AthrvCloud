//FormAI DATASET v1.0 Category: Error handling ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize random seed
    srand(time(0));
    
    // Generate random integer between 0 and 4
    int error_code = rand() % 5;
    
    // Execute corresponding error scenario
    switch(error_code)
    {
        case 0:
            printf("Error: Power grid failure. Please wait for restoration.\n");
            system("shutdown -h now");
            break;
        case 1:
            printf("Error: Oxygen levels critically low. Close all airlocks and activate emergency generators.\n");
            system("activate_airlock_1");
            system("activate_airlock_2");
            system("activate_emergency_generators");
            break;
        case 2:
            printf("Error: Communication with outside world lost. Attempting to reconnect.\n");
            system("reboot_comms");
            break;
        case 3:
            printf("Error: Food synthesizer malfunction. Please wait for repairs.\n");
            system("activate_emergency_rations");
            break;
        case 4:
            printf("Error: Radiation levels dangerously high. Seek immediate shelter.\n");
            system("activate_shielding");
            system("alert_emergency_response_team");
            break;
        default:
            printf("Error: Unknown error. Please contact system administrator.\n");
            exit(1);
    }
    
    return 0;
}