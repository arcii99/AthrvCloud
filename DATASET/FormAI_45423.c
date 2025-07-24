//FormAI DATASET v1.0 Category: Error handling ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    FILE* file = NULL;
    char* fileName = "nonexistent-file.txt";
    file = fopen(fileName, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s. ", fileName);
        if (errno == ENOENT) {
            fprintf(stderr, "No such file or directory. ");
        } else if (errno == EACCES) {
            fprintf(stderr, "Permission denied. ");
        }
        perror("");
        exit(EXIT_FAILURE);
    }
    fclose(file);
    return 0;
}