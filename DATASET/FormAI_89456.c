//FormAI DATASET v1.0 Category: Error handling ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void handleError(int errnum, const char *errmsg) {
    if (errmsg == NULL) {
        fprintf(stderr, "Error %d occurred\n", errnum);
    } else {
        fprintf(stderr, "Error %d: %s\n", errnum, errmsg);
    }

    exit(1);
}

int main(int argc, char *argv[]) {
    int i, val;
    FILE *file = NULL;

    if (argc < 2) {
        handleError(EINVAL, "No file name provided");
    }

    file = fopen(argv[1], "r");
    if (file == NULL) {
        handleError(errno, "Unable to open file");
    }

    for (i = 0; i < 5; i++) {
        if (fscanf(file, "%d", &val) != 1) {
            handleError(EIO, "Error reading from file");
        }
        printf("Value %d: %d\n", i, val);
    }

    if (fclose(file) == EOF) {
        handleError(errno, "Error closing file");
    }

    return 0;
}