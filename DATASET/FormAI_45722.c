//FormAI DATASET v1.0 Category: Mailing list manager ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAILS 100

struct email {
    char address[50];
    char type[10];
};

struct mailing_list {
    char name[50];
    struct email emails[MAX_EMAILS];
    int count;
};

void add_email(struct mailing_list *list, char *address, char *type) {
    if (list->count < MAX_EMAILS) {
        struct email new_email;
        strcpy(new_email.address, address);
        strcpy(new_email.type, type);
        list->emails[list->count++] = new_email;
        printf("Added email: %s\n", address);
    } else {
        printf("Mailing list is full\n");
    }
}

void print_emails(struct mailing_list *list) {
    printf("Mailing List: %s\n", list->name);
    printf("-----------------\n");
    for (int i = 0; i < list->count; i++) {
        printf("%s : %s\n", list->emails[i].type, list->emails[i].address);
    }
    printf("-----------------\n");
}

int main() {
    struct mailing_list list = {"My List", {}, 0};

    add_email(&list, "johndoe@gmail.com", "Personal");
    add_email(&list, "janedoe@yahoo.com", "Work");
    add_email(&list, "joebloggs@hotmail.com", "Personal");
    print_emails(&list);

    return 0;
}