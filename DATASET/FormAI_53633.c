//FormAI DATASET v1.0 Category: Temperature monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMPERATURE 50
#define MIN_TEMPERATURE 0
#define TARGET_TEMPERATURE 25

int main()
{
    srand(time(0));
    
    int current_temperature = (rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1)) + MIN_TEMPERATURE;
    
    printf("Current temperature is: %d\n", current_temperature);

    if (current_temperature == TARGET_TEMPERATURE)
    {
        printf("The temperature is at the target value of %d degrees Celsius\n", TARGET_TEMPERATURE);
    }
    else if (current_temperature > TARGET_TEMPERATURE)
    {
        printf("The temperature is too hot!\n");
    }
    else
    {
        printf("The temperature is too cold!\n");
    }

    for (int i = 0; i < 10; i++)
    {
        int temp_change = (rand() % 5) + 1;

        if (i % 2 == 0)
        {
            current_temperature += temp_change;
        }
        else
        {
            current_temperature -= temp_change;
        }

        printf("Temperature after change %d is %d\n", i+1, current_temperature);

        if (current_temperature == TARGET_TEMPERATURE)
        {
            printf("The temperature is at the target value of %d degrees Celsius\n", TARGET_TEMPERATURE);
            break;
        }
        else if (current_temperature > TARGET_TEMPERATURE)
        {
            printf("The temperature is too hot!\n");
        }
        else
        {
            printf("The temperature is too cold!\n");
        }
    }

    return 0;
}