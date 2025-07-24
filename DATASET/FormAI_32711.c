//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct menu_item {
  char item_name[50];
  int item_price;
};

int main() {
  struct menu_item menu[10];

  strcpy(menu[0].item_name, "Black Coffee");
  menu[0].item_price = 50;
  
  strcpy(menu[1].item_name, "Latte");
  menu[1].item_price = 80;
  
  // Add more menu items as required
  
  int total = 0;
  char choice[50];
  int quantity;
  int flag = 0;

  printf("Welcome to the C Cafe billing system!\n");

  while(1) {
    printf("\nMENU:\n");
    for(int i = 0; i < 10; i++) {
      if(strlen(menu[i].item_name) == 0) {
        break;
      }
      printf("%d. %s - Rs. %d\n", i+1, menu[i].item_name, menu[i].item_price);
    }
    printf("\nEnter your choice (or enter 'done' if finished): ");

    scanf("%s", choice);

    if(strcmp(choice, "done") == 0) {
      flag = 1;
      break;
    }

    int item_index = atoi(choice) - 1;
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    total += menu[item_index].item_price * quantity;
  }

  if(flag) {
    printf("\nTotal bill amount: Rs. %d", total);
    printf("\nThank you for visiting C Cafe! Come back soon.\n");
  }

  return 0;
}