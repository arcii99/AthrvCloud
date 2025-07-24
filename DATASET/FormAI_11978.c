//FormAI DATASET v1.0 Category: Phone Book ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_NUM_LEN 10

struct contact {
   char name[MAX_NAME_LEN];
   char number[MAX_NUM_LEN];
};

int main() {
   struct contact phone_book[100];
   int count = 0;
   int i;

   while (1) {
      printf("Enter name (or 'quit' to exit): ");
      scanf("%s", phone_book[count].name);
      
      if (strcmp(phone_book[count].name, "quit") == 0) {
         break;
      }
      
      printf("Enter number: ");
      scanf("%s", phone_book[count].number);
      count++;
   }

   printf("\nPhone book:\n");

   for (i = 0; i < count; i++) {
      printf("%s\t%s\n", phone_book[i].name, phone_book[i].number);
   }

   return 0;
}