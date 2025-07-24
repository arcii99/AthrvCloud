//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: irregular
#include<stdio.h>
#include<stdlib.h>

struct Item{
    char name[20];
    int quantity;
    float price;
};

void add_Item(struct Item *item)
{
    printf("Enter the name of the item: ");
    scanf("%s", item->name);

    printf("Enter the quantity of the item: ");
    scanf("%d", &(item->quantity));

    printf("Enter the price of the item: ");
    scanf("%f", &(item->price));
}

int main()
{
    int n, option;
    printf("Enter the number of items to be stored: ");
    scanf("%d", &n);
    struct Item *items = (struct Item*) malloc(n * sizeof(struct Item));

    for(int i = 0; i < n; i++)
        add_Item(items + i);

    printf("\nWarehouse Management System\n\n");

    printf("Select an option:\n");
    printf("1. Display all items\n");
    printf("2. Display items below a certain price\n");
    printf("3. Display items with low stock\n");

    scanf("%d", &option);

    switch(option)
    {
        case 1: // Display all items
            printf("\n  %-20s %-10s %-10s\n", "Name", "Quantity", "Price");
            printf("--------------------------------------------\n");

            for(int i = 0; i < n; i++)
                printf("  %-20s %-10d $%-9.2f\n", (items + i)->name, (items + i)->quantity, (items + i)->price);

            break;

        case 2: // Display items below a certain price
            float price_limit;
            printf("Enter the maximum price of the item: ");
            scanf("%f", &price_limit);

            printf("\n  %-20s %-10s %-10s\n", "Name", "Quantity", "Price");
            printf("--------------------------------------------\n");

            for(int i = 0; i < n; i++)
                if((items + i)->price <= price_limit)
                    printf("  %-20s %-10d $%-9.2f\n", (items + i)->name, (items + i)->quantity, (items + i)->price);

            break;

        case 3: // Display items with low stock
            int stock_limit;
            printf("Enter the minimum stock of the item: ");
            scanf("%d", &stock_limit);

            printf("\n  %-20s %-10s %-10s\n", "Name", "Quantity", "Price");
            printf("--------------------------------------------\n");

            for(int i = 0; i < n; i++)
                if((items + i)->quantity <= stock_limit)
                    printf("  %-20s %-10d $%-9.2f\n", (items + i)->name, (items + i)->quantity, (items + i)->price);

            break;

        default:
            printf("Invalid option\n");
            break;
    }

    free(items);

    return 0;
}