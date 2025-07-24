//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct products{
    char name[30];
    int quantity;
};

struct warehouses{
    char location[20];
    struct products *inventory;
};

void checkInventory(struct warehouses warehouse[], int num_warehouses){
    char search[30];
    printf("\nEnter the name of the product to search for: ");
    scanf("%s", search);
    for(int i=0; i<num_warehouses; i++){
        for(int j=0; j<3; j++){
            if(strcmp(warehouse[i].inventory[j].name, search) == 0){
                printf("\nProduct found in warehouse at %s.", warehouse[i].location);
                return;
            }
        }
    }
    printf("\nProduct not found in any warehouse.");
}

void printInventory(struct warehouses warehouse[], int num_warehouses){
    printf("\nCURRENT INVENTORY:\n");
    for(int i=0; i<num_warehouses; i++){
        printf("\nWarehouse at %s:", warehouse[i].location);
        for(int j=0; j<3; j++){
            printf("\n%s: %d", warehouse[i].inventory[j].name, warehouse[i].inventory[j].quantity);
        }
    }
}

void main(){
    struct warehouses warehouse[2];
    strcpy(warehouse[0].location, "New York");
    strcpy(warehouse[1].location, "Los Angeles");
    warehouse[0].inventory = (struct products*) malloc(3 * sizeof(struct products));
    warehouse[1].inventory = (struct products*) malloc(3 * sizeof(struct products));
    strcpy(warehouse[0].inventory[0].name, "Shoes");
    warehouse[0].inventory[0].quantity = 50;
    strcpy(warehouse[0].inventory[1].name, "Hats");
    warehouse[0].inventory[1].quantity = 30;
    strcpy(warehouse[0].inventory[2].name, "Socks");
    warehouse[0].inventory[2].quantity = 100;
    strcpy(warehouse[1].inventory[0].name, "Shirts");
    warehouse[1].inventory[0].quantity = 25;
    strcpy(warehouse[1].inventory[1].name, "Pants");
    warehouse[1].inventory[1].quantity = 40;
    strcpy(warehouse[1].inventory[2].name, "Jackets");
    warehouse[1].inventory[2].quantity = 15;
    printf("\nWelcome to the Warehouse Management System!");
    int choice;
    do{
        printf("\n\nWhat would you like to do?\n1. Check inventory\n2. Print current inventory\n3. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1: checkInventory(warehouse, 2);
                    break;
            case 2: printInventory(warehouse, 2);
                    break;
            case 3: printf("\nThank you for using the Warehouse Management System!");
                    break;
            default: printf("\nInvalid choice.");
        }
    }while(choice != 3);
}