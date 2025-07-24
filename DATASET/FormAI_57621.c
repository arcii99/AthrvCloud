//FormAI DATASET v1.0 Category: Temperature monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temperature = 0;
    int i;

    printf("Temperature monitor started...\n\n");

    for(i = 0; i < 50; i++)
    {
        // Generate random temperature between 20 to 40 degree Celsius
        srand(time(NULL));
        temperature = (float) (rand() % 21 + 20);

        printf("Current Temperature: %.2f\xB0C\n", temperature);

        // Check if temperature exceeds 35 degree Celsius
        if(temperature > 35)
        {
            printf("WARNING: Temperature exceeded 35\xB0C. Cooling system needs to be activated.\n\n");
        }
        else
        {
            printf("\n");
        }

        // Delay for 2 seconds
        sleep(2);
    }

    printf("Temperature monitor stopped.\n");

    return 0;
}