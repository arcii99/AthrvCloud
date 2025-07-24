//FormAI DATASET v1.0 Category: Product Inventory System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

//define the maximum number of products
#define MAX_PRODUCTS 100

//struct for a product
typedef struct product{
    int productID;          //unique product ID
    char productName[20];   //name of product
    int quantity;           //quantity in stock
    float price;            //price of product
} product;

//function to initialize the product array
void initializeProducts(product *array, int size){
    for(int i=0; i<size; i++){
        array[i].productID = i+1;
        sprintf(array[i].productName, "Product %d", i+1);
        array[i].quantity = rand() % 100;
        array[i].price = ((float)rand()/(float)(RAND_MAX)) * 100;
    }
}

//function to display products
void displayProducts(product *array, int size){
    printf("Product ID\tProduct Name\tQuantity\tPrice\n");
    for(int i=0; i<size; i++){
        printf("%d\t\t%s\t\t%d\t\t%.2f\n", array[i].productID, array[i].productName, array[i].quantity, array[i].price);
    }
}

//function to search for a product by ID
int getProductIndex(product *array, int size, int productID){
    for(int i=0; i<size; i++){
        if(array[i].productID == productID){
            return i;
        }
    }
    return -1;
}

//function to update a product quantity by ID
void updateQuantity(product *array, int size, int productID, int newQuantity){
    int index = getProductIndex(array, size, productID);
    if(index != -1){
        array[index].quantity = newQuantity;
        printf("Quantity updated successfully.\n");
    }
    else{
        printf("Product not found.\n");
    }
}

//function to add a new product
void addProduct(product *array, int size, product newProduct){
    int index = getProductIndex(array, size, newProduct.productID);
    if(index == -1 && size < MAX_PRODUCTS){
        array[size] = newProduct;
        printf("Product added successfully.\n");
    }
    else if(size == MAX_PRODUCTS){
        printf("Product inventory is full.\n");
    }
    else{
        printf("Product ID already exists.\n");
    }
}

//main function
int main(){
    //seed random number generator
    srand(1234);
    
    //initialize product array
    product inventory[MAX_PRODUCTS];
    int numProducts = 10;
    initializeProducts(inventory, numProducts);
    
    //display initial inventory
    displayProducts(inventory, numProducts);
    
    //update quantity of product with ID 5
    updateQuantity(inventory, numProducts, 5, 50);
    
    //display updated inventory
    displayProducts(inventory, numProducts);
    
    //add a new product
    product newProduct = {11, "Product 11", 25, 9.99};
    addProduct(inventory, numProducts, newProduct);
    numProducts++;
    
    //display final inventory
    displayProducts(inventory, numProducts);
    
    return 0;
}