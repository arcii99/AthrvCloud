//FormAI DATASET v1.0 Category: System process viewer ; Style: unmistakable
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PID 99999   
#define BUFFER_SIZE 1024   // Maximum size of buffer for storing process name

int main(int argc, char **argv) {
    DIR *d;
    struct dirent *dir;
    char filename[BUFFER_SIZE], line[BUFFER_SIZE], name[BUFFER_SIZE];
    pid_t pid;
    int is_process;
    FILE *fp;
 
    printf("System Process Viewer\n");

    // Iterate over all possible PID values
    for (pid = 1; pid < MAX_PID; pid++) {
        // Check if directory /proc/pid exits
        sprintf(filename, "/proc/%d", pid);
        d = opendir(filename);
        if (!d) {
            continue;
        }

        // Check if the directory contains a file named "status"
        sprintf(filename, "/proc/%d/status", pid);
        fp = fopen(filename, "r");
        if (fp) {
            // Check if the file contains "Name:" string and extract the process name
            while (fgets(line, BUFFER_SIZE, fp)) {
                if (strstr(line, "Name:")) {
                    sscanf(line, "%*s %s", name);
                    break;
                }
            }
            fclose(fp);

            // Check if the process name is not an empty string
            if (strlen(name) > 0) {
                printf("PID: %d, Name: %s\n", pid, name);
                is_process = 1;
            }
        }
        closedir(d);
    }

    if (!is_process) {
        printf("No running processes found.\n");
    }

    return 0;
}