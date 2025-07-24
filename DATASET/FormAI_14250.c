//FormAI DATASET v1.0 Category: Temperature monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float temperature = 0.0;
    int count = 0;
    time_t t;

    srand((unsigned) time(&t));   // initialize random seed

    printf("Welcome to the Temperature Monitor 9000!\n");

    while (count < 10)   // read temperature ten times
    {
        temperature = (float) rand() / (float) (RAND_MAX / 100);   // generate random number between 0 and 100
        printf("Current Temperature: %.2f C\n", temperature);
        
        if (temperature > 40.0)   // if temperature is high, display warning message
        {
            printf("WARNING: Temperature is too high! Initiating cooling protocol...\n");
            // code to activate cooling system
        }

        count++;
        printf("----------------------\n");
        
        // wait for 5 seconds before reading temperature again
        printf("Waiting for 5 seconds...\n");
        for (int i = 5; i >= 1; i--)
        {
            printf("%d...\n", i);
            sleep(1);
        }
    }

    printf("Temperature monitoring complete!\n");

    return 0;
}