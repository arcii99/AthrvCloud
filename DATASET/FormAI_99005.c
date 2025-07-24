//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define a structure for a customer's order
struct order {
    char item[20];
    float price;
};

// define a function to calculate the total bill of the customer
float calc_bill(struct order o[], int n) {
    float total = 0.0;
    for(int i=0; i<n; i++) {
        total += o[i].price;
    }
    return total;
}

int main() {
    int n; // number of items in the order
    printf("Enter the number of items in the order: ");
    scanf("%d", &n);
    
    struct order *o = (struct order*) malloc(n * sizeof(struct order)); // allocate memory for the order
    
    // get input for each item in the order
    for(int i=0; i<n; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", o[i].item);
        printf("Enter the price of item %d: ", i+1);
        scanf("%f", &o[i].price);
    }
    
    // print the order
    printf("\nOrder Summary:\n");
    for(int i=0; i<n; i++) {
        printf("%s %.2f\n", o[i].item, o[i].price);
    }
    
    // calculate the total bill
    float total = calc_bill(o, n);
    printf("\nTotal Bill: %.2f\n", total);
    
    free(o); // free the memory
    
    return 0;
}