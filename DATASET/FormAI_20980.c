//FormAI DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a structure to store bank customer information */
typedef struct {
   char name[50];
   int account_number;
   float balance;
} Customer;

/* Define a function to print out all the customers in the database */
void print_customers(Customer *customers, int num_customers) {
   int i;
   printf("Name \t\t Account Number \t\t Balance\n");
   printf("------------------------------------------------------------\n");
   for(i = 0; i < num_customers; i++) {
      printf("%s \t\t %d \t\t\t %.2f\n", customers[i].name, customers[i].account_number, customers[i].balance);
   }
}

int main() {
   int option;
   int i, index;
   int num_customers = 0;
   Customer *customers = calloc(10, sizeof(Customer)); /* Initialize 10 customers */
   do {
      printf("\nWelcome to the C Banking Record System\n");
      printf("1. Add Customer\n");
      printf("2. Delete Customer\n");
      printf("3. Search Customer by Account Number\n");
      printf("4. Update Customer Information\n");
      printf("5. Print All Customers in the Database\n");
      printf("6. Quit\n");
      printf("\nEnter your option: ");
      scanf("%d", &option);

      switch(option) {
         case 1: /* Add a new customer */
            printf("Enter the name of the customer: ");
            scanf("%s", customers[num_customers].name);
            printf("Enter the account number of the customer: ");
            scanf("%d", &customers[num_customers].account_number);
            printf("Enter the balance of the customer: ");
            scanf("%f", &customers[num_customers].balance);
            num_customers++;
            printf("Customer added successfully.\n");
            break;

         case 2: /* Remove an existing customer */
            printf("Enter the account number of the customer to be deleted: ");
            int account_number;
            int found = 0;
            scanf("%d", &account_number);
            for(i = 0; i < num_customers; i++) {
               if(customers[i].account_number == account_number) {
                  index = i;
                  found = 1;
                  break;
               }
            }
            if(found) {
               /* Move all customers to the left by 1 to overwrite the deleted customer */
               for(i = index; i < num_customers-1; i++) {
                  customers[i] = customers[i+1];
               }
               printf("Customer with account number %d deleted successfully.\n", account_number);
               num_customers--;
            } else {
               printf("Customer with account number %d not found.\n", account_number);
            }
            break;

         case 3: /* Search for a customer by account number */
            printf("Enter the account number of the customer to search for: ");
            scanf("%d", &account_number);
            found = 0;
            for(i = 0; i < num_customers; i++) {
               if(customers[i].account_number == account_number) {
                  printf("Name: %s\nAccount Number: %d\nBalance: %.2lf\n", customers[i].name, customers[i].account_number, customers[i].balance);
                  found = 1;
                  break;
               }
            }
            if(!found) {
               printf("Customer with account number %d not found.\n", account_number);
            }
            break;

         case 4: /* Update existing customer information */
            printf("Enter the account number of the customer to update information for: ");
            scanf("%d", &account_number);
            found = 0;
            for(i = 0; i < num_customers; i++) {
               if(customers[i].account_number == account_number) {
                  index = i;
                  found = 1;
                  break;
               }
            }
            if(found) {
               printf("Enter the new balance of the customer: ");
               scanf("%f", &customers[index].balance);
               printf("Customer information updated successfully.\n");
            } else {
               printf("Customer with account number %d not found.\n", account_number);
            }
            break;

         case 5: /* Print out all customers in the database */
            if(num_customers == 0) {
               printf("No customers in the database.\n");
            } else {
               print_customers(customers, num_customers);
            }
            break;

         case 6: /* Exit the program */
            printf("Exiting C Banking Record System.\n");
            break;

         default: /* Invalid option */
            printf("Invalid option. Please try again.\n");
            break;
      }

   } while(option != 6);

   free(customers); /* Free up memory allocated for customers */
   return 0;
}