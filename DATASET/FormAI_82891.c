//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 10000

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }
    
    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        printf("Failed to open file %s\n", argv[1]);
        return 1;
    }
    
    // Read the file into a buffer
    char buffer[MAX_FILE_SIZE];
    int file_size = 0;
    while (!feof(file) && file_size < MAX_FILE_SIZE) {
        buffer[file_size] = fgetc(file);
        ++file_size;
    }
    fclose(file);
    
    // Search for virus signature in buffer
    char* virus_signature = "29a";
    int virus_signature_length = strlen(virus_signature);
    
    for(int i = 0; i < file_size - virus_signature_length; i++) {
        int found_virus = 1;
        for (int j = 0; j < virus_signature_length; j++) {
            if (buffer[i+j] != virus_signature[j]) {
                found_virus = 0;
                break;
            }
        }
        if (found_virus) {
            printf("Virus detected!\n");
            return 0;
        }
    }
    
    // If control reaches here, no virus was detected
    printf("No virus detected.\n");
    return 0;
}