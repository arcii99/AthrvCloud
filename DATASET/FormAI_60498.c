//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20
#define MAX_PRODUCT_NUMBER 100

typedef struct Product{
    char name[MAX_NAME_LENGTH];
    int quantity;
}Product;

Product warehouse[MAX_PRODUCT_NUMBER];
int numProducts = 0;

void addProduct(char* name, int quantity){
    if(numProducts >= MAX_PRODUCT_NUMBER){
        printf("Warehouse is full, cannot add more products.\n");
        return;
    }
    Product newProduct;
    strcpy(newProduct.name, name);
    newProduct.quantity = quantity;
    warehouse[numProducts++] = newProduct;
    printf("New product %s added successfully.\n", name);
}

void removeProduct(char* name){
    int indexToRemove = -1;
    for(int i = 0; i < numProducts; i++){
        if(strcmp(warehouse[i].name, name) == 0){
            indexToRemove = i;
            break;
        }
    }
    if(indexToRemove == -1){
        printf("Product %s not found in warehouse.\n", name);
        return;
    }
    for(int i = indexToRemove; i < numProducts - 1; i++){
        warehouse[i] = warehouse[i+1];
    }
    numProducts--;
    printf("Product %s removed successfully.\n", name);
}

void displayWarehouse(){
    printf("Warehouse:\n");
    printf("%-20s   %-10s\n", "PRODUCT NAME", "QUANTITY");
    for(int i = 0; i < numProducts; i++){
        printf("%-20s   %-10d\n", warehouse[i].name, warehouse[i].quantity);
    }
}

int main(){
    addProduct("Chair", 12);
    addProduct("Table", 6);
    addProduct("Lamp", 20);
    displayWarehouse();
    removeProduct("Chair");
    displayWarehouse();
    addProduct("Desk", 8);
    addProduct("Chair", 4);
    displayWarehouse();
    return 0;
}