//FormAI DATASET v1.0 Category: Product Inventory System ; Style: imaginative
#include<stdio.h>
#include<string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

int main(){
    int n;
    printf("Enter the number of products: ");
    scanf("%d", &n);
    struct product products[n];
    int i, j, choice;
    char search[50];
    
    // Adding products to inventory
    for(i=0; i<n; i++){
        printf("\nEnter Product %d Details: \n", i+1);
        printf("Enter Product Name: ");
        scanf("%s", products[i].name);
        printf("Enter Product Quantity: ");
        scanf("%d", &products[i].quantity);
        printf("Enter Product Price: ");
        scanf("%f", &products[i].price);
    }
    
    // Displaying inventory
    printf("\n\t\tInventory List\n");
    printf("-------------------------------------------------------------\n");
    printf("|     Name     |    Quantity    |     Price     |    Value    |\n");
    printf("-------------------------------------------------------------\n");
    float total_value = 0;
    for(i=0; i<n; i++){
        printf("| %-12s| %10d   | %13.2f | %11.2f |\n", products[i].name, products[i].quantity, products[i].price, products[i].quantity * products[i].price);
        total_value += products[i].quantity * products[i].price;
    }
    printf("-------------------------------------------------------------\n");
    printf("Total Value of Inventory = %.2f\n", total_value);
    
    // Searching for a product by name
    printf("\nDo you want to search a product by name? 1 for Yes, 2 for No: ");
    scanf("%d", &choice);
    if(choice == 1){
        printf("Enter the name of the product to search: ");
        scanf("%s", search);
        for(i=0; i<n; i++){
            if(strcmp(products[i].name, search) == 0){
                printf("\nProduct Found in Inventory:\n");
                printf("Name: %s\n", products[i].name);
                printf("Quantity: %d\n", products[i].quantity);
                printf("Price: %.2f\n\n", products[i].price);
                break;
            }
        }
        if(i == n){
            printf("Product not found in inventory.\n");
        }
    }

    // Updating quantity of a product
    printf("\nDo you want to update quantity of a product? 1 for Yes, 2 for No: ");
    scanf("%d", &choice);
    if(choice == 1){
        printf("\nEnter the name of the product to update quantity: ");
        scanf("%s", search);
        for(i=0; i<n; i++){
            if(strcmp(products[i].name, search) == 0){
                printf("\nEnter the new quantity: ");
                scanf("%d", &products[i].quantity);
                printf("\nQuantity of product %s updated to %d\n", products[i].name, products[i].quantity);
                break;
            }
        }
        if(i == n){
            printf("Product not found in inventory.\n");
        }
    }
    
    // Deleting a product from inventory
    printf("\nDo you want to delete a product from inventory? 1 for Yes, 2 for No: ");
    scanf("%d", &choice);
    if(choice == 1){
        printf("\nEnter the name of the product to delete: ");
        scanf("%s", search);
        for(i=0; i<n; i++){
            if(strcmp(products[i].name, search) == 0){
                for(j=i+1; j<n; j++){
                    strcpy(products[j-1].name, products[j].name);
                    products[j-1].quantity = products[j].quantity;
                    products[j-1].price = products[j].price;
                }
                n--;
                printf("\nProduct %s deleted from inventory.\n", search);
                break;
            }
        }
        if(i == n){
            printf("Product not found in inventory.\n");
        }
    }
    
    // Displaying final inventory
    printf("\n\t\tFinal Inventory List\n");
    printf("-------------------------------------------------------------\n");
    printf("|     Name     |    Quantity    |     Price     |    Value    |\n");
    printf("-------------------------------------------------------------\n");
    total_value = 0;
    for(i=0; i<n; i++){
        printf("| %-12s| %10d   | %13.2f | %11.2f |\n", products[i].name, products[i].quantity, products[i].price, products[i].quantity * products[i].price);
        total_value += products[i].quantity * products[i].price;
    }
    printf("-------------------------------------------------------------\n");
    printf("Total Value of Inventory = %.2f\n", total_value);
    
    return 0;
}