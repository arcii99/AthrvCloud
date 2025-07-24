//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item {  //structure to define an item in the warehouse
    char code[10];
    char name[50];
    int quantity;
    float price;
};

void add_item(struct item *items, int *num_items) { //function to add a new item to the warehouse
    printf("\nEnter the code of the item: ");
    scanf("%s", items[*num_items].code);
    printf("\nEnter the name of the item: ");
    scanf("%s", items[*num_items].name);
    printf("\nEnter the price of the item: ");
    scanf("%f", &items[*num_items].price);
    printf("\nEnter the quantity of the item: ");
    scanf("%d", &items[*num_items].quantity);
    printf("\nItem added successfully!\n\n");
    (*num_items)++;
}

void display_items(struct item *items, int num_items){ //function to display the items in the warehouse
    if(num_items==0) { //checking to see if the warehouse is empty
        printf("\nWarehouse is empty!\n\n");
        return;
    }

    printf("\nItems in the warehouse:\n");
    printf("Code\tName\tPrice\tQuantity\n");

    for(int i=0; i<num_items; i++) { //displaying each item in the warehouse
        printf("%s\t%s\t%.2f\t%d\n", items[i].code, items[i].name, items[i].price, items[i].quantity);
    }

    printf("\n");
}

void search_item(struct item *items, int num_items) { //function to search for an item in the warehouse using its code
    char code[10];
    printf("\nEnter the code of the item you want to search for: ");
    scanf("%s", code);

    for(int i=0; i<num_items; i++) {
        if(strcmp(code, items[i].code) == 0) { //comparing the codes of the items in the warehouse to the entered code
            printf("\nCode\tName\tPrice\tQuantity\n");
            printf("%s\t%s\t%.2f\t%d\n", items[i].code, items[i].name, items[i].price, items[i].quantity);
            return;
        }
    }

    printf("\nItem not found!\n\n");
}

int main() {
    struct item warehouse[100]; //an array of structures to store the items in the warehouse
    int num_items = 0; //variable to keep track of the number of items in the warehouse
    int choice;

    while(1) { //infinite loop to display the menu until the user chooses to exit
        printf("Warehouse Management System\n\n");
        printf("1. Add new item\n");
        printf("2. Display items\n");
        printf("3. Search for an item\n");
        printf("4. Exit\n\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) { //switch case to handle the user's choice
            case 1:
                add_item(warehouse, &num_items);
                break;

            case 2:
                display_items(warehouse, num_items);
                break;

            case 3:
                search_item(warehouse, num_items);
                break;

            case 4:
                exit(0); //exit the program

            default:
                printf("\nInvalid choice! Please try again.\n\n");
        }
    }

    return 0;
}