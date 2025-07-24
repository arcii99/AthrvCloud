//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: visionary
/* The CPU Usage Monitor */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __unix__
#include <unistd.h>
#include <sys/resource.h>
#endif

#define MAX_PROC_NAME_LENGTH 256

int main() {
    char proc_name[MAX_PROC_NAME_LENGTH];

    printf("Enter a process name (e.g. Chrome): ");
    fgets(proc_name, MAX_PROC_NAME_LENGTH, stdin);
    proc_name[strcspn(proc_name, "\n")] = '\0'; // remove trailing newline character

#ifdef __unix__
    pid_t pid = getpid();
    FILE* fp;
    char command[256];
    float cpu_usage, prev_cpu_usage = 0;

    while (1) {
        sprintf(command, "ps -p %d -o %%cpu | tail -n 1", pid);
        fp = popen(command, "r");
        fscanf(fp, "%f", &cpu_usage);
        pclose(fp);

        if (cpu_usage > prev_cpu_usage) {
            printf("%s is using more CPU! (%.2f%%)\n", proc_name, cpu_usage);
        }

        prev_cpu_usage = cpu_usage;
        sleep(1);
    }
#else
    printf("Sorry, this feature is only available on Unix systems.");
#endif

    return 0;
}