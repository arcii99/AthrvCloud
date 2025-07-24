//FormAI DATASET v1.0 Category: Digital Auction System ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct for each item on auction */
struct AuctionItem {
    char name[50];
    int startingPrice;
    int currentBid;
    char bidderName[50];
    char bidderContact[50];
};

/* Define a function to display each auction item */
void displayItem(struct AuctionItem item) { 
    printf("\n%s\nStarting Price: $%d\nCurrent Top Bid: $%d\n", item.name, item.startingPrice, item.currentBid);
    if(item.currentBid > item.startingPrice){
        printf("Top Bidder: %s\nContact Info: %s\n", item.bidderName, item.bidderContact);
    }
}

/* Define a function to search for an item by name */
void searchItem(struct AuctionItem items[], int numItems) {
    char searchName[50];
    printf("Enter the name of the item you would like to search for: ");
    scanf("%s", searchName);
    for(int i=0; i<numItems; i++){
        if(strcmp(items[i].name, searchName) == 0) {
            displayItem(items[i]);
            return;
        }
    }
    printf("\nSorry, we could not find an item with that name.\n");
}

/* Define a function to place a bid on an item */
void placeBid(struct AuctionItem *item) {
    int newBid;
    printf("Enter your bid amount: ");
    scanf("%d", &newBid);
    if(newBid > item->currentBid){
        printf("Congratulations! You are now the top bidder!\n");
        item->currentBid = newBid;
        char newBidderName[50];
        char newBidderContact[50];
        printf("Please enter your name: ");
        scanf("%s", newBidderName);
        printf("Please enter your contact information: ");
        scanf("%s", newBidderContact);
        strcpy(item->bidderName, newBidderName);
        strcpy(item->bidderContact, newBidderContact);
    } else {
        printf("Sorry, your bid was not high enough. The current top bid is $%d.\n", item->currentBid);
    }
}

/* Define main function */
int main() {
    struct AuctionItem items[4]; // Create an array of AuctionItem structs
    int numItems = 4;
    
    /* Initialize each item */
    strcpy(items[0].name, "Antique Chair");
    items[0].startingPrice = 50;
    items[0].currentBid = 50;

    strcpy(items[1].name, "Vintage Record Player");
    items[1].startingPrice = 100;
    items[1].currentBid = 100;

    strcpy(items[2].name, "Signed Baseball");
    items[2].startingPrice = 75;
    items[2].currentBid = 75;

    strcpy(items[3].name, "Collectible Doll");
    items[3].startingPrice = 25;
    items[3].currentBid = 25;

    /* Display menu options */
    printf("Welcome to the Digital Auction System!\n");
    printf("Please select an option from the menu below:\n\n");
    printf("1. Display all items\n");
    printf("2. Search for an item by name\n");
    printf("3. Place a bid on an item\n");
    printf("4. Exit\n");

    int choice;
    /* Keep looping until user selects "Exit" */
    do {
        printf("\nPlease enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                for(int i=0; i<numItems; i++){
                    displayItem(items[i]);
                }
                break;
            case 2:
                searchItem(items, numItems);
                break;
            case 3:
                printf("Please enter the name of the item you would like to bid on: ");
                char itemName[50];
                scanf("%s", itemName);
                for(int i=0; i<numItems; i++){
                    if(strcmp(items[i].name, itemName) == 0) {
                        placeBid(&items[i]);
                        break;
                    }
                }
                break;
            case 4:
                printf("Thank you for using the Digital Auction System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);

    return 0;
}