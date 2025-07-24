//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Bidder {
    char name[50];
    int bid;
};

int main(){
    int n, i, max_bid = 0, winner = 0;
    char auction[50];

    printf("Welcome to the Digital Auction, where we have the rarest artifacts on display!\n");
    printf("Please enter the name of the auction: ");
    scanf("%s", &auction);
    printf("How many bidders do we have today? ");
    scanf("%d", &n);
    struct Bidder bidders[n];

    for(i = 0; i < n; i++){
        printf("Please enter the name of bidder %d: ", i+1);
        scanf("%s", &bidders[i].name);
        printf("Please enter the auction bid of bidder %d: $", i+1);
        scanf("%d", &bidders[i].bid);
        if(bidders[i].bid > max_bid){
            max_bid = bidders[i].bid;
            winner = i;
        }
    }

    printf("The auction for %s has ended!\n", auction);
    printf("The winner of the auction is %s with the highest bid of $%d!\n", bidders[winner].name, bidders[winner].bid);

    return 0;
}