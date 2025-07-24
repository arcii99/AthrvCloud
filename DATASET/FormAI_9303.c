//FormAI DATASET v1.0 Category: Stock market tracker ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stock{
    char symbol[10];
    float price;
};

int main(){
    struct stock* stocks[10]; //Setting up an array of stock structures
    int choice = 0; //Variable to store user's choice
    int count = 0; //Variable to keep track of number of stocks
    char ch = '\0'; //Variable to flush input buffer
    char input[10]; //Variable to store user input for symbol
    float price; //Variable to store user input for price
    
    while(choice != 4){ //Iterating through the menu until user chooses to exit
        printf("\nPlease select an option:\n");
        printf("1. Add new stock\n");
        printf("2. Display all stocks\n");
        printf("3. Search for a stock\n");
        printf("4. Exit\n");
        printf("Choice: ");
        
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                if(count == 10){ //Checking if the array is full
                    printf("\nERROR: Maximum number of stocks reached!\n");
                    break;
                }
                
                printf("\nEnter stock symbol: ");
                fgets(input, 10, stdin); //Flushing input buffer
                fgets(input, 10, stdin); //Getting user input for symbol
                input[strcspn(input, "\n")] = '\0'; //Removing newline character from input
                
                printf("Enter stock price: ");
                scanf("%f", &price); //Getting user input for price
                
                //Creating a new stock structure and adding it to the array
                stocks[count] = (struct stock*) malloc(sizeof(struct stock));
                strncpy(stocks[count]->symbol, input, sizeof(stocks[count]->symbol));
                stocks[count]->price = price;
                
                printf("\nNew stock added!\n");
                
                count++; //Incrementing the stock count
                
                break;
            case 2:
                if(count == 0){ //Checking if the array is empty
                    printf("\nERROR: No stocks to display!\n");
                    break;
                }
                
                printf("\nStocks in the system:\n");
                
                for(int i = 0; i < count; i++){ //Iterating through the array and printing the contents
                    printf("%s: $%.2f\n", stocks[i]->symbol, stocks[i]->price);
                }
                
                break;
            case 3:
                if(count == 0){ //Checking if the array is empty
                    printf("\nERROR: No stocks to search!\n");
                    break;
                }
                
                printf("\nEnter stock symbol to search for: ");
                fgets(input, 10, stdin); //Flushing input buffer
                fgets(input, 10, stdin); //Getting user input for symbol
                input[strcspn(input, "\n")] = '\0'; //Removing newline character from input
                
                int found = 0; //Variable to keep track of whether the stock was found
                
                for(int i = 0; i < count; i++){ //Iterating through the array and checking if the symbol matches
                    if(strcmp(stocks[i]->symbol, input) == 0){
                        printf("\nStock found!\n");
                        printf("%s: $%.2f\n", stocks[i]->symbol, stocks[i]->price);
                        found = 1; //Setting found to 1
                        break;
                    }
                }
                
                if(found == 0){ //Checking if the stock was not found
                    printf("\nERROR: Stock not found!\n");
                }
                
                break;
            case 4:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nERROR: Invalid choice!\n");
                break;
        }
    }
    
    //Freeing memory allocated for each stock structure
    for(int i = 0; i < count; i++){
        free(stocks[i]);
    }
    
    return 0;
}