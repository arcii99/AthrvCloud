//FormAI DATASET v1.0 Category: Error handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void handle_error(int err) {
    if (err == EACCES) {
        printf("Error: Permission denied!\n");
    } else if (err == EFAULT) {
        printf("Error: Bad address!\n");
    } else if (err == EINVAL) {
        printf("Error: Invalid argument!\n");
    } else if (err == ENOMEM) {
        printf("Error: Out of memory!\n");
    } else {
        printf("Error: Unknown error code %d!\n", err);
    }
    exit(1);
}

int main() {
    FILE *fp;
    char filename[] = "example.txt";

    fp = fopen(filename, "r");
    if (fp == NULL) {
        handle_error(errno);
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (read > 10) {
            printf("Error: Line too long!\n");
            free(line);
            fclose(fp);
            exit(1);
        }
        printf("Line: %s", line);
    }

    free(line);
    fclose(fp);
    return 0;
}