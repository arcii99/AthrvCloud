//FormAI DATASET v1.0 Category: Banking Record System ; Style: irregular
#include<stdio.h>

struct BankRecord {
   int account_number;
   char name[50];
   float balance;
};

int main() {
   struct BankRecord bank[3];

   for (int i = 0; i < 3; i++) {
      printf("\nEnter account number for customer %d: ", i+1);
      scanf("%d", &bank[i].account_number);
      printf("Enter name for customer %d: ", i+1);
      scanf("%s", bank[i].name);
      printf("Enter balance for customer %d: ", i+1);
      scanf("%f", &bank[i].balance);
   }

   printf("\nBank Records:");

   for (int i = 0; i < 3; i++) {
      printf("\nAccount Number: %d", bank[i].account_number);
      printf("\nName: %s", bank[i].name);
      printf("\nBalance: %.2f", bank[i].balance);
   }

   return 0;
}