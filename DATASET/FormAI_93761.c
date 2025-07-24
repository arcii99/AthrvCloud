//FormAI DATASET v1.0 Category: System process viewer ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define PROC "/proc"
#define MAX_PID_LENGTH 6   // PID can have maximum 6 digit length
#define MAX_CMDLINE_LEN 2048   // Maximum length of Command Line for a process

// Function declarations
void print_process_info(pid_t pid);

int main(void) {
    DIR *dirp;
    FILE *fp;
    struct dirent *entry;
    pid_t pid;

    if ((dirp = opendir(PROC)) == NULL) {
        fprintf(stderr, "Could not open /proc directory!\n");
        exit(EXIT_FAILURE);
    }

    // Traverse through all the processes in /proc directory
    while ((entry = readdir(dirp))) {
        pid = atoi(entry -> d_name);
        if (pid > 0) {
            print_process_info(pid); // Get and print Process information
            printf("\n");    // Add new line to make output readable
        }
    }

    closedir(dirp);   // Close the /proc directory
    return 0;
}

// Function to get and print information about a process
void print_process_info(pid_t pid) {
    FILE *fp;
    char filename[MAX_PID_LENGTH + 20];   // Length of filename can be PID + 20
    char cmdline[MAX_CMDLINE_LEN];    // Allocate buffer to store command line
    int i;

    sprintf(filename, "/proc/%d/cmdline", pid);   // Form filename from PID
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        return;
    }

    // Read command line from file and store it in cmdline buffer
    i = 0;
    while ((cmdline[i] = fgetc(fp)) != EOF && i < (MAX_CMDLINE_LEN - 1)) {
        i++;
    }
    cmdline[i] = '\0';    // Terminate string with null character

    fclose(fp);   // Close the file

    // Print Process ID, Parent Process ID and Command Line
    printf("Process ID: %d\n", pid);
    sprintf(filename, "/proc/%d/stat", pid);   // Form filename from PID
    if ((fp = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        return;
    }
    int ppid = -1;
    char name[MAX_CMDLINE_LEN];
    fscanf(fp,"%*d %s %*c %d",&name,&ppid);
    fclose(fp);
    printf("Command Line: %s\n", cmdline);
    printf("Parent Process ID: %d\n", ppid);
}