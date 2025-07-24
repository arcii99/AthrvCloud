//FormAI DATASET v1.0 Category: File Backup System ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: backup <filename>\n");
        return 1;
    }

    char *filename = argv[1];
    char backup_filename[MAX_FILENAME_LENGTH];

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    sprintf(backup_filename, "%s_%d-%02d-%02d_%02d-%02d-%02d.bak",
            filename, tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
            tm->tm_hour, tm->tm_min, tm->tm_sec);
    printf("Creating backup file: %s\n", backup_filename);

    FILE *source_file = fopen(filename, "r");
    if (source_file == NULL) {
        printf("Error: unable to open file %s\n", filename);
        return 1;
    }

    FILE *backup_file = fopen(backup_filename, "w");
    if (backup_file == NULL) {
        printf("Error: unable to create backup file %s\n", backup_filename);
        fclose(source_file);
        return 1;
    }

    int c;
    while ((c = fgetc(source_file)) != EOF) {
        fputc(c, backup_file);
    }

    fclose(source_file);
    fclose(backup_file);

    printf("Backup created successfully!\n");
    return 0;
}