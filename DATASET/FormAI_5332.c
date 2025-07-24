//FormAI DATASET v1.0 Category: Data recovery tool ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "rb");

    if (fp == NULL) {
        printf("Unable to open file: %s\n", argv[1]);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    if (file_size == 0) {
        printf("File is empty: %s\n", argv[1]);
        exit(1);
    }

    char *buffer = malloc(file_size);

    if (buffer == NULL) {
        printf("Unable to allocate memory.\n");
        exit(1);
    }

    long bytes_read = fread(buffer, 1, file_size, fp);

    if (bytes_read != file_size) {
        printf("Unable to read complete file.\n");
        exit(1);
    }

    fclose(fp);

    printf("Successfully read %ld bytes.\n", bytes_read);

    // Recover data here...

    free(buffer);

    return 0;
}