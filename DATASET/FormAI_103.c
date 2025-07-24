//FormAI DATASET v1.0 Category: Phone Book ; Style: intelligent
#include <stdio.h>
#include <string.h>

struct phonebookEntry {
  char name[50];
  char address[100];
  char phoneNumber[11];
};

int main() {
  int numEntries;
  printf("How many entries would you like to add to your phone book?\n");
  scanf("%d", &numEntries);

  struct phonebookEntry entries[numEntries];
  int i;
  for(i = 0; i < numEntries; i++) {
    printf("Enter the name of entry #%d: ", i+1);
    scanf("%s", entries[i].name);
    printf("Enter the address of entry #%d: ", i+1);
    scanf("%s", entries[i].address);
    printf("Enter the phone number of entry #%d: ", i+1);
    scanf("%s", entries[i].phoneNumber);
  }

  char searchName[50];
  printf("Enter the name of the person you would like to search for: ");
  scanf("%s", searchName);

  int found = 0;
  for(i = 0; i < numEntries; i++) {
    if(strcmp(searchName, entries[i].name) == 0) {
      printf("Entry found:\n");
      printf("Name: %s\n", entries[i].name);
      printf("Address: %s\n", entries[i].address);
      printf("Phone Number: %s\n", entries[i].phoneNumber);
      found = 1;
      break;
    }
  }

  if(!found) {
    printf("Entry not found.\n");
  }

  return 0;
}