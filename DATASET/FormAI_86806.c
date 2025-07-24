//FormAI DATASET v1.0 Category: Phone Book ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct contact {
   int phone_num;
   char name[50];
};

int main() {
   int num;
   printf("Enter the number of contacts you want to store: ");
   scanf("%d", &num);

   struct contact *contacts;
   contacts = (struct contact*)malloc(num * sizeof(struct contact));

   for(int i=0; i<num; i++) {
      printf("\nEnter contact %d details:\n", i+1);
      printf("Name: ");
      getchar(); // to consume the newline character in the input buffer
      fgets(contacts[i].name, 50, stdin);
      printf("Phone number: ");
      scanf("%d", &contacts[i].phone_num);
   }

   // displaying the entered contacts
   printf("\nEntered Contacts:\n");
   for(int i=0; i<num; i++) {
      printf("\nContact %d:\n", i+1);
      printf("Name: %s", contacts[i].name);
      printf("Phone number: %d", contacts[i].phone_num);
   }

   free(contacts);
   return 0;
}