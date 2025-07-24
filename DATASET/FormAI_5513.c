//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    int id;
    char name[50];
    float price;
    int quantity;
} Product;

void readCsvFile(FILE *file, Product *products, int *numProducts) {
    char buffer[MAX_LINE_SIZE];

    // Read header line
    fgets(buffer, MAX_LINE_SIZE, file);

    // Read remaining lines
    while (fgets(buffer, MAX_LINE_SIZE, file)) {
        // Parse line
        char *token = strtok(buffer, ",");
        products[*numProducts].id = atoi(token);

        token = strtok(NULL, ",");
        strcpy(products[*numProducts].name, token);

        token = strtok(NULL, ",");
        products[*numProducts].price = atof(token);

        token = strtok(NULL, ",");
        products[*numProducts].quantity = atoi(token);

        // Update numProducts
        (*numProducts)++;
    }
}

int main() {
    FILE *file = fopen("products.csv", "r");

    if (!file) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    int numProducts = 0;
    Product products[100];

    readCsvFile(file, products, &numProducts);

    fclose(file);

    // Print products
    printf("ID\tName\t\tPrice\tQuantity\n");
    for (int i = 0; i < numProducts; i++) {
        printf("%d\t%20s\t%.2f\t%d\n",
               products[i].id, products[i].name,
               products[i].price, products[i].quantity);
    }

    return 0;
}