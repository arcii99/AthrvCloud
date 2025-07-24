//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Constants
#define MAX_PRODUCTS 100 // Maximum number of products that can be stored
#define MAX_NAME_LENGTH 50 // Maximum length of product name
#define MAX_CODE_LENGTH 20 // Maximum length of product code
#define MAX_ID_LENGTH 20 // Maximum length of employee ID

// Define Structs
typedef struct {
    char code[MAX_CODE_LENGTH];
    char name[MAX_NAME_LENGTH];
    int quantity;
} Product;

typedef struct {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
} Employee;

// Define Global Variables
int num_products = 0; // Number of products stored
Product products[MAX_PRODUCTS]; // Array of products
Employee employee; // Current employee logged in

// Declare Functions
void addProduct(char* code, char* name, int quantity);
void removeProduct(char* code, int quantity);
void displayProducts();
void login();
void logout();

// Main Function
int main() {
    login(); // Prompt user to login
    printf("Welcome %s!\n", employee.name);
    
    // Prompt user for action
    char action;
    do {
        printf("\nEnter 'a' to add product, 'r' to remove product, 'd' to display products, or 'q' to quit: ");
        scanf(" %c", &action);
        switch (action) {
            case 'a':
                // Prompt user for product details
                char code[MAX_CODE_LENGTH];
                char name[MAX_NAME_LENGTH];
                int quantity;
                printf("Enter product code: ");
                scanf(" %[^\n]%*c", code);
                printf("Enter product name: ");
                scanf(" %[^\n]%*c", name);
                printf("Enter product quantity: ");
                scanf("%d", &quantity);
                // Add product to warehouse
                addProduct(code, name, quantity);
                break;
            case 'r':
                // Prompt user for product code and quantity to remove
                printf("Enter product code to remove: ");
                char codeToRemove[MAX_CODE_LENGTH];
                scanf(" %[^\n]%*c", codeToRemove);
                printf("Enter quantity to remove: ");
                int quantityToRemove;
                scanf("%d", &quantityToRemove);
                // Remove products from warehouse
                removeProduct(codeToRemove, quantityToRemove);
                break;
            case 'd':
                // Display all products in warehouse
                displayProducts();
                break;
            case 'q':
                // Prompt user to logout
                logout();
                printf("Goodbye!\n");
                break;
            default:
                // Prompt user to enter valid action
                printf("Invalid action.\n");
        }
    } while (action != 'q');
    
    return 0;
}

// Add product to warehouse
void addProduct(char* code, char* name, int quantity) {
    // Check if product already exists
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].code, code) == 0) {
            products[i].quantity += quantity; // Increase quantity if product already exists
            printf("%d units of %s added to warehouse.\n", quantity, name);
            return;
        }
    }
    // If product does not already exist, add it to warehouse
    if (num_products < MAX_PRODUCTS) {
        strcpy(products[num_products].code, code);
        strcpy(products[num_products].name, name);
        products[num_products].quantity = quantity;
        printf("%d units of %s added to warehouse.\n", quantity, name);
        num_products++;
    } else {
        printf("Warehouse is full. Cannot add product.\n");
    }
}

// Remove product from warehouse
void removeProduct(char* code, int quantity) {
    // Check if product exists in warehouse
    int indexToRemove = -1;
    for (int i = 0; i < num_products; i++) {
        if (strcmp(products[i].code, code) == 0) {
            indexToRemove = i;
        }
    }
    if (indexToRemove != -1) {
        // Check if there is enough quantity to remove
        if (products[indexToRemove].quantity >= quantity) {
            products[indexToRemove].quantity -= quantity;
            printf("%d units of %s removed from warehouse.\n", quantity, products[indexToRemove].name);
            // If quantity is now 0, remove product from warehouse
            if (products[indexToRemove].quantity == 0) {
                for (int i = indexToRemove; i < num_products - 1; i++) {
                    strcpy(products[i].code, products[i + 1].code);
                    strcpy(products[i].name, products[i + 1].name);
                    products[i].quantity = products[i + 1].quantity;
                }
                num_products--;
            }
        } else {
            printf("Not enough %s in warehouse. Cannot remove.\n", products[indexToRemove].name);
        }
    } else {
        printf("%s not found in warehouse. Cannot remove.\n", code);
    }
}

// Display all products in warehouse
void displayProducts() {
    printf("Code\tName\t\tQuantity\n");
    for (int i = 0; i < num_products; i++) {
        printf("%s\t%s\t\t%d\n", products[i].code, products[i].name, products[i].quantity);
    }
}

// Prompt user to login
void login() {
    printf("Please login to continue.\n");
    printf("Enter employee ID: ");
    scanf(" %[^\n]%*c", employee.id);
    printf("Enter employee name: ");
    scanf(" %[^\n]%*c", employee.name);
}

// Prompt user to logout
void logout() {
    printf("Logging out %s...\n", employee.name);
}