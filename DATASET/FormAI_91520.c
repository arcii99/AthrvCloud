//FormAI DATASET v1.0 Category: Error handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handleError(int errnum)
{
    printf("Error number: %d\n", errnum);

    if (errnum == EACCES) {
        printf("Permission denied\n");
    } else if (errnum == ENOENT) {
        printf("File not found\n");
    } else if (errnum == ENOMEM) {
        printf("Out of memory\n");
    } else {
        printf("Unknown error\n");
    }

    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    FILE *fp;
    char *filename = "example.txt";

    fp = fopen(filename, "r");

    if (fp == NULL) {
        handleError(errno);
    }

    // Rest of code goes here

    fclose(fp);

    return 0;
}