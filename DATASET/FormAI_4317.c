//FormAI DATASET v1.0 Category: Phone Book ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>

struct phone_number {
  char name[50];
  char number[20];
};

int main() {
  int count = 0;
  struct phone_number contacts[50];

  // Adding contacts
  strcpy(contacts[count].name, "John Doe");
  strcpy(contacts[count].number, "555-1234");
  count++;

  strcpy(contacts[count].name, "Jane Smith");
  strcpy(contacts[count].number, "555-5678");
  count++;

  // Printing contacts
  printf("Phone Book\n----------\n");
  for(int i = 0; i < count; i++) {
    printf("%s\t%s\n", contacts[i].name, contacts[i].number);
  }

  return 0;
}