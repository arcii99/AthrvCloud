//FormAI DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node {
    char website[50];
    char username[50];
    char password[50];
    struct node* next;
};

struct node *head = NULL;

void add_password() {
    struct node *new_node, *temp;
    new_node = (struct node *) malloc(sizeof(struct node));

    printf("Enter website name: ");
    scanf("%s", new_node->website);

    printf("Enter username: ");
    scanf("%s", new_node->username);

    printf("Enter password: ");
    scanf("%s", new_node->password);

    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        printf("Password added successfully!\n");
    }
    else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        printf("Password added successfully!\n");
    }
}

void search_password() {
    char search_website[50];
    printf("Enter website name to search password: ");
    scanf("%s", search_website);
    struct node *temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->website, search_website) == 0) {
            printf("Website: %s\n", temp->website);
            printf("Username: %s\n", temp->username);
            printf("Password: ****\n");
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (!found)
        printf("Password not found for the given website!\n");
}

void delete_password() {
    char search_website[50];
    printf("Enter website name to delete password: ");
    scanf("%s", search_website);
    struct node *temp1 = head, *temp2 = NULL;
    int found = 0;
    while (temp1 != NULL) {
        if (strcmp(temp1->website, search_website) == 0) {
            found = 1;
            if (temp1 == head) {
                head = temp1->next;
                printf("Password deleted successfully!\n");
            }
            else {
                temp2->next = temp1->next;
                printf("Password deleted successfully!\n");
            }
            free(temp1);
            break;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    if (!found)
        printf("Password not found for the given website!\n");
}

void display_passwords() {
    if (head == NULL)
        printf("No passwords added yet!\n");
    else {
        printf("Website\t\tUsername\t\tPassword\n");
        printf("-------\t\t--------\t\t--------\n");
        struct node *temp = head;
        while (temp != NULL) {
            printf("%s\t\t%s\t\t****\n", temp->website, temp->username);
            temp = temp->next;
        }
    }
}

int main() {
    int choice;
    while (1) {
        printf("Password Manager\n");
        printf("\t1. Add New Password\n");
        printf("\t2. Search Password\n");
        printf("\t3. Delete Password\n");
        printf("\t4. Display All Passwords\n");
        printf("\t5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_password();
                break;
            case 2:
                search_password();
                break;
            case 3:
                delete_password();
                break;
            case 4:
                display_passwords();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}