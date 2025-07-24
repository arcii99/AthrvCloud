//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int ram_usage;
    char command[50];
    FILE *fp;

    while(1) {
        /* Run command to get RAM usage */
        sprintf(command, "ps -p %d -o %%mem | awk 'NR == 2 {print $1}'", getpid());
        fp = popen(command, "r");

        if (fp == NULL) {
            printf("Error running command\n");
            return 1;
        }

        /* Read command output and convert to integer */
        char output[10];
        fgets(output, sizeof(output), fp);
        ram_usage = atoi(output);

        /* Print RAM usage */
        printf("Current RAM usage: %d%%\n", ram_usage);

        /* Close command output */
        pclose(fp);

        /* Wait for 1 second */
        sleep(1);
    }

    return 0;
}