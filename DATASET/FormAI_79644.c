//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define the maximum number of products and warehouses 
#define MAX_PRODUCTS 1000
#define MAX_WAREHOUSES 5

// define a product struct
typedef struct{
    int id; 
    char name[50];
    double price;
    int quantity;
} Product;

// define a warehouse struct 
typedef struct{
    int id;
    char name[50];
    Product products[MAX_PRODUCTS];
    int num_of_products;
} Warehouse;

// function to print the product details 
void print_product(Product p){
    printf("Product ID: %d\n",p.id);
    printf("Product Name: %s\n",p.name);
    printf("Product Price: %.2lf\n",p.price);
    printf("Product Quantity: %d\n\n",p.quantity);
}

// function to add a product to a warehouse
void add_product(Warehouse *w, Product p){
    w->products[w->num_of_products] = p;
    w->num_of_products++;
}

int main(){

    // create an array of 5 warehouses 
    Warehouse warehouses[MAX_WAREHOUSES];

    // initialize the warehouses
    for(int i=0;i<MAX_WAREHOUSES;i++){
        warehouses[i].id = i+1;
        sprintf(warehouses[i].name,"Warehouse %d",i+1);
        warehouses[i].num_of_products = 0;
    }

    // create some products 
    Product p1 = {1,"Product 1",10.25,100};
    Product p2 = {2,"Product 2",15.50,50};
    Product p3 = {3,"Product 3",5.75,75};
    Product p4 = {4,"Product 4",7.80,120};

    // add the products to the warehouses 
    add_product(&warehouses[0],p1);
    add_product(&warehouses[0],p2);
    add_product(&warehouses[1],p3);
    add_product(&warehouses[1],p4);
    add_product(&warehouses[2],p1);
    add_product(&warehouses[3],p2);
    add_product(&warehouses[4],p3);

    // print the details of the products in each warehouse 
    for(int i=0;i<MAX_WAREHOUSES;i++){
        printf("Warehouse ID: %d\n",warehouses[i].id);
        printf("Warehouse Name: %s\n",warehouses[i].name);
        printf("Number of Products: %d\n",warehouses[i].num_of_products);
        printf("Products List:\n");
        for(int j=0;j<warehouses[i].num_of_products;j++){
            print_product(warehouses[i].products[j]);
        }
    }

    // exit the program
    return 0;
}