//FormAI DATASET v1.0 Category: Stock market tracker ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

struct stock {
   char name[20];
   float price;
};

typedef struct stock stock;

int main() {
   int num_stocks;
   printf("How many stocks do you want to track? ");
   scanf("%d", &num_stocks);

   // Allocate memory for the stocks
   stock *stocks = (stock *)malloc(num_stocks * sizeof(stock));

   // Fill in stock details
   for(int i=0; i<num_stocks; i++){
      printf("Enter stock name: ");
      scanf("%s", &(stocks+i)->name);
      printf("Enter price: ");
      scanf("%f", &(stocks+i)->price);
   }

   // Display stock details
   printf("\nStocks you are tracking:\n");
   for(int i=0; i<num_stocks; i++){
      printf("Stock %d\n", i+1);
      printf("Name: %s\n", (stocks+i)->name);
      printf("Price: %.2f\n", (stocks+i)->price);
   }

   // Free the memory
   free(stocks);

   return 0;
}