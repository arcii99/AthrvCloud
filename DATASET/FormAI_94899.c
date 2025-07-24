//FormAI DATASET v1.0 Category: File Backup System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_BACKUP_COUNT 10

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    time_t timestamp;
} backup_file;

backup_file backups[MAX_BACKUP_COUNT];
int backup_count = 0;

void add_backup(char* filename) {
    if (backup_count == MAX_BACKUP_COUNT) {
        printf("Error: Maximum number of backups reached\n");
        return;
    }
    backup_file backup;
    strcpy(backup.filename, filename);
    backup.timestamp = time(NULL);
    backups[backup_count++] = backup;
    printf("Backup created for %s at %s", filename, ctime(&(backup.timestamp)));
}

int main() {

    char input[MAX_FILENAME_LENGTH];
    printf("Enter filename to backup:\n");
    scanf("%s", input);

    add_backup(input);

    return 0;
}