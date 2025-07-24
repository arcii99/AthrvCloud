//FormAI DATASET v1.0 Category: Data mining ; Style: energetic
#include <stdio.h>

// Defining the structure of data for the mining
struct data {
    int id;
    char name[50];
    float price;
};

// Defining a function to sort the data by price
void sort_by_price(struct data d[], int size) {
    // Sorting the data using bubble sort algorithm
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(d[j].price > d[j+1].price) {
                // Swapping the data
                struct data temp = d[j];
                d[j] = d[j+1];
                d[j+1] = temp;
            }
        }
    }
}

// Defining a function to print the data
void print_data(struct data d[], int size) {
    printf("ID\tName\t\tPrice\n");
    for(int i=0; i<size; i++) {
        printf("%d\t%s\t\t%f\n", d[i].id, d[i].name, d[i].price);
    }
}

int main() {
    // Initializing the data to be mined
    struct data products[] = {
        {101, "Product A", 50.0},
        {102, "Product B", 25.0},
        {103, "Product C", 100.0},
        {104, "Product D", 75.0},
        {105, "Product E", 10.0}
    };

    // Getting the size of data
    int size = sizeof(products)/sizeof(products[0]);

    // Sorting the data by price
    sort_by_price(products, size);

    // Printing the sorted data
    printf("Data sorted by price:\n");
    print_data(products, size);

    return 0;
}