//FormAI DATASET v1.0 Category: File handling ; Style: Alan Touring
#include <stdio.h>

int main() {
    FILE *file_pointer;
    char filename[25], content[100];

    printf("Enter the file name: ");
    scanf("%s", filename);

    file_pointer = fopen(filename, "w");

    if (file_pointer == NULL) {
        printf("Error opening file.");
        return 0;
    }

    printf("Enter content to write to file: ");
    scanf(" %[^\n]", content);

    fprintf(file_pointer, "%s", content);

    fclose(file_pointer);

    printf("Content has been written to the file successfully.\n");

    return 0;
}