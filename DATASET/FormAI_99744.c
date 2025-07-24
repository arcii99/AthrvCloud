//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
} Item;

float calculateTotal(Item items[], int size) {
    float total = 0.0;
    for(int i=0;i<size;i++) {
        total += items[i].price * items[i].quantity;
    }
    return total;
}

void printBill(Item items[], int size) {
    printf("=================================================================\n");
    printf("\t\t\t  C Cafe\n");
    printf("=================================================================\n");
    printf("Item ID \t Item Name \t Price \t Quantity \t Total\n");
    for(int i=0;i<size;i++) {
        printf("%d \t\t %s \t\t %.2f \t %d \t\t %.2f\n", items[i].id, items[i].name, items[i].price, items[i].quantity, items[i].price*items[i].quantity);
    }
    printf("=================================================================\n");
    printf("\t\t\t    Total: %.2f\n", calculateTotal(items, size));
}

int main() {
    Item menu[] = {{1, "Cappuccino", 2.99, 0}, {2, "Latte", 3.49, 0}, {3, "Espresso", 1.99, 0}, {4, "Hot Chocolate", 2.99, 0}};
    int size = sizeof(menu)/sizeof(menu[0]);
    Item items[size];
    int choice, quantity, count=0;
    char cont;
    do {
        printf("\n\t\t Menu\n");
        printf("=================================================================\n");
        printf("Item ID \t Item Name \t Price\n");
        for(int i=0;i<size;i++) {
            printf("%d \t\t %s \t\t %.2f\n", menu[i].id, menu[i].name, menu[i].price);
        }
        printf("Enter the item id you want to order: ");
        scanf("%d", &choice);
        printf("Enter the quantity: ");
        scanf("%d", &quantity);
        for(int i=0;i<size;i++) {
            if(menu[i].id == choice) {
                items[count].id = menu[i].id;
                strcpy(items[count].name, menu[i].name);
                items[count].price = menu[i].price;
                items[count].quantity = quantity;
                count++;
            }
        }
        printf("Do you want to order more items? (y/n): ");
        scanf(" %c", &cont);
    } while(cont == 'y' || cont == 'Y');

    printBill(items, count);
    return 0;
}