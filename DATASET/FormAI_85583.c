//FormAI DATASET v1.0 Category: Digital Auction System ; Style: enthusiastic
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// Defining the structure for an auction item
struct auction_item{
    char name[50];
    char description[100];
    int base_price;
    int highest_bid;
    char highest_bidder[50];
};

// Function to display the details of an auction item
void display_item(struct auction_item item){
    printf("\nItem Name: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Base Price: %d\n", item.base_price);
    printf("Highest Bid: %d\n", item.highest_bid);
    printf("Highest Bidder: %s\n", item.highest_bidder);
}

int main(){
    srand(time(0));
    struct auction_item item1, item2;
    int bidder1 = 0, bidder2 = 0;
    
    // Initializing item1
    strcpy(item1.name, "Samsung Galaxy S21");
    strcpy(item1.description, "A high-end smartphone with 5G connectivity and Snapdragon 888 processor");
    item1.base_price = 80000;
    item1.highest_bid = 80000;
    strcpy(item1.highest_bidder, "No bid yet");
    
    // Initializing item2
    strcpy(item2.name, "Sony Bravia OLED TV");
    strcpy(item2.description, "A 4K smart TV with 65 inch display and Android OS");
    item2.base_price = 120000;
    item2.highest_bid = 120000;
    strcpy(item2.highest_bidder, "No bid yet");

    printf("Welcome to the Digital Auction System!\n");
    printf("Here are the items available for bidding:\n");

    // Displaying the available items
    display_item(item1);
    display_item(item2);

    // Taking bids for item1
    printf("\nBidding for %s starts at %d\n", item1.name, item1.base_price);
    while(1){
        printf("Enter your bid (or 0 to exit): ");
        scanf("%d", &bidder1);
        if(bidder1 == 0)
            break;
        if(bidder1 <= item1.highest_bid){
            printf("Your bid must be higher than the current highest bid of %d\n", item1.highest_bid);
            continue;
        }
        item1.highest_bid = bidder1;
        printf("Congratulations! You are the highest bidder with %d\n", bidder1);
        strcpy(item1.highest_bidder, "Bidder 1");
    }

    // Taking bids for item2
    printf("\nBidding for %s starts at %d\n", item2.name, item2.base_price);
    while(1){
        printf("Enter your bid (or 0 to exit): ");
        scanf("%d", &bidder2);
        if(bidder2 == 0)
            break;
        if(bidder2 <= item2.highest_bid){
            printf("Your bid must be higher than the current highest bid of %d\n", item2.highest_bid);
            continue;
        }
        item2.highest_bid = bidder2;
        printf("Congratulations! You are the highest bidder with %d\n", bidder2);
        strcpy(item2.highest_bidder, "Bidder 2");
    }

    // Displaying the final details of the items
    printf("\nHere are the final details of the items:\n");
    display_item(item1);
    display_item(item2);

    printf("Thank you for using the Digital Auction System!\n");
    return 0;
}