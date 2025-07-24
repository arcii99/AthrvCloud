//FormAI DATASET v1.0 Category: Product Inventory System ; Style: post-apocalyptic
#include <stdio.h>

struct product {
    char name[50];
    float price;
    int quantity;
};

int main(){
    struct product inventory[100];
    int count = 0;
    char choice;
    do {
        printf("Product Name: ");
        scanf("%s", inventory[count].name);
        printf("Price: ");
        scanf("%f", &inventory[count].price);
        printf("Quantity: ");
        scanf("%d", &inventory[count].quantity);
        count++;

        printf("\nDo you want to add another product? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    float total_value = 0;
    printf("\n\nCurrent Inventory:\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t", inventory[i].name);
        printf("%.2f\t", inventory[i].price);
        printf("%d\n", inventory[i].quantity);
        total_value += inventory[i].price * inventory[i].quantity;
    }

    printf("\nTotal Inventory Value: $%.2f\n", total_value);

    return 0;
}