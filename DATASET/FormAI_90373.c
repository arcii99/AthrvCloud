//FormAI DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

// Function to check if a string is a number
bool is_number(char *string) {
    int length = strlen(string);
    for (int i=0; i<length; i++) {
        if (!isdigit(string[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    DIR *proc_dir;
    struct dirent *entry;
    char buffer[BUFFER_SIZE];
    pid_t pid;
    char cmdline_path[BUFFER_SIZE];
    char cmdline[BUFFER_SIZE];

    // Open the /proc directory
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("Error: /proc directory could not be opened.\n");
        return 1;
    }

    // Print the header
    printf("%-10s %-20s %-20s %-15s %-15s %-15s\n", "PID", "NAME", "STATE", "RSS", "VSZ", "CMDLINE");
    printf("-----------------------------------------------------------------------------\n");

    while ((entry = readdir(proc_dir)) != NULL) {
        // Skip the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Check if the directory is a process directory
        if (is_number(entry->d_name)) {
            pid = atoi(entry->d_name);

            // Get the process command line
            snprintf(cmdline_path, BUFFER_SIZE, "/proc/%d/cmdline", pid);
            FILE *cmdline_file = fopen(cmdline_path, "r");
            if (cmdline_file != NULL) {
                fgets(cmdline, BUFFER_SIZE, cmdline_file);
                fclose(cmdline_file);
            } else {
                strcpy(cmdline, "");
            }

            // Get the process state and memory usage
            snprintf(buffer, BUFFER_SIZE, "/proc/%d/status", pid);
            FILE *status_file = fopen(buffer, "r");
            if (status_file != NULL) {
                char line[BUFFER_SIZE];
                char *token;
                char state;
                int rss;
                int vsz;

                fgets(line, sizeof(line), status_file);
                while (!feof(status_file)) {
                    token = strtok(line, ":\t");
                    if (strcmp(token, "State") == 0) {
                        token = strtok(NULL, ":\t");
                        state = token[0];
                    } else if (strcmp(token, "VmRSS") == 0) {
                        token = strtok(NULL, ":\t");
                        rss = atoi(token);
                    } else if (strcmp(token, "VmSize") == 0) {
                        token = strtok(NULL, ":\t");
                        vsz = atoi(token);
                    }
                    fgets(line, sizeof(line), status_file);
                }

                fclose(status_file);

                // Print the process information
                printf("%-10d %-20s %-20c %-15d %-15d %-15s\n", pid, entry->d_name, state, rss, vsz, cmdline);
            }
        }
    }

    // Close the /proc directory
    closedir(proc_dir);

    return 0;
}