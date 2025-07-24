//FormAI DATASET v1.0 Category: Mailing list manager ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the name and email fields
#define MAX_NAME_LENGTH 50 
#define MAX_EMAIL_LENGTH 100

// Define the maximum number of subscribers our mailing list can handle
#define MAX_SUBSCRIBERS 100

// Define a struct for each subscriber that will hold their name and email address
struct Subscriber {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

// Define a struct to hold the mailing list, which is an array of subscribers
struct MailingList {
    struct Subscriber subscribers[MAX_SUBSCRIBERS];
    int count;
};

// Function to add a new subscriber to the mailing list
void addSubscriber(struct MailingList *list, char *name, char *email) {
    // Check if there is still room for another subscriber
    if (list->count < MAX_SUBSCRIBERS) {
        // Copy the name and email into the new subscriber's struct
        strcpy(list->subscribers[list->count].name, name);
        strcpy(list->subscribers[list->count].email, email);
        
        // Increment the count of subscribers in the list
        list->count++;
        
        // Print a confirmation to the user
        printf("Subscriber %s <%s> added to the mailing list.\n", name, email);
    }
    else {
        // If there is no more room, print an error message
        printf("Error: mailing list is full. Unable to add subscriber %s <%s>.\n", name, email);
    }
}

// Function to print out the entire mailing list
void printMailingList(struct MailingList list) {
    printf("Mailing List:\n");
    // Loop through each subscriber and print their name and email
    for (int i=0; i<list.count; i++) {
        printf("%s <%s>\n", list.subscribers[i].name, list.subscribers[i].email);
    }
    // Print the total number of subscribers
    printf("Total Subscribers: %d\n", list.count);
}

int main() {
    // Create a new empty mailing list
    struct MailingList list = { .count=0 };
    
    // Add some subscribers to the list
    addSubscriber(&list, "John Smith", "jsmith@email.com");
    addSubscriber(&list, "Jane Doe", "jdoe@email.com");
    
    // Print out the entire mailing list
    printMailingList(list);
    
    // Exit the program
    return 0;
}