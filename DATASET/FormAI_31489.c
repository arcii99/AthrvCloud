//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scanner(char *file) {

    FILE *fp = fopen(file, "r");
    char line[100];
    int virusCount = 0;

    if (fp == NULL) {
        printf("ERROR: Unable to open file\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "virus") || strstr(line, "malware")) {
            printf("Virus detected in line: %s\n", line);
            virusCount++;
        }
    }

    fclose(fp);

    if (virusCount == 0) {
        printf("This file is clean! No viruses detected\n");
    } else {
        printf("WARNING: %d viruses detected in this file\n", virusCount);
    }
}

int main() {

    char filename[20];

    printf("Enter the name of the file to scan: ");
    scanf("%s", filename);
    scanner(filename);

    return 0;
}