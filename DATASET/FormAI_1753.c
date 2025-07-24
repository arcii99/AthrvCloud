//FormAI DATASET v1.0 Category: Error handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handle_error(int errnum) {
    switch (errnum) {
        case EACCES:
            printf("Error: Permission denied\n");
            break;
        case ENOENT:
            printf("Error: File or directory not found\n");
            break;
        case EINVAL:
            printf("Error: Invalid argument\n");
            break;
        default:
            printf("Unknown Error\n");
            break;
    }
}

int main() {
    FILE *fp;
    char *filename = "test.txt";
    int val = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        handle_error(errno);
        exit(EXIT_FAILURE);
    }

    if (fscanf(fp, "%d", &val) != 1) {
        handle_error(EINVAL);
        exit(EXIT_FAILURE);
    }

    if (fclose(fp) != 0) {
        handle_error(errno);
        exit(EXIT_FAILURE);
    }

    printf("Value read from file: %d\n", val);

    return 0;
}