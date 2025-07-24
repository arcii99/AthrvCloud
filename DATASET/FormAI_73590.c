//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: secure
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to calculate the total bill 
double calculateBill(char [], int);

int main()
{ 
    int n;
    printf("\nEnter the number of customers: ");
    scanf("%d", &n);

    // Arrays to hold the details of each customer
    char name[n][50];
    int quantity[n];
    double bill[n];

    // Get the details of each customer
    for(int i=0; i<n; i++){
        printf("\nEnter the name of customer %d: ", i+1);
        scanf("%s", name[i]);
        printf("Enter the quantity of coffee bought by customer %d: ", i+1);
        scanf("%d", &quantity[i]);
        bill[i] = calculateBill(name[i], quantity[i]);
    }

    // Print the total bill for each customer
    printf("\n\nCafe Billing System\n\n");
    for(int i=0; i<n; i++){
        printf("Customer %d: %s\n", i+1, name[i]);
        printf("Quantity bought: %d\n", quantity[i]);
        printf("Total bill: %.2lf\n\n", bill[i]);
    }

    return 0;
}

// Function to calculate the total bill for a customer
double calculateBill(char name[], int quantity){
    double price = 2.5; // Price of one cup of coffee
    double totalBill = price * quantity;
    char premium[] = "premium";
    char regular[] = "regular";
    if(strcmp(name, premium) == 0){
        totalBill = 0.9 * totalBill; // 10% discount for premium customers
    }
    else if(strcmp(name, regular) == 0){
        totalBill = 0.95 * totalBill; // 5% discount for regular customers
    }
    return totalBill;
}