//FormAI DATASET v1.0 Category: Mailing list manager ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100
#define MAX_LIST_LEN 100

// Define a structure to hold contact information
struct contact {
  char name[MAX_NAME_LEN];
  char email[MAX_EMAIL_LEN];
};

// Define a structure to hold a Mailing list
struct mailing_list {
  struct contact list[MAX_LIST_LEN];
  int length;
};

// Function prototypes
void add_contact(struct mailing_list *list, struct contact new_contact);
void display_list(struct mailing_list list);

int main() {
  struct mailing_list my_list = {0}; // Initialize the list to be empty
  struct contact new_contact;

  // Add some contacts to the list
  strcpy(new_contact.name, "Alice");
  strcpy(new_contact.email, "alice@example.com");
  add_contact(&my_list, new_contact);

  strcpy(new_contact.name, "Bob");
  strcpy(new_contact.email, "bob@example.com");
  add_contact(&my_list, new_contact);

  strcpy(new_contact.name, "Charlie");
  strcpy(new_contact.email, "charlie@example.com");
  add_contact(&my_list, new_contact);

  // Display the list of contacts
  display_list(my_list);

  return 0;
}

// Function to add a new contact to the mailing list
void add_contact(struct mailing_list *list, struct contact new_contact) {
  // Check that the list is not already full
  if (list->length >= MAX_LIST_LEN) {
    printf("Error: Mailing list is full\n");
    return;
  }

  // Add the new contact to the list
  list->list[list->length] = new_contact;
  list->length++;
}

// Function to display the contents of the mailing list
void display_list(struct mailing_list list) {
  int i;

  printf("%-20s %-20s\n", "Name", "Email");
  for (i = 0; i < list.length; i++) {
    printf("%-20s %-20s\n", list.list[i].name, list.list[i].email);
  }
}