//FormAI DATASET v1.0 Category: File Backup System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_FILE_CONTENT_LENGTH 1024

typedef struct backup_node {
    char filename[MAX_FILENAME_LENGTH];
    char content[MAX_FILE_CONTENT_LENGTH];
    time_t modified_time;
    struct backup_node* next;
} BackupNode;

/*
 * Creates a new backup node with the given filename, file content, and last modified time.
 */
BackupNode* createBackupNode(char* filename, char* content, time_t modified_time) {
    BackupNode* node = (BackupNode*) malloc(sizeof(BackupNode));
    if (node == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for backup node!\n");
        exit(1);
    }
    strcpy(node->filename, filename);
    strcpy(node->content, content);
    node->modified_time = modified_time;
    node->next = NULL;
    return node;
}

/*
 * Adds a new backup node to the linked list.
 */
void addBackupNode(BackupNode** head, char* filename, char* content, time_t modified_time) {
    BackupNode* node = createBackupNode(filename, content, modified_time);
    if (*head == NULL) {
        *head = node;
    } else {
        BackupNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

/*
 * Displays all backup nodes in the linked list.
 */
void displayBackupNodes(BackupNode* head) {
    if (head == NULL) {
        printf("No backup nodes to display!\n");
    } else {
        printf("Backup Nodes:\n");
        printf("-----------------------------------------------------------------\n");
        printf("%-30s%-30s%s\n", "Filename", "Modified Time", "Content");
        printf("-----------------------------------------------------------------\n");
        BackupNode* current = head;
        while (current != NULL) {
            printf("%-30s%-30s%s\n", current->filename, ctime(&current->modified_time), current->content);
            current = current->next;
        }
        printf("-----------------------------------------------------------------\n");
    }
}

int main() {
    BackupNode* backups = NULL;
    addBackupNode(&backups, "file1.txt", "This is the content of file 1.", time(NULL));
    addBackupNode(&backups, "file2.txt", "This is the content of file 2.", time(NULL));
    displayBackupNodes(backups);
    return 0;
}