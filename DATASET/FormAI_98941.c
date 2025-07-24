//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

int main() {
    int priceOfTea = 15; // cost of a cup of tea
    int priceOfCoffee = 20; // cost of a cup of coffee
    int quantityOfTea = 0; // default quantity of tea
    int quantityOfCoffee = 0; // default quantity of coffee
    float serviceTax = 0.05; // 5% service tax
    float totalBill = 0; // default total bill value
    
    // get the quantity of tea from the customer
    printf("Enter the quantity of tea: ");
    scanf("%d", &quantityOfTea);
    
    // get the quantity of coffee from the customer
    printf("Enter the quantity of coffee: ");
    scanf("%d", &quantityOfCoffee);
    
    // calculate the bill for tea and coffee
    float billForTea = (priceOfTea * quantityOfTea);
    float billForCoffee = (priceOfCoffee * quantityOfCoffee);
    
    // calculate the total bill amount with service tax
    totalBill = (billForTea + billForCoffee) + (serviceTax * (billForTea + billForCoffee));
    
    printf("\n\n");
    printf("--------------------------------------------------\n");
    printf("-----------------------BILL-----------------------\n");
    printf("--------------------------------------------------\n");
    
    // display the item details and the bill amount
    printf("Item\t\t\tQuantity\t\tPrice\n");
    printf("Tea\t\t\t%d\t\t\tRs. %d\n", quantityOfTea, priceOfTea);
    printf("Coffee\t\t\t%d\t\t\tRs. %d\n", quantityOfCoffee, priceOfCoffee);
    printf("\n");
    printf("Service Tax (5%%)\t\t\t\tRs. %.2f\n", serviceTax * (billForTea + billForCoffee));
    printf("Total Bill\t\t\t\tRs. %.2f\n", totalBill);
    
    printf("--------------------------------------------------\n");
    printf("----------------------- THANK ---------------------\n");
    printf("----------------------- YOU -----------------------\n");
    printf("--------------------------------------------------\n");
    
    return 0;
}