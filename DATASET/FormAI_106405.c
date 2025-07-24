//FormAI DATASET v1.0 Category: File Backup System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Happy File Backup System!\n");
    printf("This program will allow you to backup your important files with ease.\n");

    char source[50];
    char destination[50];

    printf("Please enter the name of the file you want to backup: ");
    scanf("%s", source);

    FILE *file = fopen(source, "r");
    if (file == NULL) {
        printf("Could not open file. Please try again.\n");
        return 1;
    }

    printf("Please enter the name of the backup file: ");
    scanf("%s", destination);

    FILE *backup = fopen(destination, "w");
    if (backup == NULL) {
        printf("Could not create backup file. Please try again.\n");
        return 1;
    }

    char buffer[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup);
    }

    printf("Backup successful! Your file has been saved as %s.\n", destination);

    fclose(file);
    fclose(backup);

    return 0;
}