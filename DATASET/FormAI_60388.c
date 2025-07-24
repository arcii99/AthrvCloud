//FormAI DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>

int main() {
    FILE *file_ptr;
    char filename[50], ch;

    // getting filename from user
    printf("Enter filename to create: ");
    scanf("%s", filename);

    // creating file
    file_ptr = fopen(filename, "w");

    if (file_ptr == NULL) {
        printf("Unable to create file\n");
        return 1;
    }

    printf("File created successfully!\n");

    // writing to file
    printf("Enter text to write to file (press Ctrl+D to stop):\n");
    while ((ch = getchar()) != EOF) {
        fputc(ch, file_ptr);
    }

    printf("Data written successfully!\n");

    // closing file
    fclose(file_ptr);

    // opening file for reading and printing contents
    file_ptr = fopen(filename, "r");

    printf("Contents of file:\n");
    while ((ch = fgetc(file_ptr)) != EOF) {
        printf("%c", ch);
    }

    // closing file
    fclose(file_ptr);

    return 0;
}