//FormAI DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>

struct Customer {
   char name[50];
   int account_number;
   float balance;
};

void print_customer(struct Customer cust) {
   printf("====================\n");
   printf("Name: %s\n", cust.name);
   printf("Account Number: %d\n", cust.account_number);
   printf("Balance: %.2f\n", cust.balance);
}

int main() {
   struct Customer c1 = {"John Smith", 123456789, 1000.00};
   struct Customer c2 = {"Jane Doe", 987654321, 500.00};

   printf("\nInitial Customer Information:\n");
   print_customer(c1);
   print_customer(c2);

   // Add deposit function
   void deposit(struct Customer *cust, float amount) {
      cust->balance += amount;
   }

   // Add withdraw function
   void withdraw(struct Customer *cust, float amount) {
      if (amount <= cust->balance) {
         cust->balance -= amount;
      } 
      else {
         printf("Withdraw failed. Insufficient funds.\n");
      }
   }

   // Perform transactions
   deposit(&c1, 250.00);
   withdraw(&c2, 100.00);

   // Print updated customer information
   printf("\nUpdated Customer Information:\n");
   print_customer(c1);
   print_customer(c2);

   return 0;
}