//FormAI DATASET v1.0 Category: File Backup System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void backup_file(char* filename);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s file_name\n", argv[0]);
        return 1;
    }
    backup_file(argv[1]);
    return 0;
}

void backup_file(char* filename) {
    FILE* original = fopen(filename, "r");
    if (original == NULL) {
        printf("Unable to open file %s\n", filename);
        return;
    }
    char* backup_filename = malloc(strlen(filename) + 5);
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
    FILE* backup = fopen(backup_filename, "w");
    if (backup == NULL) {
        printf("Unable to create backup file %s\n", backup_filename);
        fclose(original);
        free(backup_filename);
        return;
    }
    char buffer[4096];
    size_t read_chars;
    do {
        read_chars = fread(buffer, 1, sizeof(buffer), original);
        if (read_chars > 0) {
            fwrite(buffer, 1, read_chars, backup);
        }
    } while (read_chars == sizeof(buffer));
    fclose(original);
    fclose(backup);
    free(backup_filename);
    printf("Backup of file %s created as %s\n", filename, backup_filename);
}