//FormAI DATASET v1.0 Category: Database simulation ; Style: lively
#include <stdio.h>
#include <string.h>

// Define a struct for products
typedef struct {
    char name[20];
    int quantity;
    float price;
} Product;

// Define a struct for the database
typedef struct {
    Product products[20];
    int numProducts;
} Database;

// Declare a function to add a product to the database
void addProduct(Database *db, char *name, int quantity, float price) {
    Product p;
    strcpy(p.name, name);
    p.quantity = quantity;
    p.price = price;
    db->products[db->numProducts++] = p;
}

// Declare a function to print the contents of the database
void printDatabase(Database db) {
    printf("Products in database:\n");
    for (int i = 0; i < db.numProducts; i++) {
        printf("%s - %d units at $%.2f each\n", db.products[i].name, db.products[i].quantity, db.products[i].price);
    }
}

int main() {
    // Create an empty database
    Database db = { .numProducts = 0 };

    // Add some products to the database
    addProduct(&db, "Apple", 10, 0.50);
    addProduct(&db, "Banana", 5, 0.25);

    // Print the contents of the database
    printDatabase(db);

    return 0;
}