//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to remove all non-alphanumeric characters from a string
void removeNonAlphanumeric(char *str) {
    int i, j = 0;
    for (i = 0; str[i]; i++) {
        if (isalnum(str[i])) {
            str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

// Function to scan a file for virus signatures
int scanFile(char *filename, char **virusSignatures, int numSignatures) {
    FILE *fp;
    char buffer[1024];
    int i, j, found;
    fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open file %s for reading\n", filename);
        return -1;
    }
    while (fgets(buffer, 1024, fp) != NULL) {
        removeNonAlphanumeric(buffer);
        for (i = 0; i < numSignatures; i++) {
            found = 1;
            for (j = 0; j < strlen(virusSignatures[i]); j++) {
                if (tolower(buffer[j]) != tolower(virusSignatures[i][j])) {
                    found = 0;
                    break;
                }
            }
            if (found) {
                printf("Virus signature detected in file %s\n", filename);
                fclose(fp);
                return 1;
            }
        }
    }
    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    char *virusSignatures[] = {"malware", "virus", "trojan", "worm", "rootkit"};
    int numSignatures = 5;
    int detected = 0;
    int i;
    if (argc < 2) {
        printf("Usage: %s [file1] [file2] ...\n", argv[0]);
        return 0;
    }
    for (i = 1; i < argc; i++) {
        detected = scanFile(argv[i], virusSignatures, numSignatures);
        if (detected) {
            break;
        }
    }
    if (!detected) {
        printf("No viruses detected\n");
    }
    return 0;
}