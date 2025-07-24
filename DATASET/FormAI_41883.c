//FormAI DATASET v1.0 Category: File Backup System ; Style: Alan Touring
// C file backup system program in Alan Turing style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

void backup(char file[][MAX_FILENAME_LENGTH], int count) {
    printf("Backing up %d files...\n", count);

    // create backup folder
    char backup_folder[] = "backup";
    if (mkdir(backup_folder) == -1) {
        printf("Error: Unable to create backup folder.\n");
        return;
    }

    // copy files to backup folder
    for (int i = 0; i < count; i++) {
        char backup_file[MAX_FILENAME_LENGTH + 10];
        sprintf(backup_file, "backup/%s.bak", file[i]);

        FILE *src = fopen(file[i], "r");
        FILE *dst = fopen(backup_file, "w");

        if (src == NULL || dst == NULL) {
            printf("Error: Unable to copy %s.\n", file[i]);
            continue;
        }

        char buffer[1024];
        size_t len;

        while ((len = fread(buffer, 1, sizeof(buffer), src)) > 0) {
            fwrite(buffer, 1, len, dst);
        }

        fclose(src);
        fclose(dst);
    }

    printf("Backup completed successfully!\n");
}

int main() {
    char file[MAX_FILES][MAX_FILENAME_LENGTH];
    int count = 0;

    printf("Welcome to the C File Backup System!\n");
    printf("Enter up to %d file names to backup (or 'done' to end):\n", MAX_FILES);

    while (count < MAX_FILES) {
        char input[MAX_FILENAME_LENGTH + 1];
        printf("%d. ", count + 1);
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        strcpy(file[count], input);
        count++;
    }

    if (count == 0) {
        printf("No files selected for backup.\n");
        return 0;
    }

    backup(file, count);

    return 0;
}