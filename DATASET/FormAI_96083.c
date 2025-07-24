//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int menu[10] = { 1000, 1200, 1500, 2000, 2200, 2500, 3000, 3500, 4000, 4500 };
    char items[10][30] = { "Espresso", "Latte", "Cappuccino", "Mocha", "Americano", "Macchiato", "Irish Coffee", "Caramel Macchiato", "Caffe Breve", "Affogato" };
    int prices[10], quantity[10], total = 0;
    char customer_name[50];

    printf("\nEnter customer name: ");
    scanf("%[^\n]", customer_name);

    printf("\nWelcome to C Cafe, %s!\n\n", customer_name);
    printf("Menu:\n---------------------------\n");
    for(int i=0; i<10; i++) {
        printf("%d. %s - %d\n", i+1, items[i], menu[i]);
    }
    printf("---------------------------\n");

    printf("\nEnter your orders by item number (e.g. \"1 2 8\" for Espresso, Latte, and Caramel Macchiato): ");

    for(int i=0; i<10; i++) {
        prices[i] = 0;
        quantity[i] = 0;
    }

    char order_input[100];
    fgets(order_input, 100, stdin);
    char* token = strtok(order_input, " ");
    while(token != NULL) {
        int item_number = atoi(token) - 1;
        quantity[item_number]++;
        prices[item_number] = menu[item_number] * quantity[item_number];
        total += menu[item_number];
        token = strtok(NULL, " ");
    }

    printf("\n%s's Orders:\n---------------------------\n", customer_name);
    for(int i=0; i<10; i++) {
        if(quantity[i] > 0) {
            printf("%s x%d - %d\n", items[i], quantity[i], prices[i]);
        }
    }
    printf("---------------------------\n");
    printf("Total: %d\n", total);

    return 0;
}