//FormAI DATASET v1.0 Category: Digital Auction System ; Style: configurable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// define constants
#define MAX_BIDS 10
#define MAX_NAME_LEN 50

// define Auction Item struct
typedef struct {
    char name[MAX_NAME_LEN];
    float currentPrice;
    float minimumIncrement;
    float highestBid;
    char highestBidder[MAX_NAME_LEN];
} AuctionItem;

// define Bid struct
typedef struct {
    char name[MAX_NAME_LEN];
    float bidPrice;
} Bid;

// function prototypes
void printAuctionItem(AuctionItem item);
void printBid(Bid bid);
void placeBid(AuctionItem* item, Bid* bid);

int main() {
    // initial setup
    AuctionItem item;
    strcpy(item.name, "Limited Edition Comic Book");
    item.currentPrice = 100.0;
    item.minimumIncrement = 10.0;
    item.highestBid = 0.0;
    strcpy(item.highestBidder, "No Bids Yet");
    
    // display auction item details
    printAuctionItem(item);
    
    // simulate bidding process
    Bid bids[MAX_BIDS];
    int bidCount = 0;
    char continueBidding = 'Y';
    
    while (continueBidding == 'Y' && bidCount < MAX_BIDS) {
        Bid newBid;
        printf("Enter your name: ");
        scanf("%s", newBid.name);
        printf("Enter your bid (minimum increment %f): ", item.minimumIncrement);
        scanf("%f", &newBid.bidPrice);
        
        // add new bid to array
        placeBid(&item, &newBid);
        bids[bidCount] = newBid;
        bidCount++;
        
        // display updated auction item details
        printAuctionItem(item);
        
        if (bidCount < MAX_BIDS) {
            printf("Continue bidding? (Y/N): ");
            scanf(" %c", &continueBidding);
            continueBidding = toupper(continueBidding);
        }
    }
    
    // display final bidding results
    printf("Bidding has ended. Final auction item details:\n");
    printAuctionItem(item);
    printf("Bidding history:\n");
    for (int i = 0; i < bidCount; i++) {
        printBid(bids[i]);
    }
    
    return 0;
}

// function definitions
void printAuctionItem(AuctionItem item) {
    printf("Auction Item: %s\n", item.name);
    printf("Current Price: %.2f\n", item.currentPrice);
    printf("Minimum Increment: %.2f\n", item.minimumIncrement);
    printf("Highest Bid: %.2f\n", item.highestBid);
    printf("Highest Bidder: %s\n", item.highestBidder);
    printf("\n");
}

void printBid(Bid bid) {
    printf("Bidder: %s\n", bid.name);
    printf("Bid Price: %.2f\n", bid.bidPrice);
    printf("\n");
}

void placeBid(AuctionItem* item, Bid* bid) {
    if (bid->bidPrice < item->currentPrice + item->minimumIncrement) {
        printf("The bid is too low. Please enter a bid of at least %.2f.\n", item->currentPrice + item->minimumIncrement);
        printf("\n");
    } else {
        printf("Bid accepted!\n");
        printf("\n");
        item->currentPrice = bid->bidPrice;
        item->highestBid = bid->bidPrice;
        strcpy(item->highestBidder, bid->name);
    }
}