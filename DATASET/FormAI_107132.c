//FormAI DATASET v1.0 Category: Phone Book ; Style: statistical
#include<stdio.h>
#include<string.h>
#define MAX 50

struct contact {      // Structure to hold contact information
    char name[20];
    char phone[15];
};

int main() {
    struct contact contacts[MAX];    // Array of structures to hold contact information
    char search_name[20];   // Variable to hold the name of the person to be searched
    int i, num_contacts;    // Variables for counting and storing the number of contacts

    // Taking input from user
    printf("Enter the number of contacts: ");
    scanf("%d", &num_contacts);

    for(i=0; i<num_contacts; i++) {
        printf("\nEnter name: ");
        scanf("%s", contacts[i].name);
        printf("Enter phone number: ");
        scanf("%s", contacts[i].phone);
    }

    // Searching for a contact
    printf("\nEnter a name to search in the phone book: ");
    scanf("%s", search_name);

    for(i=0; i<num_contacts; i++) {
        if(strcmp(search_name, contacts[i].name) == 0) {   // Comparing names using strcmp function
            printf("\nName: %s\tPhone: %s\n", contacts[i].name, contacts[i].phone);
            break;
        }
    }

    if(i == num_contacts) {    // If contact not found
        printf("\nSorry, the name you searched for is not in the phone book.\n");
    }

    return 0;
}