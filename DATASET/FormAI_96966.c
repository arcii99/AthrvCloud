//FormAI DATASET v1.0 Category: Mailing list manager ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define linked list node structure for emails
struct email {
  char* address;
  struct email* next;
};

// Define linked list node structure for mailing lists
struct mailing_list {
  char* name;
  struct email* emails;
  struct mailing_list* next;
};

// Function to create a new email node
struct email* create_email(char* address) {
  struct email* new_email = (struct email*) malloc(sizeof(struct email));
  new_email->address = address;
  new_email->next = NULL;
  return new_email;
}

// Function to create a new mailing list node
struct mailing_list* create_mailing_list(char* name) {
  struct mailing_list* new_mailing_list = (struct mailing_list*) malloc(sizeof(struct mailing_list));
  new_mailing_list->name = name;
  new_mailing_list->emails = NULL;
  new_mailing_list->next = NULL;
  return new_mailing_list;
}

// Function to add an email to a mailing list
void add_email_to_list(struct mailing_list* list, char* address) {
  struct email* new_email = create_email(address);
  if (list->emails == NULL) {
    list->emails = new_email;
  } else {
    struct email* current = list->emails;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_email;
  }
}

// Function to add a mailing list to the master linked list
void add_mailing_list(struct mailing_list** master_list, struct mailing_list* new_list) {
  if (*master_list == NULL) {
    *master_list = new_list;
  } else {
    struct mailing_list* current = *master_list;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_list;
  }
}

// Function to print a single email
void print_email(struct email* email) {
  printf("%s\n", email->address);
}

// Function to print a single mailing list
void print_mailing_list(struct mailing_list* list) {
  printf("List Name: %s\n", list->name);
  struct email* current = list->emails;
  while (current != NULL) {
    printf("- ");
    print_email(current);
    current = current->next;
  }
}

// Function to print the master list of mailing lists
void print_master_list(struct mailing_list* master_list) {
  struct mailing_list* current = master_list;
  while (current != NULL) {
    print_mailing_list(current);
    current = current->next;
  }
}

int main() {
  struct mailing_list* master_list = NULL;
  
  // Create some example mailing lists and add email addresses to them
  struct mailing_list* list1 = create_mailing_list("List 1");
  add_email_to_list(list1, "example1@example.com");
  add_email_to_list(list1, "example2@example.com");
  add_email_to_list(list1, "example3@example.com");
  add_mailing_list(&master_list, list1);
  
  struct mailing_list* list2 = create_mailing_list("List 2");
  add_email_to_list(list2, "example4@example.com");
  add_email_to_list(list2, "example5@example.com");
  add_mailing_list(&master_list, list2);
  
  // Print the master list
  print_master_list(master_list);
  
  return 0;
}