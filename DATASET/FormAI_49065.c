//FormAI DATASET v1.0 Category: Phone Book ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for storing phone book entries
typedef struct {
  char name[100];
  char number[20];
  char address[200];
} PhoneEntry;

int main() {
  // Initialize an array of 10 PhoneEntry structs
  PhoneEntry phonebook[10];

  // Prompt user to input data for each entry
  for (int i = 0; i < 10; i++) {
    printf("\nEnter details for person #%d\n", i+1);

    // Prompt user to input name
    printf("Name: ");
    fgets(phonebook[i].name, 100, stdin);
    phonebook[i].name[strcspn(phonebook[i].name, "\n")] = 0;

    // Prompt user to input number
    printf("Number: ");
    fgets(phonebook[i].number, 20, stdin);
    phonebook[i].number[strcspn(phonebook[i].number, "\n")] = 0;

    // Prompt user to input address
    printf("Address: ");
    fgets(phonebook[i].address, 200, stdin);
    phonebook[i].address[strcspn(phonebook[i].address, "\n")] = 0;
  }

  // Print out all phone book entries
  printf("\nPhone Book Entries:\n");
  for (int i = 0; i < 10; i++) {
    printf("\n%d. %s\n   %s\n   %s\n", i+1, phonebook[i].name, phonebook[i].number, phonebook[i].address);
  }

  return 0;
}