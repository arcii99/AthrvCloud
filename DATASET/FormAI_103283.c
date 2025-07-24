//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_SIZE 256
#define MAX_FILE_SIZE 1024

int checkFile(char *filename);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *filename = argv[1];
    int result = checkFile(filename);

    if (result) {
        printf("%s is infected with a virus.\n", filename);
    } else {
        printf("%s is clean.\n", filename);
    }

    return 0;
}

int checkFile(char *filename) {
    char virus[] = "virus";
    char buffer[MAX_FILE_SIZE];
    FILE *fp;
    int foundVirus = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("%s could not be opened.\n", filename);
        return -1;
    }

    while (!feof(fp) && !foundVirus) {
        fgets(buffer, MAX_FILE_SIZE, fp);
        if (strstr(buffer, virus) != NULL) {
            foundVirus = 1;
        }
    }

    fclose(fp);

    return foundVirus;
}