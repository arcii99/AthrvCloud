//FormAI DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if(argc != 3) {
        printf("Usage: %s <file_to_backup> <backup_file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *file_to_backup = argv[1];
    char *backup_file_path = argv[2];
    
    char backup_file_name[strlen(file_to_backup)+10];
    sprintf(backup_file_name, "%s.bak", file_to_backup);
    
    char buffer[BUFFER_SIZE];
    size_t nread;
    
    FILE *original_file = fopen(file_to_backup, "r");
    if(original_file == NULL) {
        printf("Error: unable to open file \"%s\".\n", file_to_backup);
        exit(EXIT_FAILURE);
    }
    
    FILE *backup_file = fopen(backup_file_name, "w");
    if(backup_file == NULL) {
        printf("Error: unable to create backup file \"%s\".\n", backup_file_name);
        fclose(original_file);
        exit(EXIT_FAILURE);
    }
    
    while((nread = fread(buffer, 1, BUFFER_SIZE, original_file)) > 0) {
        fwrite(buffer, 1, nread, backup_file);
    }
    
    fclose(original_file);
    fclose(backup_file);
    
    printf("File %s successfully backed up to %s\n", file_to_backup, backup_file_path);
    
    return 0;
}