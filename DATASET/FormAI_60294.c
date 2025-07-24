//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1024

int infected = 0;

struct Virus {
    char name[30];
    char signature[50];
};

void scanFile(FILE *fp, struct Virus viruses[], int numViruses) {
    char buffer[MAX_FILE_SIZE];
    int fileSize, i, j, matchFound;

    // Get file size
    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Read file into buffer
    fread(buffer, fileSize, 1, fp);

    // Check for virus match in buffer
    for (i = 0; i < numViruses; i++) {
        matchFound = 0;
        for (j = 0; j < fileSize - strlen(viruses[i].signature); j++) {
            if (strncmp(&buffer[j], viruses[i].signature, strlen(viruses[i].signature)) == 0) {
                printf("Virus found: %s\n", viruses[i].name);
                matchFound = 1;
                infected++;
                break;
            }
        }
        if (matchFound) break;
    }
}

int main() {
    struct Virus viruses[] = {
        { "Stealth", "KLHwejfhqwe8r9823fh" },
        { "Trojan", "wewfg2iufg8efn73bbv" },
        { "Worm", "wg2389regh239ddfhsf" },
        { "Spyware", "efqwenfi843d98hg23rh" },
        { "Rootkit", "dfhwihefh8e923hrf8e" }
    };
    int numViruses = sizeof(viruses) / sizeof(viruses[0]);

    FILE *fp;

    // Open file for scanning
    fp = fopen("sample_file.txt", "r");
    if (fp == NULL) {
        printf("File not found\n");
        exit(1);
    }

    // Scan file for viruses
    scanFile(fp, viruses, numViruses);

    // Close file
    fclose(fp);

    // Print results
    if (infected > 0) {
        printf("%d viruses found in file\n", infected);
    } else {
        printf("No viruses found in file\n");
    }

    return 0;
}