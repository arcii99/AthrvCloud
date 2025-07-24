//FormAI DATASET v1.0 Category: System boot optimizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the C System Boot Optimizer!\n");

    printf("Optimizing boot sequence...\n");
    srand(time(NULL)); //initialize random seed

    //generate random numbers to simulate optimization process
    for(int i=1; i<=10; i++)
    {
        int rand_num = rand() % 100 + 1; //random number between 1 and 100
        printf("Phase %d: Optimizing boot sequence by %d percent...\n", i, rand_num);
    }

    printf("Optimization complete!\n");
    printf("Press any key to continue booting...\n");

    getchar(); //wait for user input

    printf("Booting up...\n");
    printf("Please wait while system loads...\n");

    //simulate loading process
    for(int j=1; j<=5; j++)
    {
        printf("Loading... ");
        for(int k=1; k<=3; k++)
        {
            printf(".");
            fflush(stdout); //flush output to display dots immediately
            sleep(1); //wait for one second
        }
        printf("\n");
    }

    printf("System is now ready to use!\n");

    return 0;
}