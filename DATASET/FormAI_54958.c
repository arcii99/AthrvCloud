//FormAI DATASET v1.0 Category: Phone Book ; Style: inquisitive
#include <stdio.h>
#include <string.h>

struct PhoneBook {
  char name[50];
  char number[20];
};

int main() {
  int i, n;
  printf("How many contacts do you want to add? ");
  scanf("%d", &n);

  struct PhoneBook contact[n];

  for (i = 0; i < n; i++) {
    printf("\nEnter name for contact %d: ", i+1);
    scanf("%s", &contact[i].name);
    printf("Enter phone number for contact %d: ", i+1);
    scanf("%s", &contact[i].number);
  }

  char search_name[50];
  printf("\nEnter name to search: ");
  scanf("%s", &search_name);

  for (i = 0; i < n; i++) {
    if (strcmp(search_name, contact[i].name) == 0) {
      printf("\n%s's phone number is %s", contact[i].name, contact[i].number);
    }
  }

  return 0;
}