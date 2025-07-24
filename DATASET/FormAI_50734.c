//FormAI DATASET v1.0 Category: Stock market tracker ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define the maximum number of stocks to be tracked
#define MAX_STOCKS 10

// Define a struct to hold stock name and price
typedef struct {
    char name[20];
    float price;
} Stock;

// Define a function to print current prices of all stocks
void printStockPrices(Stock stocks[], int numStocks) {
    printf("\nStock Prices:\n");
    for (int i=0; i<numStocks; i++) {
        printf("%s: $%.2f\n", stocks[i].name, stocks[i].price);
    }
}

int main() {
    // Declare variables
    Stock stocks[MAX_STOCKS];
    int numStocks = 0;
    char input[20];
    float priceInput;
    
    // Infinite loop until user exits
    while (1) {
        // Print menu options
        printf("\nWhat would you like to do?\n");
        printf("1. Add a stock\n");
        printf("2. Update a stock price\n");
        printf("3. Print current stock prices\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        // Get user input
        fgets(input, sizeof(input), stdin);
        int choice = atoi(input);
        
        switch (choice) {
            case 1:
                // Add a new stock
                if (numStocks == MAX_STOCKS) {
                    printf("Error: Maximum number of stocks reached.\n");
                    break;
                }
                
                printf("Enter the name of the stock: ");
                fgets(stocks[numStocks].name, sizeof(stocks[numStocks].name), stdin);
                stocks[numStocks].name[strcspn(stocks[numStocks].name, "\n")] = 0;
                
                printf("Enter the price of the stock: $");
                fgets(input, sizeof(input), stdin);
                priceInput = atof(input);
                stocks[numStocks].price = priceInput;
                
                printf("Stock added successfully.\n");
                numStocks++;
                break;
            
            case 2:
                // Update a stock price
                if (numStocks == 0) {
                    printf("Error: No stocks added yet.\n");
                    break;
                }
                
                printf("Enter the name of the stock you want to update: ");
                fgets(input, sizeof(input), stdin);
                input[strcspn(input, "\n")] = 0;
                
                int found = 0;
                for (int i=0; i<numStocks; i++) {
                    if (strcmp(input, stocks[i].name) == 0) {
                        printf("Enter the new price of the stock: $");
                        fgets(input, sizeof(input), stdin);
                        priceInput = atof(input);
                        stocks[i].price = priceInput;
                        printf("Stock price updated successfully.\n");
                        found = 1;
                        break;
                    }
                }
                
                if (!found) {
                    printf("Error: Stock not found.\n");
                }
                break;
                
            case 3:
                // Print current stock prices
                if (numStocks == 0) {
                    printf("No stocks added yet.\n");
                    break;
                }
                
                printStockPrices(stocks, numStocks);
                break;
                
            case 4:
                // Exit program
                printf("Goodbye!\n");
                exit(0);
                
            default:
                printf("Error: Invalid choice.\n");
                break;
        }
    }
    
    return 0;
}