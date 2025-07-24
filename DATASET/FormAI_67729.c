//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int scan_file(char *filename);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    int infected = scan_file(argv[1]);
    if (infected) {
        printf("%s is infected with a virus!\n", argv[1]);
    } else {
        printf("%s is clean.\n", argv[1]);
    }
    return 0;
}

int scan_file(char *filename) {
    FILE *fp;
    char buffer[MAX_BUFFER_SIZE];
    int infected = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error while opening file");
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, MAX_BUFFER_SIZE, fp)) {
        // Check for known virus signatures in file
        if (strstr(buffer, "virus_signature_1") != NULL ||
            strstr(buffer, "virus_signature_2") != NULL ||
            strstr(buffer, "virus_signature_3") != NULL) {
            infected = 1;
            break;
        }
    }

    if (fclose(fp) != 0) {
        perror("Error while closing file");
        exit(EXIT_FAILURE);
    }
    return infected;
}