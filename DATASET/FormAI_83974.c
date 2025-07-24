//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_virus(char *file_name) {
    FILE *file;
    char virus_signature[100];
    int infected = 0;
    // Read virus signature from virus definition file
    if ((file = fopen("virus_definition.txt", "r")) != NULL) {
        while (fgets(virus_signature, sizeof(virus_signature), file)) {
            // Remove newline character from signature
            virus_signature[strcspn(virus_signature, "\r\n")] = 0;
            // Check if virus signature is present in file
            if (strstr(file_name, virus_signature)) {
                printf("Infected: %s\n", file_name);
                infected = 1;
                break;
            }
        }
        fclose(file);
    }
    return infected;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }
    int infected = check_virus(argv[1]);
    if (!infected) {
        printf("File is clean\n");
    }
    return 0;
}