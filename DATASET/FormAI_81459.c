//FormAI DATASET v1.0 Category: Product Inventory System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_QTY_LENGTH 20
#define MAX_PRICE_LENGTH 20

struct PRODUCT {
    char name[MAX_NAME_LENGTH];
    char qty[MAX_QTY_LENGTH];
    char price[MAX_PRICE_LENGTH];
};

struct INVENTORY {
    struct PRODUCT product;
    int count;
    struct INVENTORY *next;
};

void add_product(struct INVENTORY **head, struct PRODUCT p) {
    struct INVENTORY *new_product = malloc(sizeof(struct INVENTORY));
    new_product->product = p;
    new_product->count = 1;
    new_product->next = NULL;

    if (*head == NULL) {
        *head = new_product;
    } else {
        struct INVENTORY *current = *head;
        while (current != NULL) {
            if (strcmp(current->product.name, p.name) == 0) {
                current->count++;
                free(new_product);
                return;
            }
            current = current->next;
        }
        new_product->next = *head;
        *head = new_product;
    }
}

void remove_product(struct INVENTORY **head, struct PRODUCT p) {
    if (*head == NULL) {
        return;
    }

    struct INVENTORY *current = *head;
    struct INVENTORY *prev = NULL;

    while (current != NULL) {
        if (strcmp(current->product.name, p.name) == 0) {
            if (current->count == 1) {
                if (prev == NULL) {
                    *head = current->next;
                } else {
                    prev->next = current->next;
                }
                free(current);
            } else {
                current->count--;
            }
            return;
        }
        prev = current;
        current = current->next;
    }
}

void list_inventory(struct INVENTORY *head) {
    if (head == NULL) {
        return;
    }

    int total_qty = 0;
    int total_value = 0;

    printf("|%-30s|%-15s|%-15s|%-10s|\n", "Product", "Quantity", "Price", "Value");
    printf("|------------------------------|---------------|---------------|----------|\n");

    struct INVENTORY *current = head;
    while (current != NULL) {
        printf("|%-30s|%-15d|%-15s|%-10d|\n", current->product.name, current->count, current->product.price, current->count * atoi(current->product.price));
        total_qty += current->count;
        total_value += current->count * atoi(current->product.price);
        current = current->next;
    }

    printf("|------------------------------|---------------|---------------|----------|\n");
    printf("|%-30s|%-15d|%15s|%10d|\n", "Total", total_qty, "", total_value);
}

int main(void) {
    struct INVENTORY *inventory = NULL;
    struct PRODUCT new_product;

    char input[MAX_NAME_LENGTH + MAX_QTY_LENGTH + MAX_PRICE_LENGTH + 2];

    while (1) {

        printf("Paranoid Product Inventory System:\n");
        printf("1. Add Product\n");
        printf("2. Remove Product\n");
        printf("3. View Inventory\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error: invalid input\n");
            continue;
        }

        switch (atoi(input)) {
            case 1:
                printf("Enter product name: ");
                if (fgets(new_product.name, sizeof(new_product.name), stdin) == NULL) {
                    printf("Error: invalid input\n");
                    continue;
                }
                new_product.name[strcspn(new_product.name, "\n")] = '\0';

                printf("Enter product quantity: ");
                if (fgets(new_product.qty, sizeof(new_product.qty), stdin) == NULL) {
                    printf("Error: invalid input\n");
                    continue;
                }
                new_product.qty[strcspn(new_product.qty, "\n")] = '\0';

                printf("Enter product price: ");
                if (fgets(new_product.price, sizeof(new_product.price), stdin) == NULL) {
                    printf("Error: invalid input\n");
                    continue;
                }
                new_product.price[strcspn(new_product.price, "\n")] = '\0';

                add_product(&inventory, new_product);
                printf("Product added to inventory.\n");
                break;
            case 2:
                printf("Enter product name: ");
                if (fgets(new_product.name, sizeof(new_product.name), stdin) == NULL) {
                    printf("Error: invalid input\n");
                    continue;
                }
                new_product.name[strcspn(new_product.name, "\n")] = '\0';

                remove_product(&inventory, new_product);
                printf("Product removed from inventory.\n");
                break;
            case 3:
                list_inventory(inventory);
                break;
            case 4:
                return 0;
            default:
                printf("Error: invalid input\n");
        }
    }

    return 0;
}