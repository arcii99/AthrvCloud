//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000

struct Product {
    char *name;
    int quantity;
};

void addProduct(struct Product products[], char *name, int quantity, int *numItems) {
    if (*numItems >= MAX_ITEMS) {
        printf("Warehouse is full\n");
        return;
    }

    struct Product product;
    product.name = malloc(sizeof(char) * (strlen(name) + 1));
    strcpy(product.name, name);
    product.quantity = quantity;

    products[*numItems] = product;
    (*numItems)++;

    printf("%s added to warehouse\n", name);
}

void removeProduct(struct Product products[], char *name, int quantity, int *numItems) {
    for (int i = 0; i < *numItems; i++) {
        if (strcmp(products[i].name, name) == 0) {
            if (quantity > products[i].quantity) {
                printf("Not enough %s in warehouse\n", name);
                return;
            }

            products[i].quantity -= quantity;
            printf("%d %s removed from warehouse\n", quantity, name);

            if (products[i].quantity == 0) {
                free(products[i].name);
                for (int j = i; j < *numItems - 1; j++) {
                    products[j] = products[j + 1];
                }
                (*numItems)--;
            }

            return;
        }
    }

    printf("%s not found in warehouse\n", name);
}

void listProducts(struct Product products[], int numItems) {
    if (numItems == 0) {
        printf("Warehouse is empty\n");
        return;
    }
    
    printf("Warehouse contents:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%d - %s (%d)\n", i + 1, products[i].name, products[i].quantity);
    }
}

int main() {
    printf("Welcome to Warehouse Management System\n");

    struct Product products[MAX_ITEMS];
    int numItems = 0;

    char command[100];
    char name[100];
    int quantity;

    while (1) {
        printf("> ");
        fgets(command, 100, stdin);

        if (strlen(command) <= 1) {
            continue;
        }

        char *token = strtok(command, " \n");

        if (strcmp(token, "add") == 0) {
            token = strtok(NULL, " \n");
            strcpy(name, token);
            token = strtok(NULL, " \n");
            quantity = atoi(token);

            addProduct(products, name, quantity, &numItems);
        }
        else if (strcmp(token, "remove") == 0) {
            token = strtok(NULL, " \n");
            strcpy(name, token);
            token = strtok(NULL, " \n");
            quantity = atoi(token);

            removeProduct(products, name, quantity, &numItems);
        }
        else if (strcmp(token, "list") == 0) {
            listProducts(products, numItems);
        }
        else if (strcmp(token, "exit") == 0) {
            break;
        }
        else {
            printf("Invalid command\n");
        }
    }

    for (int i = 0; i < numItems; i++) {
        free(products[i].name);
    }

    printf("Goodbye\n");
    return 0;
}