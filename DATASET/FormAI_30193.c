//FormAI DATASET v1.0 Category: Phone Book ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Max number of contacts in the phonebook
#define MAX_CONTACTS 100

// Struct for a contact
typedef struct {
    char name[50];
    char number[20];
} Contact;

// Array to hold all contacts
Contact phonebook[MAX_CONTACTS];

// Variable to keep track of the number of contacts in the phonebook
int num_contacts = 0;

// Mutex for accessing the phonebook
pthread_mutex_t phonebook_mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to add a contact to the phonebook
void add_contact(char* name, char* number) {
    // Lock the mutex to prevent concurrent access to the phonebook
    pthread_mutex_lock(&phonebook_mutex);

    // Check if the phonebook is full
    if (num_contacts >= MAX_CONTACTS) {
        printf("Phonebook is full, cannot add contact\n");
        pthread_mutex_unlock(&phonebook_mutex);
        return;
    }

    // Add the contact to the phonebook
    strcpy(phonebook[num_contacts].name, name);
    strcpy(phonebook[num_contacts].number, number);
    num_contacts++;

    // Unlock the mutex
    pthread_mutex_unlock(&phonebook_mutex);
}

// Function to search for a contact in the phonebook
void search_contact(char* name) {
    // Lock the mutex to prevent concurrent access to the phonebook
    pthread_mutex_lock(&phonebook_mutex);

    // Search for the contact in the phonebook
    int i;
    for (i = 0; i < num_contacts; i++) {
        if (strcmp(phonebook[i].name, name) == 0) {
            printf("%s's phone number is: %s\n", name, phonebook[i].number);
            pthread_mutex_unlock(&phonebook_mutex);
            return;
        }
    }

    // Contact was not found in the phonebook
    printf("Contact not found\n");

    // Unlock the mutex
    pthread_mutex_unlock(&phonebook_mutex);
}

// Function to print out all contacts in the phonebook
void print_phonebook() {
    // Lock the mutex to prevent concurrent access to the phonebook
    pthread_mutex_lock(&phonebook_mutex);

    // Print out all contacts in the phonebook
    int i;
    for (i = 0; i < num_contacts; i++) {
        printf("%s: %s\n", phonebook[i].name, phonebook[i].number);
    }

    // Unlock the mutex
    pthread_mutex_unlock(&phonebook_mutex);
}

// Main function
int main() {
    // Add some sample contacts
    add_contact("John Smith", "555-1234");
    add_contact("Jane Doe", "555-5678");

    // Search for a contact
    search_contact("John Smith");

    // Print out the phonebook
    print_phonebook();

    return 0;
}