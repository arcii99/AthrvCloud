//FormAI DATASET v1.0 Category: File Backup System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_COMMAND_LENGTH 200

int main()
{
    char source_file[MAX_FILENAME_LENGTH];
    char backup_file[MAX_FILENAME_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    
    printf("Enter the name of the file to be backed up (including file extension): ");
    scanf("%s", source_file);
    
    printf("Enter the desired name of the backup file (including file extension): ");
    scanf("%s", backup_file);
    
    // Generate the command to copy the file
    sprintf(command, "cp %s %s", source_file, backup_file);
    
    // Execute the command to copy the file
    system(command);
    
    printf("File backup complete!\n");
    
    return 0;
}