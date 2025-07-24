//FormAI DATASET v1.0 Category: Digital Auction System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BidderInfo{
    char name[50];
    int bid;
} BidderInfo;

typedef struct Auction{
    int highestBid;
    BidderInfo *highestBidder;
} Auction;

int main(){
    Auction auction;
    auction.highestBid = 0;
    auction.highestBidder = NULL;

    int numBidders;
    printf("Enter number of bidders: ");
    scanf("%d", &numBidders);

    BidderInfo *bidders = (BidderInfo*) malloc(numBidders * sizeof(BidderInfo));
    for(int i=0; i<numBidders; i++){
        printf("Enter name of bidder %d: ", i+1);
        scanf("%s", bidders[i].name);

        printf("Enter bid of bidder %d: ", i+1);
        scanf("%d", &bidders[i].bid);
    }

    for(int i=0; i<numBidders; i++){
        if(bidders[i].bid > auction.highestBid){
            auction.highestBid = bidders[i].bid;
            auction.highestBidder = &bidders[i];
        }
    }

    printf("Auction winner is %s with a bid of %d\n", 
            auction.highestBidder->name, auction.highestBid);

    free(bidders);
    return 0;
}