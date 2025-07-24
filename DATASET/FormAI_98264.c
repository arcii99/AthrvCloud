//FormAI DATASET v1.0 Category: Phone Book ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char phone[14];
};

void add_contact(struct contact *list, int *size) {
    printf("Enter name: ");
    scanf("%49s", list[*size].name);
    printf("Enter phone number (XXX-XXX-XXXX): ");
    scanf("%13s", list[*size].phone);
    (*size)++;
    printf("Contact added!\n");
}

void search_contact(struct contact *list, int size) {
    char name_search[50];
    int found = 0;
    printf("Enter name to search: ");
    scanf("%49s", name_search);
    for (int i = 0; i < size; i++) {
        if (strcmp(name_search, list[i].name) == 0) {
            printf("%s's phone number is %s\n", list[i].name, list[i].phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Contact not found.\n");
    }
}

int main() {
    char choice;
    int size = 0;
    struct contact *list = malloc(sizeof(struct contact));
    
    printf("Welcome to the Invasive Phone Book App!\n");
    printf("========================================\n");
    printf("Please select an option:\n");
    printf("Add a contact\t\t\tA\n");
    printf("Search for a contact\t\tS\n");
    printf("Quit the program\t\tQ\n");
    
    while (1) {
        printf("Enter choice: ");
        scanf(" %c", &choice);
        switch(choice) {
            case 'A':
                add_contact(list, &size);
                if (size % 10 == 0) {
                    list = realloc(list, (size + 10) * sizeof(struct contact));
                }
                break;
            case 'S':
                search_contact(list, size);
                break;
            case 'Q':
                printf("Bye bye!\n");
                free(list);
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
}