//FormAI DATASET v1.0 Category: Mailing list manager ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

struct subscriber {
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
};

struct mailing_list {
    struct subscriber subscribers[1000];
    int count;
};

void display_menu() {
    printf("\nMailing List Manager\n");
    printf("--------------------\n");
    printf("1. Add subscriber\n");
    printf("2. Remove subscriber\n");
    printf("3. Display mailing list\n");
    printf("4. Exit program\n");
    printf("\nEnter your choice (1-4): ");
}

void add_subscriber(struct mailing_list *list) {
    char name[MAX_NAME_LEN], email[MAX_EMAIL_LEN];
    printf("\nEnter name: ");
    fgets(name, MAX_NAME_LEN, stdin);
    name[strlen(name) - 1] = '\0';
    printf("Enter email: ");
    fgets(email, MAX_EMAIL_LEN, stdin);
    email[strlen(email) - 1] = '\0';
    strcpy(list->subscribers[list->count].name, name);
    strcpy(list->subscribers[list->count].email, email);
    list->count++;
    printf("Subscriber added successfully!\n");
}

void remove_subscriber(struct mailing_list *list) {
    int i, j;
    char email[MAX_EMAIL_LEN];
    printf("\nEnter the email of the subscriber to remove: ");
    fgets(email, MAX_EMAIL_LEN, stdin);
    email[strlen(email) - 1] = '\0';
    for (i = 0; i < list->count; i++) {
        if (strcmp(list->subscribers[i].email, email) == 0) {
            for (j = i; j < list->count - 1; j++) {
                list->subscribers[j] = list->subscribers[j + 1];
            }
            list->count--;
            printf("Subscriber removed successfully!\n");
            return;
        }
    }
    printf("Subscriber not found!\n");
}

void display_mailing_list(struct mailing_list *list) {
    int i;
    printf("\nSubscribers:\n");
    printf("-------------\n");
    for (i = 0; i < list->count; i++) {
        printf("%s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

int main() {
    struct mailing_list list;
    int choice;
    list.count = 0;
    printf("Welcome to the Mailing List Manager!\n");
    do {
        display_menu();
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                add_subscriber(&list);
                break;
            case 2:
                remove_subscriber(&list);
                break;
            case 3:
                display_mailing_list(&list);
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
    return 0;
}