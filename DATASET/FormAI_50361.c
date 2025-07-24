//FormAI DATASET v1.0 Category: System process viewer ; Style: surprised
#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *dir;
    struct dirent *dp;
    char path[1024] = "/proc/";
    char cmdline[1024], buffer[1024], state;

    printf("Welcome to the Process Viewer! Here are the details of the currently running processes:\n\n");
    
    dir = opendir("/proc/");
    if (!dir) {
        printf("Oops! There seems to be an issue with the /proc/ directory. Please try again later.\n");
        return 1;
    }

    while ((dp = readdir(dir)) != NULL) {
        if (atoi(dp->d_name)) {
            strcat(path, dp->d_name);
            strcat(path, "/status");

            FILE *fp = fopen(path, "r");
            if (fp != NULL) {
                while(fgets(buffer, 1024, fp)) {
                    if (strncmp(buffer, "Name:", 5) == 0) {
                        printf("Name:\t%s", buffer+6);
                    } else if (strncmp(buffer, "State:", 6) == 0) {
                        printf("State:\t%c", buffer[7]);
                    } else if (strncmp(buffer, "Pid:", 4) == 0) {
                        printf("Pid:\t%s", buffer+5);
                    }
                }
                fclose(fp);
            }
            strcpy(path, "/proc/");
        }
    }

    printf("\n\nThat's all for now! Thank you for using the Process Viewer.\n");

    closedir(dir);
    return 0;
}