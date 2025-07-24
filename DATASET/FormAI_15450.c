//FormAI DATASET v1.0 Category: File Backup System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("***WARNING***\n");
    printf("This is not a drill! Backup system initiated.\n");

    // Prompt user for source file name
    char source_file[100];
    printf("Enter source file name: ");
    scanf("%s", source_file);

    // Prompt user for backup directory name
    char backup_dir[200];
    printf("Enter backup directory: ");
    scanf("%s", backup_dir);

    // Create backup file name by appending current date and time
    char datetime[30];
    time_t now;
    time(&now);
    strftime(datetime, sizeof(datetime), "_%m_%d_%Y_%H_%M_%S", localtime(&now));
    char backup_file[330];
    strcpy(backup_file, backup_dir);
    strcat(backup_file, "/");
    char source_file_name[100];
    char *p = strrchr(source_file, '/');
    if (p == NULL) {
        strcpy(source_file_name, source_file);
    } else {
        strcpy(source_file_name, p + 1);
    }
    strcat(backup_file, source_file_name);
    strcat(backup_file, datetime);

    // Open source file for reading
    FILE *source_fp = fopen(source_file, "rb");
    if (source_fp == NULL) {
        printf("ERROR: Unable to open source file.\n");
        return 1;
    }

    // Create backup file
    FILE *backup_fp = fopen(backup_file, "wb");
    if (backup_fp == NULL) {
        printf("ERROR: Unable to create backup file.\n");
        return 1;
    }

    // Copy source file to backup file byte by byte
    int c;
    while ((c = fgetc(source_fp)) != EOF) {
        fputc(c, backup_fp);
    }

    // Cleanup
    fclose(source_fp);
    fclose(backup_fp);

    printf("Backup done successfully!\n");
    printf("File '%s' backed up as '%s'\n", source_file, backup_file);

    return 0;
}