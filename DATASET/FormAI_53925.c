//FormAI DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BACKUP_COUNT 5

void backup(char* filename);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    backup(argv[1]);

    return 0;
}

void backup(char* filename) {
    char backup_filename[MAX_BACKUP_COUNT][MAX_FILENAME_LENGTH];
    int i;

    for (i = 0; i < MAX_BACKUP_COUNT; i++) {
        sprintf(backup_filename[i], "%s.backup.%d", filename, i+1);
    }

    for (i = MAX_BACKUP_COUNT-2; i >= 0; i--) {
        char source[MAX_FILENAME_LENGTH];
        char dest[MAX_FILENAME_LENGTH];

        sprintf(source, "%s.backup.%d", filename, i);
        sprintf(dest, "%s.backup.%d", filename, i+1);

        rename(source, dest);
    }

    rename(filename, backup_filename[0]);

    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    char buffer[100];
    time_t now = time(NULL);
    strftime(buffer, 100, "%c", localtime(&now));
    fprintf(file, "Backup created on %s\n", buffer);

    fclose(file);
}