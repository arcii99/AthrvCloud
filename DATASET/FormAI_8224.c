//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for the items in the inventory
struct InventoryItem {
    char item_name[50];
    int item_id;
    int quantity;
};

// Define a struct for the locations in the warehouse
struct WarehouseLocation {
    int row;
    int column;
};

// Define a struct for the individual boxes in the shelves
struct ShelfBox {
    int box_id;
    int item_id;
    int quantity;
};

// Define a struct for the shelves in the warehouse
struct WarehouseShelf {
    int shelf_id;
    struct ShelfBox boxes[10];
};

// Define the main function
int main() {
    // Declare variables for the inventory, warehouse, and user input
    struct InventoryItem inventory[25];
    struct WarehouseShelf warehouse[10][10];
    char input[50];

    // Fill the inventory with sample items
    strcpy(inventory[0].item_name, "Screwdriver");
    inventory[0].item_id = 1;
    inventory[0].quantity = 50;

    strcpy(inventory[1].item_name, "Hammer");
    inventory[1].item_id = 2;
    inventory[1].quantity = 30;

    strcpy(inventory[2].item_name, "Drill Bit Set");
    inventory[2].item_id = 3;
    inventory[2].quantity = 20;

    // Fill the warehouse with shelves and boxes
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            warehouse[i][j].shelf_id = i * 10 + j;
            for (int k = 0; k < 10; k++) {
                warehouse[i][j].boxes[k].box_id = k;
            }
        }
    }

    // Loop indefinitely to allow the user to interact with the system
    while (1) {
        printf("Enter a command: ");
        fgets(input, 50, stdin);

        // Parse the user input for the command and arguments
        char *token;
        char args[20][50];
        int arg_count = 0;

        token = strtok(input, " \n");
        while (token != NULL) {
            strcpy(args[arg_count], token);
            token = strtok(NULL, " \n");
            arg_count++;
        }

        // Check the first argument to determine the command to execute
        if (strcmp(args[0], "add_item") == 0) {
            // Check that the correct number of arguments were passed
            if (arg_count != 4) {
                printf("Usage: add_item <item_name> <item_id> <quantity>\n");
            } else {
                // Create a new item in the inventory with the specified properties
                strcpy(inventory[25].item_name, args[1]);
                inventory[25].item_id = atoi(args[2]);
                inventory[25].quantity = atoi(args[3]);
            }
        } else if (strcmp(args[0], "remove_item") == 0) {
            // Check that the correct number of arguments were passed
            if (arg_count != 2) {
                printf("Usage: remove_item <item_id>\n");
            } else {
                // Find the specified item in the inventory and remove it
                for (int i = 0; i < 25; i++) {
                    if (inventory[i].item_id == atoi(args[1])) {
                        inventory[i].item_id = 0;
                        strcpy(inventory[i].item_name, "");
                        inventory[i].quantity = 0;
                    }
                }
            }
        } else if (strcmp(args[0], "move_box") == 0) {
            // Check that the correct number of arguments were passed
            if (arg_count != 5) {
                printf("Usage: move_box <shelf_row> <shelf_column> <box_id> <new_row> <new_column>\n");
            } else {
                // Find the specified box in the current shelf and move it to the specified location
                struct WarehouseLocation current_location = {
                    .row = atoi(args[1]),
                    .column = atoi(args[2]),
                };
                struct WarehouseLocation new_location = {
                    .row = atoi(args[4]),
                    .column = atoi(args[5]),
                };
                for (int i = 0; i < 10; i++) {
                    if (warehouse[current_location.row][current_location.column].boxes[i].box_id == atoi(args[3])) {
                        warehouse[new_location.row][new_location.column].boxes[i] = warehouse[current_location.row][current_location.column].boxes[i];
                        warehouse[current_location.row][current_location.column].boxes[i].box_id = 0;
                    }
                }
            }
        } else if (strcmp(args[0], "print_inventory") == 0) {
            // Loop through the inventory and print each item
            printf("Inventory:\n");
            for (int i = 0; i < 25; i++) {
                if (inventory[i].item_id != 0) {
                    printf("Item %d: %s (ID: %d) - Quantity: %d\n", i, inventory[i].item_name, inventory[i].item_id, inventory[i].quantity);
                }
            }
        } else if (strcmp(args[0], "print_shelf") == 0) {
            // Check that the correct number of arguments were passed
            if (arg_count != 2) {
                printf("Usage: print_shelf <shelf_row> <shelf_column>\n");
            } else {
                // Loop through the boxes in the specified shelf and print each one
                printf("Shelf %d,%d:\n", atoi(args[1]), atoi(args[2]));
                for (int i = 0; i < 10; i++) {
                    if (warehouse[atoi(args[1])][atoi(args[2])].boxes[i].box_id != 0) {
                        printf("Box %d (ID: %d) - Item: %d - Quantity: %d\n", i, warehouse[atoi(args[1])][atoi(args[2])].boxes[i].box_id, warehouse[atoi(args[1])][atoi(args[2])].boxes[i].item_id, warehouse[atoi(args[1])][atoi(args[2])].boxes[i].quantity);
                    }
                }
            }
        } else if (strcmp(args[0], "quit") == 0) {
            // Exit the program
            break;
        } else {
            // Invalid command
            printf("Invalid command.\n");
        }
    }

    return 0;
}