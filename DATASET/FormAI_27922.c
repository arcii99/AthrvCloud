//FormAI DATASET v1.0 Category: System process viewer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Struct to hold process information
typedef struct {
    char name[256];
    pid_t pid;
    long rss;
    long vms;
} ProcessInfo;

// Function to extract information about a process from its stats file
void getProcessInfo(ProcessInfo *info, pid_t pid) {
    char filename[256];
    sprintf(filename, "/proc/%d/stat", pid);

    FILE *file = fopen(filename, "r");
    if (!file) {
        return;
    }

    fscanf(file, "%d %s %*c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %ld %ld", &info->pid, info->name, &info->rss, &info->vms);

    // Convert vms to kilobytes
    info->vms /= 1024;

    fclose(file);
}

int main() {
    DIR *dir = opendir("/proc");
    if (!dir) {
        printf("Could not open /proc directory\n");
        return 1;
    }

    // Print header
    printf("%-10s %-20s %-10s %-10s\n", "PID", "NAME", "MEMORY", "VIRTUAL");
    printf("---------------------------------------------------------\n");

    // Walk through the /proc directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        pid_t pid = atoi(entry->d_name);

        if (!pid) {
            continue;
        }

        // Get process information
        ProcessInfo info;
        getProcessInfo(&info, pid);

        // Print process information
        printf("%-10d %-20s %-10ld %-10ld\n", info.pid, info.name, info.rss, info.vms);
    }

    closedir(dir);

    return 0;
}