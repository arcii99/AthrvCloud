//FormAI DATASET v1.0 Category: Error handling ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    char filename[100];
    FILE *fp;

    printf("Enter the name of the file to open: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("\nFailed to open file %s.\nError code: %d\n", filename, errno);

        if (errno == EACCES) {
            printf("Permission Denied.\n");
        } else if (errno == ENOENT) {
            printf("File does not exist.\n");
        } else if (errno == ELOOP) {
            printf("Too many symbolic links encountered while traversing the path.\n");
        } else {
            printf("Unknown error occured.\n");
        }

        exit(EXIT_FAILURE);
    } else {
        printf("\nFile opened successfully.\n");
        fclose(fp);
    }

    return 0;
}