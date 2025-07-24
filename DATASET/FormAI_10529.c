//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

struct warehouse_item {
    char item_name[50];
    int item_id;
    int item_qty;
    float item_price;
};

int main() {
    int num_items;
    printf("Enter the number of items in the warehouse: ");
    scanf("%d", &num_items);
    
    struct warehouse_item *items = (struct warehouse_item*) malloc(num_items * sizeof(struct warehouse_item));
    
    for(int i = 0; i < num_items; i++) {
        printf("\nEnter item name for item %d: ", i+1);
        scanf("%s", &items[i].item_name);
        
        printf("Enter item ID for item %d: ", i+1);
        scanf("%d", &items[i].item_id);
        
        printf("Enter quantity for item %d: ", i+1);
        scanf("%d", &items[i].item_qty);
        
        printf("Enter price per item for item %d: ", i+1);
        scanf("%f", &items[i].item_price);
    }
    
    printf("\n\nWarehouse Inventory\n\n");
    printf("%-15s %-15s %-15s %-15s\n", "Item Name", "Item ID", "Quantity", "Price/Item");
    for(int i = 0; i < num_items; i++) {
        printf("%-15s %-15d %-15d %-15.2f\n", items[i].item_name, items[i].item_id, items[i].item_qty, items[i].item_price);
    }
    
    free(items);
    return 0;
}