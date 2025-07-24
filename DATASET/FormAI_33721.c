//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_SIZE 1000
#define FILENAME "example.c"

// Define functions
void extract_metadata(FILE* fp, char* extracted_metadata);

int main() {
    char extracted_metadata[MAX_SIZE]; // Create a buffer to store the extracted metadata
    FILE* fp = fopen(FILENAME, "r"); // Open the file for reading
    
    if (fp == NULL) { // Check if the file exists
        printf("Error: Unable to open file '%s'\n", FILENAME);
        return 1;
    }
    
    extract_metadata(fp, extracted_metadata); // Extract the metadata from the file
    
    printf("Extracted metadata: %s\n", extracted_metadata); // Output the extracted metadata
    
    fclose(fp); // Close the file
    
    return 0;
}

void extract_metadata(FILE* fp, char* extracted_metadata) {
    char line[MAX_SIZE]; // Create a buffer to store each line of the file
    int metadata_found = 0; // Create a flag to indicate if the metadata has been found
    
    while (fgets(line, MAX_SIZE, fp)) { // Loop through each line of the file
        if (strstr(line, "/*") && strstr(line, "*/")) { // Check if the metadata is on the same line
            metadata_found = 1;
            char* start_of_metadata = strstr(line, "/*") + 2; // Set a pointer to the start of the metadata
            char* end_of_metadata = strstr(line, "*/") - 1; // Set a pointer to the end of the metadata
            strncpy(extracted_metadata, start_of_metadata, end_of_metadata - start_of_metadata + 1); // Copy the metadata to the extracted_metadata buffer
            extracted_metadata[end_of_metadata - start_of_metadata + 1] = '\0'; // Add the null terminator to the end of the extracted_metadata buffer
            break; // Exit the loop
        }
        else if (strstr(line, "/*")) { // Check if the metadata is on a line by itself
            metadata_found = 1;
            do {
                fgets(line, MAX_SIZE, fp); // Keep reading each line until the end of the metadata is found
                if (strstr(line, "*/")) { // Check if the end of the metadata has been found
                    char* end_of_metadata = strstr(line, "*/") - 1; // Set a pointer to the end of the metadata
                    strncpy(extracted_metadata, line, end_of_metadata - line + 1); // Copy the metadata to the extracted_metadata buffer
                    extracted_metadata[end_of_metadata - line + 1] = '\0'; // Add the null terminator to the end of the extracted_metadata buffer
                    break; // Exit the loop
                }
                else {
                    strcat(extracted_metadata, line); // Append the current line to the extracted_metadata buffer
                }
            } while (fgets(line, MAX_SIZE, fp));
            break; // Exit the loop
        }
    }
    
    if (!metadata_found) { // Check if the metadata was not found
        strcpy(extracted_metadata, "No metadata found"); // Set the extracted_metadata buffer to a default message
    }
}