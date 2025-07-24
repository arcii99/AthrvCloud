//FormAI DATASET v1.0 Category: System process viewer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    DIR *dirp;
    struct dirent *direntp;
    char path[] = "/proc/";
    char num[256];

    printf("Welcome to the C System Process Viewer program, my dear Watson.\n");

    dirp = opendir(path);
    if (dirp == NULL) {
        printf("Error: Unable to open /proc directory.\n");
        exit(EXIT_FAILURE);
    }

    printf("The following processes are currently running:\n");
    printf("PID\t\tName\n");

    while ((direntp = readdir(dirp)) != NULL) {
        if (isdigit(*direntp->d_name)) {
            strcpy(num, direntp->d_name);
            strcat(num, "/comm");
            FILE *commFile = fopen(num, "r");
            fgets(num, sizeof(num), commFile);
            fclose(commFile);
            printf("%s\t\t%s", direntp->d_name, num);
        }
    }

    closedir(dirp);
    printf("\nGoodbye, Watson. Another mystery solved.\n");
    return 0;
}