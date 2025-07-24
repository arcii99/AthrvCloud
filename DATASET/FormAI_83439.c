//FormAI DATASET v1.0 Category: Product Inventory System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 1000

struct Product {
    int id; // Unique identifier for each product
    char name[50]; // Name of the product
    int quantity; // Number of items available in the inventory
    double price; // Price of each item in USD
};

struct Inventory {
    struct Product products[MAX_PRODUCTS]; // An array of available products in the inventory
    int numProducts; // Total number of products in the inventory
    int nextID; // Next id to assign for a new product
};

// Function prototypes
void displayMenu();
void addProduct(struct Inventory*);
void updateProduct(struct Inventory*);
void deleteProduct(struct Inventory*);
void viewProduct(struct Inventory*);
void searchProduct(struct Inventory*);
void saveInventory(struct Inventory*, char*);
void loadInventory(struct Inventory*, char*);

int main() {
    struct Inventory inventory;
    inventory.numProducts = 0;
    inventory.nextID = 1;
    
    // Load the inventory from file
    loadInventory(&inventory, "inventory.txt");
    
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addProduct(&inventory);
                break;
            case 2:
                updateProduct(&inventory);
                break;
            case 3:
                deleteProduct(&inventory);
                break;
            case 4:
                viewProduct(&inventory);
                break;
            case 5:
                searchProduct(&inventory);
                break;
            case 6:
                saveInventory(&inventory, "inventory.txt");
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0); // Terminate the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(1); // Loop back to the menu

    return 0;
}

void displayMenu() {
    printf("\nProduct Inventory System\n");
    printf("-------------------------\n");
    printf("1. Add product\n");
    printf("2. Update product\n");
    printf("3. Delete product\n");
    printf("4. View product\n");
    printf("5. Search product\n");
    printf("6. Save inventory to file\n");
    printf("7. Quit\n");
    printf("\nEnter your choice (1-7): ");
}

void addProduct(struct Inventory *inventory) {
    if(inventory->numProducts == MAX_PRODUCTS) {
        printf("Error: Max number of products reached.\n");
        return;
    }
    
    struct Product newProduct;
    newProduct.id = inventory->nextID++; // Assign a unique ID to the new product
    
    printf("Enter the name of the product: ");
    fgets(newProduct.name, sizeof(newProduct.name), stdin);
    newProduct.name[strcspn(newProduct.name, "\n")] = 0; // Remove trailing newline character
    
    printf("Enter the quantity of the product: ");
    scanf("%d", &newProduct.quantity);
    
    printf("Enter the price of the product: ");
    scanf("%lf", &newProduct.price);
    
    inventory->products[inventory->numProducts++] = newProduct;
    
    printf("Product successfully added!\n");
}

void updateProduct(struct Inventory *inventory) {
    int id;
    printf("Enter the ID of the product to update: ");
    scanf("%d", &id);
    
    int index = -1; // Initialize to an invalid value
    for(int i = 0; i < inventory->numProducts; i++) {
        if(inventory->products[i].id == id) {
            index = i;
            break;
        }
    }
    
    if(index == -1) { // Product with the given ID not found
        printf("Error: Product with ID %d not found.\n", id);
        return;
    }
    
    struct Product *product = &inventory->products[index];
    printf("Enter new name for product (or leave blank to keep old name): ");
    char newName[50];
    fgets(newName, sizeof(newName), stdin);
    newName[strcspn(newName, "\n")] = 0; // Remove trailing newline character
    if(newName[0] != '\0') {
        strcpy(product->name, newName);
    }
    
    printf("Enter new quantity for product (or leave blank to keep old quantity): ");
    char newQuantity[10];
    fgets(newQuantity, sizeof(newQuantity), stdin);
    newQuantity[strcspn(newQuantity, "\n")] = 0; // Remove trailing newline character
    if(newQuantity[0] != '\0') {
        product->quantity = atoi(newQuantity);
    }
    
    printf("Enter new price for product (or leave blank to keep old price): ");
    char newPrice[20];
    fgets(newPrice, sizeof(newPrice), stdin);
    newPrice[strcspn(newPrice, "\n")] = 0; // Remove trailing newline character
    if(newPrice[0] != '\0') {
        product->price = atof(newPrice);
    }
    
    printf("Product successfully updated!\n");
}

