//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: artistic
#include<stdio.h>
#include<stdlib.h>
typedef struct Customer{
    int tableNumber;
    char name[50];
    int foodPrice;
    int drinkPrice;
    int totalCost;
}Customer;

void printBill(Customer customer){
    printf("\nTable Number: %d\nCustomer Name: %s\n",customer.tableNumber,customer.name);
    printf("\nFood Cost: %d\nDrink Cost: %d\nTotal Cost: %d\n",customer.foodPrice,customer.drinkPrice,customer.totalCost);
    printf("\n----------------------");
}

int main(){
    int num;
    printf("Enter the number of customers: ");
    scanf("%d",&num);

    Customer *customerList = (Customer*)malloc(num*sizeof(Customer));

    for(int i=0;i<num;i++){
        printf("\n\nEnter details for Customer %d:\n",i+1);
        printf("Table number: ");
        scanf("%d",&(customerList[i].tableNumber));

        printf("Name: ");
        scanf("%s",customerList[i].name);

        printf("Food cost: ");
        scanf("%d",&customerList[i].foodPrice);

        printf("Drink cost: ");
        scanf("%d",&customerList[i].drinkPrice);

        customerList[i].totalCost = customerList[i].foodPrice+customerList[i].drinkPrice;

        printf("\nBill for Customer %d:\n",i+1);
        printBill(customerList[i]);
    }

    free(customerList);

    return 0;
}