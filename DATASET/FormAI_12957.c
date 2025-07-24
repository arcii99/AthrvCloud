//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BUFFER_SIZE 1024

char* scan_file(char *filename) {
    printf("Scanning %s for viruses...\n", filename);
    char *result = "SAFE";
    FILE *file = fopen(filename, "r");
    if (!file) {
        result = "ERROR";
        printf("Could not open file: %s\n", filename);
        return result;
    }

    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, file) != NULL) {
        if (strstr(buffer, "virus") != NULL) {
            result = "INFECTED";
            printf("Found virus in %s!\n", filename);
            break;
        }
    }

    fclose(file);
    return result;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <file1> [<file2> ...]\n", argv[0]);
        return 1;
    }

    int i;
    for (i = 1; i < argc; i++) {
        if (strlen(argv[i]) > MAX_FILENAME_LENGTH) {
            printf("Filename too long: %s\n", argv[i]);
            return 1;
        }

        char *result = scan_file(argv[i]);
        printf("%s: %s\n", argv[i], result);
    }

    return 0;
}