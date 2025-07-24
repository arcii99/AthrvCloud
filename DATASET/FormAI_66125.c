//FormAI DATASET v1.0 Category: Mailing list manager ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 50
#define MAX_LIST_SIZE 1000

struct EmailList {
    char emails[MAX_LIST_SIZE][MAX_EMAIL_LENGTH];
    int size;
};

void addEmail(struct EmailList *list, char *email) {
    if (list->size == MAX_LIST_SIZE) {
        printf("Email list is full. Cannot add any more emails.\n");
        return;
    }
    strcpy(list->emails[list->size], email);
    list->size++;
}

void removeEmail(struct EmailList *list, char *email) {
    int i, removed = 0;
    for (i = 0; i < list->size; i++) {
        if (strcmp(list->emails[i], email) == 0) {
            int j;
            for (j = i; j < list->size - 1; j++) {
                strcpy(list->emails[j], list->emails[j + 1]);
            }
            list->size--;
            removed = 1;
            printf("Email \"%s\" removed successfully.\n", email);
            break;
        }
    }
    if (!removed) {
        printf("Email \"%s\" not found in list.\n", email);
    }
}

void printList(struct EmailList list) {
    if (list.size == 0) {
        printf("Email list is empty.\n");
        return;
    }
    int i;
    printf("Email List:\n");
    for (i = 0; i < list.size; i++) {
        printf("%d. %s\n", i + 1, list.emails[i]);
    }
}

int main() {
    struct EmailList list;
    list.size = 0;
    int choice = 1;
    char email[MAX_EMAIL_LENGTH];
    while (choice != 0) {
        printf("\n1. Add Email\n2. Remove Email\n3. View List\n0. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter email to add: ");
                scanf("%s", email);
                addEmail(&list, email);
                break;
            case 2:
                printf("Enter email to remove: ");
                scanf("%s", email);
                removeEmail(&list, email);
                break;
            case 3:
                printList(list);
                break;
            case 0:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}