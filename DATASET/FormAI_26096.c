//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check if the given file is infected with a virus
int is_infected(char *filename) {
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error: Cannot open file %s\n", filename);
        return 0;
    }

    // Define the virus signature that we will check for
    char virus[] = "W32/wannacry";

    // Read the contents of the file byte-by-byte
    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        for (int i = 0; i < bytes_read - strlen(virus); i++) {
            if (memcmp(buffer+i, virus, strlen(virus)) == 0) {
                printf("Virus found in file %s\n", filename);
                return 1;
            }
        }
    }

    fclose(fp);
    return 0;
}

// Function to scan the given directory for infected files
void scan_directory(char *dirname) {
    char command[1024];
    sprintf(command, "ls %s", dirname);

    FILE *fp = popen(command, "r");

    if (fp == NULL) {
        printf("Error: Cannot open directory %s\n", dirname);
        exit(-1);
    }

    char filename[256];

    while (fgets(filename, sizeof(filename), fp) != NULL) {
        strtok(filename, "\n");

        if (is_infected(filename)) {
            printf("Infected file: %s\n", filename);
        }
    }

    pclose(fp);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s directory\n", argv[0]);
        exit(-1);
    }

    char *dirname = argv[1];
    scan_directory(dirname);

    printf("Directory %s has been scanned.\n", dirname);
    return 0;
}