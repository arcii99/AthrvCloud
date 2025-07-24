//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include<stdio.h>
#include<string.h>

struct menu_items{
    char dish_name[50];
    int price;
};

/* Function to display the menu */
void show_menu(struct menu_items menu[], int menu_size)
{
    printf("\t\t\tMenu\n");
    printf("-----------------------------------------------\n");
    for(int i=0; i<menu_size; i++)
    {
        printf("%d. %s\t\t%d\n", i+1, menu[i].dish_name, menu[i].price);
    }
    printf("-----------------------------------------------\n");
}

/* Function to take the order from the user */
void order(struct menu_items menu[], int menu_size, int order_index[], int order_quantity[])
{
    int choice, quantity;
    int i=0;
    do{
        printf("Enter your choice of dish (1-%d): ", menu_size);
        scanf("%d", &choice);
        if(choice>=1 && choice<=menu_size)
        {
            order_index[i] = choice-1;
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            order_quantity[i] = quantity;
            i++;
        }
        else{
            printf("Invalid choice! Please enter again.\n");
        }
    }while(choice<1 || choice>menu_size);
}

/* Function to calculate the bill and display it */
void generate_bill(struct menu_items menu[], int menu_size, int order_index[], int order_quantity[], int order_size)
{
    int total=0;
    printf("\n\n\t\t\tInvoice\n");
    printf("-----------------------------------------------\n");
    printf("Dish\t\tQuantity\tPrice\n");
    printf("-----------------------------------------------\n");
    for(int i=0; i<order_size; i++)
    {
        printf("%s\t\t%d\t\t%d\n", menu[order_index[i]].dish_name, order_quantity[i], menu[order_index[i]].price*order_quantity[i]);
        total += menu[order_index[i]].price*order_quantity[i];
    }
    printf("-----------------------------------------------\n");
    printf("Total:\t\t\t\t%d\n", total);
}

int main()
{
    // Initializing the menu items
    struct menu_items menu[5];
    strcpy(menu[0].dish_name, "Coffee");
    menu[0].price = 50;
    strcpy(menu[1].dish_name, "Tea");
    menu[1].price = 40;
    strcpy(menu[2].dish_name, "Sandwich");
    menu[2].price = 80;
    strcpy(menu[3].dish_name, "Burger");
    menu[3].price = 100;
    strcpy(menu[4].dish_name, "Pizza");
    menu[4].price = 150;

    int order_size = 0;
    int order_index[10], order_quantity[10];
    char choice;
    do{
        show_menu(menu, 5);
        printf("Do you want to order something? (Y/N): ");
        scanf(" %c", &choice);
        if(choice == 'Y' || choice == 'y')
        {
            order(menu, 5, order_index, order_quantity);
            order_size++;
        }
        else if(choice == 'N' || choice == 'n')
        {
            generate_bill(menu, 5, order_index, order_quantity, order_size);
            printf("Thank you for visiting us!\n");
        }
        else{
            printf("Invalid choice! Please enter again.\n");
        }
    }while(choice != 'N' && choice != 'n');

    return 0;
}