//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the character buffer size
#define BUFFER_SIZE 256

// Define the metadata structure
typedef struct metadata {
    char artist[BUFFER_SIZE];
    char title[BUFFER_SIZE];
    int year;
} metadata_t;

// Function to extract metadata from file
int extract_metadata(char* filename, metadata_t* mdata) {
    // Declare the file pointer and open the file in binary mode
    FILE* fp = fopen(filename, "rb");
    // Check if file was opened successfully
    if (fp == NULL) {
        return -1;
    }

    // Declare variables to store the line and buffer
    char line[BUFFER_SIZE];
    char buffer[BUFFER_SIZE];

    // Loop through the lines in the file
    while (fgets(line, BUFFER_SIZE, fp)) {
        // Search for the artist tag
        if (strncmp(line, "ARTIST=", 7) == 0) {
            strcpy(buffer, line + 7);
            // Remove any trailing newline characters
            buffer[strcspn(buffer, "\r\n")] = 0;
            strcpy(mdata->artist, buffer);
        }
        // Search for the title tag
        else if (strncmp(line, "TITLE=", 6) == 0) {
            strcpy(buffer, line + 6);
            // Remove any trailing newline characters
            buffer[strcspn(buffer, "\r\n")] = 0;
            strcpy(mdata->title, buffer);
        }
        // Search for the year tag
        else if (strncmp(line, "YEAR=", 5) == 0) {
            strcpy(buffer, line + 5);
            // Convert the year to an integer and store it in the metadata structure
            mdata->year = atoi(buffer);
        }
    }

    // Close the file and return success
    fclose(fp);
    return 0;
}

// Main function to test the metadata extractor
int main(int argc, char** argv) {
    // Declare a metadata structure variable
    metadata_t mdata;

    // Check if the correct number of command line arguments were provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Extract the metadata from the file
    if (extract_metadata(argv[1], &mdata) != 0) {
        printf("Error: could not extract metadata from file.\n");
        return EXIT_FAILURE;
    }

    // Print the extracted metadata
    printf("Artist: %s\nTitle: %s\nYear: %d\n", mdata.artist, mdata.title, mdata.year);

    return EXIT_SUCCESS;
}