//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct bill{
    char item[30];
    int quantity;
    float price;
    float total;
}; // structure to store item, quantity, price and total cost

int main(){
    int n;  //number of items
    float grand_total = 0;  // to store total billing amount
    printf("\t\tWELCOME TO C CAFE\n");
    printf("\t\t-----------------\n\n");
    printf("How many items you want to order? ");
    scanf("%d",&n);
    struct bill orders[n]; // array of structure
    for(int i=0; i<n; i++){
        printf("\nEnter the item name: ");
        scanf("%s",&orders[i].item);
        printf("Enter the quantity: ");
        scanf("%d",&orders[i].quantity);
        printf("Enter the price: ");
        scanf("%f",&orders[i].price);
        orders[i].total = orders[i].quantity * orders[i].price; //calculate total cost of a single item
        grand_total+= orders[i].total; // add the item total to grand total
    }
    printf("\n\n");
    printf("\t\tItem\t\tQuantity\tPrice\tTotal\n");
    printf("\t\t-----------------------------------------------\n");

    for(int i=0; i<n; i++){
        printf("\t\t%s\t\t%d\t\t%.2f\t%.2f\n",orders[i].item,orders[i].quantity,orders[i].price,orders[i].total);
    } //printing the order details

    printf("\n\n");
    printf("\t\t-----------------------------------------------\n");
    printf("\t\t\t\tGrand Total: $%.2f\n",grand_total);
    printf("\t\t-----------------------------------------------\n\n");

    return 0;
}