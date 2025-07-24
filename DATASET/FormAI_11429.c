//FormAI DATASET v1.0 Category: Digital Auction System ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Auction {
    int lot_number;
    char item_name[50];
    float current_bid;
    char bidder_name[50];
};

int main() {
    int i, j, n, pos;
    float max_bid;
    struct Auction temp;
    printf("Enter the number of items to be auctioned: ");
    scanf("%d", &n);
    struct Auction auction[n];
    for(i=0; i<n; i++) {
        printf("\nEnter the details of item no. %d:\n", i+1);
        printf("Lot Number: ");
        scanf("%d", &auction[i].lot_number);
        printf("Item Name: ");
        scanf("%s", &auction[i].item_name);
        printf("Starting Bid: ");
        scanf("%f", &auction[i].current_bid);
        strcpy(auction[i].bidder_name, "None");
    }

    printf("\nItem list:\n");
    printf("Lot No.\tItem Name\tStarting Bid\n");
    for(i=0; i<n; i++) {
        printf("%d\t%s\t%.2f\n", auction[i].lot_number, auction[i].item_name, auction[i].current_bid);
    }

    printf("\nEnter the lot number of the item to bid: ");
    scanf("%d", &pos);

    for(i=0; i<n; i++) {
        if(auction[i].lot_number == pos) {
            printf("\nEnter your name: ");
            scanf("%s", &auction[i].bidder_name);
            printf("Enter your bid: ");
            scanf("%f", &max_bid);
            if(max_bid > auction[i].current_bid) {
                auction[i].current_bid = max_bid;
                printf("\nCongratulations! You are the highest bidder now.\n");
            } else {
                printf("\nSorry, your bid is lower than the current bid.\n");
            }
        }
    }

    printf("\nItem list after bidding:\n");
    printf("Lot No.\tItem Name\tCurrent Bid\tBidder\n");
    for(i=0; i<n; i++) {
        printf("%d\t%s\t%.2f\t%s\n", auction[i].lot_number, auction[i].item_name, auction[i].current_bid, auction[i].bidder_name);
    }

    // Sort items by current bid
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(auction[j].current_bid < auction[j+1].current_bid) {
                temp = auction[j];
                auction[j] = auction[j+1];
                auction[j+1] = temp;
            }
        }
    }

    printf("\nItem list sorted by current bid (highest to lowest):\n");
    printf("Lot No.\tItem Name\tCurrent Bid\tBidder\n");
    for(i=0; i<n; i++) {
        printf("%d\t%s\t%.2f\t%s\n", auction[i].lot_number, auction[i].item_name, auction[i].current_bid, auction[i].bidder_name);
    }

    return 0;
}