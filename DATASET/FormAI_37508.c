//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to scan for viruses
void scan_for_virus(char* filename) {
    // opening the file in read mode
    FILE *fp = fopen(filename, "r");

    // checking if file exists
    if (fp == NULL) {
        printf("Cannot open file %s\n", filename);
        return;
    }

    // scanning each line of the file for virus detection
    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        // checking if virus exists in the line
        if (strstr(line, "evil") != NULL || strstr(line, "malware") != NULL || strstr(line, "virus") != NULL) {
            printf("Virus found in line: %s\n", line);
        }
    }

    // closing the file
    fclose(fp);
}

int main() {
    // declaring the filename variable
    char filename[50];

    // prompt the user for the file to be scanned
    printf("Enter the name of the file to be scanned: ");
    scanf("%s", filename);

    // scanning the file for viruses
    scan_for_virus(filename);

    return 0;
}