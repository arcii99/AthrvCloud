//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>

int main() {
    struct sysinfo info;
    unsigned int load_factor;
    char cmd[50];
    FILE *pipe;

    while (1) {
        sysinfo(&info);
        load_factor = info.loads[0] / (double)(1 << SI_LOAD_SHIFT);

        sprintf(cmd, "ps -p %d -o %%cpu,args", getpid());

        pipe = popen(cmd, "r");
        if (pipe == NULL) {
            perror("popen failed");
            exit(EXIT_FAILURE);
        }

        char output[100];
        fgets(output, sizeof(output), pipe);
        pclose(pipe);

        printf("\033[H\033[J");    // Clear screen
        printf("CPU Usage: %d%%\n", (int)load_factor);
        printf("%s\n", output);

        usleep(10000);    // Sleep for 10 milliseconds
    }

    return EXIT_SUCCESS;
}