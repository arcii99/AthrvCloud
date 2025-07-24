//FormAI DATASET v1.0 Category: Mailing list manager ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EMAIL_LENGTH 100
#define MAX_NAME_LENGTH 50
#define MAX_CONTACTS 1000

struct Contact {
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];
};

struct MailingList {
  char name[MAX_NAME_LENGTH];
  struct Contact contacts[MAX_CONTACTS];
  int size;
};

void addContact(struct MailingList* list, char name[], char email[]) {
  // Check if the contact already exists
  for (int i = 0; i < list->size; i++) {
    if (strcmp(list->contacts[i].email, email) == 0) {
      printf("A contact with this email already exists.\n");
      return;
    }
  }
  
  // Add the new contact
  strcpy(list->contacts[list->size].name, name);
  strcpy(list->contacts[list->size].email, email);
  list->size++;
  printf("Contact added successfully.\n");
}

void printContacts(struct MailingList* list) {
  printf("Contacts in %s:\n", list->name);
  for (int i = 0; i < list->size; i++) {
    printf("%d. %s (%s)\n", i+1, list->contacts[i].name, list->contacts[i].email);
  }
}

int main() {
  struct MailingList list;
  strcpy(list.name, "My Mailing List");
  list.size = 0;
  
  // Menu options
  int choice;
  char name[MAX_NAME_LENGTH];
  char email[MAX_EMAIL_LENGTH];

  while (1) {
    printf("\n%s Manager\n\n", list.name);
    printf("1. Add Contact\n");
    printf("2. Print Contacts\n");
    printf("3. Quit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
  
    switch (choice) {
      case 1:
        printf("\nEnter contact name: ");
        scanf("%s", name);
        printf("Enter contact email: ");
        scanf("%s", email);
        addContact(&list, name, email);
        break;
      
      case 2:
        printContacts(&list);
        break;
      
      case 3:
        printf("\nGoodbye!\n");
        exit(0);
      
      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  }
  
  return 0;
}