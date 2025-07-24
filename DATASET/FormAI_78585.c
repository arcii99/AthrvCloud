//FormAI DATASET v1.0 Category: Stock market tracker ; Style: cheerful
#include <stdio.h>

int main()
{
    printf("Welcome to our cheerful C stock market tracker!\n");
    printf("Enter the number of stocks you want to track: ");
    
    int numStocks;
    scanf("%d", &numStocks);
    
    float stocks[numStocks];
    char stockNames[numStocks][20];
    
    for(int i=0; i<numStocks; i++)
    {
        printf("\nEnter the name of stock %d: ", i+1);
        scanf("%s", &stockNames[i]);
        printf("Enter the current price of %s: ", stockNames[i]);
        scanf("%f", &stocks[i]);
    }
    
    printf("\nLet's start tracking the stock market!\n");
    
    while(1)
    {
        printf("\n\nCURRENT PRICES:\n");
        
        for(int i=0; i<numStocks; i++)
        {
            printf("%s: %.2f\n", stockNames[i], stocks[i]);
        }
        
        printf("\nEnter the number corresponding to the stock you want to update or 0 to exit: ");
        
        int choice;
        scanf("%d", &choice);
        
        if(choice == 0)
        {
            printf("\nThanks for tracking with us. Goodbye!\n");
            break;
        }
        
        printf("Enter the updated price of %s: ", stockNames[choice-1]);
        scanf("%f", &stocks[choice-1]);
    }
    
    return 0;
}