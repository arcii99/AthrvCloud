//FormAI DATASET v1.0 Category: Product Inventory System ; Style: portable
#include <stdio.h>
#define MAX_PRODUCTS 100

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

struct Product products[MAX_PRODUCTS];
int num_products = 0;

int main() {
    char choice;
    do {
        printf("\n*******************************************\n");
        printf("Inventory management system\n");
        printf("*******************************************\n");
        printf("1. Add a product\n");
        printf("2. Update a product\n");
        printf("3. Delete a product\n");
        printf("4. Search for a product by name\n");
        printf("5. List all the products\n");
        printf("6. Quit\n");
        printf("Enter your choice: ");
        fflush(stdin);
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_product();
                break;

            case '2':
                update_product();
                break;

            case '3':
                delete_product();
                break;

            case '4':
                search_product_by_name();
                break;

            case '5':
                list_products();
                break;

            case '6':
                printf("\nExiting the program...\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }

    } while (choice != '6');

    return 0;
}

void add_product() {
    struct Product p;

    printf("Enter the product name: ");
    fflush(stdin);
    gets(p.name);

    printf("Enter the product price: ");
    fflush(stdin);
    scanf("%f", &p.price);

    printf("Enter the product quantity: ");
    fflush(stdin);
    scanf("%d", &p.quantity);

    p.id = num_products + 1;
    products[num_products] = p;
    num_products++;

    printf("\nProduct added successfully.\n");
}

void update_product() {
    int product_id, found = 0;

    printf("Enter the ID of the product you want to update: ");
    fflush(stdin);
    scanf("%d", &product_id);

    for (int i = 0; i < num_products; i++) {
        if (products[i].id == product_id) {
            found = 1;

            printf("Enter the new product name: ");
            fflush(stdin);
            gets(products[i].name);

            printf("Enter the new product price: ");
            fflush(stdin);
            scanf("%f", &products[i].price);

            printf("Enter the new product quantity: ");
            fflush(stdin);
            scanf("%d", &products[i].quantity);

            printf("\nProduct updated successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found. Please try again.\n");
    }
}

void delete_product() {
    int product_id, found = 0;

    printf("Enter the ID of the product you want to delete: ");
    fflush(stdin);
    scanf("%d", &product_id);

    for (int i = 0; i < num_products; i++) {
        if (products[i].id == product_id) {
            found = 1;

            for (int j = i; j < num_products - 1; j++) {
                products[j] = products[j + 1];
            }

            num_products--;

            printf("\nProduct deleted successfully.\n");
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found. Please try again.\n");
    }
}

void search_product_by_name() {
    char product_name[50];
    int found = 0;

    printf("Enter the name of the product you want to search for: ");
    fflush(stdin);
    gets(product_name);

    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].name, product_name) == 0) {
            found = 1;

            printf("\nID: %d\nName: %s\nPrice: %.2f\nQuantity: %d\n", 
                products[i].id, products[i].name, products[i].price, products[i].quantity);
            break;
        }
    }

    if (!found) {
        printf("\nProduct not found. Please try again.\n");
    }
}

void list_products() {
    printf("\n%-5s%-25s%-10s%s", "ID", "Name", "Price", "Quantity");
    for (int i = 0; i < num_products; i++) {
        printf("\n%-5d%-25s%-10.2f%d", 
            products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("\n");
}