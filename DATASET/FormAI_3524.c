//FormAI DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 255
#define MAX_FILE_SIZE 1000000

/* Define a file struct */
typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    char data[MAX_FILE_SIZE];
    int size;
} File;

/* Define a linked list node for files */
typedef struct Node {
    File file;
    struct Node *next;
} Node;

/* Append a file to the end of the linked list */
void append(Node **head_ref, File new_file) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    Node *last = *head_ref;

    /* Add file data to new node */
    new_node->file = new_file;

    /* Set next node to NULL (new file is the last node in the list) */
    new_node->next = NULL;

    /* If the list is empty, set the new node to be the head */
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    /* Traverse to the end of the list and add the new node */
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

/* Remove a file with the specified filename from the linked list */
void remove_file(Node **head_ref, char *filename) {
    Node *temp = *head_ref, *prev;

    /* If the head node needs to be deleted */
    if (temp != NULL && strcmp(temp->file.filename, filename) == 0) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    /* Find the file with the specified filename */
    while (temp != NULL && strcmp(temp->file.filename, filename) != 0) {
        prev = temp;
        temp = temp->next;
    }

    /* If the file was not found */
    if (temp == NULL) {
        printf("File not found.\n");
        return;
    }

    /* Unlink the node and free the memory */
    prev->next = temp->next;
    free(temp);
}

/* Print all files in the linked list */
void print_files(Node *head) {
    Node *current = head;

    /* Traverse the list and print each file */
    while (current != NULL) {
        printf("%s\n", current->file.filename);
        current = current->next;
    }
}

int main() {
    Node *head = NULL;
    char filename[MAX_FILENAME_LENGTH];
    char filedata[MAX_FILE_SIZE];
    File new_file;
    int option;

    /* Display menu options */
    printf("1. Add a file\n");
    printf("2. Remove a file\n");
    printf("3. View all files\n");
    printf("4. Exit\n");

    /* Loop until the user chooses to exit */
    while (1) {
        printf("\nEnter an option: ");
        scanf("%d", &option);

        /* Perform the selected option */
        switch (option) {
            case 1:
                printf("Enter filename: ");
                scanf("%s", filename);
                printf("Enter file data: ");
                scanf(" %[^\n]s", filedata);

                /* Add the new file to the linked list */
                strcpy(new_file.filename, filename);
                strcpy(new_file.data, filedata);
                new_file.size = strlen(new_file.data);
                append(&head, new_file);

                printf("File added.\n");
                break;

            case 2:
                printf("Enter filename: ");
                scanf("%s", filename);

                /* Remove the specified file from the linked list */
                remove_file(&head, filename);
                printf("File removed.\n");
                break;

            case 3:
                printf("Files:\n");
                print_files(head);
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);
                break;

            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}