//FormAI DATASET v1.0 Category: Product Inventory System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for product
struct Product {
    char name[50];
    int id;
    int quantity;
    float price;
};

// Define struct for node of linked list
struct Node {
    struct Product* product;
    struct Node* next;
};

// Function to create new product with given parameters
struct Product* createProduct(char name[], int id, int quantity, float price) {
    struct Product* product = malloc(sizeof(struct Product));
    strcpy(product->name, name);
    product->id = id;
    product->quantity = quantity;
    product->price = price;
    return product;
}

// Function to insert product into linked list
void insertProduct(struct Node** headRef, char name[], int id, int quantity, float price) {
    struct Product* product = createProduct(name, id, quantity, price);
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->product = product;
    newNode->next = NULL;
    if ((*headRef) == NULL) {
        (*headRef) = newNode;
        return;
    }
    struct Node* temp = (*headRef);
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete product from linked list by ID
void deleteProduct(struct Node** headRef, int id) {
    if (*headRef == NULL) {
        printf("Error: product inventory system is empty.\n");
        return;
    }
    if ((*headRef)->product->id == id) {
        struct Node* temp = (*headRef);
        (*headRef) = (*headRef)->next;
        free(temp->product);
        free(temp);
        printf("Product with ID %d has been deleted.\n", id);
        return;
    }
    struct Node* temp1 = (*headRef);
    struct Node* temp2 = (*headRef)->next;
    while(temp2 != NULL) {
        if (temp2->product->id == id) {
            temp1->next = temp2->next;
            free(temp2->product);
            free(temp2);
            printf("Product with ID %d has been deleted.\n", id);
            return;
        }
        temp1 = temp2;
        temp2 = temp2->next;
    }
    printf("Error: product with specified ID not found.\n");
}

// Function to update product quantity
void updateProduct(struct Node** headRef, int id, int quantity) {
    if (*headRef == NULL) {
        printf("Error: product inventory system is empty.\n");
        return;
    }
    struct Node* temp = (*headRef);
    while(temp != NULL) {
        if (temp->product->id == id) {
            temp->product->quantity = quantity;
            printf("Quantity for product with ID %d has been updated to %d.\n", id, quantity);
            return;
        }
        temp = temp->next;
    }
    printf("Error: product with specified ID not found.\n");
}

// Function to display inventory
void displayInventory(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("Product inventory system is empty.\n");
        return;
    }
    printf("%-4s | %-20s | %-10s | %-10s | %-10s\n", "ID", "Name", "Quantity", "Price", "Total");
    printf("--------------------------------------------------------\n");
    struct Node* temp = (*headRef);
    while(temp != NULL) {
        printf("%-4d | %-20s | %-10d | $%-9.2f | $%-9.2f\n", temp->product->id, temp->product->name, temp->product->quantity, temp->product->price, temp->product->price * temp->product->quantity);
        temp = temp->next;
    }
}

int main() {
    // Initialize linked list for inventory
    struct Node* head = NULL;
    // Insert some sample products
    insertProduct(&head, "Product A", 1, 10, 5.99);
    insertProduct(&head, "Product B", 2, 7, 9.99);
    insertProduct(&head, "Product C", 3, 20, 2.49);
    // Display initial inventory
    printf("Initial inventory:\n");
    displayInventory(&head);
    // Delete product and display updated inventory
    deleteProduct(&head, 2);
    printf("Inventory after deleting product:\n");
    displayInventory(&head);
    // Update product quantity and display updated inventory
    updateProduct(&head, 1, 20);
    printf("Inventory after updating product quantity:\n");
    displayInventory(&head);
    // Insert new product and display updated inventory
    insertProduct(&head, "Product D", 4, 15, 7.99);
    printf("Inventory after inserting new product:\n");
    displayInventory(&head);
    // Delete all products and display empty inventory
    deleteProduct(&head, 1);
    deleteProduct(&head, 3);
    deleteProduct(&head, 4);
    printf("Inventory after deleting all products:\n");
    displayInventory(&head);
    // Exit program
    return 0;
}