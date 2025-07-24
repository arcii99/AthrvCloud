//FormAI DATASET v1.0 Category: System process viewer ; Style: energetic
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

void printProcessInformation(char* pid) {
    char path[30];
    FILE *fp;
    char buffer[1024];
    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    fp=fopen(path, "r");
    if (fp != NULL) {
        while (fgets(buffer,1024, fp)) {
            printf("%s",buffer);
        }
        fclose(fp);
    }
}

void listProcesses() {
    DIR *dp;
    struct dirent * ep;
    dp = opendir("/proc");
    if (dp != NULL) {
        while (ep = readdir(dp)) {
            if ((strcmp(ep->d_name, ".")!=0) && (strcmp(ep->d_name, "..")!=0)) {
                if (atoi(ep->d_name) != 0) {
                    printf("Process ID: %s\n",ep->d_name);
                    printProcessInformation(ep->d_name);
                    printf("\n");
                }
            }
        }
        closedir(dp);
    }
}

int main() {
    printf("Welcome to the C System Process Viewer!\n");
    printf("Listing all processes:\n");
    listProcesses();
    return 0;
}