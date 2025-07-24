//FormAI DATASET v1.0 Category: Error handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE* fp;
    char filename[50];
    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r"); // try to open file for reading

    if (fp == NULL) { // an error occured while opening the file
        perror("Error opening file");
        printf("Error code: %d\n", errno);
        exit(EXIT_FAILURE); // exit program with failure status code
    }

    // File is now open, read it or do whatever processing necessary.
    printf("%s opened successfully\n", filename);

    // close the file before exiting
    fclose(fp);
    return 0;
}