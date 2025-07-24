//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUCTS 100

struct Product {
    char name[30];
    int quantity;
    double price;
};

typedef struct Product Product;

Product productList[MAX_PRODUCTS];
int numProducts;

void addProduct(char *name, int quantity, double price);
void removeProduct(char *name);
void listProducts();
void updatePrice(char *name, double newPrice);
int getProductIndex(char *name);
double getTotalValue();

int main() {
    numProducts = 0;

    addProduct("Apple", 50, 0.50);
    addProduct("Banana", 30, 0.25);
    addProduct("Orange", 40, 0.40);
    listProducts();

    removeProduct("Banana");
    listProducts();

    updatePrice("Apple", 0.60);
    listProducts();

    double totalValue = getTotalValue();
    printf("\nTotal value of products: $%.2f\n", totalValue);

    return 0;
}

void addProduct(char *name, int quantity, double price) {
    if (numProducts == MAX_PRODUCTS) {
        printf("Error: Maximum number of products reached!\n");
        return;
    }

    Product newProduct = { *name, quantity, price };
    productList[numProducts++] = newProduct;

    printf("%s added!\n", name);
}

void removeProduct(char *name) {
    int index = getProductIndex(name);
    if (index == -1) {
        printf("Error: Product not found!\n");
        return;
    }

    for (int i = index; i < numProducts - 1; i++) {
        productList[i] = productList[i + 1];
    }

    numProducts--;

    printf("%s removed!\n", name);
}

void listProducts() {
    printf("\nList of Products:\n");
    printf("-------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Name", "Quantity", "Price");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < numProducts; i++) {
        printf("%-20s %-10d $%-10.2f\n", productList[i].name, productList[i].quantity, productList[i].price);
    }

    printf("-------------------------------------------------\n");
}

void updatePrice(char *name, double newPrice) {
    int index = getProductIndex(name);
    if (index == -1) {
        printf("Error: Product not found!\n");
        return;
    }

    productList[index].price = newPrice;

    printf("%s price updated to $%.2f\n", name, newPrice);
}

int getProductIndex(char *name) {
    for (int i = 0; i < numProducts; i++) {
        if (strcmp(productList[i].name, name) == 0) {
            return i;
        }
    }

    return -1;
}

double getTotalValue() {
    double total = 0.0;

    for (int i = 0; i < numProducts; i++) {
        total += productList[i].quantity * productList[i].price;
    }

    return total;
}