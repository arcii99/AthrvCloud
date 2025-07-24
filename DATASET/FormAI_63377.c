//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {

    DIR *dirp;
    struct dirent *direntp;
    char *infected_file = argv[1];
    int infected = 0;
    char *file_extension;

    if (argc == 1) {
        printf("Please provide a filename to scan.\n");
        exit(0);
    }

    if ((dirp = opendir(".")) == NULL) {
        perror("Failed to open directory");
        exit(1);
    }

    while ((direntp = readdir(dirp)) != NULL) {
        if (strcmp(direntp->d_name, infected_file) == 0) {
            infected = 1;
            file_extension = strrchr(direntp->d_name, '.');
            if (strcmp(file_extension, ".exe") == 0 || strcmp(file_extension, ".bat") == 0) {
                printf("%s is infected with a virus.\n", infected_file);
            } else {
                printf("%s is not infected with a virus.\n", infected_file);
            }
        }
    }

    if (infected == 0) {
        printf("File not found.\n");
    }

    closedir(dirp);

    return 0;
}