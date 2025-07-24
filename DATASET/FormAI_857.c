//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

struct warehouse {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int num_items, i, max_index;
    float total_price = 0;
    
    printf("Enter the number of items in the warehouse: ");
    scanf("%d", &num_items);
    
    // creating an array of size num_items to hold warehouse items
    struct warehouse items[num_items];
    
    // inputting details of each item
    for(i = 0; i < num_items; i++) {
        printf("\nItem %d:\n", i+1);
        printf("Enter name: ");
        scanf("%s", &items[i].name);
        printf("Enter quantity: ");
        scanf("%d", &items[i].quantity);
        printf("Enter price: ");
        scanf("%f", &items[i].price);
    }
    
    // displaying all items in the warehouse
    printf("\nWarehouse Inventory:\n");
    for(i = 0; i < num_items; i++) {
        printf("%d. %s - %d pcs - RM%.2f/pc\n", i+1, items[i].name, items[i].quantity, items[i].price);
        total_price += items[i].quantity * items[i].price;
    }
    printf("\nTotal value of warehouse inventory: RM%.2f\n", total_price);
    
    // finding the item with the maximum price
    max_index = 0;
    for(i = 0; i < num_items; i++) {
        if(items[i].price > items[max_index].price) {
            max_index = i;
        }
    }
    printf("\nItem with the maximum price: %s (RM%.2f/pc)\n", items[max_index].name, items[max_index].price);
    
    return 0;
}