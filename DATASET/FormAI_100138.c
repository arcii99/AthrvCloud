//FormAI DATASET v1.0 Category: File Backup System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_SIZE 128

void backup(char* original_file, char* backup_file)
{
    FILE* source = fopen(original_file, "r");
    FILE* backup = fopen(backup_file, "w");
    char ch;
    while((ch = fgetc(source)) != EOF)
    {
        fputc(ch, backup);
    }
    fclose(backup);
    fclose(source);
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printf("Usage: backup <original file>\n");
        return -1;
    }

    char file_name[MAX_SIZE];
    char backup_file[MAX_SIZE];
    strcpy(file_name, argv[1]);
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(backup_file, "%d-%d-%d_%d:%d:%d_%s", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec, file_name);
    printf("Backing up %s to %s...\n", file_name, backup_file);
    backup(file_name, backup_file);
    printf("Backup complete.\n");
    return 0;
}