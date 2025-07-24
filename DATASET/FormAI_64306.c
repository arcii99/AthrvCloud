//FormAI DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //Initial values for the stock market indices
    int dow_index = 34000;
    int nasdaq_index = 14000;
    int s_p_index = 4200;

    //Random number generator seed
    srand(time(0));

    //Display initial values of the indices
    printf("Welcome to the cheerful stock market tracker!\n\n");
    printf("Dow Jones Industrial Average: %d\n", dow_index);
    printf("NASDAQ Composite Index: %d\n", nasdaq_index);
    printf("S&P 500 Index: %d\n\n", s_p_index);

    //Main loop of the program, runs for 50 iterations
    for(int i = 1; i <= 50; i++)
    {
        //Generate random percentage change of the indices
        int dow_percent_change = (rand() % 5) - 2;
        int nasdaq_percent_change = (rand() % 5) - 2;
        int s_p_percent_change = (rand() % 5) - 2;

        //Calculate actual point change based on percentage change
        int dow_change = dow_index * dow_percent_change / 100;
        int nasdaq_change = nasdaq_index * nasdaq_percent_change / 100;
        int s_p_change = s_p_index * s_p_percent_change / 100;

        //Update indices values
        dow_index += dow_change;
        nasdaq_index += nasdaq_change;
        s_p_index += s_p_change;

        //Print new indices values
        printf("Day %d:\n", i);
        printf("Dow Jones Industrial Average: %d (%d%%)\n", dow_index, dow_percent_change);
        printf("NASDAQ Composite Index: %d (%d%%)\n", nasdaq_index, nasdaq_percent_change);
        printf("S&P 500 Index: %d (%d%%)\n\n", s_p_index, s_p_percent_change);
    }

    printf("Thank you for using the cheerful stock market tracker! Have a great day!\n");

    return 0;
}