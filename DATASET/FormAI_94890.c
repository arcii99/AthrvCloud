//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int i;
    printf("Real-time C RAM Usage Monitor starting...\n");

    while(1) {
        int pid = getpid(); // get the current process ID
        char command[50];
        sprintf(command, "pmap %d | tail -n1", pid); // create the command to get RAM usage
        char buffer[100];
        FILE* pipe = popen(command, "r"); // open the command pipeline
        fgets(buffer, 100, pipe); // read the output from the pipeline
        pclose(pipe); // close the pipeline

        char* ram_usage = strtok(buffer, " "); // get the first token which is RAM usage in KB
        ram_usage = strtok(NULL, " "); // get the second token which is RAM usage in MB
        printf("RAM usage: %s MB\n", ram_usage);

        for(i=0; i<5; i++) {
            printf("=");
        }
        printf("\n");

        sleep(3); // sleep for 3 seconds
    }
    return 0;
}