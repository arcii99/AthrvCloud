//FormAI DATASET v1.0 Category: Metadata Extractor ; Style: unmistakable
#include <stdio.h>
#include <string.h>

// Define the maximum length of meta data elements
#define MAX_LENGTH 100

// Define a struct to store the extracted meta data
typedef struct {
    char title[MAX_LENGTH];
    char author[MAX_LENGTH];
    char date[MAX_LENGTH];
} Metadata;

// Extract the meta data from a given file and store it in the Metadata struct
Metadata extract_metadata(char* filename) {
    // Open the file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Initialize the metadata struct with empty strings
    Metadata metadata;
    memset(metadata.title, 0, MAX_LENGTH);
    memset(metadata.author, 0, MAX_LENGTH);
    memset(metadata.date, 0, MAX_LENGTH);

    // Read each line of the file and look for meta data elements
    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, file)) {
        // Check if the line contains a title element
        if (strncmp(line, "Title:", 6) == 0) {
            strncpy(metadata.title, line + 7, MAX_LENGTH - 1);
            metadata.title[strcspn(metadata.title, "\n")] = 0;
        }

        // Check if the line contains an author element
        if (strncmp(line, "Author:", 7) == 0) {
            strncpy(metadata.author, line + 8, MAX_LENGTH - 1);
            metadata.author[strcspn(metadata.author, "\n")] = 0;
        }

        // Check if the line contains a date element
        if (strncmp(line, "Date:", 5) == 0) {
            strncpy(metadata.date, line + 6, MAX_LENGTH - 1);
            metadata.date[strcspn(metadata.date, "\n")] = 0;
        }
    }

    // Close the file
    fclose(file);

    // Return the extracted meta data
    return metadata;
}

int main() {
    // Define the filename of the file to extract meta data from
    char filename[MAX_LENGTH] = "example.txt";

    // Extract the meta data from the file
    Metadata metadata = extract_metadata(filename);

    // Print the extracted meta data to the console
    printf("Title: %s\n", metadata.title);
    printf("Author: %s\n", metadata.author);
    printf("Date: %s\n", metadata.date);

    // Exit the program successfully
    return 0;
}