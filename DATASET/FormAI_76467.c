//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: authentic
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char** argv) {
    char buffer[MAX_BUFFER_SIZE]; // Used to store file data
    FILE *fp; // Pointer to file object
    int virus_found = 0; // Flag to indicate virus found or not 

    // Check if program is run with file name as argument
    if (argc < 2) {
        printf("Please provide a file name\n");
        return 1;
    }

    // Open file for reading
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Cannot open file: %s\n", argv[1]);
        return 1;
    }

    // Read file data into buffer
    fread(buffer, MAX_BUFFER_SIZE, 1, fp);

    // Close file
    fclose(fp);

    // Check for virus signature in file data
    if (strstr(buffer, "virus") != NULL) {
        printf("Virus found in file: %s\n", argv[1]);
        virus_found = 1;
    }

    // Display result
    if (!virus_found) {
        printf("No virus found in file: %s\n", argv[1]);
    }

    return 0;
}