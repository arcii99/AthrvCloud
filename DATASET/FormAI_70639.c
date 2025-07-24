//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Inventory {
    char itemName[20];
    int itemQuantity;
    float itemPrice;
};

void displayMenu() {
    printf("\nWelcome to Happy Warehouse Management System!\n");
    printf("------------------------------------------------\n");
    printf("1. Add item to inventory\n");
    printf("2. Remove item from inventory\n");
    printf("3. Update inventory information\n");
    printf("4. View inventory\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    int numItems = 0;
    struct Inventory *inventory = NULL;
    float totalPrice = 0;

    do {
        displayMenu();
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inventory = (struct Inventory*)realloc(inventory, (numItems+1)*sizeof(struct Inventory));
                printf("\nEnter name of the new item: ");
                scanf("%s", inventory[numItems].itemName);

                printf("Enter quantity of the new item: ");
                scanf("%d", &inventory[numItems].itemQuantity);

                printf("Enter price of the new item: ");
                scanf("%f", &inventory[numItems].itemPrice);

                printf("\nItem added to inventory successfully!\n");
                numItems++;
                break;

            case 2:
                char itemNameToDelete[20];
                printf("\nEnter name of the item you want to delete from inventory: ");
                scanf("%s", itemNameToDelete);

                for (int i = 0; i < numItems; i++) {
                    if (strcmp(itemNameToDelete, inventory[i].itemName) == 0) {
                        totalPrice -= inventory[i].itemPrice * inventory[i].itemQuantity;
                        for(int j = i; j<numItems-1; j++){
                            inventory[j] = inventory[j+1];
                        }
                        inventory = (struct Inventory*)realloc(inventory, (numItems-1)*sizeof(struct Inventory));
                        printf("\nItem removed from inventory successfully!\n");
                        numItems--;
                        break;
                    }
                }
                break;

            case 3:
                char itemNameToUpdate[20];
                printf("\nEnter name of the item you want to update in inventory: ");
                scanf("%s", itemNameToUpdate);

                for (int i = 0; i < numItems; i++) {
                    if (strcmp(itemNameToUpdate, inventory[i].itemName) == 0) {
                        printf("\nEnter new quantity of the item : ");
                        scanf("%d", &inventory[i].itemQuantity);

                        printf("Enter new price of the item : ");
                        scanf("%f", &inventory[i].itemPrice);

                        printf("\nInventory information updated successfully!\n");

                        break;
                    }
                }
                break;

            case 4:
                printf("\nInventory Information\n");
                printf("=============================\n");
                if(numItems==0){
                    printf("No items found!\n");
                }
                else{
                    for (int i = 0; i < numItems; i++) {
                        printf("\nItem Name: %s", inventory[i].itemName);
                        printf("\nQuantity: %d", inventory[i].itemQuantity);
                        printf("\nPrice per Unit: %.2f\n", inventory[i].itemPrice);
                        totalPrice += inventory[i].itemPrice * inventory[i].itemQuantity;
                    }
                    printf("\nTotal inventory value is %.2f\n", totalPrice);
                }
                break;

            case 5:
                printf("\nThank you for using Happy Warehouse Management System!\n");
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 5);

    free(inventory);
    inventory = NULL;

    return 0;
}