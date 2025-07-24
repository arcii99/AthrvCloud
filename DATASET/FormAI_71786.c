//FormAI DATASET v1.0 Category: Stock market tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   srand(time(NULL)); //initialize the random number generator

   int stocks[10]; //create an array to hold 10 stocks
   int prices[10]; //create an array to hold the prices of the stocks
   int change[10]; //create an array to hold the percentage change of the stocks

   //initialize the arrays with random values
   for(int i=0; i<10;i++){
       stocks[i] = rand() %1000; //assign a random ID for each stock
       prices[i] = rand() %50 + 50; //assign a random initial price between 50 and 100
       change[i] = rand() %10 - 5; //assign a random percentage change between -5% and +5%
   }

   while(1){
       system("clear"); //clear the console

       printf("<=========================== Surrealist Stock Market Tracker ===========================>\n\n");

       printf("Stock ID\tPrice\t\tPercentage Change\n");

       //print the information for each stock
       for(int i=0;i<10;i++){
           printf("%d\t\t$%d\t\t", stocks[i], prices[i]);
      
           if(change[i]>=0){
               printf("+%d%%\n", change[i]);
               prices[i] += (prices[i] * change[i]) / 100;
           }else{
               printf("%d%%\n", change[i]);
               prices[i] -= (prices[i] * (-change[i])) / 100;
           }
       }

       printf("\n");

       //wait for 3 seconds before updating the prices again
       sleep(3);
   }

   return 0;
}