//FormAI DATASET v1.0 Category: Stock market tracker ; Style: enthusiastic
#include <stdio.h>

// Welcome Message
void welcomeMessage() {
    printf("Welcome to the Super Stock Tracker - C Edition!\n");
    printf("Get ready to track the hottest stocks on the market!\n");
    printf("---------------------------------------------\n\n");
}

void displayStocks() {
    printf("Here are the top stocks of the day:\n");
    printf("----------------------------------\n");
    printf("1. AAPL (Apple Inc.) - $145.86\n");
    printf("2. AMZN (Amazon.com Inc.) - $3,520.71\n");
    printf("3. TSLA (Tesla Inc.) - $677.93\n");
    printf("4. FB (Facebook Inc.) - $341.37\n");
    printf("5. GOOGL (Alphabet Inc.) - $2,460.10\n\n");
}

// Function to get stock information
void getStockInfo() {
    // Variables for stock information
    int stockNumber;
    float price;
    char stockSymbol[5];
    
    // Get stock number
    printf("Enter the stock number:\n");
    scanf("%d", &stockNumber);

    // Get stock information based on user input
    switch(stockNumber) {
        case 1:
            strcpy(stockSymbol, "AAPL");
            price = 145.86;
            break;
        case 2:
            strcpy(stockSymbol, "AMZN");
            price = 3520.71;
            break;
        case 3:
            strcpy(stockSymbol, "TSLA");
            price = 677.93;
            break;
        case 4:
            strcpy(stockSymbol, "FB");
            price = 341.37;
            break;
        case 5:
            strcpy(stockSymbol, "GOOGL");
            price = 2460.10;
            break;
        default:
            printf("Invalid stock number entered\n\n");
            break;
    }

    // Print stock information
    if (stockNumber >= 1 && stockNumber <= 5) {
        printf("\n%s - $%.2f\n\n", stockSymbol, price);
    }
}

int main() {
    // Display welcome message
    welcomeMessage();
    // Display top stocks
    displayStocks();
    // Get stock information based on user input
    getStockInfo();

    return 0;
}