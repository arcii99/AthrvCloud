//FormAI DATASET v1.0 Category: File Backup System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*The following code is a C File Backup System program that uses surrealist style*/

int main()
{
    char source[256], backup[256], filelist[][256] = {"file1.c", "file2.c", "file3.c", "file4.c"}; /*list of files to be backed up*/
    int i, filecount = 4; /*count of files to be backed up*/

    printf("Welcome to the Surrealist File Backup System!\n");

    /*get source and backup folder names*/
    printf("Please enter the name of the folder to be backed up: ");
    fgets(source, 256, stdin);
    source[strcspn(source, "\n")] = 0; /*remove newline*/
    printf("Please enter the name of the backup folder: ");
    fgets(backup, 256, stdin);
    backup[strcspn(backup, "\n")] = 0;

    /*create backup folder if it doesn't exist*/
    int exist = system("mkdir -p backup");
    if (exist == -1)
    {
        printf("Oops, something went wrong. Unable to create backup folder.\n");
        return 1;
    }

    /*backup each file*/
    for (i = 0; i < filecount; i++)
    {
        char command[256];
        sprintf(command, "cp \"%s/%s\" \"%s/%s-backup\"", source, filelist[i], backup, filelist[i]);
        printf("Backing up file %s...\n", filelist[i]);
        int result = system(command);
        if (result == -1)
        {
            printf("Oops, something went wrong. Unable to backup file %s.\n", filelist[i]);
        }
        else
        {
            printf("File %s backed up successfully!\n", filelist[i]);
        }
    }

    printf("All files backed up successfully. Thank you for using the Surrealist File Backup System!\n");

    return 0;
}