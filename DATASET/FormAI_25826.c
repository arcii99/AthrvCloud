//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: grateful
#include <stdio.h>
#include <string.h>

// Define the size of the metadata array
#define METADATA_SIZE 100

// Define the size of the file buffer
#define BUFFER_SIZE 1000000

// Define the metadata struct
typedef struct {
    char name[50];
    char value[50];
} Metadata;

// Define the metadata array
Metadata metadata[METADATA_SIZE];

// Define the number of metadata items in the array
int num_metadata = 0;

// Define the file buffer
char buffer[BUFFER_SIZE];

// Define the file length
int file_length = 0;

// Define the metadata extractor function
void metadata_extractor(char* file_name) {
    // Open the file in read mode
    FILE* fp = fopen(file_name, "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    // Read the file into the buffer
    fread(buffer, BUFFER_SIZE, 1, fp);
    // Get the file length
    file_length = strlen(buffer);
    // Close the file
    fclose(fp);

    // Loop through the buffer to find metadata items
    int i = 0;
    while(i < file_length) {
        // Check if the current character is a metadata start character
        if(buffer[i] == '<' && buffer[i+1] == '!' && buffer[i+2] == '-' && buffer[i+3] == '-') {
            // Move the pointer to the end of the metadata start characters
            i += 4;
            int j = 0;
            // Loop through the buffer to read the metadata name
            while(buffer[i] != ':') {
                metadata[num_metadata].name[j] = buffer[i];
                i++;
                j++;
            }
            metadata[num_metadata].name[j] = '\0';
            // Move the pointer to the metadata value
            i++;
            j = 0;
            // Loop through the buffer to read the metadata value
            while(buffer[i] != '-' || buffer[i+1] != '-' || buffer[i+2] != '>') {
                metadata[num_metadata].value[j] = buffer[i];
                i++;
                j++;
            }
            metadata[num_metadata].value[j] = '\0';
            // Increment the number of metadata items
            num_metadata++;
            // Move the pointer to the end of the metadata end characters
            i += 3;
        }
        i++;
    }
}

int main() {
    // Call the metadata extractor function with the file name
    metadata_extractor("example.html");
    // Print the metadata items
    for(int i = 0; i < num_metadata; i++) {
        printf("%s: %s\n", metadata[i].name, metadata[i].value);
    }

    return 0;
}