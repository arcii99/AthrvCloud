//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 128

int isInfected(char* filename);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Please provide the filename as argument.\n");
        return 1;
    }

    char* filename = argv[1];

    if (isInfected(filename)) {
        printf("The file \"%s\" is infected with a virus.\n", filename);
    } else {
        printf("The file \"%s\" is clean.\n", filename);
    }

    return 0;
}

int isInfected(char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Failed to open the file \"%s\".\n", filename);
        return -1;
    }

    char buffer[MAX_LENGTH];
    while (fgets(buffer, MAX_LENGTH, file)) {
        if (strstr(buffer, "virus")) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}