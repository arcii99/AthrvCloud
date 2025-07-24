//FormAI DATASET v1.0 Category: Mailing list manager ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct person {
    char name[50];
    char email[100];
    char phone[20];
    struct person *next;
} *head;

void add_person() {
    struct person *new_person = (struct person*) malloc(sizeof(struct person));
    printf("Enter name: ");
    fgets(new_person->name, 50, stdin);
    printf("Enter email: ");
    fgets(new_person->email, 100, stdin);
    printf("Enter phone: ");
    fgets(new_person->phone, 20, stdin);
    new_person->next = head;
    head = new_person;
}

void print_list() {
    struct person *current = head;
    printf("Mailing list:\n");
    while (current) {
        printf("%s%s%s", current->name, current->email, current->phone);
        current = current->next;
    }
}

int main() {
    head = NULL;
    char command[10];
    while (1) {
        printf("Enter command (add, print, quit): ");
        fgets(command, 10, stdin);
        if (strcmp(command, "add\n") == 0) {
            add_person();
        } else if (strcmp(command, "print\n") == 0) {
            print_list();
        } else if (strcmp(command, "quit\n") == 0) {
            return 0;
        } else {
            printf("Invalid command\n");
        }
    }
}