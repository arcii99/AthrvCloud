//FormAI DATASET v1.0 Category: Temperature monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int temperature = 0;
    srand(time(NULL));

    printf("Welcome to the Temperature Monitor!\n\n");

    while(1)
    {
        // generate a random temperature within a range of -20 to 50 degrees Celsius
        temperature = (rand() % (50 - (-20) + 1)) + (-20);
        printf("Current temperature: %d degrees Celsius\n", temperature);

        if(temperature >= 30)
        {
            printf("Warning: High temperature! Take necessary actions.\n\n");
        }
        else if(temperature <= 0)
        {
            printf("Warning: Low temperature! Take necessary actions.\n\n");
        }
        else
        {
            printf("Temperature is within the safe range.\n\n");
        }

        // wait for 10 seconds before checking the temperature again
        sleep(10);
    }

    return 0;
}