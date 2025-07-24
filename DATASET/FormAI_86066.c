//FormAI DATASET v1.0 Category: System process viewer ; Style: Linus Torvalds
#include <stdio.h>
#include <dirent.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PID 32768
#define MAX_PATH_LENGTH 4096

typedef struct {
    char name[256], state[16];
    int pid, ppid, threads;
} process_info;

process_info *processes;

void read_processes() {
    DIR *dir;
    struct dirent *entry;

    dir = opendir("/proc");
    if (!dir) {
        perror("opendir");
        return;
    }

    processes = calloc(MAX_PID, sizeof(process_info));
    int count = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (!isdigit(entry->d_name[0])) {
            continue;
        }

        char path[MAX_PATH_LENGTH];
        snprintf(path, MAX_PATH_LENGTH, "/proc/%s/stat", entry->d_name);

        FILE *file = fopen(path, "r");
        if (!file) {
            continue;
        }

        process_info info;
        fscanf(file, "%d (%[^)]) %s %d %*d %*d %*d %*d %*u %*lu %*lu %*lu %*lu %*lu %*ld %*ld %*ld %*ld %*ld %*ld %*llu %*lu %*ld %d", &info.pid, info.name, info.state, &info.ppid, &info.threads);
        fclose(file);

        strcpy(processes[count].name, info.name);
        strcpy(processes[count].state, info.state);
        processes[count].pid = info.pid;
        processes[count].ppid = info.ppid;
        processes[count].threads = info.threads;

        count++;
    }

    closedir(dir);
}

void print_processes() {
    printf("PID\tPPID\tSTATE\tTHREADS\tNAME\n");
    for (int i = 0; i < MAX_PID; i++) {
        if (processes[i].pid == 0) {
            continue;
        }

        printf("%d\t%d\t%s\t%d\t%s\n", processes[i].pid, processes[i].ppid, processes[i].state, processes[i].threads, processes[i].name);
    }
}

int main() {
    read_processes();
    print_processes();
    free(processes);
    return 0;
}