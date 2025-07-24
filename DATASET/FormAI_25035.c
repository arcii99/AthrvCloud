//FormAI DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PROCESS_NAME_LEN 256
#define MAX_PID_LEN 8

int is_number(const char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int main(int argc, char *argv[]) {
    int i = 0, j = 0;
    char pid[MAX_PID_LEN];
    char pname[MAX_PROCESS_NAME_LEN];
    DIR* proc_dir;
    FILE* cmdline_file;

    // Let's begin with some detective work to find the process ID
    printf("Welcome, dear Watson. We are here to investigate and find the details of a running process.\n");
    printf("Please tell me the PID (Process ID) you want to investigate: ");
    scanf("%s", pid);
    printf("\n");

    // We need to verify if the input is numeric
    if (is_number(pid) == 0) {
        printf("[ERROR] Invalid input! PID has to be a number.\n");
        return -1;
    }

    // Opening the /proc/ directory to look up the pid directory
    proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        printf("[ERROR] Unable to open /proc/ directory\n");
        return -1;
    }

    // Iterating through the /proc/ directory to look up for the pid directory
    struct dirent* proc_entry;
    while ((proc_entry = readdir(proc_dir)) != NULL) {
        if (strncmp(proc_entry->d_name, pid, strlen(pid)) == 0) {
            // We found the pid directory. Now we want to look up the process name from cmdline file.
            // Creating cmdline file path
            char cmdline_path[MAX_PID_LEN + 11];
            strcpy(cmdline_path, "/proc/");
            strcat(cmdline_path, pid);
            strcat(cmdline_path, "/cmdline");

            // Opening cmdline file
            cmdline_file = fopen(cmdline_path, "r");
            if (cmdline_file == NULL) {
                printf("[ERROR] Unable to open cmdline file in directory /proc/%s/\n", pid);
                return -1;
            }

            // Reading the process name from cmdline file
            char cmdline[MAX_PROCESS_NAME_LEN];
            fgets(cmdline, MAX_PROCESS_NAME_LEN, cmdline_file);
            fclose(cmdline_file);

            // Let's clean the process name from any unnecessary characters
            for (i = 0, j = 0; i < strlen(cmdline); i++) {
                if (!isspace(cmdline[i]) && cmdline[i] != '\0') {
                    pname[j] = cmdline[i];
                    j++;
                }
                else break;
            }
            pname[j] = '\0';
            break;
        }
    }
    closedir(proc_dir);

    // Checking if we could find the process name
    if (strlen(pname) == 0) {
        printf("[ERROR] Could not find process name for given PID.\n");
        return -1;
    }

    // We have uncovered the process with its details. Now, let's reveal it to the user
    printf("Ah! I have found it. The running process with PID %s is %s. Here are the details:\n", pid, pname);

    // Time to look into the process status file
    char status_path[MAX_PID_LEN + 12];
    strcpy(status_path, "/proc/");
    strcat(status_path, pid);
    strcat(status_path, "/status");
    FILE* status_file = fopen(status_path, "r");
    if (status_file == NULL) {
        printf("[ERROR] Unable to open status file in directory /proc/%s/\n", pid);
        return -1;
    }

    // Reading the process status file to gather required details
    char line[MAX_PROCESS_NAME_LEN] = {0};
    int count = 0;
    int uid = 0, gid = 0;
    while (fgets(line, MAX_PROCESS_NAME_LEN, status_file)) {
        // We are interested in the following details:
        // - uid
        // - gid
        // - state
        // - voluntary_ctxt_switches
        // - nonvoluntary_ctxt_switches
        if (strncmp(line, "Uid:", 4) == 0) {
            sscanf(line, "Uid:\t%d %*d %*d %*d", &uid);
        }
        else if (strncmp(line, "Gid:", 4) == 0) {
            sscanf(line, "Gid:\t%d %*d %*d %*d", &gid);
        }
        else if (strncmp(line, "State:", 6) == 0) {
            printf("- Process is in %s\n", (line + 7));
        }
        else if (strncmp(line, "voluntary_ctxt_switches:", 23) == 0) {
            printf("- Process has made %s voluntary context switches\n", (line + 24));
        }
        else if (strncmp(line, "nonvoluntary_ctxt_switches:", 26) == 0) {
            printf("- Process has made %s non-voluntary context switches\n", (line + 27));
        }

        if (count == 4) break;
        count++;
    }
    fclose(status_file);

    // Printing the UID and GID information
    printf("- UID of the process owner is %d\n", uid);
    printf("- GID of the process owner is %d\n", gid);

    printf("\nThat's all, Watson. Our investigation is complete.\n");
    return 0;
}