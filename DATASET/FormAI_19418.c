//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item
{
    int item_id;
    char item_name[50];
    int quantity;
};

struct Warehouse
{
    char warehouse_name[50];
    int max_capacity;
    int used_capacity;
    struct Item items[100];
};

void add_item(struct Warehouse* warehouse)
{
    int id, quantity;
    char name[50];
    printf("Enter item ID: ");
    scanf("%d", &id);
    printf("Enter item name: ");
    scanf("%s", name);
    printf("Enter item quantity: ");
    scanf("%d", &quantity);

    warehouse->items[warehouse->used_capacity].item_id = id;
    strcpy(warehouse->items[warehouse->used_capacity].item_name, name);
    warehouse->items[warehouse->used_capacity].quantity = quantity;
    warehouse->used_capacity++;

    printf("Item added successfully!\n");
}

void remove_item(struct Warehouse* warehouse)
{
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);

    int found = 0;
    for(int i=0; i<warehouse->used_capacity; i++)
    {
        if(warehouse->items[i].item_id == id)
        {
            found = 1;
            for(int j=i; j<warehouse->used_capacity-1; j++)
            {
                warehouse->items[j] = warehouse->items[j+1];
            }
            warehouse->used_capacity--;
            printf("Item removed successfully!\n");
            break;
        }
    }

    if(!found)
    {
        printf("Item not found!\n");
    }
}

void display_items(struct Warehouse* warehouse)
{
    printf("Warehouse: %s\n", warehouse->warehouse_name);
    printf("Current capacity: %d/%d\n\n", warehouse->used_capacity, warehouse->max_capacity);
    printf("%-10s %-20s %-10s\n", "ID", "Name", "Quantity");
    printf("------------------------------------\n");
    for(int i=0; i<warehouse->used_capacity; i++)
    {
        printf("%-10d %-20s %-10d\n", warehouse->items[i].item_id, warehouse->items[i].item_name, warehouse->items[i].quantity);
    }
    printf("\n");
}

int main()
{
    struct Warehouse warehouse;
    strcpy(warehouse.warehouse_name, "Warehouse A");
    warehouse.max_capacity = 100;
    warehouse.used_capacity = 0;

    int choice;
    while(1)
    {
        printf("Warehouse Management System\n");
        printf("----------------------------\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display items\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: add_item(&warehouse);
                    break;
            case 2: remove_item(&warehouse);
                    break;
            case 3: display_items(&warehouse);
                    break;
            case 4: printf("Thank you for using our system!\n");
                    exit(0);
            default: printf("Invalid choice!\n");
        }
    }

    return 0;
}