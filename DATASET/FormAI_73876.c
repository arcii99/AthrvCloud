//FormAI DATASET v1.0 Category: File Backup System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void backup_file(char *filename) {
    char backup_filename[strlen(filename) + 5];  // Adding "bak" suffix
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");

    FILE *original_file = fopen(filename, "r");
    if(original_file == NULL) {
        printf("Error: Cannot open file '%s' for reading!\n", filename);
        return;
    }

    FILE *backup_file = fopen(backup_filename, "w");
    if(backup_file == NULL) {
        printf("Error: Cannot create backup file '%s'!\n", backup_filename);
        fclose(original_file);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while((bytes_read = fread(buffer, 1, BUFFER_SIZE, original_file)) > 0) {
        fwrite(buffer, 1, bytes_read, backup_file);
    }

    fclose(original_file);
    fclose(backup_file);

    printf("Backup successful! Original file '%s' is now saved as '%s'\n", filename, backup_filename);
}

int main() {
    char filename[100];
    printf("Enter filename: ");
    fgets(filename, 100, stdin);
    filename[strcspn(filename, "\n")] = 0;  // Removing newline character if present

    backup_file(filename);

    return 0;
}