//FormAI DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILE_SIZE 1024

int main(int argc, char *argv[]) {
    char path[MAX_PATH_LENGTH];
    char filename[MAX_PATH_LENGTH];
    char filepath[MAX_PATH_LENGTH];

    if (argc != 3) {
        printf("Usage: %s <source file path> <destination file path>\n", argv[0]);
        exit(1);
    }

    strncpy(path, argv[1], MAX_PATH_LENGTH - 1);
    strncpy(filename, strrchr(path, '/') + 1, MAX_PATH_LENGTH - 1);
    snprintf(filepath, MAX_PATH_LENGTH, "%s/%s", argv[2], filename);

    FILE *src = fopen(argv[1], "r");
    FILE *dest = fopen(filepath, "w");

    if (src == NULL || dest == NULL) {
        printf("Error: could not open files\n");
        exit(1);
    }

    char buffer[MAX_FILE_SIZE];
    size_t bytesRead;

    while ((bytesRead = fread(buffer, 1, MAX_FILE_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytesRead, dest);
    }

    fclose(src);
    fclose(dest);

    printf("File synchronized successfully!\n");

    return 0;
}