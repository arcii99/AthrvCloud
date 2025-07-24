//FormAI DATASET v1.0 Category: Mailing list manager ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

// Struct defining the subscriber
typedef struct Subscriber { 
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
} Subscriber;

// Struct defining the mailing list
typedef struct MailingList {
    char listName[MAX_NAME_LENGTH];
    Subscriber subscribers[100];
    int numSubscribers;
} MailingList;

// Function to add subscriber to mailing list
void addSubscriber(MailingList* list) {
    Subscriber newSubscriber;

    printf("Enter subscriber name: ");
    scanf("%[^\n]%*c", newSubscriber.name);

    printf("Enter subscriber email: ");
    scanf("%[^\n]%*c", newSubscriber.email);

    list->subscribers[list->numSubscribers++] = newSubscriber;

    printf("Subscriber added to %s mailing list.\n", list->listName);
}

// Function to print all subscribers in a mailing list
void printSubscribers(MailingList* list) {
    printf("Subscribers in %s mailing list:\n", list->listName);
    for(int i=0; i<list->numSubscribers; i++) {
        printf("%s (%s)\n", list->subscribers[i].name, list->subscribers[i].email);
    }
}

int main() {
    MailingList list1;
    MailingList list2;

    // Setting the name of the mailing lists
    strcpy(list1.listName, "List 1");
    strcpy(list2.listName, "List 2");
    
    // Adding subscribers to mailing list
    addSubscriber(&list1);
    addSubscriber(&list1);
    addSubscriber(&list2);

    // Printing subscribers in mailing list
    printSubscribers(&list1);
    printSubscribers(&list2);

    return 0;
}