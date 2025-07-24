//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int num_items;
} Warehouse;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_warehouses;
    Warehouse warehouses[10];
} Player;

void print_menu() {
    printf("\n");
    printf("1. Add item to warehouse\n");
    printf("2. Remove item from warehouse\n");
    printf("3. Transfer item between warehouses\n");
    printf("4. Display warehouse inventory\n");
    printf("5. Display player inventory\n");
    printf("6. Quit\n");
    printf("\n");
}

void add_item(Warehouse *warehouse) {
    char name[MAX_NAME_LENGTH];
    int quantity;
    
    printf("Enter item name: ");
    scanf("%s", name);
    
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            warehouse->items[i].quantity += quantity;
            printf("Added %d %s to warehouse\n", quantity, name);
            return;
        }
    }
    
    if (warehouse->num_items == MAX_ITEMS) {
        printf("Warehouse is full\n");
    } else {
        strcpy(warehouse->items[warehouse->num_items].name, name);
        warehouse->items[warehouse->num_items].quantity = quantity;
        warehouse->num_items++;
        printf("Added %d %s to warehouse\n", quantity, name);
    }
}

void remove_item(Warehouse *warehouse) {
    char name[MAX_NAME_LENGTH];
    int quantity;
    
    printf("Enter item name: ");
    scanf("%s", name);
    
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    
    for (int i = 0; i < warehouse->num_items; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            if (warehouse->items[i].quantity >= quantity) {
                warehouse->items[i].quantity -= quantity;
                printf("Removed %d %s from warehouse\n", quantity, name);
            } else {
                printf("Not enough %s in warehouse\n", name);
            }
            return;
        }
    }
    
    printf("%s not found in warehouse\n", name);
}

void transfer_item(Player *player) {
    char name[MAX_NAME_LENGTH];
    int quantity;
    int from_warehouse_index, to_warehouse_index;
    
    printf("Enter item name: ");
    scanf("%s", name);
    
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    
    printf("Enter index of source warehouse: ");
    scanf("%d", &from_warehouse_index);
    
    printf("Enter index of destination warehouse: ");
    scanf("%d", &to_warehouse_index);
    
    Warehouse *from_warehouse = &player->warehouses[from_warehouse_index];
    Warehouse *to_warehouse = &player->warehouses[to_warehouse_index];
    
    for (int i = 0; i < from_warehouse->num_items; i++) {
        if (strcmp(from_warehouse->items[i].name, name) == 0) {
            if (from_warehouse->items[i].quantity >= quantity) {
                for (int j = 0; j < to_warehouse->num_items; j++) {
                    if (strcmp(to_warehouse->items[j].name, name) == 0) {
                        to_warehouse->items[j].quantity += quantity;
                        from_warehouse->items[i].quantity -= quantity;
                        printf("Transferred %d %s from warehouse %d to warehouse %d\n", quantity, name, from_warehouse_index, to_warehouse_index);
                        return;
                    }
                }
                if (to_warehouse->num_items == MAX_ITEMS) {
                    printf("Destination warehouse is full\n");
                } else {
                    strcpy(to_warehouse->items[to_warehouse->num_items].name, name);
                    to_warehouse->items[to_warehouse->num_items].quantity = quantity;
                    to_warehouse->num_items++;
                    from_warehouse->items[i].quantity -= quantity;
                    printf("Transferred %d %s from warehouse %d to warehouse %d\n", quantity, name, from_warehouse_index, to_warehouse_index);
                }
                return;
            } else {
                printf("Not enough %s in warehouse %d\n", name, from_warehouse_index);
                return;
            }
        }
    }
    
    printf("%s not found in warehouse %d\n", name, from_warehouse_index);
}

void display_warehouse(Warehouse *warehouse) {
    printf("Item name\tQuantity\n");
    printf("----------------------\n");
    
    for (int i = 0; i < warehouse->num_items; i++) {
        printf("%s\t\t%d\n", warehouse->items[i].name, warehouse->items[i].quantity);
    }
    
    printf("\n");
}

void display_player_inventory(Player *player) {
    printf("Player: %s\n", player->name);
    for (int i = 0; i < player->num_warehouses; i++) {
        printf("Warehouse %d:\n", i);
        display_warehouse(&player->warehouses[i]);
    }
}

int main() {
    Player players[2];
    players[0].num_warehouses = 2;
    players[1].num_warehouses = 2;
    
    printf("Enter name for player 1: ");
    scanf("%s", players[0].name);
    
    printf("Enter name for player 2: ");
    scanf("%s", players[1].name);
    
    while (1) {
        int choice;
        
        printf("Choose a player:\n");
        printf("1. %s\n", players[0].name);
        printf("2. %s\n", players[1].name);
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        Player *player = &players[choice - 1];
        
        printf("1. Warehouse 1\n");
        printf("2. Warehouse 2\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        Warehouse *warehouse = &player->warehouses[choice - 1];
        
        print_menu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                add_item(warehouse);
                break;
            }
            case 2: {
                remove_item(warehouse);
                break;
            }
            case 3: {
                transfer_item(player);
                break;
            }
            case 4: {
                display_warehouse(warehouse);
                break;
            }
            case 5: {
                display_player_inventory(player);
                break;
            }
            case 6: {
                printf("Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
                break;
            }
        }
    }
    
    return 0;
}