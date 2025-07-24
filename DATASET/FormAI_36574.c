//FormAI DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include <stdio.h>
#define MAX_PRODUCTS 100

struct Product
{
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Product products[MAX_PRODUCTS];
int numProducts = 0;

void addProduct()
{
    if (numProducts < MAX_PRODUCTS)
    {
        printf("Enter product name: ");
        scanf("%s", products[numProducts].name);

        printf("Enter product quantity: ");
        scanf("%d", &products[numProducts].quantity);

        printf("Enter product price: ");
        scanf("%f", &products[numProducts].price);

        products[numProducts].id = numProducts + 1;
        numProducts++;

        printf("\nNew product added successfully!\n\n");
    }
    else
    {
        printf("\nInventory is full. Cannot add more products.\n\n");
    }
}

void removeProduct()
{
    int id;
    printf("Enter product ID: ");
    scanf("%d", &id);

    for (int i = 0; i < numProducts; i++)
    {
        if (products[i].id == id)
        {
            for (int j = i; j < numProducts - 1; j++)
            {
                products[j] = products[j + 1];
            }
            numProducts--;
            printf("\nProduct removed successfully!\n\n");
            return;
        }
    }

    printf("\nProduct ID not found.\n\n");
}

void displayProducts()
{
    if (numProducts == 0)
    {
        printf("\nInventory is empty.\n\n");
        return;
    }

    printf("\nID\tName\t\tQuantity\tPrice\n");
    for (int i = 0; i < numProducts; i++)
    {
        printf("%d\t%-10s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
    }
    printf("\n");
}

int main()
{
    int choice;

    do
    {
        printf("Product Inventory System\n");
        printf("------------------------\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. Display Products\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addProduct(); break;
            case 2: removeProduct(); break;
            case 3: displayProducts(); break;
            case 4: printf("\nExiting program. Goodbye!\n\n"); break;
            default: printf("\nInvalid choice. Try again.\n\n");
        }
    } while (choice != 4);

    return 0;
}