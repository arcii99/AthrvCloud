//FormAI DATASET v1.0 Category: File Backup System ; Style: modular
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function to backup one file
void backup_file(char *filename) {
    FILE *source = fopen(filename, "r");
    if (source == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char backup_filename[strlen(filename) + 9];
    sprintf(backup_filename, "%s.bak", filename);

    FILE *backup = fopen(backup_filename, "w");
    if (backup == NULL) {
        printf("Error creating backup file!\n");
        fclose(source);
        return;
    }

    char c;
    while ((c = fgetc(source)) != EOF) {
        fputc(c, backup);
    }

    fclose(source);
    fclose(backup);
    printf("File %s backed up to %s\n", filename, backup_filename);
}

// Function to backup multiple files
void backup_files(char **filenames, int num_files) {
    for (int i = 0; i < num_files; i++) {
        backup_file(filenames[i]);
    }
}

// Main function
int main() {
    char *filenames[] = {"file1.txt", "file2.txt", "file3.txt"};
    backup_files(filenames, 3);
    return 0;
}