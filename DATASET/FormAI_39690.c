//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

#define MAX_BUF_SIZE 1024

int main() {
    struct rusage usage;
    const char* separator = "----------------";
    int counter = 0;

    while (1) {
        if (getrusage(RUSAGE_SELF, &usage) != 0) {
            fprintf(stderr, "Error getting resource usage\n");
            exit(1);
        }

        printf("%s\n", separator);
        printf("CPU usage: %ld.%06ld sec\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
        printf("%s\n", separator);

        if (++counter % 10 == 0) {
            printf("%s\n", separator);
            printf("Memory usage:\n");
            printf("%s\n", separator);

            char buffer[MAX_BUF_SIZE];
            FILE* command_output = NULL;

            snprintf(buffer, MAX_BUF_SIZE, "ps -p %d -o pid,rss | grep -v PID | awk '{print $2}'", getpid());

            if ((command_output = popen(buffer, "r")) == NULL) {
                fprintf(stderr, "Error running command: %s\n", buffer);
                exit(1);
            }

            fgets(buffer, sizeof(buffer), command_output);

            if (pclose(command_output) == -1) {
                fprintf(stderr, "Error closing pipe\n");
                exit(1);
            }

            printf("RSS: %ld KB\n", strtol(buffer, NULL, 10));
        }

        usleep(100000);
    }

    return 0;
}