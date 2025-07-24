//FormAI DATASET v1.0 Category: Stock market tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 50
#define MAX_NAME_LENGTH 20

struct stock {
   char name[MAX_NAME_LENGTH];
   float price;
   int quantity;
};

struct portfolio {
   char name[MAX_NAME_LENGTH];
   struct stock stocks[MAX_STOCKS];
   int count;
};

void print_portfolio(struct portfolio *p) {
   if (p->count == 0) {
      printf("The portfolio '%s' is empty.\n", p->name);
   } else {
      printf("Portfolio '%s':\n", p->name);
      for (int i = 0; i < p->count; i++) {
         printf("  %s: $%.2f (%d shares)\n", p->stocks[i].name, p->stocks[i].price, p->stocks[i].quantity);
      }
   }
}

void add_stock(struct portfolio *p, char *name, float price, int quantity) {
   if (p->count == MAX_STOCKS) {
      printf("Error: portfolio is full, cannot add '%s'\n", name);
      return;
   }

   for (int i = 0; i < p->count; i++) {
      if (strcmp(p->stocks[i].name, name) == 0) {
         printf("Error: '%s' already exists in portfolio '%s'\n", name, p->name);
         return;
      }
   }

   struct stock new_stock;
   strncpy(new_stock.name, name, MAX_NAME_LENGTH);
   new_stock.price = price;
   new_stock.quantity = quantity;
   p->stocks[p->count] = new_stock;
   p->count++;

   printf("Added '%s' to portfolio '%s'\n", name, p->name);
}

void remove_stock(struct portfolio *p, char *name) {
   int found = 0;

   for (int i = 0; i < p->count; i++) {
      if (strcmp(p->stocks[i].name, name) == 0) {
         found = 1;

         printf("Removed '%s' from portfolio '%s'\n", name, p->name);

         for (int j = i; j < p->count - 1; j++) {
            p->stocks[j] = p->stocks[j+1];
         }

         p->count--;
      }
   }

   if (!found) {
      printf("Error: '%s' not found in portfolio '%s'\n", name, p->name);
   }
}

void update_stock(struct portfolio *p, char *name, float price, int quantity) {
   int found = 0;

   for (int i = 0; i < p->count; i++) {
      if (strcmp(p->stocks[i].name, name) == 0) {
         found = 1;

         p->stocks[i].price = price;
         p->stocks[i].quantity = quantity;

         printf("Updated '%s' in portfolio '%s'\n", name, p->name);
      }
   }

   if (!found) {
      printf("Error: '%s' not found in portfolio '%s'\n", name, p->name);
   }
}

int main() {
   struct portfolio my_portfolio = { "My Portfolio", {}, 0 };

   add_stock(&my_portfolio, "AAPL", 130.41, 100);
   add_stock(&my_portfolio, "GOOG", 2433.53, 50);
   add_stock(&my_portfolio, "AMZN", 3340.88, 25);
   print_portfolio(&my_portfolio);

   update_stock(&my_portfolio, "AAPL", 135.47, 150);
   remove_stock(&my_portfolio, "GOOG");
   print_portfolio(&my_portfolio);

   add_stock(&my_portfolio, "TSLA", 568.82, 75);
   add_stock(&my_portfolio, "NVDA", 193.08, 125);
   print_portfolio(&my_portfolio);

   update_stock(&my_portfolio, "AMZN", 3457.16, 10);
   remove_stock(&my_portfolio, "AAPL");
   print_portfolio(&my_portfolio);

   return 0;
}