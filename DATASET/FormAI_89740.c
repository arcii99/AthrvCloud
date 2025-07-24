//FormAI DATASET v1.0 Category: File handling ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main()
{
    char *filename = "data.txt";
    FILE *file = fopen(filename, "r+");
    char buffer[BUFFER_SIZE], modify[BUFFER_SIZE];

    if (file == NULL)
    {
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    // Read data from file
    fgets(buffer, BUFFER_SIZE, file);
    printf("File content before modification:\n%s", buffer);

    // Modify data
    printf("Enter new data:\n");
    fgets(modify, BUFFER_SIZE, stdin);
    fseek(file, 0, SEEK_SET); // Move file pointer to beginning of file
    fwrite(modify, sizeof(char), strlen(modify), file);

    // Write modified data back to file
    fseek(file, 0, SEEK_SET); // Move file pointer to beginning of file
    fgets(buffer, BUFFER_SIZE, file); // Clear current buffer contents
    fgets(buffer, BUFFER_SIZE, file); // Read modified data into buffer
    printf("File content after modification:\n%s", buffer);

    // Close file
    fclose(file);

    return 0;
}