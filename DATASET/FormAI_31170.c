//FormAI DATASET v1.0 Category: Digital Auction System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure to store bid details
struct bidDetails {
    char bidderName[50];
    int bidAmount;
};

int main() {
    int numBids, i, winnerBid=0, numWinners=0;
    printf("Enter the number of bids: ");
    scanf("%d",&numBids);

    struct bidDetails bids[numBids];
    for(i=0;i<numBids;i++) {
        //Accept bidder name and bid amount for each bid
        printf("Enter bidder name: ");
        scanf("%s", bids[i].bidderName);
        printf("Enter bid amount: ");
        scanf("%d",&bids[i].bidAmount);
    }

    //Determine the winner bid amount
    for(i=0;i<numBids;i++) {
        if(bids[i].bidAmount>winnerBid) {
            winnerBid=bids[i].bidAmount;
        }
    }

    //Count number of winners
    for(i=0;i<numBids;i++) {
        if(bids[i].bidAmount==winnerBid) {
            numWinners++;
        }
    }

    //Print the winner or winners
    printf("\nThe winner%s:\n",numWinners>1?"s":"");
    for(i=0;i<numBids;i++) {
        if(bids[i].bidAmount==winnerBid) {
            printf("%s\n",bids[i].bidderName);
        }
    }

    return 0;
}