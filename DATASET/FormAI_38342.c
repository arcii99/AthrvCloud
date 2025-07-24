//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    int current_temp = rand() % 101;
    printf("           CYBER TEMP MONITOR\n");
    printf("-------------------------------------------\n");
    printf("Current Temperature: %dC\n", current_temp);
    printf("-------------------------------------------\n");
    printf("\n");

    for(int i = 0; i < 10; i++)
    {
        int temp_change = (rand() % 11) - 5;
        current_temp += temp_change;
        if(current_temp < 0)
        {
            current_temp = 0;
        }
        
        printf("Simulating Temp Reading... %dC\n", current_temp);
        printf("\n");

        if(current_temp > 80)
        {
            printf("DANGER: High Temperature Detected!\n");
        }

        if(current_temp <= 0)
        {
            printf("ALERT: Temperature has dropped below 0C!\n");
            break;
        }

        sleep(1);
    }

    printf("Program Terminated: Cyber Temp Monitor Deactivated\n");
    return 0;
}