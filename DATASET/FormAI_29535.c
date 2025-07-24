//FormAI DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void handleError(int errorNum, char *errorMsg) {
    fprintf(stderr, "Error %d: %s\n", errorNum, errorMsg);
    exit(1);
}

int main() {
    FILE *fp;
    char *filename = "example.txt";
    char buffer[100];

    fp = fopen(filename, "r");
    if (fp == NULL) {
        handleError(errno, strerror(errno));
    }

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }
        printf("%s\n", buffer);
    }

    if (feof(fp)) {
        printf("\nSuccessfully reached end of file!\n");
    } else if (ferror(fp)) {
        handleError(errno, strerror(errno));
    }

    fclose(fp);

    return 0;
}