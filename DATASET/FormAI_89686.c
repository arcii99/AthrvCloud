//FormAI DATASET v1.0 Category: File handling ; Style: energetic
#include <stdio.h>

int main() {
    char filename[50];
    char content[100];

    // Get the filename from the user
    printf("Enter the filename to create: ");
    scanf("%s", filename);

    // Create and open the file with write permissions
    FILE *file_ptr = fopen(filename, "w");

    // Check if file was successfully created/opened
    if (file_ptr == NULL) {
        printf("Error creating file!");
        return 1;
    }

    // Get content to write to the file from the user
    printf("\nEnter the content to write to the file: ");
    scanf("%s", content);

    // Write the content to the file
    fprintf(file_ptr, "%s", content);

    // Close the file once writing is complete
    fclose(file_ptr);

    printf("\nFile created and content written successfully!");

    return 0;
}