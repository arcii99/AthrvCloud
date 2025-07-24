//FormAI DATASET v1.0 Category: Error handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    FILE *file = fopen("file.txt", "r");
    if (file == NULL) {
        perror("Error while opening the file");
        return EXIT_FAILURE;
    }

    char buffer[256];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        if (ferror(file)) {
            perror("Error while reading from the file");
        } else {
            fprintf(stderr, "Unexpected end of file\n");
        }
        fclose(file);
        return EXIT_FAILURE;
    }

    printf("The content of the file is: %s", buffer);
    fclose(file);
    return EXIT_SUCCESS;
}