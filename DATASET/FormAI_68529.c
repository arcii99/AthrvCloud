//FormAI DATASET v1.0 Category: File Backup System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES   1000    // Maximum number of lines in the file
#define MAX_LENGTH  100     // Maximum length of each line in the file

int main()
{
    char original_file[MAX_LINES][MAX_LENGTH], backup_file[MAX_LINES][MAX_LENGTH];
    int num_lines, i, j;
    
    // Get the original file
    printf("Enter the original file:\n");
    for (i = 0; i < MAX_LINES; i++)
    {
        fgets(original_file[i], MAX_LENGTH, stdin);
        if (original_file[i][0] == '\n')    // End of input
            break;
    }
    num_lines = i;
    
    // Create the backup file
    printf("Creating the backup file...\n");
    for (i = 0; i < num_lines; i++)
    {
        for (j = 0; j < MAX_LENGTH; j++)
        {
            backup_file[i][j] = original_file[i][j] ^ (i + j);
        }
    }
    
    // Save the backup file
    FILE *fp;
    fp = fopen("backup_file.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }
    for (i = 0; i < num_lines; i++)
    {
        fputs(backup_file[i], fp);
    }
    fclose(fp);
    
    // Verify the backup file
    printf("Verifying the backup file...\n");
    fp = fopen("backup_file.txt", "r");
    if (fp == NULL)
    {
        printf("Error opening the file.\n");
        return 1;
    }
    for (i = 0; i < num_lines; i++)
    {
        fgets(backup_file[i], MAX_LENGTH, fp);
        for (j = 0; j < MAX_LENGTH; j++)
        {
            if (backup_file[i][j] != (original_file[i][j] ^ (i + j)))
            {
                printf("Error verifying the backup file.\n");
                return 1;
            }
        }
    }
    fclose(fp);
    
    printf("Backup file successfully created and verified.\n");
    return 0;
}