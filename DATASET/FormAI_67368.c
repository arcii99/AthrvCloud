//FormAI DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h> 
#include <string.h> 

#define MAX_CONTACTS 50
#define CONTACT_NAME_LENGTH 30
#define PHONE_NUMBER_LENGTH 12

typedef struct contact {
   char name[CONTACT_NAME_LENGTH];
   char phone[PHONE_NUMBER_LENGTH];
} Contact;

Contact phoneBook[MAX_CONTACTS];
int numContacts = 0;

int main() {
   printf("Welcome to the Surrealist Phone Book!\n");

   int choice = 0;
   do {
      printf("\nChoose an option to begin your journey:\n");
      printf("1. Add contact\n");
      printf("2. Remove contact\n");
      printf("3. Search contacts\n");
      printf("4. Print all contacts\n");
      printf("5. Quit\n");
      printf("Enter your choice (1-5): ");
      scanf("%d", &choice);

      switch (choice) {
         case 1: 
            addContact();
            break;
         case 2:
            removeContact();
            break;
         case 3:
            searchContacts();
            break;
         case 4:
            printContacts();
            break;
         case 5:
            printf("Goodbye, friend.\n");
            break;
         default:
            printf("That's not an option. Please try again.\n");
            break;
      }
   } while (choice != 5);

   return 0;
}

void addContact() {
   if (numContacts < MAX_CONTACTS) {
      printf("Enter name: ");
      scanf("%s", phoneBook[numContacts].name);
      printf("Enter phone number: ");
      scanf("%s", phoneBook[numContacts].phone);
      printf("%s has been added to your dreamscape.\n", phoneBook[numContacts].name);
      numContacts++;
   } else {
      printf("You've reached the edge of the abyss. No more contacts can be added.\n");
   }
}

void removeContact() {
   char nameToRemove[CONTACT_NAME_LENGTH];
   int contactToRemove = -1;

   printf("Enter name you'd like to erase from existence: ");
   scanf("%s", nameToRemove);

   for (int i = 0; i < numContacts; i++) {
      if (strcmp(nameToRemove, phoneBook[i].name) == 0) {
         contactToRemove = i;
         break;
      }
   }

   if (contactToRemove == -1) {
      printf("%s was not found within your subconscious memory.\n", nameToRemove);
   } else {
      printf("%s has been erased from your dream world.\n", phoneBook[contactToRemove].name);

      for (int i = contactToRemove; i < numContacts - 1; i++) {
         strcpy(phoneBook[i].name, phoneBook[i+1].name);
         strcpy(phoneBook[i].phone, phoneBook[i+1].phone);
      }
      numContacts--;
   }
}

void searchContacts() {
   char nameToFind[CONTACT_NAME_LENGTH];
   int contactToFind = -1;

   printf("Enter name you'd like to search for: ");
   scanf("%s", nameToFind);

   for (int i = 0; i < numContacts; i++) {
      if (strcmp(nameToFind, phoneBook[i].name) == 0) {
         contactToFind = i;
         break;
      }
   }

   if (contactToFind == -1) {
      printf("%s is not present within the depths of your mind.\n", nameToFind);
   } else {
      printf("%s is a reflection of yourself, with phone number %s.\n", phoneBook[contactToFind].name, phoneBook[contactToFind].phone);
   }
}

void printContacts() {
   printf("Your surreal phone book contains %d contacts:\n", numContacts);

   for (int i = 0; i < numContacts; i++) {
      printf("%s: %s\n", phoneBook[i].name, phoneBook[i].phone);
   }
}