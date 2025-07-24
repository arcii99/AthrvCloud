//FormAI DATASET v1.0 Category: File Backup System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the C File Backup System!\n");
    printf("Please enter the name of the file you want to backup: ");

    char filename[100];
    fgets(filename, 100, stdin); // get user input
    filename[strcspn(filename, "\n")] = 0; // remove newline character

    FILE *file;
    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Sorry, couldn't open the file %s.\n", filename);
        printf("Please double check the file name and try again.\n");
        return 1;
    }

    printf("Enter the name for the backup file: ");

    char backup_filename[100];
    fgets(backup_filename, 100, stdin); // get user input
    backup_filename[strcspn(backup_filename, "\n")] = 0; // remove newline character

    printf("Backing up %s...\n", filename);

    // create backup file
    FILE *backup_file;
    backup_file = fopen(backup_filename, "w");

    if (backup_file == NULL) {
        printf("Sorry, couldn't create the backup file %s.\n", backup_filename);
        printf("Please double check the file name and try again.\n");
        fclose(file);
        return 1;
    }

    // copy contents of original file to backup file
    char c = fgetc(file);
    while (c != EOF) {
        fputc(c, backup_file);
        c = fgetc(file);
    }

    printf("Backup created successfully!\n");

    fclose(file);
    fclose(backup_file);

    return 0;
}