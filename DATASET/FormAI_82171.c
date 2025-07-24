//FormAI DATASET v1.0 Category: Phone Book ; Style: ephemeral
// Ephemeral-style C Phone Book Program

#include <stdio.h>
#include <string.h>
#define MAX_ENTRIES 10

struct phonebookEntry {
   char name[50];
   char telephone[12];
};

int main() {
   struct phonebookEntry phoneBook[MAX_ENTRIES];
   int numberOfEntries = 0;
   char userInput[50];
   char tempName[50];
   char tempTelephone[12];

   printf("Welcome to your ephemeral phonebook program.\n");

   while (numberOfEntries < MAX_ENTRIES) {
      printf("Enter name and phone number separated by a comma.\n");
      fgets(userInput, 50, stdin);

      if (sscanf(userInput, "%[^,],%s", tempName, tempTelephone) == 2) {
         strcpy(phoneBook[numberOfEntries].name, tempName);
         strcpy(phoneBook[numberOfEntries].telephone, tempTelephone);
         printf("Entry added to the phonebook.\n");
         numberOfEntries++;
      } else {
         printf("Invalid input. Please try again.\n");
      }
   }

   printf("You have reached the maximum number of entries.\n");
   printf("Here is your phonebook:\n");

   for (int i = 0; i < numberOfEntries; i++) {
      printf("%s, %s\n", phoneBook[i].name, phoneBook[i].telephone);
   }

   return 0;
}