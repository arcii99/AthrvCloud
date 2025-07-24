//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define BUFFER_SIZE 1024

int main() {
    pid_t pid = getpid();
    char pid_str[10];
    sprintf(pid_str, "%d", pid);
    char file_path[BUFFER_SIZE] = "/proc/";
    strcat(file_path, pid_str);
    strcat(file_path, "/stat");
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: Failed to open the file.\n");
        exit(1);
    }
    char buffer[BUFFER_SIZE];
    fgets(buffer, BUFFER_SIZE, file);
    fclose(file);
    char* token = strtok(buffer, " ");
    int count = 0;
    while (token != NULL) {
        count++;
        if (count == 14) {
            double cpu_usage = atof(token) / (double)sysconf(_SC_CLK_TCK);
            printf("CPU Usage: %f%%\n", cpu_usage * 100);
            break;
        }
        token = strtok(NULL, " ");
    }
    return 0;
}