//FormAI DATASET v1.0 Category: Digital Auction System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 10
#define MAX_ITEMS 10

// User structure
struct User{
    char name[20];
    int balance;
};

// Item structure
struct Item{
    char name[20];
    int price;
    struct User *highestBidder;
};

// Initialize users
struct User users[MAX_USERS] = {
    {"Alice", 1000},
    {"Bob", 500},
    {"Charlie", 750},
    {"David", 300},
    {"Eve", 200},
    {"Frank", 100},
    {"Grace", 150},
    {"Heidi", 50},
    {"Ivan", 25},
    {"John", 10}
};

// Initialize items
struct Item items[MAX_ITEMS] = {
    {"Item 1", 100, NULL},
    {"Item 2", 200, NULL},
    {"Item 3", 300, NULL},
    {"Item 4", 400, NULL},
    {"Item 5", 500, NULL},
    {"Item 6", 600, NULL},
    {"Item 7", 700, NULL},
    {"Item 8", 800, NULL},
    {"Item 9", 900, NULL},
    {"Item 10", 1000, NULL},
};

// Main function
int main(){
    int i,j; // Loop variables
    int bidAmount; // Variable to store user bid amount
    int userIndex; // Index of user who made the bid
    
    printf("Digital Auction System\n");
    
    while(1){ // Infinite loop, exits only on user request
        printf("\n\n");
        printf("Users:\n");
        printf("-------\n");
        
        // Print all users
        for(i=0; i<MAX_USERS; i++){
            printf("%d. %s ($%d)\n", i+1, users[i].name, users[i].balance);
        }
        
        printf("\n");
        
        printf("Items for sale:\n");
        printf("---------------\n");
        
        // Print all items and their bids
        for(i=0; i<MAX_ITEMS; i++){
            if(items[i].highestBidder == NULL){
                printf("%d. %s ($%d)\n", i+1, items[i].name, items[i].price);
            }
            else{
                printf("%d. %s ($%d) [Highest bid by %s]\n", i+1, items[i].name, items[i].price, items[i].highestBidder->name);
            }
        }
        
        printf("\n");
        
        // Prompt user to enter their name
        printf("Enter your name (or type 'exit' to quit): ");
        char username[20];
        scanf("%s", username);
        
        // Check if user entered 'exit'
        if(strcmp(username, "exit") == 0){
            printf("\nThank you for using our Digital Auction System!\n");
            break; // Exit while loop and end program
        }
        
        // Find user in users array
        for(i=0; i<MAX_USERS; i++){
            if(strcmp(users[i].name, username) == 0){
                userIndex = i;
                break;
            }
        }
        
        // Check if user is in users array
        if(i == MAX_USERS){
            printf("\nUser '%s' does not exist. Please try again.\n", username);
            continue; // Go to beginning of while loop and prompt user to enter name again
        }
        
        // Prompt user to enter item number and bid amount
        printf("Enter the item number you want to bid for (or type 'back' to go back): ");
        char input[20];
        scanf("%s", input);
        
        // Check if user typed 'back'
        if(strcmp(input, "back") == 0){
            continue; // Go to beginning of while loop and prompt user to enter name again
        }
        
        int itemIndex = atoi(input) - 1;
        
        // Check if item number entered is valid
        if(itemIndex < 0 || itemIndex >= MAX_ITEMS){
            printf("\nInvalid item number. Please try again.\n");
            continue; // Go to beginning of while loop and prompt user to enter name again
        }
        
        // Check if item already has a highest bidder
        if(items[itemIndex].highestBidder != NULL){
            printf("\nItem already has a highest bidder. Please try again later.\n");
            continue; // Go to beginning of while loop and prompt user to enter name again
        }
        
        printf("Enter the bid amount: ");
        scanf("%d", &bidAmount);
        
        // Check if user has enough balance
        if(users[userIndex].balance < bidAmount){
            printf("\nYou do not have enough balance. Please try again with a lower bid amount.\n");
            continue; // Go to beginning of while loop and prompt user to enter name again
        }
        
        // Update item bid and highest bidder
        items[itemIndex].price = bidAmount;
        items[itemIndex].highestBidder = &users[userIndex];
        
        // Update user balance
        users[userIndex].balance -= bidAmount;
        
        printf("\nCongratulation! You are the highest bidder for item '%s' with a bid of $%d.\n", items[itemIndex].name, bidAmount);
    }
    
    return 0;
}