//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = getpid(); // get current process ID
    char command[50];
    sprintf(command, "cat /proc/%d/status | grep VmSize", pid); // assemble command to get process virtual memory size
    FILE* fp = popen(command, "r"); // open pipe and execute command

    char output[64];
    if (fgets(output, sizeof(output), fp) != NULL) { // read output from command
        printf("Virtual Memory Used: %s", output);
    } else {
        printf("Error getting virtual memory usage.\n");
        exit(1);
    }

    pclose(fp); // close pipe

    return 0;
}