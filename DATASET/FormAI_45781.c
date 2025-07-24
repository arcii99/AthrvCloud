//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {                   //structure for menu items
   char name[50];
   float price;
   int quantity;
};

void add_to_cart(struct item menu[], struct item cart[], int *cart_size, int item_id, int qty); //add selected item to cart
void print_menu(struct item menu[]);  //print list of menu items
void print_cart(struct item cart[], int *cart_size); //print current items in cart


int main() {
   struct item menu[] = {{"Coffee", 1.50, 10}, {"Tea", 1.00, 15}, {"Sandwich", 3.00, 5}, {"Muffin", 2.00, 7}};  //sample menu items
   struct item cart[50];  //maximum 50 items can be added to a cart
   int cart_size = 0;
   int n;
   printf("Welcome to the Cafe Billing System!\n");

   do {
      printf("\nMenu:\n");
      print_menu(menu);
      printf("\nCurrent Cart:\n");
      print_cart(cart, &cart_size);
      printf("\nWhat would you like to order? (Enter ID and Quantity separated by space, enter 0 to exit): ");
      int item_id, qty;
      scanf("%d %d", &item_id, &qty);
      if (item_id == 0) {
         break;
      }
      add_to_cart(menu, cart, &cart_size, item_id-1, qty);
   } while (1);

   printf("\nHere is your receipt:\n");
   print_cart(cart, &cart_size);
   float total = 0;
   for (int i = 0; i < cart_size; i++) {
      total += cart[i].price * cart[i].quantity;
   }
   printf("\nTotal: $%.2f", total);
   printf("\nThank you for choosing our Cafe!");
   return 0;
}

void add_to_cart(struct item menu[], struct item cart[], int *cart_size, int item_id, int qty) {
   //check if item is already in cart
   for (int i = 0; i < *cart_size; i++) {
      if (strcmp(menu[item_id].name, cart[i].name) == 0) {
         cart[i].quantity += qty;
         if (cart[i].quantity > menu[item_id].quantity) {   //check if item quantity in cart exceeds availability
            printf("\nCannot add more than %d %s to cart!", menu[item_id].quantity, menu[item_id].name);
            cart[i].quantity -= qty;   //roll back quantity
         }
         return;
      }
   }
   if (menu[item_id].quantity < qty) {  //check if requested quantity exceeds availability
      printf("\nCannot add more than %d %s to cart!", menu[item_id].quantity, menu[item_id].name);
      return;
   }
   cart[*cart_size] = menu[item_id];
   cart[*cart_size].quantity = qty;  //set quantity to user input
   (*cart_size)++;
   return;
}

void print_menu(struct item menu[]) {
   printf("-------------------------------------------\n");
   printf("ID\tNAME\t\tPRICE\n");
   printf("-------------------------------------------\n");
   for (int i = 0; i < 4; i++) {  //print all menu items
      printf("%d\t", i+1);
      printf("%-15s", menu[i].name);
      printf("$%.2f\n", menu[i].price);
   }
   return;
}

void print_cart(struct item cart[], int *cart_size) {
   printf("-------------------------------------------\n");
   printf("NAME\t\tQUANTITY\tPRICE\n");
   printf("-------------------------------------------\n");
   for (int i = 0; i < *cart_size; i++) {  //print all items in cart
      printf("%-15s", cart[i].name);
      printf("%-15d", cart[i].quantity);
      printf("$%.2f\n", cart[i].price * cart[i].quantity);
   }
   return;
}