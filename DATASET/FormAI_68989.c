//FormAI DATASET v1.0 Category: Stock market tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STOCKS 10

struct Stock {
    char name[50];
    double price;
    int quantity;
};

int main() {
    // Declare an array of Stock structs to hold up to MAX_STOCKS
    struct Stock stocks[MAX_STOCKS];
    
    // Declare variables to hold user input
    char input[50];
    int choice;
    int numStocks = 0;
    
    // Initialize the array
    for (int i = 0; i < MAX_STOCKS; i++) {
        strcpy(stocks[i].name, "");
        stocks[i].price = 0.0;
        stocks[i].quantity = 0;
    }
    
    // Main loop
    while (1) {
        // Print choices to the user
        printf("\nOptions: \n");
        printf("1 - Add Stock\n");
        printf("2 - Remove Stock\n");
        printf("3 - View Portfolio\n");
        printf("4 - Exit\n");
        
        // Get user input
        printf("Enter your choice: ");
        fgets(input, 50, stdin);
        choice = atoi(input);
        
        switch(choice) {
            // Add Stock
            case 1:
                // Check if portfolio is full
                if (numStocks < MAX_STOCKS) {
                    printf("\nEnter stock name: ");
                    fgets(input, 50, stdin);
                    input[strcspn(input, "\n")] = 0; // remove newline character
                    
                    // Check if stock already exists
                    int flag = 0;
                    for (int i = 0; i < numStocks; i++) {
                        if (strcmp(stocks[i].name, input) == 0) {
                            printf("Stock already exists in portfolio\n");
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1) break;
                    
                    // Get other stock information
                    printf("Enter stock price: ");
                    fgets(input, 50, stdin);
                    double price = atof(input);
                    
                    printf("Enter quantity of stock: ");
                    fgets(input, 50, stdin);
                    int quantity = atoi(input);
                    
                    // Add stock to portfolio
                    strcpy(stocks[numStocks].name, input);
                    stocks[numStocks].price = price;
                    stocks[numStocks].quantity = quantity;
                    
                    numStocks++;
                    printf("Stock added to portfolio\n");
                    
                }
                else {
                    printf("\nPortfolio is full\n");
                }
                break;
            
            // Remove Stock
            case 2:
                // Check if portfolio is empty
                if (numStocks == 0) {
                    printf("\nPortfolio is empty\n");
                }
                else {
                    printf("\nEnter stock name to remove: ");
                    fgets(input, 50, stdin);
                    input[strcspn(input, "\n")] = 0; // remove newline character
                    
                    // Check if stock exists
                    int flag = 0;
                    for (int i = 0; i < numStocks; i++) {
                        if (strcmp(stocks[i].name, input) == 0) {
                            // Shift remaining elements of array left by one
                            for (int j = i; j < numStocks-1; j++) {
                                strcpy(stocks[j].name, stocks[j+1].name);
                                stocks[j].price = stocks[j+1].price;
                                stocks[j].quantity = stocks[j+1].quantity;
                            }
                            
                            // Set last element to null values
                            strcpy(stocks[numStocks-1].name, "");
                            stocks[numStocks-1].price = 0.0;
                            stocks[numStocks-1].quantity = 0;
                            
                            numStocks--;
                            printf("Stock removed from portfolio\n");
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 0) printf("\nStock not found in portfolio\n");
                }
                break;
            
            // View Portfolio
            case 3:
                // Check if portfolio is empty
                if (numStocks == 0) {
                    printf("\nPortfolio is empty\n");
                }
                else {
                    printf("\nCurrent Portfolio:\n");
                    for (int i = 0; i < numStocks; i++) {
                        printf("- %s\nPrice: $%.2f\nQuantity: %d\n\n", stocks[i].name, stocks[i].price, stocks[i].quantity);
                    }
                }
                break;
            
            // Exit Program
            case 4:
                printf("\nExiting Program...\n");
                exit(0);
            
            // Invalid Choice
            default:
                printf("\nInvalid choice\n");
        }
        
        fflush(stdin); // clear input buffer
    }
    
    return 0;
}