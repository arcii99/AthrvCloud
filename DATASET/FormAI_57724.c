//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    printf("Surprise! You stumbled upon a unique CPU usage monitor program.\n");
    printf("This program will monitor the CPU usage of the current process every one second.\n");

    time_t current_time;
    char* c_time_string;

    for(int i = 0; i < 50; i++) {
        float cpu_percent;
        int pid = getpid();
        char cmd[50];
        sprintf(cmd, "ps -p %d -o %%cpu | tail -1", pid);
        FILE* cmd_result = popen(cmd, "r");
        fscanf(cmd_result, "%f", &cpu_percent);
        pclose(cmd_result);

        // Get the current time
        current_time = time(NULL);

        // Convert the current time to a string
        c_time_string = ctime(&current_time);

        printf("CPU Usage: %.2f%% at %s", cpu_percent, c_time_string);

        sleep(1);
    }

    printf("CPU monitoring finished. Goodbye!\n");

    return 0;
}