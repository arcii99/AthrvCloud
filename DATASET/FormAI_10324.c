//FormAI DATASET v1.0 Category: Product Inventory System ; Style: safe
#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 100     // Maximum number of products that can be stored
#define MAX_NAME_LENGTH 50   // Maximum length of product name
#define MAX_CATEGORY_LENGTH 20  // Maximum length of category name
#define MAX_LOCATION_LENGTH 20  // Maximum length of storage location name

// Struct to hold information about a single product
typedef struct {
    int id;                    // Unique id of the product
    char name[MAX_NAME_LENGTH];    // Name of the product
    char category[MAX_CATEGORY_LENGTH];      // Category of the product
    char location[MAX_LOCATION_LENGTH];      // Storage location of the product
    int quantity;              // Quantity of the product
    float price;               // Price of the product
} Product;

// Function declarations
void initialize(Product *inventory, int *size);
void addProduct(Product *inventory, int *size);
void removeProduct(Product *inventory, int *size);
void displayProductInventory(Product *inventory, int size);
void showMenu();

// Main function
int main() {
    Product inventory[MAX_PRODUCTS];   // Array to hold product information
    int numProducts = 0;         // Number of products in the array
    int choice;                  // User's menu choice

    // Initialize the product inventory with default values
    initialize(inventory, &numProducts);

    do {
        // Display the menu and get the user's choice
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the appropriate action based on the user's choice
        switch (choice) {
            case 1:
                addProduct(inventory, &numProducts);
                break;
            case 2:
                removeProduct(inventory, &numProducts);
                break;
            case 3:
                displayProductInventory(inventory, numProducts);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to initialize the product inventory with default values
void initialize(Product *inventory, int *size) {
    *size = 4;

    inventory[0].id = 1;
    strcpy(inventory[0].name, "Watch");
    strcpy(inventory[0].category, "Accessories");
    strcpy(inventory[0].location, "Shelf 1");
    inventory[0].quantity = 10;
    inventory[0].price = 50.0;

    inventory[1].id = 2;
    strcpy(inventory[1].name, "T-shirt");
    strcpy(inventory[1].category, "Clothing");
    strcpy(inventory[1].location, "Rack 1");
    inventory[1].quantity = 20;
    inventory[1].price = 25.0;

    inventory[2].id = 3;
    strcpy(inventory[2].name, "Laptop");
    strcpy(inventory[2].category, "Electronics");
    strcpy(inventory[2].location, "Counter");
    inventory[2].quantity = 5;
    inventory[2].price = 1000.0;

    inventory[3].id = 4;
    strcpy(inventory[3].name, "Jeans");
    strcpy(inventory[3].category, "Clothing");
    strcpy(inventory[3].location, "Rack 2");
    inventory[3].quantity = 15;
    inventory[3].price = 50.0;
}

// Function to add a product to the inventory
void addProduct(Product *inventory, int *size) {
    Product newProduct;
    int idExists = 0;
    int id;

    // Get input from the user for the new product
    printf("Enter the name of the product: ");
    scanf("%s", newProduct.name);

    printf("Enter the category of the product: ");
    scanf("%s", newProduct.category);

    printf("Enter the storage location of the product: ");
    scanf("%s", newProduct.location);

    printf("Enter the quantity of the product: ");
    scanf("%d", &newProduct.quantity);

    printf("Enter the price of the product: ");
    scanf("%f", &newProduct.price);

    // Generate a unique id for the new product
    do {
        printf("Enter a unique id for the product: ");
        scanf("%d", &id);

        // Check if the id already exists in the inventory
        for (int i = 0; i < *size; i++) {
            if (inventory[i].id == id) {
                printf("Error: id already exists in inventory, please choose a different id.\n");
                idExists = 1;
                break;
            }
        }
    } while (idExists);

    // Assign the generated id to the new product
    newProduct.id = id;

    // Add the new product to the inventory
    inventory[*size] = newProduct;
    (*size)++;

    printf("Product added to inventory successfully!\n");
}

// Function to remove a product from the inventory
void removeProduct(Product *inventory, int *size) {
    int id, index, found = 0;

    // Get input from the user for the product to be removed
    printf("Enter the id of the product to be removed: ");
    scanf("%d", &id);

    // Search for the product in the inventory and get its index
    for (int i = 0; i < *size; i++) {
        if (inventory[i].id == id) {
            index = i;
            found = 1;
            break;
        }
    }

    // If the product is found, remove it from the inventory
    if (found) {
        for (int i = index; i < (*size - 1); i++) {
            inventory[i] = inventory[i + 1];
        }
        (*size)--;
        printf("Product removed from inventory successfully!\n");
    } else {
        printf("Error: product with id %d not found in inventory.\n", id);
    }
}

// Function to display the product inventory
void displayProductInventory(Product *inventory, int size) {
    printf("Product Inventory:\n");
    printf("ID\tName\t\tCategory\tLocation\tQuantity\tPrice\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t\t%s\t\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name,
             inventory[i].category, inventory[i].location, inventory[i].quantity, inventory[i].price);
    }
}

// Function to display the menu of options
void showMenu() {
    printf("\nProduct Inventory System\n");
    printf("------------------------\n");
    printf("1. Add a new product\n");
    printf("2. Remove a product\n");
    printf("3. Display inventory\n");
    printf("4. Quit\n");
}