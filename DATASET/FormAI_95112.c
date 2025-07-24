//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char name[20];
    float price;
} Product;

void printProductInfo(Product prod){
    printf("Product ID: %d\n", prod.id);
    printf("Name: %s\n", prod.name);
    printf("Price: %0.2f\n", prod.price);
}

void watermarkProduct(Product *prod, char *watermark){
    int i = 0;
    while (watermark[i] != '\0'){
        prod->name[i] = watermark[i];
        i++;
    }
}

int main(){
    // Create a sample product
    Product prod;
    prod.id = 101;
    sprintf(prod.name, "T-Shirt");
    prod.price = 19.99;
    
    // Print the product info
    printf("Before watermarking:\n");
    printProductInfo(prod);
    
    // Watermark the product with a unique code
    watermarkProduct(&prod, "XYZ-1234");
    
    // Print the product info after watermarking
    printf("After watermarking:\n");
    printProductInfo(prod);
    
    return 0;
}