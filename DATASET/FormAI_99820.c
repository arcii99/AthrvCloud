//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>

int main() {
   float coffee_price = 2.50; // Price of a cup of coffee
   float tea_price = 2.00; // Price of a cup of tea
   float total = 0.00; // Total amount due
   char order_type; // Type of order: (C)offee or (T)ea
   int order_quantity; // Quantity of the order
   
   printf("*** WELCOME TO OUR CAFE! ***\n\n");
   
   do {
      printf("What would you like to order? (C)offee or (T)ea? ");
      scanf(" %c", &order_type); // Get user's order type
      
      if(order_type == 'C' || order_type == 'c') { // User wants to order coffee
         printf("How many cups of coffee would you like? ");
         scanf("%d", &order_quantity); // Get user's order quantity
         total += (order_quantity * coffee_price); // Add the current order total to the running total
      }
      else if(order_type == 'T' || order_type == 't') { // User wants to order tea
         printf("How many cups of tea would you like? ");
         scanf("%d", &order_quantity); // Get user's order quantity
         total += (order_quantity * tea_price); // Add the current order total to the running total
      }
      else { // User entered an invalid order type
         printf("Invalid order type. Please enter C for coffee or T for tea.\n");
      }
      
      printf("\nYour current total is: $%.2f\n\n", total); // Display user's running total
      
      printf("Would you like to place another order? (Y/N) ");
      scanf(" %c", &order_type); // Get user's answer
      
      while(order_type != 'Y' && order_type != 'y' && order_type != 'N' && order_type != 'n') { // User entered an invalid answer
         printf("Invalid answer. Please enter Y for yes or N for no.\n");
         printf("Would you like to place another order? (Y/N) ");
         scanf(" %c", &order_type); // Get user's answer
      }
      
   } while(order_type == 'Y' || order_type == 'y'); // Keep looping until user says no
   
   printf("\nThank you for ordering from our cafe!\n");
   printf("Your total amount due is: $%.2f\n\n", total); // Display the final total
   
   return 0;
}