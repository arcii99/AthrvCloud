//FormAI DATASET v1.0 Category: Product Inventory System ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
} products[100];

int count;

void addProduct() {
    printf("Enter product name: ");
    scanf("%s", &products[count].name);
    printf("Enter product price: ");
    scanf("%f", &products[count].price);
    printf("Enter product quantity: ");
    scanf("%d", &products[count].quantity);
    products[count].id = count + 1;
    count++;
    printf("Product added successfully!\n\n");
}

void editProduct() {
    int id;
    printf("Enter product ID to edit: ");
    scanf("%d", &id);
    if (id > count || id <= 0) {
        printf("Invalid product ID!\n\n");
        return;
    }
    printf("Enter new name (press enter to skip): ");
    char newName[50];
    scanf("%s", &newName);
    if (strlen(newName) > 0) {
        strcpy(products[id-1].name, newName);
    }
    printf("Enter new price (press 0 to skip): ");
    float newPrice;
    scanf("%f", &newPrice);
    if (newPrice > 0) {
        products[id-1].price = newPrice;
    }
    printf("Enter new quantity (press 0 to skip): ");
    int newQuantity;
    scanf("%d", &newQuantity);
    if (newQuantity > 0) {
        products[id-1].quantity = newQuantity;
    }
    printf("Product updated successfully!\n\n");
}

void deleteProduct() {
    int id;
    printf("Enter product ID to delete: ");
    scanf("%d", &id);
    if (id > count || id <= 0) {
        printf("Invalid product ID!\n\n");
        return;
    }
    for (int i = id-1; i < count-1; i++) {
        products[i] = products[i+1];
    }
    count--;
    printf("Product deleted successfully!\n\n");
}

void displayProducts() {
    printf("ID\tName\tPrice\tQuantity\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\t%d\n", products[i].id, products[i].name, products[i].price, products[i].quantity);
    }
    printf("\n");
}

int main() {
    count = 0;
    int choice = 0;
    while (choice != 5) {
        printf("1. Add product\n");
        printf("2. Edit product\n");
        printf("3. Delete product\n");
        printf("4. Display products\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                editProduct();
                break;
            case 3:
                deleteProduct();
                break;
            case 4:
                displayProducts();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice!\n\n");
                break;
        }
    }
    return 0;
}