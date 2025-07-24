//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct menu // structure to hold menu items and their prices
{
    char name[50];
    int price;
};
struct order // structure to hold ordered items and their quantities
{
    char name[50];
    int qty;
};

int main()
{
    struct menu m[10]; // array of menu items and their prices
    m[0].price = 50;
    strcpy(m[0].name, "Coffee");
    m[1].price = 30;
    strcpy(m[1].name, "Tea");
    m[2].price = 100;
    strcpy(m[2].name, "Sandwich");
    m[3].price = 80;
    strcpy(m[3].name, "Burger");
    m[4].price = 150;
    strcpy(m[4].name, "Pizza");
    m[5].price = 20;
    strcpy(m[5].name, "Biscuit");
    m[6].price = 50;
    strcpy(m[6].name, "Cake");
    m[7].price = 15;
    strcpy(m[7].name, "Jam Bread");
    m[8].price = 10;
    strcpy(m[8].name, "Butter Bread");
    m[9].price = 5;
    strcpy(m[9].name, "Water");

    struct order o[10]; // array of ordered items and their quantities
    int count = 0; // count of ordered items

    int choice; // user's choice in selecting menu items

    do // loop to ask user for menu item selection and quantity until exit chosen
    {
        printf("\nMENU\n");
        printf("1. Coffee - Rs.50\n");
        printf("2. Tea - Rs.30\n");
        printf("3. Sandwich - Rs.100\n");
        printf("4. Burger - Rs.80\n");
        printf("5. Pizza - Rs.150\n");
        printf("6. Biscuit - Rs.20\n");
        printf("7. Cake - Rs.50\n");
        printf("8. Jam Bread - Rs.15\n");
        printf("9. Butter Bread - Rs.10\n");
        printf("10. Water - Rs.5\n");
        printf("11. Confirm Order\n");
        printf("12. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice >= 1 && choice <= 10) // if menu item selected
        {
            printf("Enter quantity: ");
            scanf("%d", &o[count].qty);
            strcpy(o[count].name, m[choice-1].name); // get item name from menu array
            count++;
        }
        else if(choice == 11) // if confirm order chosen
        {
            int total = 0;

            printf("\nORDER DETAILS\n");
            printf("==================================================\n");
            printf("Item Name \t\t Quantity \t\t Price\n");
            printf("==================================================\n");
            for(int i = 0; i < count; i++) // print details of ordered items
            {
                printf("%s \t\t %d \t\t\t Rs. %d\n", o[i].name, o[i].qty, m[find_menu_index(m, o[i].name, 10)].price * o[i].qty);
                total += m[find_menu_index(m, o[i].name, 10)].price * o[i].qty;
            }
            printf("==================================================\n");
            printf("Total: Rs. %d\n", total); // print total price of order
            printf("\nThank you for visiting. Have a nice day!\n");
            return 0;
        }
    }while(choice != 12);

    printf("\nThank you for visiting. Have a nice day!\n");
    return 0;
}

int find_menu_index(struct menu m[], char name[], int len) // function to find index of menu item
{
    for(int i = 0; i < len; i++)
    {
        if(strcmp(name, m[i].name) == 0)
        {
            return i;
        }
    }
    return -1;
}