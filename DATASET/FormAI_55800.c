//FormAI DATASET v1.0 Category: Error handling ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {

    FILE *fp;

    fp = fopen("non_existent_file.txt", "r");

    if(fp == NULL) {
        if(errno == ENOENT) {
            printf("Error: No such file or directory exists.\n");
        } else if(errno == EACCES) {
            printf("Error: Permission denied.\n");
        } else {
            printf("Error: Unknown error occurred: %d\n", errno);
        }
        exit(EXIT_FAILURE);
    }

    // Do something with file here...

    fclose(fp);

    return 0;
}