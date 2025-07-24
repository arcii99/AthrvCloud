//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

struct item{
    char name[MAX_NAME_LENGTH];
    double price;
};

struct order{
    int item_number;
    int quantity;
};

double total_price(struct order *order_list, struct item *item_list, int num_orders);
double calculate_tax(double total_price);
int print_receipt(struct order *order_list, struct item *item_list, int num_orders, double total_price, double tax);

int main(){
    struct item menu[MAX_ITEMS] = {
        {"Cappuccino", 4.99},
        {"Latte", 3.99},
        {"Espresso", 2.99},
        {"Muffin", 2.49},
        {"Croissant", 1.99},
        {"Bagel", 1.49},
        {"Juice", 1.99},
        {"Water", 0.99}
    };
    int num_items = sizeof(menu)/sizeof(struct item);
    
    printf("***Welcome to Donald Knuth's Cafe Billing System***\n\n");
    printf("Menu:\n");
    int i;
    for(i = 0; i < num_items; i++){
        printf("%d. %-10s $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
    printf("\n");
    
    struct order order_list[MAX_ITEMS];
    int num_orders = 0;
    
    char input[MAX_NAME_LENGTH];
    int item_number;
    int quantity;
    printf("Enter item number and quantity (separated by space, type 'done' when finished): ");
    scanf("%s", input);
    while(strcmp(input, "done") != 0 && num_orders < MAX_ITEMS){
        item_number = atoi(input) - 1;
        if(item_number < 0 || item_number >= num_items){
            printf("Invalid item number. Please enter a number between 1 and %d.\n", num_items);
        }else{
            scanf("%d", &quantity);
            if(quantity < 1){
                printf("Invalid quantity. Please enter a positive integer.\n");
            }else{
                order_list[num_orders].item_number = item_number;
                order_list[num_orders].quantity = quantity;
                num_orders++;
            }
        }
        printf("Enter item number and quantity (separated by space, type 'done' when finished): ");
        scanf("%s", input);
    }
    printf("\n");
    
    double total = total_price(order_list, menu, num_orders);
    double tax = calculate_tax(total);
    print_receipt(order_list, menu, num_orders, total, tax);
    
    printf("\nThank you for visiting Donald Knuth's Cafe. Have a great day!\n");
    
    return 0;
}

double total_price(struct order *order_list, struct item *item_list, int num_orders){
    double total = 0;
    int i;
    for(i = 0; i < num_orders; i++){
        total += item_list[order_list[i].item_number].price * order_list[i].quantity;
    }
    return total;
}

double calculate_tax(double total_price){
    const double tax_rate = 0.0825;
    return total_price * tax_rate;
}

int print_receipt(struct order *order_list, struct item *item_list, int num_orders, double total_price, double tax){
    printf("Receipt:\n");
    printf("%-20s%-10s%-10s%s\n", "Item", "Quantity", "Price", "Total");
    int i;
    for(i = 0; i < num_orders; i++){
        struct item item = item_list[order_list[i].item_number];
        int quantity = order_list[i].quantity;
        double price = item.price;
        double total = price * quantity;
        printf("%-20s%-10d$%-9.2f$%.2f\n", item.name, quantity, price, total);
    }
    printf("\n");
    printf("%40s$%.2f\n", "Total:", total_price);
    printf("%40s$%.2f\n", "Tax:", tax);
    printf("%40s$%.2f\n", "Grand Total:", total_price + tax);
    return 0;
}