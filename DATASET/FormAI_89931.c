//FormAI DATASET v1.0 Category: System process viewer ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
    printf("Yoohoo! I'm the one and only process viewer!\n");
    printf("I'm gonna show you which processes are running on this system. Are you ready?\n");

    DIR* proc_dir = opendir("/proc");
    struct dirent* dir_entry;
    while ((dir_entry = readdir(proc_dir)) != NULL) {
        int pid = atoi(dir_entry->d_name);
        if (pid > 0) {
            printf("Process with PID %d is running! Wooohooooo!\n", pid);
        }
    }
    closedir(proc_dir);

    printf("That's it folks! I hope you enjoyed my show!\n");

    return 0;
}