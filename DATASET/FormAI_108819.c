//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Customer {
  char name[50];
  int numOrders;
  float totalBill;
};

float calculateBill(int burgerQty, int pizzaQty, int pastaQty, int saladQty) {
  float burgerPrice = 3.50, pizzaPrice = 4.50, pastaPrice = 5.00, saladPrice = 2.50;
  float bill = (burgerPrice * burgerQty) + (pizzaPrice * pizzaQty) + (pastaPrice * pastaQty) + (saladPrice * saladQty);
  return bill;
}

void displayMenu() {
  printf("\nWelcome to C Cafe! Here's our menu:\n");
  printf("1. Burger - $3.50\n");
  printf("2. Pizza - $4.50\n");
  printf("3. Pasta - $5.00\n");
  printf("4. Salad - $2.50\n");
}

int main() {

  printf("Enter number of customers: ");
  int numCustomers;
  scanf("%d", &numCustomers);

  struct Customer customers[numCustomers];
  memset(customers, 0, sizeof(customers));
  
  for(int i=0; i<numCustomers; i++) {

    printf("\nEnter customer name: ");
    char name[50];
    scanf(" %[^\n]", name);
    strcpy(customers[i].name, name);

    printf("Enter number of burgers: ");
    int burgerQty;
    scanf("%d", &burgerQty);

    printf("Enter number of pizzas: ");
    int pizzaQty;
    scanf("%d", &pizzaQty);

    printf("Enter number of pastas: ");
    int pastaQty;
    scanf("%d", &pastaQty);

    printf("Enter number of salads: ");
    int saladQty;
    scanf("%d", &saladQty);

    float totalBill = calculateBill(burgerQty, pizzaQty, pastaQty, saladQty);
    customers[i].numOrders = burgerQty + pizzaQty + pastaQty + saladQty;
    customers[i].totalBill = totalBill;
  }

  printf("\nCustomer\tOrders\tBill\n");
  printf("_______________________________\n");
  for(int i=0; i<numCustomers; i++) {
    printf("%s\t\t%d\t$%.2f\n", customers[i].name, customers[i].numOrders, customers[i].totalBill);
  }

  return 0;
}