//FormAI DATASET v1.0 Category: System process viewer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    DIR* directory = opendir("/proc"); // Open the /proc directory
    struct dirent* entry = readdir(directory);

    // Iterate over all items in the /proc directory
    while (entry != NULL) {
        int pid = atoi(entry->d_name); // Convert the name to an integer

        // Check if the name is a number and the directory actually exists
        if (pid > 0) {
            char path[50];
            sprintf(path, "/proc/%d/cmdline", pid);

            FILE* cmdfile = fopen(path, "r");
            char name[100];
            fgets(name, sizeof(name), cmdfile);

            // Check if the name is not empty
            if (strlen(name) > 0) {
                printf("Process ID: %d\nName: %s", pid, name);
            }

            fclose(cmdfile);
        }

        entry = readdir(directory);
    }

    closedir(directory);

    return 0;
}