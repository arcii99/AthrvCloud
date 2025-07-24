//FormAI DATASET v1.0 Category: Data mining ; Style: careful
#include <stdio.h>

#define NUM_PRODUCTS 5
#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    int sales[NUM_PRODUCTS];
} Salesperson;

int main() {
    Salesperson salespeople[3]; // Three salespeople
    
    // Initialize salespeople with example data
    sprintf(salespeople[0].name, "Alice");
    salespeople[0].sales[0] = 10;
    salespeople[0].sales[1] = 30;
    salespeople[0].sales[2] = 5;
    salespeople[0].sales[3] = 7;
    salespeople[0].sales[4] = 15;

    sprintf(salespeople[1].name, "Bob");
    salespeople[1].sales[0] = 20;
    salespeople[1].sales[1] = 5;
    salespeople[1].sales[2] = 12;
    salespeople[1].sales[3] = 25;
    salespeople[1].sales[4] = 10;

    sprintf(salespeople[2].name, "Charlie");
    salespeople[2].sales[0] = 5;
    salespeople[2].sales[1] = 15;
    salespeople[2].sales[2] = 10;
    salespeople[2].sales[3] = 8;
    salespeople[2].sales[4] = 20;

    // Calculate total sales for each product
    int total_sales[NUM_PRODUCTS] = {0};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < NUM_PRODUCTS; j++) {
            total_sales[j] += salespeople[i].sales[j];
        }
    }

    // Print total sales for each product
    printf("Total sales:\n");
    for (int i = 0; i < NUM_PRODUCTS; i++) {
        printf("Product %d: %d\n", i+1, total_sales[i]);
    }

    // Calculate average sales for each salesperson
    float average_sales[3];
    for (int i = 0; i < 3; i++) {
        int total = 0;
        for (int j = 0; j < NUM_PRODUCTS; j++) {
            total += salespeople[i].sales[j];
        }
        average_sales[i] = (float) total / NUM_PRODUCTS;
    }

    // Print average sales for each salesperson
    printf("Average sales per salesperson:\n");
    for (int i = 0; i < 3; i++) {
        printf("%s: %.2f\n", salespeople[i].name, average_sales[i]);
    }

    return 0;
}