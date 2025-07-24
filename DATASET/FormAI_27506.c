//FormAI DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>

int main() {
    FILE *original_file, *backup_file;
    char original_file_name[100], backup_file_name[100], c;

    printf("Enter the name of the file you want to backup: ");
    scanf("%s", original_file_name);

    // open the original file
    original_file = fopen(original_file_name, "r");

    if (original_file == NULL) {
        printf("Error: File does not exist.\n");
        return 1;
    }

    // create the backup file
    sprintf(backup_file_name, "%s.bak", original_file_name);
    backup_file = fopen(backup_file_name, "w");

    if (backup_file == NULL) {
        printf("Error: Unable to create backup file.\n");
        return 1;
    }

    // copy the content from original file to backup file
    while ((c = fgetc(original_file)) != EOF) {
        fputc(c, backup_file);
    }

    // close the files
    fclose(original_file);
    fclose(backup_file);

    printf("File backup successful!\n");

    return 0;
}