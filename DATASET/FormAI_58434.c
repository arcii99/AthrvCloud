//FormAI DATASET v1.0 Category: Stock market tracker ; Style: protected
#include <stdio.h> 
#include <stdlib.h> 

int main() 
{ 
   char company[50] = "Apple Inc."; // Change the company name to the desired stock.
   float price, change, percent_change;

   // Randomly generate initial stock price between $50 and $100.
   price = (rand() % 5000)/100.00 + 50.00; 
   
   printf("%s Tracker\n", company);
   printf("Initial Price: $%.2f\n\n", price);
   
   while(1) // Infinite loop to continuously track changes.
   {
      // Randomly generate change in stock price between -$2.00 and $2.00.
      change = ((rand() % 400)/100.00) - 2.00;
      
      price += change; // Update price of stock.
      
      // Calculate percent change.
      percent_change = (change/price) * 100;
      
      // Print out change in stock price and percent change.
      printf("Change: %.2f\n", change);
      printf("Percent Change: %.2f%\n", percent_change);
      
      // Sleep for 5 seconds before generating next change in stock price.
      sleep(5);
   }

   return 0;
}