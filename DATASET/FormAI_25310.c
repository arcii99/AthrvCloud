//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[]) {
    if (argc != 2) { // Check if user provided a file name
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE * file = fopen(argv[1], "r"); // Open the file for reading
    if (file == NULL) { // Check if the file could be opened
        printf("%s could not be opened\n", argv[1]);
        return 1;
    }

    char buffer[1024]; // A buffer to store data from the file
    int virusFound = 0; // Flag to indicate if a virus is found

    while (fgets(buffer, sizeof(buffer), file)) { // Read line by line
        if (strstr(buffer, "virus")) { // Check for a virus string
            printf("%s contains a virus!\n", argv[1]);
            virusFound = 1;
            break;
        }
    }

    fclose(file); // Close the file

    if (!virusFound) { // If no virus is found
        printf("%s is clean\n", argv[1]);
    }

    return 0;
}