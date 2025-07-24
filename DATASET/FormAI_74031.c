//FormAI DATASET v1.0 Category: System process viewer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

// function to check if a string is numeric
int is_numeric(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    DIR *dir = opendir("/proc"); // open the "/proc" directory
    struct dirent *dir_entry;
    printf("PID\tPPID\tSTATE\tCMD\n");
    while ((dir_entry = readdir(dir)) != NULL) { // iterate over all the directory entries in "/proc"
        if (is_numeric(dir_entry->d_name)) { // check if the directory entry is a pid (numeric)
            char stat_path[255];
            char cmdline_path[255];
            snprintf(stat_path, sizeof(stat_path), "/proc/%s/stat", dir_entry->d_name);
            snprintf(cmdline_path, sizeof(cmdline_path), "/proc/%s/cmdline", dir_entry->d_name);
            FILE *stat_file = fopen(stat_path, "r");
            FILE *cmdline_file = fopen(cmdline_path, "r");
            if (stat_file && cmdline_file) { // check if both the files could be opened
                int pid, ppid;
                char state, cmd[255];
                fscanf(stat_file, "%d %*s %c %d", &pid, &state, &ppid); // read the PID, state and PPID from the stat file
                fgets(cmd, sizeof(cmd), cmdline_file); // read the command from cmdline file
                printf("%d\t%d\t%c\t%s\n", pid, ppid, state, cmd); // print the details
                fclose(stat_file);
                fclose(cmdline_file);
            }
        }
    }
    return 0;
}