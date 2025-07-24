//FormAI DATASET v1.0 Category: File Backup System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void backup_file(char *filename)
{
    time_t rawtime;
    struct tm *timeinfo;
    char file_backup[100];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(file_backup, sizeof(file_backup), "%Y-%m-%d_%H:%M:%S", timeinfo);

    char command[100];
    sprintf(command, "cp %s %s_%s.bak", filename, filename, file_backup);
    system(command);

    printf("Backup created for: %s\n", filename);
}

int main(int argc, char *argv[])
{
    if (argc <= 1) {
        printf("Usage: program_name file1 file2 fileN\n");
        return 1;
    }

    for(int i=1; i < argc; i++) {
        backup_file(argv[i]);
    }

    return 0;
}