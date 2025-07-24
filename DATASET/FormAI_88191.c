//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define constants
#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_CODE_LEN 10
#define MAX_TABLES 20

typedef struct {
    char name[MAX_NAME_LEN];
    char code[MAX_CODE_LEN];
    double price;
} MenuItem;

typedef struct {
    char name[MAX_NAME_LEN];
    MenuItem items[MAX_ITEMS];
    int num_items;
} Menu;

typedef struct {
    int table_num;
    char items[MAX_ITEMS][MAX_NAME_LEN];
    double prices[MAX_ITEMS];
    int num_items;
    double total;
    int paid;
} Table;

int main() {
    // initialize menu
    Menu menu;
    strcpy(menu.name, "C Cafe Menu");
    menu.num_items = 0;
    MenuItem item1 = {"Latte", "LT01", 3.50};
    MenuItem item2 = {"Cappuccino", "CP02", 3.00};
    MenuItem item3 = {"Espresso", "EP03", 2.50};
    MenuItem item4 = {"Croissant", "CR04", 1.50};
    MenuItem item5 = {"Muffin", "MF05", 1.50};
    menu.items[0] = item1;
    menu.items[1] = item2;
    menu.items[2] = item3;
    menu.items[3] = item4;
    menu.items[4] = item5;
    menu.num_items = 5;

    // initialize tables
    Table tables[MAX_TABLES];
    for (int i = 0; i < MAX_TABLES; i++) {
        tables[i].table_num = i + 1;
        tables[i].num_items = 0;
        tables[i].total = 0;
        tables[i].paid = 0;
    }

    // display menu
    printf("%s\n", menu.name);
    for (int i = 0; i < menu.num_items; i++) {
        printf("%-10s %-15s %.2lf\n", menu.items[i].code, menu.items[i].name, menu.items[i].price);
    }
    printf("\n");

    // prompt user for table number
    int table_num;
    printf("Enter table number: ");
    scanf("%d", &table_num);

    // display table information
    printf("\nTable %d\n", table_num);
    printf("--------------------\n");

    // prompt user for items
    char item_code[10];
    int item_num;
    do {
        printf("Enter item code (0 to finish): ");
        scanf("%s", item_code);
        if (strcmp(item_code, "0") != 0) {
            // find item in menu
            int found = 0;
            for (int i = 0; i < menu.num_items; i++) {
                if (strcmp(menu.items[i].code, item_code) == 0) {
                    found = 1;
                    printf("%-10s added to order\n", menu.items[i].name);
                    // add item to table order
                    strcpy(tables[table_num-1].items[tables[table_num-1].num_items], menu.items[i].name);
                    tables[table_num-1].prices[tables[table_num-1].num_items] = menu.items[i].price;
                    tables[table_num-1].num_items++;
                    tables[table_num-1].total += menu.items[i].price;
                }
            }
            if (found == 0) {
                printf("Item not found\n");
            }
        }
    } while (strcmp(item_code, "0") != 0);

    // display table order
    printf("\nTable %d Order\n", table_num);
    printf("--------------------\n");
    for (int i = 0; i < tables[table_num-1].num_items; i++) {
        printf("%-15s %.2lf\n", tables[table_num-1].items[i], tables[table_num-1].prices[i]);
    }
    printf("--------------------\n");
    printf("Total: %.2lf\n", tables[table_num-1].total);

    // prompt user for payment
    double payment;
    do {
        printf("Enter payment amount: ");
        scanf("%lf", &payment);
        if (payment < tables[table_num-1].total) {
            printf("Insufficient payment\n");
        } else {
            tables[table_num-1].paid = 1;
            double change = payment - tables[table_num-1].total;
            printf("Change: %.2lf\n", change);
        }
    } while (payment < tables[table_num-1].total);

    // display table payment
    printf("\nTable %d Payment\n", table_num);
    printf("--------------------\n");
    for (int i = 0; i < tables[table_num-1].num_items; i++) {
        printf("%-15s %.2lf\n", tables[table_num-1].items[i], tables[table_num-1].prices[i]);
    }
    printf("--------------------\n");
    printf("Total: %.2lf\n", tables[table_num-1].total);
    printf("Payment: %.2lf\n", payment);
    printf("Change: %.2lf\n", payment - tables[table_num-1].total);

    // wait for user input before exiting
    printf("\nPress enter to exit...");
    getchar();
    return 0;
}