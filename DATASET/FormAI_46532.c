//FormAI DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>

int main() {
    // Welcome message to the user
    printf("Welcome to the File Backup System!\n\n");

    // Ask the user for the file name that needs to be backed up
    char file_name[20];
    printf("Please enter the name of the file that needs to be backed up: ");
    scanf("%s", file_name);

    // Open the existing file
    FILE *file_pointer;
    file_pointer = fopen(file_name, "r");

    // If the file does not exist, it cannot be backed up
    if (file_pointer == NULL) {
        printf("\nError: The file '%s' does not exist.\n", file_name);
        return 0;
    }

    // Create a new file for the backup and copy the contents of the original file to it
    FILE *backup_file_pointer;
    backup_file_pointer = fopen("backup.txt", "w");

    // Copy the contents of the original file to the backup file
    char c;
    while ((c = fgetc(file_pointer)) != EOF) {
        fputc(c, backup_file_pointer);
    }

    // Success message
    printf("\nSuccess: The file '%s' has been backed up as 'backup.txt'.\n", file_name);

    // Close the file pointers
    fclose(file_pointer);
    fclose(backup_file_pointer);

    return 0;
}