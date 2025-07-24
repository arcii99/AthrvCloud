//FormAI DATASET v1.0 Category: Banking Record System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
 
// Structure for each bank record
struct bankRecord {
   int accountNumber;
   char customerName[50];
   int accountBalance;
};
 
// Function to create a new bank record
struct bankRecord createRecord(int accNo, char custName[], int accBal) {
   struct bankRecord rec;
   rec.accountNumber = accNo;
   strcpy(rec.customerName,custName);
   rec.accountBalance = accBal;
   return rec;
}
 
// Function to print a bank record
void printRecord(struct bankRecord rec) {
   printf("Account Number: %d\n", rec.accountNumber);
   printf("Customer Name: %s\n", rec.customerName);
   printf("Account Balance: %d\n\n", rec.accountBalance);
}
 
int main()
{
   // Create an array of bank records
   struct bankRecord bankRecords[3];
   bankRecords[0] = createRecord(1, "John Doe", 500);
   bankRecords[1] = createRecord(2, "Jane Smith", 1000);
   bankRecords[2] = createRecord(3, "Bob Johnson", 250);
 
   // Print out all bank records
   for (int i = 0; i < 3; i++) {
      printf("Bank Record #%d:\n", i);
      printRecord(bankRecords[i]);
   }
 
   return 0;
}