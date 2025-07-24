//FormAI DATASET v1.0 Category: Stock market tracker ; Style: futuristic
//Futuristic C Stock Market Tracker

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); //initialize random seed

   //declare variables
   float CI = 25000.00; //current index
   float stocks[5] = {0}; //initialize stocks array with 5 elements
   int option = 0; //user option
   float random = 0; //random number generated to simulate market conditions

   //display welcome message and initial stock prices
   printf("Welcome to the Futuristic C Stock Market Tracker!\n");
   for (int i = 0; i < 5; i++) {
      stocks[i] = CI + (rand() % 500 - 250); //randomly generate starting stock prices
      printf("Stock %d: $%.2f\n", i+1, stocks[i]);
   }

   //loop while user input is not 'q'
   while (option != 'q') {
      //display menu options
      printf("\nWhat would you like to do?\n");
      printf("1. View stock prices\n");
      printf("2. Simulate market conditions\n");
      printf("3. Buy stocks\n");
      printf("4. Sell stocks\n");
      printf("q. Quit\n");
      printf("Enter option: ");
      scanf(" %d", &option); //get user option

      //process user option
      switch (option) {
         case 1:
            //display current stock prices
            printf("\nCurrent Stock Prices:\n");
            for (int i = 0; i < 5; i++) {
               printf("Stock %d: $%.2f\n", i+1, stocks[i]);
            }
            break;
         case 2:
            //simulate market conditions
            random = (float)(rand() % 200 - 100)/100; //randomly generate a float between -1 and 1
            CI += random; //update current index with random value
            for (int i = 0; i < 5; i++) {
               stocks[i] *= (1 + random); //update stock prices using random value
            }
            printf("\nMarket conditions simulated.\n");
            break;
         case 3:
            //buy stocks
            printf("\nWhich stock would you like to buy? (1-5): ");
            int stocknum;
            scanf(" %d", &stocknum); //get user input for stock number
            printf("Enter amount to buy: $");
            float amount;
            scanf(" %f", &amount); //get user input for amount to buy
            stocks[stocknum-1] += amount/stocks[stocknum-1]; //update stock with purchased amount
            printf("$%.2f worth of stock %d purchased.\n", amount, stocknum);
            break;
         case 4:
            //sell stocks
            printf("\nWhich stock would you like to sell? (1-5): ");
            scanf(" %d", &stocknum); //get user input for stock number
            printf("Enter amount to sell: $");
            scanf(" %f", &amount); //get user input for amount to sell
            if (amount > stocks[stocknum-1]) { //check if user is selling more stocks than they have
               printf("Error: not enough stocks available to sell.\n");
            } else {
               stocks[stocknum-1] -= amount/stocks[stocknum-1]; //update stock with sold amount
               printf("$%.2f worth of stock %d sold.\n", amount, stocknum);
            }
            break;
         case 'q':
            //quit program
            printf("\nGoodbye!\n");
            break;
         default:
            //invalid user input
            printf("\nInvalid option! Try again.\n");
            break;
      }
   }

   return 0;
}