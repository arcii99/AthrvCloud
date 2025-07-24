//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: random
#include <stdio.h>
#include <string.h>

int main() {
    char file[100];
    printf("Enter the filename to scan: ");
    scanf("%s", file);
    
    char extension[10];
    int i = strlen(file) - 1;
    while (i >= 0 && file[i] != '.') {
        i--;
    }
    if (i == -1) {
        printf("Error: File has no extension.\n");
        return 0;
    }
    strcpy(extension, file + i + 1);
    
    if (strcmp(extension, "exe") != 0) {
        printf("File is not executable.\n");
        return 0;
    }
    
    printf("Scanning file...\n\n");
    
    FILE* fp = fopen(file, "rb");
    if (fp == NULL) {
        printf("Error: File could not be opened.\n");
        return 0;
    }
    
    int virus_found = 0;
    char virus_signature[] = "CVir";
    char buffer[5];
    while (fread(buffer, 1, 4, fp) == 4) {
        buffer[4] = '\0';
        if (strcmp(buffer, virus_signature) == 0) {
            printf("Virus detected!\n");
            virus_found = 1;
            break;
        }
    }
    fclose(fp);
    if (!virus_found) {
        printf("No viruses found.\n");
    }
    return 0;
}