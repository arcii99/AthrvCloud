//FormAI DATASET v1.0 Category: System process viewer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

extern int errno;

int isNumber(char *str);
void printProcessInfo(char *pid);

int main(int argc, char *argv[]) {
    DIR *dir = NULL;
    struct dirent *entry;
    char path[BUF_SIZE], buf[BUF_SIZE];

    // open directory /proc
    dir = opendir("/proc");
    if (!dir) {
        printf("Error: cannot open /proc directory\n");
        exit(1);
    }

    // read all the entries in directory
    while ((entry = readdir(dir)) != NULL) {
        // check if the entry is a directory and contains only digits
        if (entry->d_type == DT_DIR && isNumber(entry->d_name)) {
            // build the path to the process folder
            sprintf(path, "/proc/%s/status", entry->d_name);

            // open the status file
            int fd = open(path, O_RDONLY);
            if (fd == -1) {
                printf("Error: cannot open %s file\n", path);
                continue;
            }

            // read the content of the status file
            ssize_t numBytes = read(fd, buf, BUF_SIZE);
            if (numBytes == -1) {
                printf("Error: cannot read %s file\n", path);
                close(fd);
                continue;
            }

            // terminate the string with a null character
            buf[numBytes] = '\0';

            // extract the process name and PID from the status file content
            char *name = NULL, *pid = NULL;
            char *token = strtok(buf, "\n");
            while (token != NULL) {
                if (strncmp(token, "Name:", 5) == 0) {
                    name = token + 6;
                } else if (strncmp(token, "Pid:", 4) == 0) {
                    pid = token + 5;
                }

                token = strtok(NULL, "\n");
            }

            // check if the PID and process name have been found
            if (pid && name) {
                // print the process information
                printProcessInfo(pid);
            }

            // close the status file
            close(fd);
        }
    }

    // close the directory
    closedir(dir);

    return 0;
}

// function to check if the string contains only digits
int isNumber(char *str) {
    while (*str) {
        if (!isdigit(*str++)) {
            return 0;
        }
    }

    return 1;
}

// function to print the process information
void printProcessInfo(char *pid) {
    char path[BUF_SIZE], buf[BUF_SIZE];
    int uid, gid;
    char comm[BUF_SIZE], state[BUF_SIZE], ppid[BUF_SIZE], sess[BUF_SIZE], tty[BUF_SIZE], nlwp[BUF_SIZE];
    unsigned long int vsize, rss;

    // build the path to the process folder
    sprintf(path, "/proc/%s/stat", pid);

    // open the stat file
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf("Error: cannot open %s file\n", path);
        return;
    }

    // read the content of the stat file
    ssize_t numBytes = read(fd, buf, BUF_SIZE);
    if (numBytes == -1) {
        printf("Error: cannot read %s file\n", path);
        close(fd);
        return;
    }

    // close the stat file
    close(fd);

    // parse the stat file content and extract the required information
    sscanf(buf, "%s %s %s %s %s %s %s %u %u %u %u %u %u %lu %lu ", pid, comm, state, ppid, sess, tty, nlwp, &uid, &gid, NULL, NULL, NULL, NULL, &vsize, &rss);

    // print the process information
    printf("PID: %s\n", pid);
    printf("Name: %s", comm);
    printf("State: %s\n", state);
    printf("PPID: %s\n", ppid);
    printf("Session ID: %s\n", sess);
    printf("Terminal: %s\n", tty);
    printf("Number of threads: %s\n", nlwp);
    printf("User ID: %u\n", uid);
    printf("Group ID: %u\n", gid);
    printf("Virtual Memory Size: %lu\n", vsize);
    printf("Resident Set Size: %lu\n\n", rss);
}