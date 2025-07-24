//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VIRUS_SIGNATURE "This program contains a virus."
#define MAX_FILE_SIZE 1000000

int scan_file(FILE *fp);
int contains_virus(char *buffer);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Error: Enter file name to scan as an argument.\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Failed to open file.\n");
        return 1;
    }

    int result = scan_file(fp);
    fclose(fp);

    if (result == 1) {
        printf("Warning: Virus detected!\n");
    } else {
        printf("File is clean.\n");
    }

    return 0;
}

int scan_file(FILE *fp) {
    char buffer[MAX_FILE_SIZE];
    size_t num_bytes_read = fread(buffer, sizeof(char), MAX_FILE_SIZE, fp);

    if (num_bytes_read == 0) {
        printf("Error while reading file.\n");
        return -1;
    }

    return contains_virus(buffer);
}

int contains_virus(char *buffer) {
    if (strstr(buffer, VIRUS_SIGNATURE) != NULL) {
        return 1;
    }

    return 0;
}