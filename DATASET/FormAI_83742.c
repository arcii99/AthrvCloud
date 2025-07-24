//FormAI DATASET v1.0 Category: Educational ; Style: medieval
#include <stdio.h>

int main() {
    int apple_qty, banana_qty, orange_qty;
    float apple_price, banana_price, orange_price, total_cost;

    printf("Enter the quantity of apples: ");
    scanf("%d", &apple_qty);
    printf("Enter the price of one apple: ");
    scanf("%f", &apple_price);

    printf("Enter the quantity of bananas: ");
    scanf("%d", &banana_qty);
    printf("Enter the price of one banana: ");
    scanf("%f", &banana_price);

    printf("Enter the quantity of oranges: ");
    scanf("%d", &orange_qty);
    printf("Enter the price of one orange: ");
    scanf("%f", &orange_price);

    //calculating the total cost of fruits
    total_cost = (apple_qty * apple_price) + (banana_qty * banana_price) + (orange_qty * orange_price);

    printf("\nTotal Cost of buying %d Apples, %d Bananas and %d Oranges is: %.2f\n", apple_qty, banana_qty, orange_qty, total_cost);

    return 0;
}