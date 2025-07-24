//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_PATH 200
#define MAX_VIRUS_SIGNATURE 100

int main() {
    char file_path[MAX_FILE_PATH];
    char virus_signature[MAX_VIRUS_SIGNATURE];

    printf("Enter file path to check for virus: ");
    scanf("%s", file_path);

    printf("Enter virus signature to look for: ");
    scanf("%s", virus_signature);

    FILE *fp = fopen(file_path, "rb");
    if (fp == NULL) {
        printf("File not found.");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *file_contents = (char*) malloc(file_size);
    fread(file_contents, 1, file_size, fp);

    char *match = strstr(file_contents, virus_signature);
    if (match == NULL) {
        printf("No virus found in file.");
        free(file_contents);
        return 0;
    }

    printf("Virus found in file.");

    fclose(fp);
    free(file_contents);

    return 0;
}