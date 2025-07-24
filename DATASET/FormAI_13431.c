//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Alan Touring
// C Stock Market Tracker Program in Alan Turing Style

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stock{
   char symbol[10];
   float price;
   int volume;
   float high;
   float low;
};

// function to display stock information
void displayStock(struct stock s){
   printf("Stock Symbol: %s\n", s.symbol);
   printf("Price: %.2f\n", s.price);
   printf("Volume: %d\n", s.volume);
   printf("High: %.2f\n", s.high);
   printf("Low: %.2f\n", s.low);
}

// function to update stock information
void updateStock(struct stock *s, float newPrice, int newVolume){
   s->price = newPrice;
   s->volume = newVolume;
   if(newPrice > s->high){
      s->high = newPrice;
   }
   if(newPrice < s->low){
      s->low = newPrice;
   }
}

int main(){

   // create an array of stocks
   struct stock s[5];

   // initialize stock information
   strcpy(s[0].symbol, "AAPL");
   s[0].price = 150.00;
   s[0].volume = 10000;
   s[0].high = s[0].price;
   s[0].low = s[0].price;

   strcpy(s[1].symbol, "GOOG");
   s[1].price = 700.00;
   s[1].volume = 5000;
   s[1].high = s[1].price;
   s[1].low = s[1].price;

   strcpy(s[2].symbol, "FB");
   s[2].price = 120.00;
   s[2].volume = 8000;
   s[2].high = s[2].price;
   s[2].low = s[2].price;

   strcpy(s[3].symbol, "NFLX");
   s[3].price = 180.00;
   s[3].volume = 2000;
   s[3].high = s[3].price;
   s[3].low = s[3].price;

   strcpy(s[4].symbol, "TSLA");
   s[4].price = 300.00;
   s[4].volume = 15000;
   s[4].high = s[4].price;
   s[4].low = s[4].price;

   // display initial stock information
   printf("=== Initial Stock Information ===\n");
   displayStock(s[0]);
   displayStock(s[1]);
   displayStock(s[2]);
   displayStock(s[3]);
   displayStock(s[4]);

   // update stock information
   printf("\n=== New Stock Information ===\n");
   updateStock(&s[0], 155.00, 12000);
   updateStock(&s[1], 720.00, 6000);
   updateStock(&s[2], 125.00, 10000);
   updateStock(&s[3], 170.00, 5000);
   updateStock(&s[4], 290.00, 18000);

   // display updated stock information
   displayStock(s[0]);
   displayStock(s[1]);
   displayStock(s[2]);
   displayStock(s[3]);
   displayStock(s[4]);

   return 0;
}