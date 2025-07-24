//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

// Structure for Warehouse
struct warehouse {
    int warehouseId;
    char location[20];
    int capacity;
    int currentStock;
};

// Function to add new warehouse
void addWarehouse(int id, char loc[], int cap, int stock, struct warehouse *w) {
    w->warehouseId = id;
    strcpy(w->location, loc);
    w->capacity = cap;
    w->currentStock = stock;
}

// Function to change current stock level of a warehouse
void changeStock(int id, int newStock, struct warehouse *w) {
    if(w->warehouseId == id) {
        w->currentStock = newStock;
    }
}

// The program starts with a basic menu
int main() {
    struct warehouse w1, w2, w3;

    addWarehouse(1, "Chicago", 100, 25, &w1);
    addWarehouse(2, "New York", 150, 50, &w2);
    addWarehouse(3, "Los Angeles", 200, 100, &w3);

    int choice;

    while(1) {
        printf("Warehouse Management System\n");
        printf("--------------------------\n");
        printf("1. Add new warehouse\n");
        printf("2. Change stock of a warehouse\n");
        printf("3. Display warehouse information\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Variable Declaration
                int warehouseId, capacity, currentStock;
                char location[20];

                printf("Enter Warehouse ID: ");
                scanf("%d", &warehouseId);
                printf("Enter Warehouse Location: ");
                scanf("%s", &location);
                printf("Enter Capacity: ");
                scanf("%d", &capacity);
                printf("Enter Current Stock: ");
                scanf("%d", &currentStock);

                // Add new warehouse
                if(w1.warehouseId == 0) {
                    addWarehouse(warehouseId, location, capacity, currentStock, &w1);
                }
                else if(w2.warehouseId == 0) {
                    addWarehouse(warehouseId, location, capacity, currentStock, &w2);
                }
                else if(w3.warehouseId == 0) {
                    addWarehouse(warehouseId, location, capacity, currentStock, &w3);
                }
                else {
                    printf("No more space for new warehouse!\n");
                }
                break;

            case 2:
                // Variable Declaration
                int warehouseId2, currentStock2;

                printf("Enter Warehouse ID: ");
                scanf("%d", &warehouseId2);
                printf("Enter New Current Stock: ");
                scanf("%d", &currentStock2);

                // Change stock of a warehouse
                if(w1.warehouseId == warehouseId2) {
                    changeStock(warehouseId2, currentStock2, &w1);
                }
                else if(w2.warehouseId == warehouseId2) {
                    changeStock(warehouseId2, currentStock2, &w2);
                }
                else if(w3.warehouseId == warehouseId2) {
                    changeStock(warehouseId2, currentStock2, &w3);
                }
                else {
                    printf("Warehouse does not exist!\n");
                }
                break;

            case 3:
                // Display warehouse information
                printf("Warehouse Information\n");
                printf("---------------------\n");
                printf("1. Warehouse ID: %d, Location: %s, Capacity: %d, Current Stock: %d\n", w1.warehouseId, w1.location, w1.capacity, w1.currentStock);
                printf("2. Warehouse ID: %d, Location: %s, Capacity: %d, Current Stock: %d\n", w2.warehouseId, w2.location, w2.capacity, w2.currentStock);
                printf("3. Warehouse ID: %d, Location: %s, Capacity: %d, Current Stock: %d\n", w3.warehouseId, w3.location, w3.capacity, w3.currentStock);
                break;

            case 4:
                // Exit the program
                printf("Thank you for using Warehouse Management System!\n");
                exit(0);

            default:
                printf("Invalid Choice! Please Try Again.\n");
        }
    }

    return 0;
}