void deleteProduct(struct Inventory *inventory) {
    int id;
    printf("Enter the ID of the product to delete: ");
    scanf("%d", &id);
    
    int index = -1; // Initialize to an invalid value
    for(int i = 0; i < inventory->numProducts; i++) {
        if(inventory->products[i].id == id) {
            index = i;
            break;
        }
    }
    
    if(index == -1) { // Product with the given ID not found
        printf("Error: Product with ID %d not found.\n", id);
        return;
    }
    
    // Remove the product from the array by shifting the rest of the elements
    for(int i = index; i < inventory->numProducts - 1; i++) {
        inventory->products[i] = inventory->products[i + 1];
    }
    inventory->numProducts--;
    
    printf("Product successfully deleted!\n");
}

void viewProduct(struct Inventory *inventory) {
    int id;
    printf("Enter the ID of the product to view: ");
    scanf("%d", &id);
    
    int index = -1; // Initialize to an invalid value
    for(int i = 0; i < inventory->numProducts; i++) {
        if(inventory->products[i].id == id) {
            index = i;
            break;
        }
    }
    
    if(index == -1) { // Product with the given ID not found
        printf("Error: Product with ID %d not found.\n", id);
        return;
    }
    
    struct Product product = inventory->products[index];
    printf("ID: %d\n", product.id);
    printf("Name: %s\n", product.name);
    printf("Quantity: %d\n", product.quantity);
    printf("Price: $%.2lf\n", product.price);
}

void searchProduct(struct Inventory *inventory) {
    char query[50];
    printf("Enter a search query: ");
    fgets(query, sizeof(query), stdin);
    query[strcspn(query, "\n")] = 0; // Remove trailing newline character
    
    int numResults = 0;
    for(int i = 0; i < inventory->numProducts; i++) {
        struct Product product = inventory->products[i];
        if(strstr(product.name, query) != NULL) {
            printf("ID: %d\n", product.id);
            printf("Name: %s\n", product.name);
            printf("Quantity: %d\n", product.quantity);
            printf("Price: $%.2lf\n", product.price);
            numResults++;
        }
    }
    
    if(numResults == 0) {
        printf("No results found.\n");
    }
}

void saveInventory(struct Inventory *inventory, char *filename) {
    FILE *file = fopen(filename, "w");
    if(file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    
    // Write the number of products to the file
    fprintf(file, "%d\n", inventory->numProducts);
    
    // Write each product to the file
    for(int i = 0; i < inventory->numProducts; i++) {
        struct Product product = inventory->products[i];
        fprintf(file, "%d,%s,%d,%.2lf\n", product.id, product.name, product.quantity, product.price);
    }
    
    fclose(file);
    
    printf("Inventory successfully saved to file!\n");
}

void loadInventory(struct Inventory *inventory, char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("File not found. Creating new file.\n");
        return;
    }
    
    // Read the number of products from the file
    fscanf(file, "%d\n", &inventory->numProducts);
    
    // Read each product from the file
    for(int i = 0; i < inventory->numProducts; i++) {
        int id, quantity;
        char name[50];
        double price;
        fscanf(file, "%d,%[^,],%d,%lf\n", &id, name, &quantity, &price);
        
        struct Product product;
        product.id = id;
        strcpy(product.name, name);
        product.quantity = quantity;
        product.price = price;
        
        inventory->products[i] = product;
    }
    
    fclose(file);
    
    printf("Inventory successfully loaded from file!\n");
}