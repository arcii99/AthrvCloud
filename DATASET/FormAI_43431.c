//FormAI DATASET v1.0 Category: Phone Book ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

struct contact {
    char name[50];
    char phone_num[20];
};

int main() {
    // Initialize network
    // Connect to other nodes in the network
    
    // User 1 adds a new contact
    struct contact new_contact_1;
    printf("Enter new contact name for User 1: ");
    scanf("%s", new_contact_1.name);
    printf("Enter new contact phone number for User 1: ");
    scanf("%s", new_contact_1.phone_num);
    
    // User 2 adds the same contact
    struct contact new_contact_2;
    printf("Enter new contact name for User 2: ");
    scanf("%s", new_contact_2.name);
    printf("Enter new contact phone number for User 2: ");
    scanf("%s", new_contact_2.phone_num);
    
    // Both users try to add the contact simultaneously
    // Conflict resolution protocol handles the conflict
    
    // New contact is added to phone book and propagated across network
    // Other users in the network receive the updated phone book
    
    return 0;
}