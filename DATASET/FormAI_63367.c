//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000

typedef struct{
    char name[50];
    int id;
    int quantity;
    float price;
} Product;

typedef struct{
    char name[50];
    int id;
    Product products[MAX_PRODUCTS];
    int num_products;
} Warehouse;

int compare(const void *a, const void *b){
    // Compare by product names
    Product *product1 = (Product *)a;
    Product *product2 = (Product *)b;
    return strcmp(product1->name, product2->name);
}

int main(){
    // Create two warehouses
    Warehouse warehouse1 = {"Warehouse 1", 1};
    Warehouse warehouse2 = {"Warehouse 2", 2};

    // Add some products to warehouse 1
    warehouse1.num_products = 3;
    strcpy(warehouse1.products[0].name, "Product 1");
    warehouse1.products[0].id = 1001;
    warehouse1.products[0].quantity = 10;
    warehouse1.products[0].price = 9.99;
    strcpy(warehouse1.products[1].name, "Product 2");
    warehouse1.products[1].id = 1002;
    warehouse1.products[1].quantity = 5;
    warehouse1.products[1].price = 19.99;
    strcpy(warehouse1.products[2].name, "Product 3");
    warehouse1.products[2].id = 1003;
    warehouse1.products[2].quantity = 2;
    warehouse1.products[2].price = 29.99;

    // Add some products to warehouse 2
    warehouse2.num_products = 2;
    strcpy(warehouse2.products[0].name, "Product 4");
    warehouse2.products[0].id = 2001;
    warehouse2.products[0].quantity = 20;
    warehouse2.products[0].price = 49.99;
    strcpy(warehouse2.products[1].name, "Product 5");
    warehouse2.products[1].id = 2002;
    warehouse2.products[1].quantity = 15;
    warehouse2.products[1].price = 39.99;

    // Sort the products in warehouse 1 by name
    qsort(warehouse1.products, warehouse1.num_products, sizeof(Product), compare);

    // Print the products in warehouse 1
    printf("Products in %s:\n", warehouse1.name);
    printf("%-15s %-10s %-10s %-10s\n", "Name", "ID", "Quantity", "Price");
    for(int i=0; i<warehouse1.num_products; i++){
        printf("%-15s %-10d %-10d $%-9.2f\n", warehouse1.products[i].name, warehouse1.products[i].id, warehouse1.products[i].quantity, warehouse1.products[i].price);
    }

    // Find a product in warehouse 1 by name
    char search_name[50] = "Product 2";
    for(int i=0; i<warehouse1.num_products; i++){
        if(strcmp(search_name, warehouse1.products[i].name) == 0){
            printf("\n%s found in %s!\n", search_name, warehouse1.name);
            printf("%-15s %-10d %-10d $%-9.2f\n", warehouse1.products[i].name, warehouse1.products[i].id, warehouse1.products[i].quantity, warehouse1.products[i].price);
            break;
        }
    }

    // Sort the products in warehouse 2 by name
    qsort(warehouse2.products, warehouse2.num_products, sizeof(Product), compare);

    // Print the products in warehouse 2
    printf("\nProducts in %s:\n", warehouse2.name);
    printf("%-15s %-10s %-10s %-10s\n", "Name", "ID", "Quantity", "Price");
    for(int i=0; i<warehouse2.num_products; i++){
        printf("%-15s %-10d %-10d $%-9.2f\n", warehouse2.products[i].name, warehouse2.products[i].id, warehouse2.products[i].quantity, warehouse2.products[i].price);
    }

    // Find a product in warehouse 2 by name
    strcpy(search_name, "Product 5");
    for(int i=0; i<warehouse2.num_products; i++){
        if(strcmp(search_name, warehouse2.products[i].name) == 0){
            printf("\n%s found in %s!\n", search_name, warehouse2.name);
            printf("%-15s %-10d %-10d $%-9.2f\n", warehouse2.products[i].name, warehouse2.products[i].id, warehouse2.products[i].quantity, warehouse2.products[i].price);
            break;
        }
    }

    return 0;
}