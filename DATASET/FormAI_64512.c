//FormAI DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(void) {

    FILE *fp;

    fp = fopen("non_existent_file.txt", "r");

    if (fp == NULL) {

        fprintf(stderr, "Error: %d \n", errno);

        switch (errno) {

            case ENOENT:
                printf("File not found error: The specified file does not exist. \n");
                break;

            case EACCES:
                printf("Permission denied error: The file cannot be accessed due to permission restrictions. \n");
                break;

            default:
                printf("Unknown error. \n");
                break;
        }

        exit(EXIT_FAILURE);
    }

    fclose(fp);

    return 0;
}