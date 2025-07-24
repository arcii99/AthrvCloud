//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Linus Torvalds
#include <stdio.h>

// Function to parse the resume
void parseResume(char* filename) {

    // Open the file
    FILE* fp = fopen(filename, "r");

    // Check if the file opened successfully
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        return;
    }

    // Loop through each line in the file
    char line[256];
    while (fgets(line, sizeof(line), fp)) {

        // Split the line by commas
        char* token = strtok(line, ",");
        while (token != NULL) {

            // Check if the token contains relevant information
            if (strstr(token, "Name") != NULL) {
                printf("Name: %s\n", token + 5);
            }
            else if (strstr(token, "Email") != NULL) {
                printf("Email: %s\n", token + 6);
            }
            else if (strstr(token, "Phone") != NULL) {
                printf("Phone: %s\n", token + 6);
            }

            // Move to the next token
            token = strtok(NULL, ",");
        }
    }

    // Close the file
    fclose(fp);
}

int main() {

    // Parse the example resume file
    parseResume("example_resume.txt");

    return 0;
}