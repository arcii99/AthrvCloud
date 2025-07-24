//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    float price;
    int quantity;
};

int main() {
    int num_items;
    printf("Enter the number of items in the order: ");
    scanf("%d", &num_items);

    struct Item* items = (struct Item*) malloc(num_items * sizeof(struct Item));

    float total_price = 0;

    for(int i=0; i<num_items; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].name);

        printf("Enter the price of item %d: ", i+1);
        scanf("%f", &items[i].price);

        printf("Enter the quantity of item %d: ", i+1);
        scanf("%d", &items[i].quantity);

        total_price += items[i].price * items[i].quantity;
    }

    printf("\n\nC Cafe\n");
    printf("============================================\n");
    printf("Item\t\tPrice\t\tQuantity\tTotal Price\n");
    printf("--------------------------------------------\n");

    for(int i=0; i<num_items; i++) {
        printf("%s\t\t%.2f\t\t%d\t\t%.2f\n", items[i].name, items[i].price, items[i].quantity, items[i].price * items[i].quantity);
    }

    printf("\n\t\t\t\tTotal Price: $%.2f\n\n", total_price);

    free(items);

    return 0;
}