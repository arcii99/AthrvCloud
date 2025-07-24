//FormAI DATASET v1.0 Category: File Backup System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_COUNT 10 // maximum number of backups to keep for each file

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char backup_time[20];
} Backup;

int main() {
    char input[MAX_FILENAME_LENGTH];
    Backup backups[MAX_BACKUP_COUNT];
    int backup_count = 0;

    printf("Enter the name of a file to backup: ");
    fgets(input, MAX_FILENAME_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    // check if file exists
    FILE *fptr = fopen(input, "r");
    if (fptr == NULL) {
        printf("Error: File '%s' does not exist.\n", input);
        return 1;
    }
    fclose(fptr);

    // create backup filename
    char backup_filename[MAX_FILENAME_LENGTH];
    time_t current_time;
    time(&current_time);
    strftime(backup_filename, sizeof(backup_filename), "%Y-%m-%d_%H-%M-%S", localtime(&current_time));
    strcat(backup_filename, "_backup");

    // copy file to backup file
    char command[MAX_FILENAME_LENGTH*2];
    sprintf(command, "cp '%s' '%s'", input, backup_filename);
    system(command);

    // add backup to list of backups for file
    strcpy(backups[backup_count].filename, input);
    strcpy(backups[backup_count].backup_time, backup_filename);
    backup_count++;

    printf("File '%s' backed up as '%s'.\n", input, backup_filename);

    // display list of backups for file
    printf("\nList of backups for file '%s':\n", input);
    for (int i = 0; i < backup_count; i++) {
        if (strcmp(backups[i].filename, input) == 0) {
            printf("%s\n", backups[i].backup_time);
        }
    }

    // limit number of backups per file to MAX_BACKUP_COUNT
    if (backup_count > MAX_BACKUP_COUNT) {
        int count = 0;
        for (int i = backup_count - 1; i >= 0; i--) {
            if (strcmp(backups[i].filename, input) == 0) {
                remove(backups[i].backup_time);
                count++;
                if (count == MAX_BACKUP_COUNT) {
                    break;
                }
            }
        }
        backup_count -= count;
    }

    return 0;
}