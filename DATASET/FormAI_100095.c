//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to hold the details of the items ordered
typedef struct{
    char name[50];
    int price;
    int quantity;
}Item;

// Structure to hold the details of a customer
typedef struct{
    char name[50];
    Item order[10];
    int no_of_items;
    int total_price;
}Customer;

// Function to initialize a menu with some items
void initialize_menu(Item *menu){
    strcpy(menu[0].name, "Coffee");
    menu[0].price = 50;
    menu[0].quantity = 10;

    strcpy(menu[1].name, "Tea");
    menu[1].price = 30;
    menu[1].quantity = 20;

    strcpy(menu[2].name, "Sandwich");
    menu[2].price = 80;
    menu[2].quantity = 5;

    strcpy(menu[3].name, "Burger");
    menu[3].price = 120;
    menu[3].quantity = 8;
}

// Function to display the menu
void display_menu(Item *menu){
    printf("\nMenu:");
    printf("\n------------------------------");
    printf("\n| %-10s | %-10s | %-10s |", "Item", "Price", "Quantity");
    printf("\n------------------------------");
    for(int i=0; i<4; i++){
        printf("\n| %-10s | %-10d | %-10d |", menu[i].name, menu[i].price, menu[i].quantity);
    }
    printf("\n------------------------------\n");
}

// Function to take the order of a customer and update the menu and total price of the customer
void take_order(Customer *customer, Item *menu){
    printf("\nEnter your name: ");
    scanf("%s", customer->name);

    char item[50];
    int found;
    do{
        found = 0;
        printf("\nEnter the name of the item you want to order (-1 to exit): ");
        scanf("%s", item);
        if(strcmp(item, "-1") != 0){
            for(int i=0; i<4; i++){
                if(strcmp(menu[i].name, item) == 0){
                    found = 1;
                    if(menu[i].quantity > 0){
                        strcpy(customer->order[customer->no_of_items].name, item);
                        customer->order[customer->no_of_items].price = menu[i].price;
                        customer->order[customer->no_of_items].quantity = 1;
                        customer->no_of_items++;
                        menu[i].quantity--;
                        customer->total_price += menu[i].price;
                        printf("\n%s added to your order!\n", item);
                    }
                    else{
                        printf("\nSorry, %s not available!\n", item);
                    }
                }
            }
            if(found == 0){
                printf("\nInvalid item name!\n");
            }
        }
    }while(strcmp(item, "-1") != 0);
}

// Function to display the order of a customer
void display_order(Customer *customer){
    printf("\nOrder details:");
    printf("\nCustomer name: %s", customer->name);
    printf("\n------------------------------");
    printf("\n| %-10s | %-10s | %-10s |", "Item", "Price", "Quantity");
    printf("\n------------------------------");
    for(int i=0; i<customer->no_of_items; i++){
        printf("\n| %-10s | %-10d | %-10d |", customer->order[i].name, customer->order[i].price, customer->order[i].quantity);
    }
    printf("\n------------------------------");
    printf("\nTotal price: %d\n", customer->total_price);
}

int main(){
    Item menu[4];
    initialize_menu(menu);

    int choice;
    do{
        printf("\n1. Display Menu");
        printf("\n2. Take Order");
        printf("\n3. Display Order");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                display_menu(menu);
                break;

            case 2:
                Customer customer;
                take_order(&customer, menu);
                break;

            case 3:
                display_order(&customer);
                break;

            case 4:
                printf("\nThank you for visiting!");
                exit(0);
                break;

            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }while(1);

    return 0;
}