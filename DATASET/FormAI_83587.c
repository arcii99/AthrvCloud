//FormAI DATASET v1.0 Category: Phone Book ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contact {
  char name[50];
  char phone_num[15];
};

typedef struct contact Contact;

int main() {
  int num_contacts;
  printf("Enter the number of contacts you want to add: ");
  scanf("%d", &num_contacts);

  Contact *phone_book = (Contact*)malloc(num_contacts * sizeof(Contact));

  if(phone_book == NULL) {
    printf("Could not allocate memory!");
    return 1;
  }

  printf("\nEnter the contacts' details:\n");

  for(int i=0; i<num_contacts; i++) {
    printf("\nContact %d:\n", i+1);
    printf("Name: ");
    scanf("%s", phone_book[i].name);
    printf("Phone Number: ");
    scanf("%s", phone_book[i].phone_num);
  }

  printf("\n======= Phone Book =======\n");
  printf("Name\t\tPhone Number\n");

  for(int i=0; i<num_contacts; i++) {
    printf("%-20s %s\n", phone_book[i].name, phone_book[i].phone_num);
  }

  free(phone_book);
  return 0;
}