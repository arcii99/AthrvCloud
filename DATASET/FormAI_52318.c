//FormAI DATASET v1.0 Category: System boot optimizer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void printHeader()
{
    printf("\n-----------------------------\n");
    printf(" C System Boot Optimizer\n");
    printf("-----------------------------\n");
}

void printProgress(int percentage)
{
    printf("[ ");
    for(int i=0; i<percentage/2; i++)
    {
        printf("=");
    }
    printf("> ");
    for(int i=percentage/2; i<50; i++)
    {
        printf(" ");
    }
    printf("] %d%%\r", percentage);
    fflush(stdout);
}

int main()
{
    printHeader();
    printf("Starting boot optimization...\n");

    int numOptimizations = 8;
    for(int i=0; i<numOptimizations; i++)
    {
        printf("Optimization %d: ", i+1);
        srand(time(NULL));
        int randomTime = rand() % 5 + 1;
        for(int j=0; j<10; j++)
        {
            printProgress((j+1)*10);
            sleep(randomTime);
        }
        printf("\nOptimization %d complete.\n", i+1);
    }

    printf("\nBoot optimization complete.\n");

    return 0;
}