//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

//Structure for item details with name, price and quantity
typedef struct item {
    char name[20];
    float price;
    int qty;
} Item;

//Function to find the total amount based on item ordered
float findTotal(Item order[], int n) {
    float total = 0.0;
    for (int i = 0; i < n; i++) {
        total += (order[i].price * order[i].qty);
    }
    return total;
}

//Main function to execute the program
int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    Item order[n];
    for (int i = 0; i < n; i++) {
        //Reading item details from user input
        printf("Enter item name: ");
        scanf("%s", &order[i].name);
        printf("Enter item price: ");
        scanf("%f", &order[i].price);
        printf("Enter item quantity: ");
        scanf("%d", &order[i].qty);
    }

    float total = findTotal(order, n);
    printf("Total bill amount: %.2f\n", total);

    return 0;
}