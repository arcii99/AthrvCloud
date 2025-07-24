//FormAI DATASET v1.0 Category: System process viewer ; Style: calm
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>

// Function to check if a string is a number
int is_number(char *string) {
    for (int i = 0; i < strlen(string); i++) {
        if (!isdigit(string[i])) {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char **argv) {
    DIR *directory;
    struct dirent *entry;
    char path[100], buffer[100], pid[10];
    int opt_c = 0, opt_p = 0;
    int pid_arg = 0;

    // Parse command line arguments using getopt
    int opt;
    while ((opt = getopt(argc, argv, "c:p:")) != -1) {
        switch (opt) {
            case 'c':
                opt_c = 1; // Set option c flag
                strncpy(path, optarg, sizeof(path));
                break;
            case 'p':
                opt_p = 1; // Set option p flag
                pid_arg = atoi(optarg);
                break;
        }
    }

    // If neither option c nor option p is set, print usage and exit
    if (!opt_c && !opt_p) {
        printf("Usage: %s [-c PATH] [-p PID]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // If option c is set, change directory to specified path
    if (opt_c) {
        if (chdir(path) != 0) {
            perror("chdir");
            exit(EXIT_FAILURE);
        }
    }

    // Print header for process viewer
    printf("%-10s %-20s %-20s %-20s %-20s\n", "PID", "NAME", "STATE", "PPID", "CMD");

    // If option p is set, only show information for specified PID
    if (opt_p) {
        sprintf(path, "/proc/%d/status", pid_arg);
        FILE *fp = fopen(path, "r");
        if (!fp) {
            printf("PID %d not found.\n", pid_arg);
            exit(EXIT_FAILURE);
        }

        char name[100], state[2], ppid[10], cmd[200];
        while (fgets(buffer, sizeof(buffer), fp)) {
            if (strncmp(buffer, "Name:", 5) == 0) {
                sscanf(buffer + 6, "%s", name);
            } else if (strncmp(buffer, "State:", 6) == 0) {
                sscanf(buffer + 7, "%s", state);
            } else if (strncmp(buffer, "PPid:", 5) == 0) {
                sscanf(buffer + 6, "%s", ppid);
            } else if (strncmp(buffer, "Cmdline:", 8) == 0) {
                sscanf(buffer + 9, "%s", cmd);
            }
        }

        fclose(fp);

        printf("%-10d %-20s %-20s %-20s %-20s\n", pid_arg, name, state, ppid, cmd);
        exit(EXIT_SUCCESS);
    }

    // If option p is not set, show information for all PIDs in /proc directory
    directory = opendir("/proc");
    if (!directory) {
        perror("/proc");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(directory))) {
        if (is_number(entry->d_name)) {
            strcpy(pid, entry->d_name);
            sprintf(path, "/proc/%s/status", pid);
            FILE *fp = fopen(path, "r");
            if (!fp) {
                continue;
            }

            char name[100], state[2], ppid[10], cmd[200];
            while (fgets(buffer, sizeof(buffer), fp)) {
                if (strncmp(buffer, "Name:", 5) == 0) {
                    sscanf(buffer + 6, "%s", name);
                } else if (strncmp(buffer, "State:", 6) == 0) {
                    sscanf(buffer + 7, "%s", state);
                } else if (strncmp(buffer, "PPid:", 5) == 0) {
                    sscanf(buffer + 6, "%s", ppid);
                } else if (strncmp(buffer, "Cmdline:", 8) == 0) {
                    sscanf(buffer + 9, "%s", cmd);
                }
            }

            fclose(fp);

            printf("%-10s %-20s %-20s %-20s %-20s\n", pid, name, state, ppid, cmd);
        }
    }

    closedir(directory);

    return 0;
}