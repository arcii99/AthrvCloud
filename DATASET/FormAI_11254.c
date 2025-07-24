//FormAI DATASET v1.0 Category: Stock market tracker ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
   int stock_prices[10], i;

   srand(time(NULL)); //setting the seed for random numbers

   printf("Welcome to the Chuck Norris Stock Market Tracker!\n");

   //Loop to generate random stock prices
   for(i=0; i<10; i++){
      stock_prices[i] = (rand() % 100) + 1; //random stock price between 1 and 100
      printf("Stock price for Chuck Norris Enterprise Inc at Day %d: $%d\n", i+1, stock_prices[i]);
   }

   printf("Please enter the day number you want to check the stock price for: ");
   int day;
   scanf("%d", &day);

   if(day >=1 && day <=10){
      printf("The stock price for Chuck Norris Enterprise Inc at Day %d is $%d.\n", day, stock_prices[day-1]);
   }
   else{
      printf("Invalid input. Please enter a number between 1 and 10.\n");
   }

   printf("Thank you for using the Chuck Norris Stock Market Tracker. Stay profitable!\n");

   return 0;
}