//FormAI DATASET v1.0 Category: File Backup System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_BACKUP_LENGTH 10

// Node structure for backup list
typedef struct backup_node {
    char filename[MAX_FILENAME_LENGTH];
    time_t backup_time;
    struct backup_node* next;
} backup_node_t;

// Add a new backup to the list
void add_backup(char* filename, backup_node_t** list) {
    // Create new node and populate it
    backup_node_t* new_backup = (backup_node_t*) malloc(sizeof(backup_node_t));
    strcpy(new_backup->filename, filename);
    new_backup->backup_time = time(NULL);
    new_backup->next = NULL;

    // If list is empty, add the backup as the first node
    if (*list == NULL) {
        *list = new_backup;
        return;
    }

    // If list is full, remove the oldest backup
    if (list_length(*list) >= MAX_BACKUP_LENGTH) {
        remove_backup(*list);
    }

    // Add the new backup to the end of the list
    backup_node_t* current = *list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_backup;
}

// Remove the oldest backup from the list
void remove_backup(backup_node_t* list) {
    if (list == NULL) {
        return;
    }
    backup_node_t* current = list->next;
    backup_node_t* prev = list;
    time_t oldest_time = prev->backup_time;
    while (current != NULL) {
        if (current->backup_time < oldest_time) {
            oldest_time = current->backup_time;
            prev = prev->next;
        }
        current = current->next;
    }
    backup_node_t* to_remove = prev->next;
    prev->next = to_remove->next;
    free(to_remove);
}

// Get the length of the backup list
int list_length(backup_node_t* list) {
    int count = 0;
    backup_node_t* current = list;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int main() {
    // Initialize backup list
    backup_node_t* backups = NULL;

    // Get filename input from user
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter file name to backup: ");
    scanf("%s", filename);

    // Make backup
    printf("Making backup...\n");
    // Code for backing up the file would go here
    // For simplicity, we'll just pretend to make a backup
    printf("Backup complete.\n");

    // Add backup to list
    add_backup(filename, &backups);

    // Print backup list
    printf("Backup history:\n");
    backup_node_t* current = backups;
    while (current != NULL) {
        printf("%s backed up at %s", current->filename, ctime(&current->backup_time));
        current = current->next;
    }

    return 0;
}