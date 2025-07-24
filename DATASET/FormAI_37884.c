//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Welcome message
    printf("Welcome to the C Antivirus Scanner!\n");

    // Ask user for input file name
    char file_name[100];
    printf("Enter the file name to scan: ");
    scanf("%s", file_name);

    // Check if file exists
    FILE *fp = fopen(file_name, "r");
    if (fp == NULL) {
        printf("The file does not exist!\n");
        return 0;
    }
    fclose(fp);

    // Scan file for viruses
    printf("Scanning file for viruses...\n");
    char virus_signature[] = "W32/NotAVirus";
    char buffer[100];
    fp = fopen(file_name, "r");
    while (fgets(buffer, 100, fp)) {
        if (strstr(buffer, virus_signature)) {
            printf("Virus detected! File is not safe.\n");
            fclose(fp);
            return 0;
        }
    }
    fclose(fp);

    // File is safe
    printf("File is safe. No virus detected.\n");

    return 0;
}