//FormAI DATASET v1.0 Category: Phone Book ; Style: light-weight
#include <stdio.h> 
#include <string.h> 

struct phoneBook {
  char name[50];
  char number[20];
};

int main() {
  struct phoneBook contacts[100];
  int numContacts = 0;
  char choice;

  printf("***C Phone Book***\n");

  do {
    printf("\nSelect an option: \n");
    printf("[1] Add a new contact\n");
    printf("[2] View all contacts\n");
    printf("[3] Search for a contact\n");
    printf("[4] Update a contact\n");
    printf("[5] Delete a contact\n");
    printf("[6] Exit\n");

    scanf(" %c", &choice);

    switch (choice) {
      case '1': // Add new contact
        printf("\nAdd a new contact: \n");
        printf("Name: ");
        scanf("%s", contacts[numContacts].name);
        printf("Number: ");
        scanf("%s", contacts[numContacts].number);
        numContacts++;
        printf("\nContact added!\n");
        break;

      case '2': // View all contacts
        printf("\nAll contacts:\n");
        for (int i = 0; i < numContacts; i++) {
          printf("[%d] %s - %s\n", i+1, contacts[i].name, contacts[i].number);
        }
        break;

      case '3': // Search for a contact
        char searchName[50];
        printf("\nEnter name to search: ");
        scanf("%s", searchName);
        for (int i = 0; i < numContacts; i++) {
          if (strcmp(searchName, contacts[i].name) == 0) {
            printf("\n%s - %s\n", contacts[i].name, contacts[i].number);
            break;
          } else if (i == numContacts-1){
            printf("\nContact not found!\n");
          }
        }
        break;

      case '4': // Update a contact
        char updateName[50];
        printf("\nEnter name to update: ");
        scanf("%s", updateName);
        for (int i = 0; i < numContacts; i++) {
          if (strcmp(updateName, contacts[i].name) == 0) {
            printf("\nEnter new name: ");
            scanf("%s", contacts[i].name);
            printf("Enter new number: ");
            scanf("%s", contacts[i].number);
            printf("\nContact updated!\n");
            break;
          } else if (i == numContacts-1){
            printf("\nContact not found!\n");
          }
        }
        break;

      case '5': // Delete a contact
        char deleteName[50];
        printf("\nEnter name to delete: ");
        scanf("%s", deleteName);
        for (int i = 0; i < numContacts; i++) {
          if (strcmp(deleteName, contacts[i].name) == 0) {
            printf("\nDeleting contact: %s - %s\n", contacts[i].name, contacts[i].number);
            for (int j = i; j < numContacts-1; j++) {
              contacts[j] = contacts[j+1];
            }
            numContacts--;
            printf("\nContact deleted!\n");
            break;
          } else if (i == numContacts-1){
            printf("\nContact not found!\n");
          }
        }
        break;

      case '6': // Exit
        printf("\nExiting C Phone Book...\n");
        break;

      default: // Invalid choice
        printf("\nInvalid choice.\n"); 
        break;
    }

  } while (choice != '6');

  return 0;
}