//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Cyberpunk
// Welcome to the CyberStock Market Tracker!
// This program provides real-time updates on stock prices from various corporations in the cyberpunk world.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    srand(time(0)); // seed the random number generator

    // initialize stocks
    int num_companies = 5;
    char* companies[] = {"Megacorp", "Neon Industries", "Cyberdine", "Infinitech", "NovaCorp"};
    float prices[] = {100.00, 50.00, 75.00, 125.00, 150.00};

    // initialize variables
    int hour = 1;
    int minute = 0;
    float fluctuation = 0.00;

    // start stock market simulation
    printf("Welcome to the CyberStock Market Tracker!\n");

    while(1)
    {
        // update stock prices
        for(int i = 0; i < num_companies; i++)
        {
            fluctuation = (float)rand() / (float)(RAND_MAX / 5.00);
            if(rand() % 2 == 0)
            {
                prices[i] += fluctuation;
            }
            else
            {
                prices[i] -= fluctuation;
            }
            printf("%s: $%.2f\n", companies[i], prices[i]);
        }
        
        // increment time
        minute += 15;
        if(minute == 60)
        {
            hour++;
            minute = 0;
        }

        // wait for next update
        printf("Next update: %d:%02d\n", hour, minute);
        sleep(3);
        system("clear");
    }

    return 0;
}