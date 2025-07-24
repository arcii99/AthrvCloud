//FormAI DATASET v1.0 Category: File Backup System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char filename[255], backupFilename[255], backupDirectory[255], command[500];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int fileLen = strlen(filename);

    //Get the filename to backup
    printf("Enter filename to backup:\n");
    fgets(filename, sizeof(filename), stdin);
    filename[fileLen - 1] = '\0';

    //Get the backup directory where the backup file should be stored
    printf("Enter backup directory:\n");
    fgets(backupDirectory, sizeof(backupDirectory), stdin);
    backupDirectory[strlen(backupDirectory) - 1] = '\0';

    //Create the backup filename
    sprintf(backupFilename, "%s_backup_%d-%02d-%02d_%02d-%02d-%02d.txt", filename, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

    //Create the backup command and execute it
    sprintf(command, "cp %s %s/%s", filename, backupDirectory, backupFilename);
    system(command);

    printf("Backup created successfully!\n");

    return 0;
}