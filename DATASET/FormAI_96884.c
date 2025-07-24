//FormAI DATASET v1.0 Category: Phone Book ; Style: post-apocalyptic
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 50
#define MAX_NAME_LEN 50
#define MAX_PHONE_LEN 20
#define MAX_FREQUENCY_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char phone[MAX_PHONE_LEN];
    char frequency[MAX_FREQUENCY_LEN];
} contact_t;

int main() {
    contact_t contacts[MAX_CONTACTS];
    int num_contacts = 0;
    printf("Welcome to the post-apocalyptic phone book program!\n");
    while (1) {
        printf("Enter command:\nadd - Add a new contact\nlist - List all contacts\nexit - Exit the program\n");
        char command[10];
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            if (num_contacts < MAX_CONTACTS) {
                printf("Enter name:\n");
                scanf("%s", contacts[num_contacts].name);
                printf("Enter phone number:\n");
                scanf("%s", contacts[num_contacts].phone);
                printf("Enter frequency:\n");
                scanf("%s", contacts[num_contacts].frequency);
                num_contacts++;
            } else {
                printf("Sorry, the maximum number of contacts has been reached.\n");
            }
        } else if (strcmp(command, "list") == 0) {
            printf("Contacts:\n");
            for (int i = 0; i < num_contacts; i++) {
                printf("%s - %s - %s\n", contacts[i].name, contacts[i].phone, contacts[i].frequency);
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Unknown command.\n");
        }
    }
    return 0;
}