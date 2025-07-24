//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024   // Maximum buffer size to read from the file

// Function to calculate Checksum of a file
unsigned int calculateChecksum(char* filename){
    unsigned int sum = 0;
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "r");     // Open the file in read mode
    if(file == NULL){
        printf("Error: Unable to open file!");
        exit(1);
    }
    
    while(!feof(file)){  // Read the file until end of file
        size_t bytesRead = fread(buffer, 1, BUFFER_SIZE, file);
        for(int i = 0; i < bytesRead; i++){  // Add the bytes to the checksum
            sum += buffer[i];
        }
        if(ferror(file)){   // Check for any error while reading the file
            printf("Error: Unable to read file!");
            exit(1);
        }
    }
    fclose(file);   // Close the file
    return sum;     // Return the calculated checksum
}

int main(){
    char filename[256];
    printf("Enter the name of the file: ");
    fgets(filename, 256, stdin);
    filename[strcspn(filename, "\n")] = 0; // Remove trailing newline character from filename

    unsigned int checksum = calculateChecksum(filename);
    printf("Checksum of file %s is : %u\n", filename, checksum);
    return 0;
}