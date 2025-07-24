//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int auctionID = rand() % 10000;
    char itemName[50];
    int initialBid, currentBid, reservePrice;
    char bidder[50];
    int timeLeft = 60;
    
    printf("Welcome to the Cyberpunk Digital Auction System!\n");
    printf("Your auction ID is %04d\n", auctionID);
    
    printf("Please enter the name of the item: ");
    scanf("%s", itemName);
    
    printf("Please enter the initial bid: ");
    scanf("%d", &initialBid);
    
    printf("Please enter the reserve price: ");
    scanf("%d", &reservePrice);
    
    printf("Your item %s is now up for auction with an initial bid of %d!\n", itemName, initialBid);
    printf("The reserve price for this item is %d.\n", reservePrice);
    printf("Bidding will close in %d seconds.\n", timeLeft);
    
    sleep(timeLeft);
    currentBid = initialBid;
    
    while(currentBid < reservePrice){
        printf("Current bid: %d\n", currentBid);
        printf("Please enter your bid: ");
        scanf("%d", &currentBid);
        printf("Your bid of %d has been accepted.\n", currentBid);
        printf("Please enter your name: ");
        scanf("%s", bidder);
        printf("Thank you %s for your bid of %d.\n", bidder, currentBid);
        printf("Bidding will close in %d seconds.\n", timeLeft);
        timeLeft -= 10;
        sleep(10);
    }
    
    printf("The item %s has been sold to %s for %d!\n", itemName, bidder, currentBid);
    
    return 0;
}