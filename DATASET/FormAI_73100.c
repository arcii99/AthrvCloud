//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for the medicine data
struct Medicine {
    char name[50];
    int quantity;
    float price;
};

int main() {
    int option, i, j;
    float totalPrice = 0.0;
    int inventorySize = 50;
    struct Medicine inventory[inventorySize];

    // Initialize the inventory with some sample data
    strcpy(inventory[0].name, "Paracetamol");
    inventory[0].quantity = 20;
    inventory[0].price = 2.5;
    strcpy(inventory[1].name, "Ibuprofen");
    inventory[1].quantity = 30;
    inventory[1].price = 3.5;
    strcpy(inventory[2].name, "Aspirin");
    inventory[2].quantity = 25;
    inventory[2].price = 1.5;
    strcpy(inventory[3].name, "Amoxicilin");
    inventory[3].quantity = 15;
    inventory[3].price = 6.0;

    do {
        printf("Welcome to the Medical Store Management System!\n");
        printf("-----------------------------------------------\n");
        printf("1. View Inventory\n");
        printf("2. Add Medicine\n");
        printf("3. Sell Medicine\n");
        printf("4. Exit\n");
        printf("Please choose an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("\nInventory:\n");
                printf("Name\tQuantity\tPrice\n");
                for(i = 0; i < inventorySize; i++) {
                    if(strlen(inventory[i].name) > 0) {
                        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                    }
                }
                break;
            case 2:
                printf("\nAdding Medicine:\n");
                for(i = 0; i < inventorySize; i++) {
                    if(strlen(inventory[i].name) == 0) {
                        printf("Enter name of the medicine: ");
                        scanf("%s", inventory[i].name);
                        printf("Enter quantity: ");
                        scanf("%d", &inventory[i].quantity);
                        printf("Enter unit price: ");
                        scanf("%f", &inventory[i].price);
                        printf("Medicine added successfully!\n");
                        break;
                    }
                }
                if(i == inventorySize) {
                    printf("Inventory is full!\n");
                }
                break;
            case 3:
                printf("\nSelling Medicine:\n");
                printf("Name\tQuantity\tPrice\n");
                for(i = 0; i < inventorySize; i++) {
                    if(strlen(inventory[i].name) > 0) {
                        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
                    }
                }

                printf("Enter name of the medicine: ");
                char medicineName[50];
                scanf("%s", medicineName);

                for(i = 0; i < inventorySize; i++) {
                    if(strcmp(inventory[i].name, medicineName) == 0) {
                        printf("Enter quantity: ");
                        int quantity;
                        scanf("%d", &quantity);

                        if(quantity <= inventory[i].quantity) {
                            inventory[i].quantity -= quantity;
                            totalPrice += quantity * inventory[i].price;
                            printf("Total price: %.2f\n", totalPrice);
                        } else {
                            printf("Insufficient stock!\n");
                        }
                        break;
                    }
                }
                if(i == inventorySize) {
                    printf("Medicine not found in inventory!\n");
                }
                break;
            case 4:
                printf("Thank you for using the Medical Store Management System!\n");
                break;
            default:
                printf("Invalid option!\n");
        }

        printf("\n");
    } while(option != 4);

    return 0;
}