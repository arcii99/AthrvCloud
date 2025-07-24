//FormAI DATASET v1.0 Category: Product Inventory System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct product {
    char name[30];
    int quantity;
    float price;
};

int main() {
    struct product inventory[100];
    int numProducts = 0;

    srand(time(NULL));

    inventory[numProducts].quantity = rand() % 100 + 10;
    strcpy(inventory[numProducts].name, "Rainbow Flavored Socks");
    inventory[numProducts].price = 14.99;
    numProducts++;

    inventory[numProducts].quantity = rand() % 100 + 10;
    strcpy(inventory[numProducts].name, "Glow-in-the-Dark Ties");
    inventory[numProducts].price = 9.99;
    numProducts++;

    inventory[numProducts].quantity = rand() % 100 + 10;
    strcpy(inventory[numProducts].name, "Unicorn Horn Headbands");
    inventory[numProducts].price = 19.99;
    numProducts++;

    printf("Welcome to the Surreal Product Inventory System!\n");

    char choice = ' ';
    int productIndex = 0;
    while (choice != 'q') {
        printf("What would you like to do?\n");
        printf("(v)iew products | (a)dd product | (r)emove product | (q)uit\n");
        scanf(" %c", &choice);

        switch(choice) {
            case 'v': {
                printf("We have the following products:\n");
                for (int i = 0; i < numProducts; i++) {
                    printf("%d. %s, Quantity: %d, Price: $%.2f\n", i+1, inventory[i].name, inventory[i].quantity, inventory[i].price);
                }
                break;
            }
            case 'a': {
                printf("What product do you want to add?\n");
                char newProduct[30];
                scanf(" %[^\n]s", newProduct);
                strcpy(inventory[numProducts].name, newProduct);

                printf("How many %s are there?\n", newProduct);
                scanf(" %d", &inventory[numProducts].quantity);

                printf("What is the price of %s?\n", newProduct);
                scanf(" %f", &inventory[numProducts].price);

                numProducts++;
                printf("%s has been added!\n", newProduct);
                break;
            }
            case 'r': {
                printf("What product do you want to remove?\n");
                for (int i = 0; i < numProducts; i++) {
                    printf("%d. %s\n", i+1, inventory[i].name);
                }
                scanf(" %d", &productIndex);

                    printf("%s has been removed from the inventory!\n", inventory[productIndex-1].name);
                    for (int i = productIndex-1; i < numProducts-1; i++) {
                        strcpy(inventory[i].name, inventory[i+1].name);
                        inventory[i].quantity = inventory[i+1].quantity;
                        inventory[i].price = inventory[i+1].price;
                    }
                    numProducts--;

                break;
            }
            case 'q': {
                printf("Thank you for using the Surreal Product Inventory System!\n");
                break;
            }
            default: {
                printf("Sorry, that is not a valid choice. Try again.\n");
                break;
            }
        }
    }

    return 0;
}