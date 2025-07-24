//FormAI DATASET v1.0 Category: System process viewer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

int main() {
    DIR* proc = opendir("/proc");
    struct dirent* ent;
    int pid;
    int ppid;
    int pgrp;
    char state;
    char cmd[20];

    printf("Enter a process ID to see its information: ");
    scanf("%d", &pid);

    while ((ent = readdir(proc)) != NULL) {
        if (isdigit(ent->d_name[0])) {
            int curr_pid = atoi(ent->d_name);
            if (curr_pid == pid) {
                char filename[100];
                sprintf(filename, "/proc/%d/stat", pid);
                FILE* stat = fopen(filename, "r");
                fscanf(stat, "%d %s %c %d", &pid, cmd, &state, &ppid);
                printf("Process %d (%s) is in state %c and has parent process %d.\n",
                       pid, cmd, state, ppid);
                break;
            }
        }
    }
    closedir(proc);
    return 0;
}