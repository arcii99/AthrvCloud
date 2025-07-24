//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100
#define MAX_ORDERS 1000

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct order {
    int id;
    int product_id;
    char date[20];
    int quantity;
};


int main()
{
    // Initialize the warehouse inventory
    struct product products[MAX_PRODUCTS] = {
        {1, "Laptop", 10, 900.0},
        {2, "Mouse", 50, 20.0},
        {3, "Keyboard", 30, 50.0},
        {4, "Monitor", 20, 400.0}
        // ...
    };

    int num_products = 4;

    // Initialize the list of orders
    struct order orders[MAX_ORDERS];
    int num_orders = 0;

    // Display the main menu and wait for user input
    while (1) {
        printf("\n\nWAREHOUSE MANAGEMENT SYSTEM\n");
        printf("1. View products\n");
        printf("2. Add product\n");
        printf("3. Update product\n");
        printf("4. Remove product\n");
        printf("5. View orders\n");
        printf("6. Place order\n");
        printf("7. Exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // View products
                // Print the table header
                printf("\nID       Name                       Quantity  Price\n");
                printf("--------------------------------------------------\n");

                // Loop over all products and print them
                for (int i = 0; i < num_products; i++) {
                    printf("%-8d %-25s %-9d $%.2f\n",
                        products[i].id, products[i].name,
                        products[i].quantity, products[i].price);
                }
                break;

            case 2: // Add product
                if (num_products >= MAX_PRODUCTS) {
                    printf("\nError: maximum number of products exceeded!\n");
                    break;
                }

                // Read the product details from the user
                struct product new_product;
                printf("\nEnter the product details:\n");
                printf("ID: ");
                scanf("%d", &new_product.id);
                printf("Name: ");
                scanf("%s", new_product.name);
                printf("Quantity: ");
                scanf("%d", &new_product.quantity);
                printf("Price: ");
                scanf("%f", &new_product.price);

                // Add the product to the inventory
                products[num_products++] = new_product;
                printf("\nProduct added successfully.\n");
                break;

            case 3: // Update product
                // Read the product ID to be updated
                int product_id;
                printf("\nEnter the ID of the product to be updated: ");
                scanf("%d", &product_id);

                // Search for the product in the inventory
                int found = 0;
                for (int i = 0; i < num_products; i++) {
                    if (products[i].id == product_id) {
                        found = 1;

                        // Read the new product details from the user
                        printf("\nEnter the new product details:\n");
                        printf("Name: ");
                        scanf("%s", products[i].name);
                        printf("Quantity: ");
                        scanf("%d", &products[i].quantity);
                        printf("Price: ");
                        scanf("%f", &products[i].price);

                        printf("\nProduct updated successfully.\n");
                        break;
                    }
                }

                if (!found) {
                    printf("\nError: product not found!\n");
                }
                break;

            case 4: // Remove product
                // Read the product ID to be removed
                printf("\nEnter the ID of the product to be removed: ");
                scanf("%d", &product_id);

                // Search for the product in the inventory
                found = 0;
                for (int i = 0; i < num_products; i++) {
                    if (products[i].id == product_id) {
                        found = 1;

                        // Remove the product from the inventory by shifting the rest of the products
                        for (int j = i; j < num_products - 1; j++) {
                            products[j] = products[j + 1];
                        }

                        printf("\nProduct removed successfully.\n");
                        num_products--;
                        break;
                    }
                }

                if (!found) {
                    printf("\nError: product not found!\n");
                }
                break;

            case 5: // View orders
                // Print the table header
                printf("\nID       Product ID  Quantity  Date\n");
                printf("----------------------------------\n");

                // Loop over all orders and print them
                for (int i = 0; i < num_orders; i++) {
                    printf("%-8d %-10d %-9d %s\n",
                        orders[i].id, orders[i].product_id, orders[i].quantity, orders[i].date);
                }
                break;

            case 6: // Place order
                if (num_orders >= MAX_ORDERS) {
                    printf("\nError: maximum number of orders exceeded!\n");
                    break;
                }

                // Read the order details from the user
                struct order new_order;
                printf("\nEnter the order details:\n");
                printf("Product ID: ");
                scanf("%d", &new_order.product_id);
                printf("Quantity: ");
                scanf("%d", &new_order.quantity);
                printf("Date: ");
                scanf("%s", new_order.date);

                // Search for the product in the inventory
                found = 0;
                for (int i = 0; i < num_products; i++) {
                    if (products[i].id == new_order.product_id) {
                        found = 1;

                        // Check if there is enough quantity in the inventory
                        if (products[i].quantity < new_order.quantity) {
                            printf("\nError: insufficient quantity in the inventory!\n");
                            break;
                        }

                        // Update the product quantity and add the order
                        products[i].quantity -= new_order.quantity;
                        new_order.id = ++num_orders;
                        orders[num_orders - 1] = new_order;

                        printf("\nOrder placed successfully.\n");
                        break;
                    }
                }

                if (!found) {
                    printf("\nError: product not found!\n");
                }
                break;

            case 7: // Quit
                printf("\nThank you for using the warehouse management system!\n");
                exit(0);

            default:
                printf("\nError: invalid choice!\n");
                break;
        }
    }

    return 0;
}