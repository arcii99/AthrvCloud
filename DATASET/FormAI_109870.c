//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: inquisitive
#include <stdio.h>

struct Item {
    int id;
    char name[50];
    int quantity;
};

int main() {
    int num_items;
    
    printf("How many items would you like to add to the warehouse?");
    scanf("%d", &num_items);
    
    struct Item items[num_items];
    
    for(int i = 0; i < num_items; i++) {
        printf("Enter information for item %d:\n", i+1);
        printf("ID: ");
        scanf("%d", &items[i].id);
        printf("Name: ");
        scanf("%s", items[i].name);
        printf("Quantity: ");
        scanf("%d", &items[i].quantity);
    }
    
    printf("Warehouse inventory:\n");
    printf("  ID      Name          Quantity\n");
    printf("----------------------------------\n");
    
    for(int i = 0; i < num_items; i++) {
        printf("%4d    %-10s      %2d\n", items[i].id, items[i].name, items[i].quantity);
    }
    
    return 0;
}