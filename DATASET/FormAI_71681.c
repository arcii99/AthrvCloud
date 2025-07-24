//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

struct Item {
    char name[MAX_LEN];
    int price;
};

struct Order {
    char itemName[MAX_LEN];
    int quantity;
};

int main() {
    struct Item menu[] = {
        {"Coffee", 50},
        {"Tea", 30},
        {"Sandwich", 80},
        {"Burger", 100},
        {"French Fries", 60},
        {"Cake", 120},
        {"Ice Cream", 70}
    };

    int numItems = sizeof(menu) / sizeof(struct Item);
    int orderNum = 1;

    while (1) {
        printf("Welcome to Cafe XYZ!\n");
        printf("Please choose an option:\n");
        printf("1. View Menu\n");
        printf("2. Place Order\n");
        printf("3. Exit\n");

        int option;
        scanf("%d", &option);

        if (option == 1) {
            printf("Menu:\n");
            for (int i = 0; i < numItems; i++) {
                printf("%d. %s - %d\n", i+1, menu[i].name, menu[i].price);
            }
            printf("\n");
        } else if (option == 2) {
            printf("Order #%d:\n", orderNum);

            printf("Enter number of items: ");
            int numOrderItems;
            scanf("%d", &numOrderItems);

            struct Order order[numOrderItems];

            int total = 0;
            for (int i = 0; i < numOrderItems; i++) {
                printf("Enter item #%d name: ", i+1);
                scanf("%s", order[i].itemName);

                printf("Enter quantity: ");
                scanf("%d", &order[i].quantity);

                for (int j = 0; j < numItems; j++) {
                    if (strcmp(order[i].itemName, menu[j].name) == 0) {
                        total += menu[j].price * order[i].quantity;
                        break;
                    }
                }
            }

            printf("Total bill: %d\n", total);

            orderNum++;

            printf("\n");
        } else if (option == 3) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Invalid option\n");
        }
    }

    return 0;
}