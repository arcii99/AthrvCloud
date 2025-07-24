//FormAI DATASET v1.0 Category: Phone Book ; Style: shocked
#include<stdio.h>
#include<string.h>

struct Contact {
    char name[50];
    char phone[20];
};

int main() {
    struct Contact phonebook[100];
    int count = 0;
    char option[20];
    printf("Welcome to your Phone Book!\n");

    do {
        printf("\nChoose an option:\n1. Add contact\n2. View contact\n3. Exit\n");
        scanf("%s", option);

        if(strcmp(option, "add") == 0) {
            printf("Enter the name of the contact: ");
            scanf("%s", phonebook[count].name);
            printf("Enter the phone number of the contact: ");
            scanf("%s", phonebook[count].phone);
            count++;
            printf("Contact added successfully.\n");
        }
        else if(strcmp(option, "view") == 0) {
            if(count == 0) {
                printf("Your phone book is empty.\n");
            }
            else {
                int i;
                printf("\nHere is your phone book:\n");
                for(i = 0; i < count; i++) {
                    printf("Contact %d: %s, %s\n", i+1, phonebook[i].name, phonebook[i].phone);
                }
            }
        }
        else if(strcmp(option, "exit") != 0) {
            printf("Invalid option. Please try again.\n");
        }
    } while(strcmp(option, "exit") != 0);

    printf("\nThank you for using our Phone Book!\n");
    return 0;
}