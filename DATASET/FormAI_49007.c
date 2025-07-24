//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: calm
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024 // Maximum buffer size for reading file

int main(int argc, char *argv[]) {
    
    if (argc != 2) { // Check argument count
        printf("Usage: %s [filename]\n", argv[0]);
        return 1;
    }
    
    FILE *file = fopen(argv[1], "rb"); // Open file for reading in binary mode
    
    if (!file) { // Check if the file exists
        printf("Could not open file: %s\n", argv[1]);
        return 1;
    }
    
    char virus_signature[] = "csgod.dll"; // Virus signature to check against
    
    size_t virus_signature_len = strlen(virus_signature); // Get virus signature length
    
    char buffer[MAX_BUFFER_SIZE]; // Buffer to read file data into
    
    size_t bytes_read; // Bytes read from file
    
    while ((bytes_read = fread(buffer, 1, MAX_BUFFER_SIZE, file)) > 0) { // Read file in chunks
        
        for (size_t i = 0; i < bytes_read - virus_signature_len; i++) {
            
            if (memcmp(&buffer[i], virus_signature, virus_signature_len) == 0) { // Check for virus signature
                
                printf("Virus detected: %s found in %s\n", virus_signature, argv[1]);
                
                fclose(file);
                
                return 0;
            }
        }
    }
    
    printf("No virus detected in %s\n", argv[1]);
    
    fclose(file);
    
    return 0;
}