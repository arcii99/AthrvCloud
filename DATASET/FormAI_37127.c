//FormAI DATASET v1.0 Category: File handling ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_pointer;
    char file_name[40], file_content[200];

    // get file name from user
    printf("Enter the name of the file: ");
    scanf("%s", file_name);

    // open file in write mode
    file_pointer = fopen(file_name, "w");

    if (file_pointer == NULL) {
        printf("Error creating file!");
        exit(EXIT_FAILURE);
    }

    // get file content
    printf("\nEnter the content to be written: ");
    scanf(" %[^\n]s", file_content);

    // write content to file
    fputs(file_content, file_pointer);

    // close file
    fclose(file_pointer);

    // open file in read mode and display content
    file_pointer = fopen(file_name, "r");

    if (file_pointer == NULL) {
        printf("Error reading file!");
        exit(EXIT_FAILURE);
    }

    printf("\nContents of %s:\n", file_name);
    char r = fgetc(file_pointer);
    while (r != EOF) {
        printf("%c", r);
        r = fgetc(file_pointer);
    }

    fclose(file_pointer);

    return 0;
}