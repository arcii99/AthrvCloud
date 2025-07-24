//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pid = getpid();  // get pid of the current process
    int mem = 0;  // variable to store RAM usage

    while (1) {
        FILE *fp;  // pointer to the file containing RAM usage info
        char path[50];  // path to the file
        sprintf(path, "/proc/%d/status", pid);  // set the path

        fp = fopen(path, "r");  // open the file
        if (fp == NULL) {
            printf("Oops! Something went wrong. Try running the program as root.\n");
            return 1;
        }

        // extract the RAM usage info
        char line[128];
        while (fgets(line, 128, fp) != NULL) {
            if (strstr(line, "VmRSS")) {
                char *tok = strtok(line, ":");
                tok = strtok(NULL, " kB\n");
                mem = atoi(tok);  // convert the string to int
                break;
            }
        }
        fclose(fp);  // close the file

        // print the RAM usage in a cheerful way
        printf("Wow! You're using %d kB of RAM. Keep up the good work!\n", mem);

        sleep(5);  // sleep for 5 seconds
    }

    return 0;
}