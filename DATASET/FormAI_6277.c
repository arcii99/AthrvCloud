//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./scanner file_to_scan\n");
        return 1;
    }
    
    char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        return 1;
    }
    
    char token[50];
    int virus_count = 0;
    
    // List of known virus signatures
    char *virus_list[] = {"trojan", "worm", "rootkit", "spyware"};
    
    while (fscanf(file, "%s", token) != EOF) {
        // Check if any of the virus signatures are present in the file
        for (int i = 0; i < sizeof(virus_list) / sizeof(virus_list[0]); i++) {
            if (strstr(token, virus_list[i]) != NULL) {
                printf("Found virus signature: %s\n", virus_list[i]);
                virus_count++;
            }
        }
    }
    
    if (virus_count == 0) {
        printf("No viruses found in file.\n");
    } else {
        printf("%d virus(es) found in file.\n", virus_count);
    }
    
    fclose(file);
    
    return 0;
}