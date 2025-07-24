//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mind-bending
#include <stdio.h>
#include <string.h>

struct Item {
    int id;
    char name[50];
    float price;
    int quantity;
};

int main() {
    struct Item items[100];

    int choice, n = 0;
    float totalCost = 0.0;

    do {
        // Display available actions
        printf("1. Add an item\n");
        printf("2. Remove an item\n");
        printf("3. View all items\n");
        printf("4. View total cost\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item ID: ");
                scanf("%d", &items[n].id);

                printf("Enter item name: ");
                scanf("%s", items[n].name);

                printf("Enter item price: ");
                scanf("%f", &items[n].price);

                printf("Enter item quantity: ");
                scanf("%d", &items[n].quantity);

                n++;
                break;
            case 2:
                int delId, flag = 0;

                printf("Enter item ID to delete: ");
                scanf("%d", &delId);

                for (int i=0; i<n; i++)
                    if (items[i].id == delId) {
                        n--;
                        flag = 1;

                        for (int j=i; j<n; j++)
                            items[j] = items[j+1];

                        break;
                    }

                if (flag == 0)
                    printf("Item not found.\n");

                break;
            case 3:
                printf("ID\tName\t\tPrice\tQuantity\n");

                for (int i=0; i<n; i++)
                    printf("%d\t%s\t%.2f\t%d\n", items[i].id, items[i].name, items[i].price, items[i].quantity);

                break;
            case 4:
                totalCost = 0;

                for (int i=0; i<n; i++)
                    totalCost += (items[i].price * items[i].quantity);

                printf("Total cost: $%.2f\n", totalCost);

                break;
            case 5:
                printf("Exiting...");
                break;
        }
    } while (choice != 5);

    return 0;
}