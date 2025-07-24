//FormAI DATASET v1.0 Category: Product Inventory System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct{
    char name[100];
    float price;
    int quantity;
} Product;

Product inventory[MAX_PRODUCTS];    // an array of Product structs to store the inventory
int num_products = 0;   // keep track of how many products are in the inventory

int add_product(char name[], float price, int quantity){
    // check if we have reached the inventory capacity
    if(num_products >= MAX_PRODUCTS){
        return -1;  // return -1 to indicate that we cannot add more products
    }
    
    // create a new Product with the given parameters
    Product new_product;
    strcpy(new_product.name, name);
    new_product.price = price;
    new_product.quantity = quantity;
    
    // add the new product to the inventory
    inventory[num_products] = new_product;
    num_products++;
    
    return 0;   // return 0 to indicate success
}

int remove_product(char name[]){
    // search for the product with the given name
    int i;
    for(i=0; i<num_products; i++){
        if(strcmp(inventory[i].name, name) == 0){
            // we found the product, now remove it from the inventory
            
            // shift the later elements in the array one position to the left
            int j;
            for(j=i; j<num_products-1; j++){
                inventory[j] = inventory[j+1];
            }
            
            num_products--;
            
            return 0;   // return 0 to indicate success
        }
    }
    
    // we didn't find the product
    return -1;  // return -1 to indicate failure
}

void print_inventory(){
    printf("Current Inventory:\n");
    printf("----------------------------\n");
    printf("%-20s %-10s %-10s\n", "Name", "Price", "Quantity");
    printf("----------------------------\n");
    
    int i;
    for(i=0; i<num_products; i++){
        printf("%-20s %-10.2f %-10d\n", inventory[i].name, inventory[i].price, inventory[i].quantity);
    }
    
    printf("----------------------------\n");
}

int main(){
    // initialize the inventory
    add_product("Apple", 0.5, 10);
    add_product("Banana", 0.3, 20);
    add_product("Orange", 0.4, 15);
    
    // test the functionality
    print_inventory();
    
    add_product("Pear", 0.6, 8);
    print_inventory();
    
    remove_product("Banana");
    print_inventory();
    
    return 0;
}