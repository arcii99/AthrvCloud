//FormAI DATASET v1.0 Category: File Backup System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void backup_file(char *filename, char *backup_directory) {
    char *backup_filename = malloc(strlen(backup_directory) + strlen(filename) + 2);
    sprintf(backup_filename, "%s/%s", backup_directory, filename);
    FILE *file = fopen(filename, "r");
    FILE *backup_file = fopen(backup_filename, "w");
    if (file != NULL && backup_file != NULL) {
        char c;
        while ((c = fgetc(file)) != EOF) {
            fputc(c, backup_file);
        }
        fclose(file);
        fclose(backup_file);
        printf("%s backed up to %s.\n", filename, backup_filename);
    } else {
        printf("Error backing up %s to %s.\n", filename, backup_filename);
    }
    free(backup_filename);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: backup <filename> <backup_directory>\n");
        exit(1);
    }
    char *filename = argv[1];
    char *backup_directory = argv[2];
    backup_file(filename, backup_directory);
    return 0;
}