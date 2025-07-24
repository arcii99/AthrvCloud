//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

/* This is a random C Intrusion Detection System Example Program */

int main()
{
    /* Initialize variables */
    char buffer[MAX_BUFFER_SIZE];
    char possible_intrusion[] = "rm -rf /";
    char possible_intrusion2[] = "sudo rm -rf /";
    int count_intrusions = 0;
    int i;
    srand(time(NULL));

    /* Main loop */
    while(1)
    {
        fgets(buffer, MAX_BUFFER_SIZE, stdin);

        if (strstr(buffer, possible_intrusion) != NULL || strstr(buffer, possible_intrusion2) != NULL)
        {
            printf("INTRUSION DETECTED!\n");
            count_intrusions++;

            /* Take action against the intrusion */
            printf("Initiating firewall protocols...\n");
            printf("Taking down the network...\n");
            printf("Identifying source of intrusion...\n");

            for (i = 0; i < 5; i++)
            {
                int random_num = rand() % 10;
                printf("Searching for trace remnants...%d%% complete\n", random_num*10);
            }

            printf("Trace remnants found. Initiating countermeasures...\n");
            printf("Countermeasures successful. Network secure.\n");
        }

        /* Check if maximum number of intrusions reached */
        if (count_intrusions >= 5)
        {
            printf("MAXIMUM NUMBER OF INTRUSIONS REACHED. SHUTTING DOWN SYSTEM.\n");
            exit(0);
        }
    }

    return 0;
}