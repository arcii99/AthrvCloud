//FormAI DATASET v1.0 Category: Phone Book ; Style: Romeo and Juliet
#include<stdio.h>

struct contact {
  char name[50];
  char phone[20];
};

int main() {
  printf("Enter the number of contacts: ");
  int n;
  scanf("%d", &n);

  struct contact contacts[n];
  for (int i = 0; i < n; i++) {
    printf("Enter name of contact #%d: ", i+1);
    scanf("%s", contacts[i].name);
    printf("Enter phone number of contact #%d: ", i+1);
    scanf("%s", contacts[i].phone);
  }

  printf("\nList of Contacts:\n");
  for (int i = 0; i < n; i++) {
    printf("Name: %s\n", contacts[i].name);
    printf("Phone Number: %s\n", contacts[i].phone);
  }

  printf("\nThank you for using our Phone Book!");

  return 0;
}