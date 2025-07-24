//FormAI DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>

int main() {
    printf("The game is afoot! Let's see what processes are running:\n");

    DIR *directory = opendir("/proc");
    struct dirent *dir;

    if (directory) {
        while ((dir = readdir(directory)) != NULL) {
            char path[1024];
            snprintf(path, sizeof(path), "/proc/%s/status", dir->d_name);
            FILE *file = fopen(path, "r");

            if (file) {
                char line[128];
                char *name = NULL;
                while (fgets(line, sizeof(line), file)) {
                    if (strncmp(line, "Name:", 5) == 0) {
                        name = strdup(line + 6);
                        break;
                    }
                }
                fclose(file);

                if (name) {
                    int pid = atoi(dir->d_name);
                    printf("\nThe process '%s' with PID %d is running.", name, pid);
                    free(name);
                }
            }
        }

        closedir(directory);

    } else {
        printf("I'm afraid I cannot access the /proc directory. This case seems unsolvable.");
        return -1;
    }

    printf("\nThis concludes our investigation, Watson.\n");
    return 0;
}