//FormAI DATASET v1.0 Category: Product Inventory System ; Style: Romeo and Juliet
/* Romeo and Juliet inspired C Product Inventory System */

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    double price;
} Product;

int main() {
    int choice, i, n, id, q;
    double p;
    char name[50];
    Product products[50];

    printf("Enter the number of products in your inventory: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        products[i].id = i + 1;

        printf("Enter the name of product %d: ", i+1);
        scanf("%s", &products[i].name);

        printf("Enter the quantity of product %d: ", i+1);
        scanf("%d", &products[i].quantity);

        printf("Enter the price of product %d: ", i+1);
        scanf("%lf", &products[i].price);
    }

    while (1) { // loop until user exits
        printf("\n1. Add a new product\n");
        printf("2. Modify a product\n");
        printf("3. Delete a product\n");
        printf("4. Display all products\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the name of the new product: ");
                scanf("%s", &name);

                printf("Enter the quantity of the new product: ");
                scanf("%d", &q);

                printf("Enter the price of the new product: ");
                scanf("%lf", &p);

                products[n].id = n + 1;
                strcpy(products[n].name, name);
                products[n].quantity = q;
                products[n].price = p;
                n++;

                printf("\nThy product hath been added to thy inventory!\n");
                break;

            case 2:
                printf("\nEnter the id of the product to be modified: ");
                scanf("%d", &id);

                for (i = 0; i < n; i++) {
                    if (products[i].id == id) {
                        printf("Product %d:\n", id);
                        printf("Name: %s\n", products[i].name);
                        printf("Quantity: %d\n", products[i].quantity);
                        printf("Price: %0.2f\n", products[i].price);

                        printf("\nEnter the new name of the product: ");
                        scanf("%s", &name);

                        printf("Enter the new quantity of the product: ");
                        scanf("%d", &q);

                        printf("Enter the new price of the product: ");
                        scanf("%lf", &p);

                        strcpy(products[i].name, name);
                        products[i].quantity = q;
                        products[i].price = p;

                        printf("\nThy product hath been updated!\n");
                        break;
                    }
                }

                if (i == n) {
                    printf("\nAlas, the id entered doth not match any of thy products.\n");
                }
                break;

            case 3:
                printf("\nEnter the id of the product to be deleted: ");
                scanf("%d", &id);

                for (i = 0; i < n; i++) {
                    if (products[i].id == id) {
                        products[i] = products[n-1];
                        n--;

                        printf("\nFarewell, thy product hath been deleted!\n");
                        break;
                    }
                }

                if (i == n) {
                    printf("\nAlas, the id entered doth not match any of thy products.\n");
                }
                break;

            case 4:
                printf("\nThy products:\n\n");

                printf("ID\tName\t\tQuantity\tPrice\n");
                printf("--\t----\t\t--------\t-----\n");

                for (i = 0; i < n; i++) {
                    printf("%d\t%s\t\t%d\t\t%0.2f\n", products[i].id, products[i].name,
                    products[i].quantity, products[i].price);
                }

                break;

            case 5:
                printf("\nFarewell, until we meet again!\n");
                exit(0);

            default:
                printf("\nInvalid choice, please try again.\n");
        }
    }

    return 0;
}