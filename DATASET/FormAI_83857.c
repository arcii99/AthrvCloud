//FormAI DATASET v1.0 Category: Mailing list manager ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_EMAILS 100

struct Email {
  char name[50];
  char email[50];
};

struct List {
  int count;
  struct Email emails[MAX_EMAILS];
};

// Function declarations
void addToList(struct List* list, char* name, char* email);
void printList(struct List* list);
void saveList(struct List* list, char* filename);
void loadList(struct List* list, char* filename);

int main() {
  struct List myList = {0};
  char filename[] = "list.dat";
  int choice; // User's menu choice

  // Print welcome message
  printf("Welcome to the post-apocalyptic Mailing List Manager!\n");

  // Load existing list if it exists
  loadList(&myList, filename);

  while (1) {
    // Print menu options
    printf("\nSelect an option:\n");
    printf("1. Add new email to list\n");
    printf("2. Print current list\n");
    printf("3. Save current list to file\n");
    printf("4. Exit program\n");

    // Prompt user for choice
    scanf("%d", &choice);

    // Process user's choice
    switch (choice) {
      case 1:
        // Prompt user for name and email
        char name[50], email[50];
        printf("Enter name: ");
        scanf("%s", name);
        printf("Enter email: ");
        scanf("%s", email);

        // Add to the list
        addToList(&myList, name, email);
        printf("Added %s to the list!\n", email);
        break;

      case 2:
        // Print current list
        printf("Current Mailing List:\n");
        printList(&myList);
        break;

      case 3:
        // Save current list to file
        saveList(&myList, filename);
        printf("List saved to %s\n", filename);
        break;

      case 4:
        // Exit program
        printf("Exiting...\n");
        return 0;

      default:
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }
}

// Function to add an email to the list
void addToList(struct List* list, char* name, char* email) {
  // Create new email object and add to list
  struct Email newEmail = {0};
  strcpy(newEmail.name, name);
  strcpy(newEmail.email, email);
  list->emails[list->count++] = newEmail;
}

// Function to print the current list
void printList(struct List* list) {
  if (list->count == 0) {
    printf("No emails in list.\n");
  } else {
    for (int i = 0; i < list->count; i++) {
      printf("%s, %s\n", list->emails[i].name, list->emails[i].email);
    }
  }
}

// Function to save the current list to file
void saveList(struct List* list, char* filename) {
  FILE* fp = fopen(filename, "wb");
  fwrite(list, sizeof(struct List), 1, fp);
  fclose(fp);
}

// Function to load an existing list from file
void loadList(struct List* list, char* filename) {
  FILE* fp = fopen(filename, "rb");
  if (fp != NULL) {
    fread(list, sizeof(struct List), 1, fp);
    fclose(fp);
    printf("List loaded from %s\n", filename);
  }
}