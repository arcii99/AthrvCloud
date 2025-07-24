//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

void print_process_info(char *pid) {
    FILE *stat, *status;
    char stat_path[256], status_path[256], line[256];
    sprintf(stat_path, "/proc/%s/stat", pid);
    sprintf(status_path, "/proc/%s/status", pid);
    stat = fopen(stat_path, "r");
    status = fopen(status_path, "r");

    if (stat == NULL || status == NULL)
        return;

    // Process name
    fscanf(stat, "%*s %s", line);
    printf("Process name: %s\n", line);

    // Process status
    fscanf(stat, "%s", line);
    printf("Process status: %s\n", line);

    // Process memory usage
    int rss;
    while (fgets(line, 256, status) != NULL) {
        if (sscanf(line, "VmRSS: %d", &rss) == 1) {
            printf("Process memory usage: %d KB\n", rss);
            break;
        }
    }

    fclose(stat);
    fclose(status);
}

int main() {
    printf("Welcome to the Surrealist Process Viewer!\n\n");
    printf("Enter the PID of the process you would like to view:\n");
    char pid[256];
    scanf("%s", pid);

    print_process_info(pid);

    printf("\nThank you for using the Surrealist Process Viewer!\n");

    return 0;
}