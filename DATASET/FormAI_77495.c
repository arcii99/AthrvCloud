//FormAI DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>

int main() {
    FILE * file_ptr;
    char file_name[50];
    char content[100];

    // Getting file name from the user
    printf("Enter the file name: ");
    scanf("%s", file_name);

    // Opening file and checking if it exists
    file_ptr = fopen(file_name, "r");
    if(file_ptr == NULL) {
        printf("File does not exist.\n");
        return -1;
    }

    // Reading content from file and printing to console
    fscanf(file_ptr, "%[^\n]", content);
    printf("Content in file '%s':\n%s\n", file_name, content);
    fclose(file_ptr);

    // Writing content to file
    file_ptr = fopen(file_name, "a");
    if(file_ptr == NULL) {
        printf("Error in opening file.\n");
        return -1;
    }

    printf("Enter the text to write in file: ");
    fflush(stdin);
    fgets(content, 100, stdin);
    fputs(content, file_ptr);
    fclose(file_ptr);

    printf("Content written to file successfully.\n");
    return 0;
}