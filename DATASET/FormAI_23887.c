//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define product details struct
typedef struct ProductDetails {
    char name[50];
    float price;
    int quantity;
} ProductDetails;

// define node struct for inventory linked list
typedef struct Node {
    ProductDetails details;
    struct Node *next;
} Node;

Node *inventory = NULL;  // initialize inventory linked list

// function to insert new product into inventory
void insert(ProductDetails newProduct) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->details = newProduct;
    newNode->next = inventory;
    inventory = newNode;
}

// function to search for product in inventory by name
Node * search(char *name) {
    Node *current = inventory;
    while(current != NULL) {
        if(strcmp(current->details.name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// function to display entire inventory
void displayInventory() {
    Node *current = inventory;
    printf("Product Name\tPrice\tQuantity\n");
    printf("-----------------------------------\n");
    while(current != NULL) {
        printf("%s\t$%.2f\t%d\n", current->details.name, current->details.price,
            current->details.quantity);
        current = current->next;
    }
}

int main() {
    // initial inventory
    ProductDetails p1, p2, p3;
    strcpy(p1.name, "iPhone");
    p1.price = 999.99;
    p1.quantity = 15;
    strcpy(p2.name, "Samsung Galaxy");
    p2.price = 899.99;
    p2.quantity = 10;
    strcpy(p3.name, "Google Pixel");
    p3.price = 799.99;
    p3.quantity = 5;

    // add initial inventory to linked list
    insert(p1);
    insert(p2);
    insert(p3);

    int choice;
    while(1) {  // infinite loop until user chooses to exit
        printf("\n\nWelcome to the Product Inventory System!\n");
        printf("1. Add New Product\n");
        printf("2. Search for Product\n");
        printf("3. Display Entire Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                ProductDetails newProduct;
                printf("\nEnter Product Name: ");
                scanf("%s", newProduct.name);
                printf("Enter Product Price: ");
                scanf("%f", &newProduct.price);
                printf("Enter Product Quantity: ");
                scanf("%d", &newProduct.quantity);
                insert(newProduct);
                printf("\nNew product added successfully!");
                break;
            }
            case 2: {
                char productName[50];
                printf("\nEnter Product Name: ");
                scanf("%s", productName);
                Node *productNode = search(productName);
                if(productNode == NULL) {
                    printf("\nProduct not found!");
                } else {
                    printf("\nProduct Details:\n");
                    printf("Product Name: %s\n", productNode->details.name);
                    printf("Product Price: $%.2f\n", productNode->details.price);
                    printf("Product Quantity: %d\n", productNode->details.quantity);
                }
                break;
            }
            case 3: {
                displayInventory();
                break;
            }
            case 4: {
                printf("\nExiting Program. Goodbye!\n");
                exit(0);
            }
            default: {
                printf("\nInvalid choice. Please try again.");
            }
        }
    }

    return 0;
}