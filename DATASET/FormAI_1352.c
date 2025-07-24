//FormAI DATASET v1.0 Category: Error handling ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void handle_error(int err_num) {
    switch(err_num) {
        case EACCES:
            fprintf(stderr, "Error: Permission denied\n");
            exit(EXIT_FAILURE);
            break;
        case EINVAL:
            fprintf(stderr, "Error: Invalid argument\n");
            exit(EXIT_FAILURE);
            break;
        default:
            fprintf(stderr, "Error: Unknown error occurred\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    FILE *fp;
    char *filename = "nonexistent_file.txt";

    fp = fopen(filename, "r");

    if(fp == NULL) {
        handle_error(errno);
    }

    printf("Successfully opened file %s\n", filename);

    fclose(fp);
    return 0;
}