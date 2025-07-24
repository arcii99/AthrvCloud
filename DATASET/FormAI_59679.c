//FormAI DATASET v1.0 Category: Mailing list manager ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char email[50];
    struct node* next;
} Node;

Node* head = NULL;

int main() {
    int choice;
    char email[50];

    printf("Welcome to the Mailing List Manager!\n");

    do {
        printf("1. Add email\n");
        printf("2. Delete email\n");
        printf("3. Display mailing list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter email to be added: ");
                scanf("%s", email);
                add_email(email);
                printf("Email added successfully.\n");
                break;

            case 2:
                printf("Enter email to be deleted: ");
                scanf("%s", email);
                delete_email(email);
                break;

            case 3:
                display_list();
                break;

            case 4:
                printf("Thank you for using the Mailing List Manager!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}

void add_email(char email[]) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->email, email);
    new_node->next = NULL;

    if(head == NULL) {
        head = new_node;
    } else {
        Node* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = new_node;
    }
}

void delete_email(char email[]) {
    if(head == NULL) {
        printf("Mailing list is empty. Cannot delete email.\n");
    } else {
        Node* temp = head;
        Node* prev = NULL;

        while(temp != NULL) {
            if(strcmp(temp->email, email) == 0) {
                if(prev == NULL) {
                    head = temp->next;
                    free(temp);
                    printf("Email deleted successfully.\n");
                    return;
                } else {
                    prev->next = temp->next;
                    free(temp);
                    printf("Email deleted successfully.\n");
                    return;
                }
            }

            prev = temp;
            temp = temp->next;
        }

        printf("Email not found in mailing list.\n");
    }
}

void display_list() {
    if(head == NULL) {
        printf("Mailing list is empty.\n");
    } else {
        Node* temp = head;

        while(temp != NULL) {
            printf("%s\n", temp->email);
            temp = temp->next;
        }
    }
}