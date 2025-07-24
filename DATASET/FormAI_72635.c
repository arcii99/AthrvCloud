//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 256

int main() {
    char cmd[MAX_LENGTH], output[MAX_LENGTH];
    FILE* fp;
    float usage;

    while (1) {
        // run free command to get current RAM usage information
        strcpy(cmd, "free | grep Mem | awk '{printf(\"%.2f\", $3/$2 * 100.0)}'");
        
        fp = popen(cmd, "r");

        if (fp == NULL) {
            printf("Error: Unable to run command.\n");
            exit(1);
        }

        // read output from free command
        fgets(output, MAX_LENGTH, fp);

        // parse float value from output
        usage = atof(output);

        // close popen stream
        pclose(fp);

        printf("Current RAM usage: %.2f%%\n", usage);

        // sleep for one second before checking again
        sleep(1);
    }

    return 0;
}