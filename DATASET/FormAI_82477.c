//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: Donald Knuth
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_ORDERS 10

/* Structs */
typedef struct {
    char item[20];
    float price;
} Menu_item;

typedef struct {
    Menu_item item;
    int quantity;
} Order_item;

typedef struct {
    Order_item items[MAX_ORDERS];
    float total_cost;
    int num_items;
} Order;

/* Function Definitions */
void display_menu(Menu_item* menu, int menu_size);
int validate_option(char* input, int menu_size);
void take_order(Menu_item* menu, int menu_size, Order* order);
void generate_bill(Order* order);

/* Main Program */
int main()
{
    Menu_item menu[] = {{"Cappuccino", 2.50}, {"Latte", 3.00}, {"Espresso", 2.00}, 
                        {"Mocha", 3.50}, {"Tea", 1.50}, {"Hot Chocolate", 2.50}};
    int menu_size = sizeof(menu)/sizeof(*menu);
    Order order = {0};

    printf("\nWelcome to the C Cafe Billing System\n");
    printf("------------------------------------\n\n");

    display_menu(menu, menu_size);
    take_order(menu, menu_size, &order);
    generate_bill(&order);

    return 0;
}

/* Function Definitions */

void display_menu(Menu_item* menu, int menu_size)
{
    printf("Menu\n");
    printf("----\n\n");
    for(int i=0; i<menu_size; i++)
    {
        printf("%d. %s - $%.2f\n", i+1, menu[i].item, menu[i].price);
    }
    printf("\n");
}

int validate_option(char* input, int menu_size)
{
    int option = atoi(input);
    if(option>=1 && option<=menu_size)
    {
        return option;
    }
    else
    {
        return 0;
    }
}

void take_order(Menu_item* menu, int menu_size, Order* order)
{
    char input[10];
    int option_num;

    do
    {
        printf("Enter menu option (1-%d) or 'done' to finish: ", menu_size);
        scanf("%s", input);
        option_num = validate_option(input, menu_size);
        if(option_num != 0)
        {
            printf("Enter quantity: ");
            scanf("%s", input);
            int quantity = atoi(input);

            if(quantity > 0)
            {
                Order_item new_item = {menu[option_num-1], quantity};
                order->items[order->num_items++] = new_item;
                order->total_cost += (menu[option_num-1].price * quantity);
                printf("%d %s added to order\n\n", quantity, menu[option_num-1].item);
            }
            else
            {
                printf("Invalid quantity entered\n\n");
            }
        }
        else if(strcmp(input, "done")!=0)
        {
            printf("Invalid option entered\n\n");
        }

    } while(strcmp(input, "done")!=0 && order->num_items < MAX_ORDERS);
    printf("\n");
}

void generate_bill(Order* order)
{
    printf("Order\n");
    printf("-----\n");
    for(int i=0; i<order->num_items; i++)
    {
        printf("%d %s - $%.2f\n", order->items[i].quantity, order->items[i].item.item, order->items[i].item.price*order->items[i].quantity);
    }
    printf("Total cost: $%.2f\n\n", order->total_cost);
}