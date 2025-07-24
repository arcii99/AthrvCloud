//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct product {
    int id;
    char name[50];
    int quantity;
    float price;
};

int main() {
    int i, n, choice;
    float total = 0;
    printf("Surprise! Welcome to the Product Inventory System!\n");
    printf("Enter the number of products you want to enter: ");
    scanf("%d", &n);
    struct product p[n];
    for(i = 0; i < n; i++) {
        printf("Enter product id: ");
        scanf("%d", &p[i].id);
        printf("Enter product name: ");
        scanf("%s", p[i].name);
        printf("Enter product quantity: ");
        scanf("%d", &p[i].quantity);
        printf("Enter product price: ");
        scanf("%f", &p[i].price);
        total += p[i].quantity * p[i].price;
    }
    printf("Information successfully stored!\n");

    while(1) {
        printf("\nWhat would you like to do now?\n");
        printf("1. Display all products\n");
        printf("2. Search for a product\n");
        printf("3. Update product information\n");
        printf("4. Delete a product\n");
        printf("5. Total inventory value\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch(choice) {
            case 1:
                for(i = 0; i < n; i++) {
                    printf("\nProduct ID: %d", p[i].id);
                    printf("\nProduct Name: %s", p[i].name);
                    printf("\nProduct Quantity: %d", p[i].quantity);
                    printf("\nProduct Price: %f\n", p[i].price);
                }
                break;

            case 2:
                int search_id, flag = 0;
                printf("\nEnter the product id you want to search for: ");
                scanf("%d", &search_id);
                for(i = 0; i < n; i++) {
                    if(p[i].id == search_id) {
                        printf("\nProduct ID: %d", p[i].id);
                        printf("\nProduct Name: %s", p[i].name);
                        printf("\nProduct Quantity: %d", p[i].quantity);
                        printf("\nProduct Price: %f\n", p[i].price);
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0) {
                    printf("\nProduct not found.");
                }
                break;

            case 3:
                int update_id, update_choice;
                printf("\nEnter the product id you want to update: ");
                scanf("%d", &update_id);
                for(i = 0; i < n; i++) {
                    if(p[i].id == update_id) {
                        printf("\nWhat information would you like to update for product with id %d?", update_id);
                        do {
                            printf("\n1. Name");
                            printf("\n2. Quantity");
                            printf("\n3. Price");
                            scanf("%d", &update_choice);
                        } while(update_choice < 1 || update_choice > 3);

                        switch(update_choice) {
                            case 1:
                                printf("\nEnter the updated name: ");
                                scanf("%s", p[i].name);
                                break;

                            case 2:
                                printf("\nEnter the updated quantity: ");
                                scanf("%d", &p[i].quantity);
                                break;

                            case 3:
                                printf("\nEnter the updated price: ");
                                scanf("%f", &p[i].price);
                                break;
                        }
                        printf("\nInformation successfully updated!\n");
                        break;
                    }
                }
                if(i == n) {
                    printf("\nProduct not found.");
                }
                break;

            case 4:
                int delete_id;
                printf("\nEnter the product id you want to delete: ");
                scanf("%d", &delete_id);
                for(i = 0; i < n; i++) {
                    if(p[i].id == delete_id) {
                        printf("\nAre you sure you want to delete the following product?");
                        printf("\nProduct ID: %d", p[i].id);
                        printf("\nProduct Name: %s", p[i].name);
                        printf("\nProduct Quantity: %d", p[i].quantity);
                        printf("\nProduct Price: %f\n", p[i].price);
                        printf("\n1. Yes");
                        printf("\n2. No");
                        int delete_choice;
                        scanf("%d", &delete_choice);
                        if(delete_choice == 1) {
                            for(int j = i; j < n-1; j++) {
                                p[j] = p[j+1];
                            }
                            n--;
                            printf("\nProduct successfully deleted!\n");
                        } else {
                            printf("\nProduct deletion cancelled.\n");
                        }
                        break;
                    }
                }
                if(i == n) {
                    printf("\nProduct not found.");
                }
                break;

            case 5:
                printf("\nThe total value of inventory is: %f\n", total);
                break;

            case 6:
                printf("\nThank you for using the Product Inventory System!\n");
                exit(0);

            default:
                printf("\nInvalid choice. Try again.\n");
        }
    }

    return 0;
}