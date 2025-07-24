//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define BUFFER_SIZE 256

int main() {
    struct sysinfo sys_info;
    char buffer[BUFFER_SIZE];
    FILE* fp;
    char* command = "grep -m1 'MemTotal' /proc/meminfo | awk '{print $2}'";
    double total_memory, current_usage;
    double percentage;

    while (1) {
        if (sysinfo(&sys_info) != 0) {
            printf("Error getting system info.\n");
            exit(1);
        }

        total_memory = atof(command);
        fp = popen("free | grep Mem | awk '{print $3/$2 * 100.0}'", "r");
        fgets(buffer, BUFFER_SIZE, fp);
        current_usage = atof(buffer);
        pclose(fp);

        percentage = current_usage / total_memory * 100;

        printf("Current RAM usage: %.2f/%.2f GB (%.2f%%)\n", 
                current_usage / 1000, total_memory / 1000, percentage);

        sleep(1);
    }

    return 0;
}