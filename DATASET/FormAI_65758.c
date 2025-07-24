//FormAI DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>

int main() {

    // Ask user for a file name
    char file_name[50];
    printf("Please enter the name of the file you want to create: ");
    scanf("%s", file_name);
    printf("\n");

    // Open the file in write mode
    FILE *fp = fopen(file_name, "w");

    if (fp == NULL) {
        // If file could not be opened, ask user for another file name
        printf("Could not open file. Please enter a different file name: ");
        scanf("%s", file_name);
        printf("\n");

        // Attempt to open file again
        fp = fopen(file_name, "w");

        if (fp == NULL) {
            // If file still cannot be opened, terminate program
            printf("Could not open file. Program terminated.\n");
            return 1;
        }
    }

    // Ask user for a message to write to the file
    char message[100];
    printf("Please enter the message you want to write to the file: ");
    scanf("%s", message);
    printf("\n");

    // Write message to file
    fprintf(fp, "%s", message);

    // Close file
    fclose(fp);

    // Inform user that message has been written to file
    printf("Message \"%s\" has been written to file \"%s\".\n", message, file_name);

    return 0;
}