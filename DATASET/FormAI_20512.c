//FormAI DATASET v1.0 Category: Digital Auction System ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_BIDS 10 // maximum bids per auction
#define MAX_AUCTIONS 5 // maximum auctions in the system

struct Auction{
    int auctionId;
    char item[100];
    float highestBid;
    int numBids;
    float bids[MAX_BIDS];
};

struct Auction auctions[MAX_AUCTIONS];
int numAuctions = 0;

// function to add a new auction
void createAuction(char* item, float startBid){
    if(numAuctions >= MAX_AUCTIONS){
        printf("ERROR: Maximum number of auctions reached!\n");
        return;
    }

    struct Auction newAuction;
    newAuction.auctionId = numAuctions + 1;
    strcpy(newAuction.item, item);
    newAuction.highestBid = startBid;
    newAuction.numBids = 0;
    auctions[numAuctions] = newAuction;
    numAuctions++;
}

// function to place a bid
void placeBid(int auctionId, float bidAmount){
    if(auctionId < 1 || auctionId > numAuctions){
        printf("ERROR: Invalid auction ID!\n");
        return;
    }

    struct Auction* auction = &auctions[auctionId - 1];

    if(bidAmount <= auction->highestBid){
        printf("ERROR: Bid amount must be higher than the current highest bid!\n");
        return;
    }

    if(auction->numBids >= MAX_BIDS){
        printf("ERROR: Maximum number of bids reached for this auction!\n");
        return;
    }

    auction->bids[auction->numBids] = bidAmount;
    auction->numBids++;
    auction->highestBid = bidAmount;
    printf("Bid of %.2f successfully placed on %s (Auction ID #%d)!\n", bidAmount, auction->item, auction->auctionId);
}

// function to display all auctions
void displayAuctions(){
    if(numAuctions == 0){
        printf("No auctions currently in the system.\n");
    }
    else{
        printf("Auctions currently in the system:\n");
        for(int i=0; i<numAuctions; i++){
            struct Auction auction = auctions[i];
            printf("%d. %s - Highest bid: %.2f (%d bids)\n", auction.auctionId, auction.item, auction.highestBid, auction.numBids);
        }
    }
}

int main(){
    // creating sample auctions
    createAuction("Painting", 500.0);
    createAuction("Smartphone", 800.0);
    createAuction("Guitar", 700.0);

    // placing sample bids
    placeBid(1, 550.0);
    placeBid(1, 600.0);
    placeBid(2, 900.0);
    placeBid(3, 750.0);

    // displaying all auctions
    displayAuctions();

    return 0;
}