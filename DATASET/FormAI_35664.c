//FormAI DATASET v1.0 Category: System process viewer ; Style: intelligent
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>

#define MAX_PROCESS_NAME_LENGTH 1024

// Function to check if a string represents an integer
int is_number(char *str) {
    int i;
    for(i = 0; str[i] != '\0'; i++) {
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

int main() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;
    char pid[MAX_PROCESS_NAME_LENGTH], process_name[MAX_PROCESS_NAME_LENGTH];
    // Loop through the /proc directory to get process information
    while((entry = readdir(dir)) != NULL) {
        if(is_number(entry->d_name)) {
            // It is a process directory
            strcpy(pid, entry->d_name);
            strcat(pid, "/");
            strcat(pid, "comm");
            FILE *fp = fopen(pid, "r");
            fgets(process_name, MAX_PROCESS_NAME_LENGTH, fp);
            fclose(fp);
            // Remove the newline character from the process name
            process_name[strcspn(process_name, "\n")] = 0;
            // Print the process ID and name
            printf("PID: %s  ", entry->d_name);
            printf("Name: %s  \n", process_name);
        }
    }
    closedir(dir);
    return 0;
}