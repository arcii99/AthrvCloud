//FormAI DATASET v1.0 Category: Digital Auction System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ITEM_NAME 50
#define MAX_BIDDER_NAME 25
#define MAX_BIDDERS 10

struct Bidder 
{
    char name[MAX_BIDDER_NAME];
    float bidAmount;
    bool hasWon;
};

struct Auction 
{
    char itemName[MAX_ITEM_NAME];
    float startingPrice;
    int numBidders;
    struct Bidder bidders[MAX_BIDDERS];
};

struct Auction createAuction(char name[], float startingPrice) 
{
    struct Auction newAuction;
    strcpy(newAuction.itemName, name);
    newAuction.startingPrice = startingPrice;
    newAuction.numBidders = 0;
    return newAuction;
}

void addBidder(struct Auction *auction, char name[], float bid) 
{
    if (auction->numBidders == MAX_BIDDERS) 
    {
        printf("Error: Maximum number of bidders exceeded\n");
        return;
    }
    struct Bidder newBidder;
    strcpy(newBidder.name, name);
    newBidder.bidAmount = bid;
    newBidder.hasWon = false;
    auction->bidders[auction->numBidders] = newBidder;
    auction->numBidders++;
}

void displayBidders(struct Auction auction) 
{
    printf("\nBidders for %s:\n", auction.itemName);
    for (int i = 0; i < auction.numBidders; i++) 
    {
        printf("%s: $%.2f\n", auction.bidders[i].name, auction.bidders[i].bidAmount);
    }
}

void updateWinners(struct Auction *auction)
{
    float highestBid = 0.0;
    int highestBidIndex = -1;
    for (int i = 0; i < auction->numBidders; i++) 
    {
        if (auction->bidders[i].bidAmount > highestBid) 
        {
            highestBid = auction->bidders[i].bidAmount;
            highestBidIndex = i;
        }
    }
    if (highestBidIndex >= 0)
    {
        auction->bidders[highestBidIndex].hasWon = true;
    }
}

void displayWinners(struct Auction auction) 
{
    printf("\nWinners for %s:\n", auction.itemName);
    bool winnersExist = false;
    for (int i = 0; i < auction.numBidders; i++) 
    {
        if (auction.bidders[i].hasWon) 
        {
            printf("%s: $%.2f\n", auction.bidders[i].name, auction.bidders[i].bidAmount);
            winnersExist = true;
        }
    }
    if (!winnersExist) 
    {
        printf("No winners\n");
    }
}

int main() 
{
    struct Auction myAuction = createAuction("Baseball Card", 10.0);
    addBidder(&myAuction, "John", 12.0);
    addBidder(&myAuction, "Mary", 15.0);
    addBidder(&myAuction, "Dave", 11.0);
    addBidder(&myAuction, "Susan", 20.0);
    
    displayBidders(myAuction);
    updateWinners(&myAuction);
    displayWinners(myAuction);
    
    return 0;
}