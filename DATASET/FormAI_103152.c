//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Post-apocalyptic style C Antivirus scanner

int main() {
    char infected_file[256]; // max length of file name
    char virus_signature[] = "THEAFTERMATH";
    char file_signature[256];
    FILE *fp;

    printf("Post-apocalyptic C Antivirus scanner\n\n");

    printf("Enter the file name you want to scan: ");
    scanf("%s", infected_file);

    fp = fopen(infected_file, "r");

    if (fp == NULL) {
        printf("ERROR! File not found.\n");
        return 0;
    }

    printf("\nScanning %s for virus signature...\n", infected_file);

    while (fgets(file_signature, sizeof(file_signature), fp) != NULL) {
        if (strstr(file_signature, virus_signature) != NULL) {
            printf("\n\nWARNING! Virus signature detected.\n");
            printf("Deleting %s...\n", infected_file);
            remove(infected_file);
            printf("File deleted.\n");
            return 0;
        }
    }

    printf("\n\nFile is safe. No virus signature detected.\n");

    fclose(fp);
    return 0;
}