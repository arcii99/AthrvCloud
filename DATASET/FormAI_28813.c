//FormAI DATASET v1.0 Category: File Backup System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256

int main()
{
    char filename[MAX_FILENAME_LENGTH];
    char backup_filename[MAX_FILENAME_LENGTH];
    FILE *fp, *fp_backup;
    char ch;

    printf("Enter the filename to backup: ");
    scanf("%s", filename);
    
    /* Create backup filename */
    strcpy(backup_filename, filename);
    strcat(backup_filename, ".bak");
    
    /* Open original file */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Unable to open file '%s'\n", filename);
        return -1;
    }
    
    /* Open backup file */
    fp_backup = fopen(backup_filename, "w");
    if (fp_backup == NULL) {
        printf("Error: Unable to create backup file '%s'\n", backup_filename);
        return -1;
    }
    
    /* Copy contents of original file to backup file */
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch, fp_backup);
    }
    
    printf("Backup created successfully!\n");
    
    /* Close files */
    fclose(fp);
    fclose(fp_backup);
    
    return 0;
}