//FormAI DATASET v1.0 Category: Digital Auction System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// creating a struct for item details 
struct item {
    char name[50];
    char description[100];
    int starting_bid;
    int current_bid;
    char bidder[50];
};

// creating a function to display the item details
void display_item(struct item i) {
    printf("\n\nItem Name: %s", i.name);
    printf("\nDescription: %s", i.description);
    printf("\nStarting Bid: $%d", i.starting_bid);
    printf("\nCurrent Bid: $%d", i.current_bid);
    if(i.bidder[0] != '\0') {
        printf("\nCurrent Highest Bidder: %s", i.bidder);
    }
}

int main() {
    // creating an array of items for the auction
    struct item items[5];
    
    // initializing the items
    strcpy(items[0].name, "Fender Guitar");
    strcpy(items[0].description, "Electric guitar used by Jimi Hendrix during his final performance");
    items[0].starting_bid = 500;
    items[0].current_bid = 0;
    items[0].bidder[0] = '\0';
    
    strcpy(items[1].name, "Van Gogh Painting");
    strcpy(items[1].description, "Oil painting on canvas, Starry Night");
    items[1].starting_bid = 1000000;
    items[1].current_bid = 0;
    items[1].bidder[0] = '\0';
    
    strcpy(items[2].name, "Rare Stamp Collection");
    strcpy(items[2].description, "Collection of rare and valuable stamps from around the world");
    items[2].starting_bid = 250000;
    items[2].current_bid = 0;
    items[2].bidder[0] = '\0';
    
    strcpy(items[3].name, "Antique Piano");
    strcpy(items[3].description, "Black grand piano, over 150 years old");
    items[3].starting_bid = 10000;
    items[3].current_bid = 0;
    items[3].bidder[0] = '\0';
    
    strcpy(items[4].name, "Sports Memorabilia Collection");
    strcpy(items[4].description, "Collection of autographed sports memorabilia, including jerseys, balls, and more");
    items[4].starting_bid = 5000;
    items[4].current_bid = 0;
    items[4].bidder[0] = '\0';
    
    int menu_choice;
    int item_choice;
    int bid_amount;
    int highest_bid;
    
    printf("Welcome to the Digital Auction System!");
    
    do {
        // displaying the main menu
        printf("\n\nMain Menu");
        printf("\n1. View Items for Sale");
        printf("\n2. View Item Details");
        printf("\n3. Place a Bid");
        printf("\n4. Quit");
        printf("\n\nEnter your choice (1-4): ");
        scanf("%d", &menu_choice);
        
        switch(menu_choice) {
            case 1:
                // displaying the list of items
                printf("\n\nItems for Sale:");
                printf("\n1. %s", items[0].name);
                printf("\n2. %s", items[1].name);
                printf("\n3. %s", items[2].name);
                printf("\n4. %s", items[3].name);
                printf("\n5. %s", items[4].name);
                break;
            case 2:
                // displaying the details of an item
                printf("\n\nEnter the number of the item you want to view: ");
                scanf("%d", &item_choice);
                display_item(items[item_choice-1]);
                break;
            case 3:
                // placing a bid on an item
                printf("\n\nEnter the number of the item you want to bid on: ");
                scanf("%d", &item_choice);
                printf("\nEnter your bid amount: ");
                scanf("%d", &bid_amount);
                highest_bid = items[item_choice-1].current_bid;
                if(bid_amount > highest_bid) {
                    items[item_choice-1].current_bid = bid_amount;
                    printf("\nYou are now the highest bidder for %s!", items[item_choice-1].name);
                    printf("\nEnter your name: ");
                    scanf("%s", &items[item_choice-1].bidder);
                }
                else {
                    printf("\nSorry, your bid was not high enough.");
                }
                break;
            case 4:
                // quitting the program
                printf("\n\nThank you for using the Digital Auction System!");
                break;
            default:
                printf("\n\nInvalid choice. Please enter a number 1-4.");
                break;
        }
    } while(menu_choice != 4);
    
    return 0;
}