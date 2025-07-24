//FormAI DATASET v1.0 Category: Database Indexing System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 51
#define MAX_PHONE_NUM_LEN 16
#define HASH_TABLE_SIZE 100

typedef struct {
  char name[MAX_NAME_LEN];
  char phone_number[MAX_PHONE_NUM_LEN];
} Contact;

typedef struct node {
  Contact contact;
  struct node *next;
} Node;

Node* hash_table[HASH_TABLE_SIZE];
int num_contacts = 0;

// Hash function, returns an integer between 0 and HASH_TABLE_SIZE - 1
int hash(char* name) {
  int sum = 0;
  for (int i = 0; name[i] != '\0'; i++) {
    sum += name[i];
  }
  return sum % HASH_TABLE_SIZE;
}

// Returns 1 if the given name exists in the hash table, 0 otherwise
int exists(char* name) {
  int index = hash(name);
  Node* curr = hash_table[index];
  while (curr != NULL) {
    if (strcmp(curr->contact.name, name) == 0) {
      return 1;
    }
    curr = curr->next;
  }
  return 0;
}

// Inserts a new contact into the hash table
void insert(Contact c) {
  if (exists(c.name)) {
    printf("Contact with name '%s' already exists.\n", c.name);
    return;
  }
  int index = hash(c.name);
  Node* new_node = malloc(sizeof(Node));
  new_node->contact = c;
  new_node->next = hash_table[index];
  hash_table[index] = new_node;
  num_contacts++;
}

// Searches for a contact with the given name in the hash table
void search(char* name) {
  int index = hash(name);
  Node* curr = hash_table[index];
  while (curr != NULL) {
    if (strcmp(curr->contact.name, name) == 0) {
      printf("%s: %s\n", curr->contact.name, curr->contact.phone_number);
      return;
    }
    curr = curr->next;
  }
  printf("Contact with name '%s' not found.\n", name);
}

// Deletes the contact with the given name from the hash table
void delete(char* name) {
  int index = hash(name);
  Node* curr = hash_table[index];
  Node* prev = NULL;
  while (curr != NULL) {
    if (strcmp(curr->contact.name, name) == 0) {
      if (prev == NULL) {
        hash_table[index] = curr->next;
      } else {
        prev->next = curr->next;
      }
      printf("Deleted contact '%s': %s\n", curr->contact.name, curr->contact.phone_number);
      free(curr);
      num_contacts--;
      return;
    }
    prev = curr;
    curr = curr->next;
  }
  printf("Contact with name '%s' not found.\n", name);
}

// Prints all the contacts in the hash table
void print_contacts() {
  for (int i = 0; i < HASH_TABLE_SIZE; i++) {
    Node* curr = hash_table[i];
    while (curr != NULL) {
      printf("%s: %s\n", curr->contact.name, curr->contact.phone_number);
      curr = curr->next;
    }
  }
  printf("Total number of contacts: %d\n", num_contacts);
}

// Main function, demonstrates the use of the hash table
int main() {
  // Initialize the hash table with NULL values
  for (int i = 0; i < HASH_TABLE_SIZE; i++) {
    hash_table[i] = NULL;
  }

  // Insert some contacts
  Contact c1 = {"Alice", "555-1234"};
  Contact c2 = {"Bob", "555-5678"};
  insert(c1);
  insert(c2);
  insert(c1);

  // Search for a contact
  search("Bob");

  // Delete a contact
  delete("Alice");

  // Print all contacts
  print_contacts();

  return 0;
}