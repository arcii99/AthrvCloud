//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_CUSTOMERS 50

//Struct defined for every product in warehouse
typedef struct {
    int id;
    char name[20];
    int quantity;
    float price;
} Product;

//Struct defined for every customer
typedef struct {
    int id;
    char name[20];
    Product products[MAX_PRODUCTS];
    int orderCount;
    float totalCost;
} Customer;

Product warehouse[MAX_PRODUCTS]; //Array of products
Customer customers[MAX_CUSTOMERS]; //Array of customers

int productCount = 0; //Number of products in warehouse
int customerCount = 0; //Number of customers registered

//Function to add a product to the warehouse
void addProduct() {
    if(productCount < MAX_PRODUCTS) {
        Product newProduct;
        
        printf("\nEnter product ID: ");
        scanf("%d", &newProduct.id);
        
        printf("Enter product name: ");
        scanf("%s", newProduct.name);
        
        printf("Enter product quantity: ");
        scanf("%d", &newProduct.quantity);
        
        printf("Enter product price: ");
        scanf("%f", &newProduct.price);
        
        warehouse[productCount++] = newProduct;
        printf("Product added successfully!\n");
    }
    else {
        printf("Warehouse is full. Cannot add new product.\n");
    }
}

//Function to display the products in the warehouse
void displayProducts() {
    printf("\nProducts in warehouse:\n");
    printf("ID\tName\tQuantity\tPrice\n");
    
    for(int i=0; i<productCount; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity, warehouse[i].price);
    }
}

//Function to search for a product in the warehouse using ID
int findProductByID(int id) {
    for(int i=0; i<productCount; i++) {
        if(warehouse[i].id == id) {
            return i;
        }
    }
    
    return -1; //If product with given ID is not found
}

//Function to register a new customer
void registerCustomer() {
    if(customerCount < MAX_CUSTOMERS) {
        Customer newCustomer;
        
        printf("\nEnter customer ID: ");
        scanf("%d", &newCustomer.id);
        
        printf("Enter customer name: ");
        scanf("%s", newCustomer.name);
        
        newCustomer.orderCount = 0;
        newCustomer.totalCost = 0;
        
        customers[customerCount++] = newCustomer;
        printf("Customer registered successfully!\n");
    }
    else {
        printf("Customer limit exceeded. Cannot register new customer.\n");
    }
}

//Function to search for a customer by ID
int findCustomerByID(int id) {
    for(int i=0; i<customerCount; i++) {
        if(customers[i].id == id) {
            return i;
        }
    }
    
    return -1; //If customer with given ID is not found
}

//Function to place an order for a customer
void placeOrder() {
    int custID, prodID, quantity;
    
    printf("\nEnter customer ID: ");
    scanf("%d", &custID);
    
    int custIndex = findCustomerByID(custID);
    if(custIndex == -1) {
        printf("Customer with given ID not found.\n");
        return;
    }
    
    printf("\nEnter product ID: ");
    scanf("%d", &prodID);
    
    int prodIndex = findProductByID(prodID);
    if(prodIndex == -1) {
        printf("Product with given ID not found.\n");
        return;
    }
    
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    
    if(quantity > warehouse[prodIndex].quantity) {
        printf("Sorry, we do not have enough stock.\n");
        return;
    }
    
    //Updating customer's order and total cost
    customers[custIndex].products[customers[custIndex].orderCount++] = warehouse[prodIndex];
    customers[custIndex].totalCost += quantity * warehouse[prodIndex].price;
    
    //Updating warehouse stock
    warehouse[prodIndex].quantity -= quantity;
    
    printf("Order placed successfully!\n");
}

//Function to display the details of a particular customer
void displayCustomer(int id) {
    int index = findCustomerByID(id);
    if(index == -1) {
        printf("Customer not found.\n");
    }
    else {
        printf("\nCustomer details:\n");
        printf("ID: %d\n", customers[index].id);
        printf("Name: %s\n", customers[index].name);
        printf("Orders: %d\n", customers[index].orderCount);
        printf("Total cost: %.2f\n", customers[index].totalCost);
        printf("Products bought:\n");
        printf("ID\tName\tQuantity\tPrice\n");
         
        for(int i=0; i<customers[index].orderCount; i++) {
             printf("%d\t%s\t%d\t\t%.2f\n", customers[index].products[i].id, customers[index].products[i].name, 1, customers[index].products[i].price);
        }
    }
}

int main() {
    printf("\nWarehouse Management System\n");
    printf("---------------------------\n");
    
    int choice;
    
    do {
        printf("\n1. Add product\n");
        printf("2. Display products\n");
        printf("3. Register customer\n");
        printf("4. Place order\n");
        printf("5. Display customer details\n");
        printf("6. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                registerCustomer();
                break;
            case 4:
                placeOrder();
                break;
            case 5:
                int id;
                printf("\nEnter customer ID: ");
                scanf("%d", &id);
                displayCustomer(id);
                break;
            case 6:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Try again.\n");
                break;
        }
    } while(choice != 6);
    
    return 0;
}