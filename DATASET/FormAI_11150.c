//FormAI DATASET v1.0 Category: System process viewer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

void print_proc_info(char *, char *, char *, char *);
void print_proc_header();

int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;
    char *pid, *status, *state, *cmdline;
    char proc_path[50];
    char stat_path[50];
    char cmdline_path[50];
    char *name;
    char c;
    int opt_recurring = 0;
    int opt_all = 0;
    int opt_pid = 0;
    int proc_counter = 0;

    // Parse command line arguments
    while ((c = getopt(argc, argv, "aqr:p:")) != -1) {
        switch(c) {
            case 'a':
                opt_all = 1;
                break;
            case 'q':
                opt_recurring = 1;
                break;
            case 'r':
                strncpy(proc_path, "/proc/", sizeof(proc_path));
                strncat(proc_path, optarg, sizeof(proc_path) - strlen(proc_path) - 1);
                opt_pid = 1;
                break;
            case 'p':
                pid = optarg;
                strncpy(proc_path, "/proc/", sizeof(proc_path));
                strncat(proc_path, optarg, sizeof(proc_path) - strlen(proc_path) - 1);
                opt_pid = 1;
                break;
            case '?':
                printf("Unknown option -%c\n", optopt);
                return 1;
        }
    }

    // If no options given, print all processes
    if (!opt_pid && !opt_all) {
        opt_all = 1;
    }

    dp = opendir("/proc");
    if (dp == NULL) {
        perror("Error opening /proc directory");
        return 1;
    }

    // Loop through all directories in /proc
    print_proc_header();
    while ((dirp = readdir(dp))) {
        // Skip non-numeric directories
        if (!isdigit(dirp->d_name[0])) {
            continue;
        }

        // Check if this process should be printed
        if (opt_all || (opt_pid && strcmp(dirp->d_name, pid) == 0) ||
            (opt_recurring && strstr(dirp->d_name, pid) != NULL)) {
            strncpy(proc_path, "/proc/", sizeof(proc_path));
            strncat(proc_path, dirp->d_name, sizeof(proc_path) - strlen(proc_path) - 1);

            // Read in status file
            strncpy(stat_path, proc_path, sizeof(stat_path));
            strncat(stat_path, "/status", sizeof(stat_path) - strlen(stat_path) - 1);

            FILE *fstat = fopen(stat_path, "r");
            if (fstat == NULL) {
                perror("Error opening status file");
                continue;
            }

            // Parse status file for process information
            name = NULL;
            status = NULL;
            while (getline(&status, &opt_pid, fstat) != -1) {
                if (strstr(status, "Name:") != NULL) {
                    name = strtok(status, "\t\n");
                    name = strtok(NULL, "\t\n");
                } else if (strstr(status, "State:") != NULL) {
                    state = strtok(status, "\t\n");
                    state = strtok(NULL, "\t\n");
                }
            }
            fclose(fstat);

            // Read in cmdline file
            strncpy(cmdline_path, proc_path, sizeof(cmdline_path));
            strncat(cmdline_path, "/cmdline", sizeof(cmdline_path) - strlen(cmdline_path) - 1);

            FILE *fcmd = fopen(cmdline_path, "r");
            if (fcmd == NULL) {
                perror("Error opening cmdline file");
                continue;
            }

            // Parse cmdline file for process command
            cmdline = NULL;
            size_t cmdline_size;
            ssize_t n_chars = getline(&cmdline, &cmdline_size, fcmd);
            cmdline[n_chars-1] = '\0';

            fclose(fcmd);

            // Print process info
            print_proc_info(dirp->d_name, name, state, cmdline);
            proc_counter++;
        }
    }

    if (proc_counter == 0) {
        printf("No processes found\n");
    }

    closedir(dp);
    return 0;
}

void print_proc_header() {
    printf("%-8s %-15s %-10s %s\n", "PID", "NAME", "STATE", "CMD");
}

void print_proc_info(char *pid, char *name, char *state, char *cmdline) {
    printf("%-8s %-15s %-10s %s\n", pid, name, state, cmdline);
}