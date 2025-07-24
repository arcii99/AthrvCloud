//FormAI DATASET v1.0 Category: Mailing list manager ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

struct email {
    char name[50];
    char address[50];
};

struct mailing_list {
    char list_name[50];
    struct email emails[MAX_EMAILS];
    int count;
};

void add_email(struct mailing_list *list) {
    if (list->count == MAX_EMAILS) {
        printf("Mailing list has reached maximum capacity.\n");
        return;
    }
    struct email new_email;
    printf("Enter name: ");
    fgets(new_email.name, 50, stdin);
    printf("Enter email address: ");
    fgets(new_email.address, 50, stdin);
    if (strlen(new_email.name) == 0 || strlen(new_email.address) == 0) {
        printf("Invalid input.\n");
        return;
    }
    int len = strlen(new_email.address);
    if (new_email.address[len-1] == '\n') {
        new_email.address[len-1] = '\0';
    }
    len = strlen(new_email.name);
    if (new_email.name[len-1] == '\n') {
        new_email.name[len-1] = '\0';
    }
    list->emails[list->count++] = new_email;
    printf("Email added successfully.\n");
}

void view_list(struct mailing_list *list) {
    printf("%s:\n", list->list_name);
    for (int i = 0; i < list->count; i++) {
        printf("%s <%s>\n", list->emails[i].name, list->emails[i].address);
    }
}

int main() {
    struct mailing_list my_list;
    strcpy(my_list.list_name, "My List");
    my_list.count = 0;

    while (1) {
        printf("\nEnter a command (add, view, quit): ");
        char command[50];
        fgets(command, 50, stdin);
        if (strcmp(command, "add\n") == 0) {
            add_email(&my_list);
        } else if (strcmp(command, "view\n") == 0) {
            view_list(&my_list);
        } else if (strcmp(command, "quit\n") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}