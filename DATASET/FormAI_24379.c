//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main()
{
    int MAX_RAM = 1024;
    int current_RAM = 0;
    int i;

    for(i=1; i<=50; i++)
    {
        printf("Iterating...\n");
        srand(time(0));
        int rand_num = rand()%51;
        current_RAM += rand_num;
        printf("Current RAM usage: %dK\n", current_RAM);

        if(current_RAM > MAX_RAM)
        {
            printf("RAM usage exceeds maximum capacity! Shutting down...\n");
            sleep(2);
            exit(0);
        }

        printf("-------------------------\n");
        sleep(1);
    }

    printf("RAM usage within safe limits.\n");
    return 0;
}