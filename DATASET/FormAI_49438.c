//FormAI DATASET v1.0 Category: Database Indexing System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define our struct for a database entry
typedef struct {
    char name[30];
    int age;
    char address[50];
    char phone[15];
} Entry;

// define our node to hold an entry and link to next node
typedef struct Node {
    Entry entry;
    struct Node* next;
} Node;

// define our indexing system, with an array index for each letter of the alphabet
typedef struct {
    Node* index[26];
} Index;

// define our function to insert a new entry into the indexing system
void insertEntry(Index* index, Entry entry) {
    // get the first letter of the name (assuming all names are lowercase)
    char firstLetter = entry.name[0];
    // calculate the array index of the first letter (ASCII value minus ASCII value of 'a')
    int arrayIndex = firstLetter - 'a';
    // allocate memory for the new node to hold the entry
    Node* newNode = malloc(sizeof(Node));
    newNode->entry = entry;
    // if the index is empty at this letter, set the new node as the head
    if(index->index[arrayIndex] == NULL) {
        index->index[arrayIndex] = newNode;
        return;
    }
    // if the index already has nodes for this letter, insert the new node in alphabetical order by name
    Node* current = index->index[arrayIndex];
    if(strcmp(newNode->entry.name, current->entry.name) < 0) {
        newNode->next = current;
        index->index[arrayIndex] = newNode;
        return;
    }
    while(current->next != NULL) {
        if(strcmp(newNode->entry.name, current->next->entry.name) < 0) {
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    current->next = newNode;
}

int main() {
    Index databaseIndex;
    memset(&databaseIndex, 0, sizeof(databaseIndex)); // initialize the index to all NULL values
    printf("Welcome to the Database Indexing System!\n");
    printf("Enter the number of entries you want to add: ");
    int numEntries;
    scanf("%d", &numEntries);
    getchar(); // need to consume the newline character left in the input buffer
    // loop through the number of entries and prompt user for each field
    // then insert the entry into the indexing system
    for(int i = 0; i < numEntries; i++) {
        printf("\nEnter name: ");
        char name[30];
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; // remove newline character from name
        printf("Enter age: ");
        int age;
        scanf("%d", &age);
        getchar(); // need to consume the newline character left in the input buffer
        printf("Enter address: ");
        char address[50];
        fgets(address, sizeof(address), stdin);
        address[strcspn(address, "\n")] = '\0'; // remove newline character from address
        printf("Enter phone number (no dashes): ");
        char phone[15];
        fgets(phone, sizeof(phone), stdin);
        phone[strcspn(phone, "\n")] = '\0'; // remove newline character from phone
        Entry newEntry = { .age = age };
        strcpy(newEntry.name, name);
        strcpy(newEntry.address, address);
        strcpy(newEntry.phone, phone);
        insertEntry(&databaseIndex, newEntry);
    }
    // loop through each array index and print out all the entries at that index
    for(int i = 0; i < 26; i++) {
        Node* current = databaseIndex.index[i];
        while(current != NULL) {
            printf("\nName: %s\n", current->entry.name);
            printf("Age: %d\n", current->entry.age);
            printf("Address: %s\n", current->entry.address);
            printf("Phone: %s\n", current->entry.phone);
            current = current->next;
        }
    }
    // free memory allocated for nodes in the indexing system
    for(int i = 0; i < 26; i++) {
        Node* current = databaseIndex.index[i];
        while(current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    printf("\nThank you for using the Database Indexing System!\n");
    return 0;
}