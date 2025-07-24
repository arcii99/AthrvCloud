//FormAI DATASET v1.0 Category: File Backup System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BACKUPS 5

struct backup {
    char timestamp[20];
    char* contents;
};

struct backup backups[MAX_BACKUPS];
int num_backups = 0;

void backup(char* contents) {
    if (num_backups == MAX_BACKUPS) {
        printf("Maximum backups reached. Please delete backups to create new backups.\n");
        return;
    }

    struct backup new_backup;

    time_t raw_time;
    struct tm* time_info;
    char time_str[20];

    time(&raw_time);
    time_info = localtime(&raw_time);

    strftime(time_str, 20, "%Y-%m-%d %H:%M:%S", time_info);

    new_backup.contents = strdup(contents);
    memcpy(new_backup.timestamp, time_str, strlen(time_str) + 1);

    backups[num_backups++] = new_backup;
}

void delete_backup(int backup_index) {
    if (backup_index < 0 || backup_index >= num_backups) {
        printf("Invalid backup index. Please provide a number between 0 and %d.\n", num_backups - 1);
        return;
    }

    free(backups[backup_index].contents);
    backups[backup_index] = backups[--num_backups];
    backups[num_backups].contents = NULL;
    backups[num_backups].timestamp[0] = '\0';
}

void list_backups() {
    if (num_backups == 0) {
        printf("No backups found.\n");
        return;
    }

    printf("Timestamp\t\tContents\n");
    for (int i = 0; i < num_backups; i++) {
        printf("%s\t%s\n", backups[i].timestamp, backups[i].contents);
    }
}

void menu() {
    int choice;
    char contents[1024];

    while (1) {
        printf("\n");
        printf("1. Backup contents\n");
        printf("2. Delete backup\n");
        printf("3. List backups\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter contents to backup: ");
            scanf(" %[^\n]", contents);
            backup(contents);
            break;
        case 2:
            if (num_backups == 0) {
                printf("No backups found.\n");
            } else {
                int index;
                printf("Enter the index of the backup to delete: ");
                scanf("%d", &index);
                delete_backup(index);
            }
            break;
        case 3:
            list_backups();
            break;
        case 4:
            goto exit;
        default:
            printf("Invalid choice. Please enter a number between 1 and 4.\n");
            break;
        }
    }

exit:
    return;
}

int main() {
    menu();
    return 0;
}