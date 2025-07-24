//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

struct Product {
    char name[50];
    float price;
    int quantity;
};

int main() {
    int n, i, totalPrice = 0;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    struct Product *products = (struct Product*) malloc(n * sizeof(struct Product));
    for(i = 0; i < n; i++) {
        printf("Enter the name of product %d: ", i+1);
        scanf("%s", products[i].name);
        printf("Enter the price of product %d: ", i+1);
        scanf("%f", &products[i].price);
        printf("Enter the quantity of product %d: ", i+1);
        scanf("%d", &products[i].quantity);
        totalPrice += products[i].price * products[i].quantity;
    }
    printf("---------------------------------------\n");
    printf("\tC Cafe Billing System\n");
    printf("---------------------------------------\n");
    printf("Product\t\tPrice\tQuantity\tTotal\n");
    for(i = 0; i < n; i++) {
        printf("%s\t\t%.2f\t%d\t\t%.2f\n", products[i].name, products[i].price, products[i].quantity, products[i].price * products[i].quantity);
    }
    printf("---------------------------------------\n");
    printf("\t\t\t\tTotal: %.2f\n", (float)totalPrice);
    printf("---------------------------------------\n");

    free(products);
    return 0;
}