//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main()
{
    int pid;
    int count = 0;
    DIR *proc;
    struct dirent *entry;

    printf("\nWelcome to the surrealist process viewer\n");
    printf("=========================================\n\n");

    printf("The processes in the system are as follows:\n\n");

    proc = opendir("/proc");
    if (proc == NULL) {
        printf("Could not open /proc directory\n");
        exit(1);
    }

    while ((entry = readdir(proc))) {
        if (entry->d_type == DT_DIR) {
            pid = atoi(entry->d_name);
            if (pid != 0) {
                printf("Process %d is running... or is it?\n", pid);
                count++;
            }
        }
    }
    closedir(proc);

    printf("\nWow! There are %d processes running on this bizarre system!\n", count);

    printf("\n\n\"To be or not to be\" that is the process...\n\n");

    return 0;
}