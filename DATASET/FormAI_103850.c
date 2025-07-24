//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct menu{
    char itemName[20];
    int quantity;
    float price;
};

typedef struct menu Menu;

int main(){
    Menu items[10];
    int n, i, j;
    float subtotal=0, tax, total;

    printf("Enter the number of items on the menu (maximum 10): ");
    scanf("%d", &n);

    printf("\n");

    for(i=0;i<n;i++){
        printf("Enter item name for item %d: ", i+1);
        scanf("%s", &items[i].itemName);
        printf("Enter item quantity for item %d: ", i+1);
        scanf("%d", &items[i].quantity);
        printf("Enter item price for item %d: ", i+1);
        scanf("%f", &items[i].price);
        printf("\n");
    }

    printf("Cafe Billing System\n\n");
    printf("Item Name \t Quantity \t Price \t\t Total \n");

    for(i=0;i<n;i++){
        printf("%s \t\t %d \t\t $%.2f \t $%.2f\n", items[i].itemName, items[i].quantity, items[i].price, (float) items[i].quantity*items[i].price);
        subtotal += (float) items[i].quantity*items[i].price;
    }

    tax = subtotal*0.06;
    total = subtotal+tax;

    printf("\nSubtotal: $%.2f\n", subtotal);
    printf("Tax: $%.2f\n", tax);
    printf("Total: $%.2f\n", total);

    return 0;
}