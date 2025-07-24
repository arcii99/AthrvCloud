//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/* Function to read the current RAM usage in KB */
float getRAMUsage() {
    char data[50];
    FILE *fp;
    float ramUsage;

    /* Open the system status file */
    fp = fopen("/proc/meminfo", "r");

    /* Read the first line of the file */
    fgets(data, 50, fp);

    /* Extract the RAM usage value */
    sscanf(data, "MemTotal: %f kB", &ramUsage);

    /* Close the file */
    fclose(fp);

    /* Return the usage value */
    return ramUsage;
}

int main() {
    float currentRAM;
    char output[100];

    /* Infinite loop */
    while (1) {
        /* Get the current RAM usage */
        currentRAM = getRAMUsage();

        /* Format the output string */
        sprintf(output, "Current RAM usage: %0.2f KB", currentRAM);

        /* Print the output */
        printf("%s\n", output);

        /* Sleep for one second */
        sleep(1);
    }

    /* Exit program */
    return 0;
}