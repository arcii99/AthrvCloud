//FormAI DATASET v1.0 Category: Error handling ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main() {

    FILE* file = fopen("non_existent_file.txt", "r");

    if (!file) {
        perror("Error");
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Code to read from the file, not executed if file cannot be opened

    fclose(file);
    return 0;
}