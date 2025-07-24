//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_ITEMS 10 // Maximum number of menu items
#define MAX_ITEM_NAME_LEN 20 // Maximum length of item name
#define MAX_ORDER_ITEMS 5 // Maximum number of items that can be ordered per table

typedef struct {
    char name[MAX_ITEM_NAME_LEN];
    float price;
} MenuItem;

typedef struct {
    int item_nums[MAX_ORDER_ITEMS];
    int num_items;
} Order;

typedef struct {
    int table_num;
    Order order;
    float total_price;
} Table;

// Function to display menu
void display_menu(MenuItem menu[], int num_items) {
    printf("\n--------------------- MENU ---------------------\n");
    for(int i=0; i<num_items; i++) {
        printf("%d. %s - %.2f EUR\n", i+1, menu[i].name, menu[i].price);
    }
    printf("-------------------------------------------------\n");
}

// Function to take order
void take_order(Table tables[], int num_tables, MenuItem menu[], int num_items) {
    int table_num, item_num;
    printf("Enter table number: ");
    scanf("%d", &table_num);
    
    if(table_num < 1 || table_num > num_tables) {
        printf("Invalid table number! Please try again.\n");
        return;
    }
    
    printf("Enter number of items: ");
    scanf("%d", &tables[table_num-1].order.num_items);
    if(tables[table_num-1].order.num_items > MAX_ORDER_ITEMS) {
        printf("Maximum number of items per table is %d!\n", MAX_ORDER_ITEMS);
        return;
    }
    
    int i = 0;
    while(i < tables[table_num-1].order.num_items) {
        printf("Enter item number %d: ", i+1);
        scanf("%d", &item_num);
        if(item_num < 1 || item_num > num_items) {
            printf("Invalid item number! Please try again.\n");
        } else {
            tables[table_num-1].order.item_nums[i] = item_num;
            tables[table_num-1].total_price += menu[item_num-1].price;
            i++;
        }
    }
    
    printf("Order taken successfully!\n");
}

// Function to display table summary
void display_table_summary(Table tables[], int num_tables) {
    printf("\n---------------- TABLE SUMMARY -----------------\n");
    for(int i=0; i<num_tables; i++) {
        printf("Table %d - Total: %.2f EUR\n", tables[i].table_num, tables[i].total_price);
    }
    printf("-------------------------------------------------\n");
}

int main() {
    MenuItem menu[MAX_MENU_ITEMS];
    int num_items = 0;
    
    // Add menu items
    strcpy(menu[num_items].name, "Coffee");
    menu[num_items].price = 1.50;
    num_items++;
    
    strcpy(menu[num_items].name, "Tea");
    menu[num_items].price = 1.00;
    num_items++;
    
    // Initialize tables
    int num_tables = 3;
    Table tables[num_tables];
    for(int i=0; i<num_tables; i++) {
        tables[i].table_num = i+1;
        tables[i].order.num_items = 0;
        tables[i].total_price = 0.0;
    }
    
    int choice;
    do {
        printf("\n------------------ CAFE BILLING SYSTEM -------------------\n");
        printf("1. Display Menu\n2. Take Order\n3. Display Table Summary\n4. Exit\n");
        printf("----------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                display_menu(menu, num_items);
                break;
            case 2:
                take_order(tables, num_tables, menu, num_items);
                break;
            case 3:
                display_table_summary(tables, num_tables);
                break;
            case 4:
                printf("Exiting Cafe Billing System. Have a nice day!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 4);
    
    return 0;
}