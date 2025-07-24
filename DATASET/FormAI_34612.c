//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include<stdio.h>

/* function to calculate total bill */
float calculateBill(int quantity, float price) {
    float total = price * quantity;
    if(total>1000) {
        total -= total*0.1; // 10% discount if bill is more than 1000
    }
    return total;
}

int main() {
    int num_items;
    float price_per_item;
    printf("Welcome to the Energetic C Cafe!\n");

    while(1) {
        printf("Enter number of items (-1 to exit): ");
        scanf("%d", &num_items);
        if(num_items == -1) break;
        else if(num_items < 0) {
            printf("Invalid input!\n");
            continue;
        }
        printf("Enter price per item: ");
        scanf("%f", &price_per_item);

        // calculate total bill
        float total_bill = calculateBill(num_items, price_per_item);
        printf("The total bill is: $%.2f\n", total_bill);
    }
    printf("Thank you for eating at the Energetic C Cafe!\n");
    return 0;
}