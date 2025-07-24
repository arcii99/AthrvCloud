//FormAI DATASET v1.0 Category: Phone Book ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100

struct Contact {
    char name[30];
    char phone[20];
};

int main() {
    struct Contact phone_book[MAX_CONTACTS];
    int num_contacts = 0;
    
    printf("Welcome to the C Phone Book!\n");
    printf("Enter 'q' at any time to quit.\n");
    
    while(num_contacts < MAX_CONTACTS) {
        printf("Enter contact name: ");
        fgets(phone_book[num_contacts].name, 30, stdin);
        phone_book[num_contacts].name[strcspn(phone_book[num_contacts].name, "\n")] = '\0'; // remove newline character
        if(strcmp(phone_book[num_contacts].name, "q") == 0) break; // quit program
        printf("Enter phone number: ");
        fgets(phone_book[num_contacts].phone, 20, stdin);
        phone_book[num_contacts].phone[strcspn(phone_book[num_contacts].phone, "\n")] = '\0'; // remove newline character
        if(strcmp(phone_book[num_contacts].phone, "q") == 0) break; // quit program
        num_contacts++;
    }
    
    printf("\nPhone Book:\n");
    for(int i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phone_book[i].name, phone_book[i].phone);
    }
    
    return 0;
}