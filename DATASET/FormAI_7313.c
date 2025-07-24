//FormAI DATASET v1.0 Category: Data mining ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

struct customer {
   int id;
   char name[32];
   char address[64];
   float spend;
} customers[5];

int main()
{
   int i, j;
   float max_spend = 0.0;

   // Input customer data
   for (i = 0; i < 5; i++) {
      printf("Enter customer ID, name, address, and spend (separated by commas): ");
      scanf("%d, %[^,], %[^\n], %f", &customers[i].id, customers[i].name, customers[i].address, &customers[i].spend);
   }

   // Output data
   printf("Customer data:\n");
   for (i = 0; i < 5; i++) {
      printf("ID: %d\nName: %s\nAddress: %s\nSpend: %.2f\n\n", customers[i].id, customers[i].name, customers[i].address, customers[i].spend);

      // find customer with highest spend
      if (customers[i].spend > max_spend) {
         max_spend = customers[i].spend;
         j = i;
      }
   }

   // Output customer with highest spend
   printf("Customer with highest spend:\nID: %d\nName: %s\nAddress: %s\nSpend: %.2f\n", customers[j].id, customers[j].name, customers[j].address, customers[j].spend);

   return 0;
}