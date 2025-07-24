//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: medieval
#include<stdio.h>
#include<string.h>

struct item{
    char name[20];
    float price;
    int quantity;
};

struct customer{
    char name[20];
    int table_no;
    struct item items[10];
    int total_items;
    float total_bill;
};

struct customer customers[50];
int customer_count = 0;

void print_menu(){
    printf("------------------------------\n");
    printf("|          MENU CARD         |\n");
    printf("------------------------------\n");
    printf("| Item Name     |   Price    |\n");
    printf("------------------------------\n");
    printf("| Bread         |   2 coins  |\n");
    printf("| Soup          |   5 coins  |\n");
    printf("| Roast Chicken |  10 coins  |\n");
    printf("| Wine          |  15 coins  |\n");
    printf("| Cake          |   7 coins  |\n");
    printf("------------------------------\n");
}

void print_bill(struct customer customer){
    int i;
    printf("------------------------------\n");
    printf("|           INVOICE          |\n");
    printf("------------------------------\n");
    printf("| Name: %19s |\n", customer.name);
    printf("| Table No.: %15d |\n", customer.table_no);
    printf("------------------------------\n");
    printf("| Item Name     |   Price    |\n");
    printf("------------------------------\n");
    for(i=0;i<customer.total_items;i++){
        printf("| %-14s | %8.2f |\n", customer.items[i].name, customer.items[i].price);
    }
    printf("------------------------------\n");
    printf("| Total items: %13d |\n", customer.total_items);
    printf("| Total Bill: %14.2f |\n", customer.total_bill);
    printf("------------------------------\n");
}

void add_item(struct item item, struct customer *customer){
    customer->items[customer->total_items] = item;
    customer->total_items++;
    customer->total_bill += item.price;
}

void create_order(char name[], int table_no){
    struct customer customer;
    int choice;
    strcpy(customer.name, name);
    customer.table_no = table_no;
    customer.total_items = 0;
    customer.total_bill = 0;
    print_menu();
    do{
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);
        if(choice == 1){
            struct item bread = {"Bread", 2, 1};
            add_item(bread, &customer);
        }else if(choice == 2){
            struct item soup = {"Soup", 5, 1};
            add_item(soup, &customer);
        }else if(choice == 3){
            struct item chicken = {"Roast Chicken", 10, 1};
            add_item(chicken, &customer);
        }else if(choice == 4){
            struct item wine = {"Wine", 15, 1};
            add_item(wine, &customer);
        }else if(choice == 5){
            struct item cake = {"Cake", 7, 1};
            add_item(cake, &customer);
        }else{
            printf("Invalid choice! Please try again.\n");
        }
        printf("Add another item? (y/n): ");
        fflush(stdin);
    }while(getchar() == 'y');
    print_bill(customer);
    customers[customer_count++] = customer;
}

void show_orders(){
    int i;
    printf("------------------------------\n");
    printf("|        CUSTOMER BILL       |\n");
    printf("------------------------------\n");
    for(i=0;i<customer_count;i++){
        print_bill(customers[i]);
        printf("\n");
    }
}

int main(){
    int choice;
    char name[20];
    int table_no;
    do{
        printf("\nWelcome to Medieval Cafe!\n");
        printf("1. Create Order\n");
        printf("2. Show Orders\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("\nEnter your name: ");
                scanf("%s", name);
                printf("Enter table number: ");
                scanf("%d", &table_no);
                create_order(name, table_no);
                break;
            case 2:
                show_orders();
                break;
            case 3:
                printf("\nThank you for visiting! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }while(choice != 3);
    return 0;
}