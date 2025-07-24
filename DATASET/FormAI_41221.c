//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  #define PILLS 1000
  #define MAX_PURCHASES 50
  
  char pill_names[PILLS][50] = {"Pain-Killer", "Antibiotic", "Anti Inflammatory", "Vitamin C", "Anti Allergy"};
  float pill_prices[PILLS] = {2.50, 1.80, 1.55, 4.20, 3.90};
  int pill_stock[PILLS] = {100, 150, 75, 200, 125};
  int total_sales = 0, total_purchases = 0;
  
  char purchase_names[MAX_PURCHASES][50];
  int purchase_qtys[MAX_PURCHASES];
  float purchase_prices[MAX_PURCHASES];
  
  printf("Welcome to the Surreal Medical Store Management System!\n\n");
  
  int choice = 0;
  do {
    printf("What would you like to do?\n");
    printf("1. Purchase pills\n");
    printf("2. View available pills\n");
    printf("3. View purchase history\n");
    printf("4. Exit\n\n");
    printf("Your choice (1-4): ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1: {
        printf("\n----- Purchase pills -----\n");
        printf("Enter the name of the pill you want to purchase: ");
        char pill_name[50];
        scanf("%s", pill_name);
        
        int pill_idx = -1;
        for(int i = 0; i < PILLS; ++i) {
          if(strcmp(pill_names[i], pill_name) == 0) {
            pill_idx = i;
            break;
          }
        }
        
        if(pill_idx == -1) {
          printf("Sorry, we don't carry that pill.\n");
        }
        else {
          int qty = 0;
          printf("Enter the quantity you want to purchase: ");
          scanf("%d", &qty);
          
          if(qty <= 0) {
            printf("Invalid quantity.\n");
          }
          else if(qty > pill_stock[pill_idx]) {
            printf("Sorry, we don't have enough stock of that pill.\n");
          }
          else {
            float price = qty * pill_prices[pill_idx];
            purchase_qtys[total_purchases] = qty;
            purchase_prices[total_purchases] = price;
            strcpy(purchase_names[total_purchases], pill_name);
            total_purchases++;
            
            printf("That will be $%.2f. Thank you for your purchase!\n\n", price);
            total_sales += qty * pill_prices[pill_idx];
            pill_stock[pill_idx] -= qty;
          }
        }
        break;
      }
      case 2: {
        printf("\n----- Available pills -----\n");
        printf("Name\t\tPrice\tStock\n\n");
        for(int i = 0; i < PILLS; ++i) {
          printf("%s\t$%.2f\t%d\n", pill_names[i], pill_prices[i], pill_stock[i]);
        }
        printf("\n");
        break;
      }
      case 3: {
        printf("\n----- Purchase history -----\n");
        if(total_purchases == 0) {
          printf("No purchases made yet.\n");
        }
        else {
          printf("Pill\tQty\tPrice\n\n");
          for(int i = 0; i < total_purchases; ++i) {
            printf("%s\t%d\t$%.2f\n", purchase_names[i], purchase_qtys[i], purchase_prices[i]);
          }
          printf("\n");
        }
        
        printf("Total sales: $%.2f\n\n", total_sales);
        break;
      }
      case 4: {
        printf("\nThank you for using the Surreal Medical Store Management System!\n\n");
        break;
      }
      default: {
        printf("\nInvalid choice. Please try again.\n\n");
        break;
      }
    }
    
  } while(choice != 4);
  
  return 0;
}