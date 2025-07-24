//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Alan Touring
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Bid {
    char bidder_name[20];
    int bid_amount;
};

void auction(int total_bidders) {
    int i;
    struct Bid bidders[total_bidders];
    for(i=0; i<total_bidders; i++) {
        printf("Enter bidder name %d: ", i+1);
        scanf("%s", bidders[i].bidder_name);
        printf("Enter bid amount %d: ", i+1);
        scanf("%d", &bidders[i].bid_amount);
    }

    printf("\n-----Bidders List-----\n");
    for(i=0; i<total_bidders; i++) {
        printf("%s: %d\n", bidders[i].bidder_name, bidders[i].bid_amount);
    }

    // Finding the winner
    int max_bid_amt=0, win_index=0;
    for(i=0; i<total_bidders; i++) {
        if(bidders[i].bid_amount > max_bid_amt) {
            max_bid_amt = bidders[i].bid_amount;
            win_index = i;
        }
    }

    printf("\n%s wins with a bid of %d\n", bidders[win_index].bidder_name, bidders[win_index].bid_amount);
}

int main() {
    int total_bidders;
    printf("Welcome to the Digital Auction System\n");
    printf("Enter total bidders: ");
    scanf("%d", &total_bidders);
    auction(total_bidders);
    return 0;
}