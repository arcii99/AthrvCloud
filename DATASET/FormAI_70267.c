//FormAI DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold banking records
struct BankRecord {
   int accountNumber;
   char customerName[100];
   float accountBalance;
};

int main() {
   // Initialize banking records
   int numRecords = 5;
   struct BankRecord records[numRecords];

   // Add some funny customer names
   strcpy(records[0].customerName, "Donald Duck");
   strcpy(records[1].customerName, "Mickey Mouse");
   strcpy(records[2].customerName, "Goofy Goof");
   strcpy(records[3].customerName, "Scooby Doo");
   strcpy(records[4].customerName, "Shaggy Rogers");

   // Add some account balances
   records[0].accountBalance = 100.50;
   records[1].accountBalance = 350.00;
   records[2].accountBalance = 1000.25;
   records[3].accountBalance = 50.75;
   records[4].accountBalance = 200.00;

   // Assign account numbers
   for (int i = 0; i < numRecords; i++) {
      records[i].accountNumber = i + 1000;
   }

   // Display banking records
   printf("Banking Records:\n");
   for (int i = 0; i < numRecords; i++) {
      printf("Account Number: %d\n", records[i].accountNumber);
      printf("Customer Name: %s\n", records[i].customerName);
      printf("Account Balance: $%.2f\n\n", records[i].accountBalance);
   }

   // Exit program
   return 0;
}