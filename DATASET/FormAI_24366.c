//FormAI DATASET v1.0 Category: Mailing list manager ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mailingList {
    char name[50];
    char email[50];
    int age;
    struct mailingList *next;
} MailingList;

MailingList *head = NULL;

int main() {
    int choice;
    do {
        printf("\n1. Add Subscriber\n2. Remove Subscriber\n3. Print List\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addSubscriber();
                break;
            case 2:
                removeSubscriber();
                break;
            case 3:
                printList();
                break;
        }
    } while(choice != 4);
    return 0;
}

void addSubscriber() {
    MailingList *newSubscriber = (MailingList*)malloc(sizeof(MailingList));
    printf("Enter name: ");
    scanf("%s", newSubscriber->name);
    printf("Enter email: ");
    scanf("%s", newSubscriber->email);
    printf("Enter age: ");
    scanf("%d", &newSubscriber->age);
    newSubscriber->next = head;
    head = newSubscriber;
    printf("Subscriber added to the list.\n");
}

void removeSubscriber() {
    MailingList *current = head;
    MailingList *prev = NULL;
    char email[50];
    printf("Enter email: ");
    scanf("%s", email);
    while(current != NULL) {
        if(strcmp(current->email, email) == 0) {
            if(prev == NULL) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            printf("Subscriber removed from the list.\n");
            return;
        }
        prev = current;
        current = current->next;
    }
    printf("Subscriber with email %s not found.\n", email);
}

void printList() {
    MailingList *current = head;
    printf("\nName\t\tEmail\t\tAge\n");
    while(current != NULL) {
        printf("%s\t\t%s\t\t%d\n", current->name, current->email, current->age);
        current = current->next;
    }
}