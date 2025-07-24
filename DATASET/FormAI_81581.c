//FormAI DATASET v1.0 Category: Digital Auction System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Structure to store auction information
struct Auction {
    int itemNumber;
    char itemDescription[50];
    float basePrice;
    float currentBid;
    char bidderName[50];
};

// Function to display the auction details
void displayAuction(struct Auction a[], int n) {
    printf("\nItem No.\tItem Description\tBase Price\tCurrent Bid\tBidder Name\n");
    for(int i=0; i<n; i++) {
        printf("%d\t\t%s\t\t%.2f\t\t", a[i].itemNumber, a[i].itemDescription, a[i].basePrice);
        if(a[i].currentBid > 0)
            printf("%.2f\t\t%s\n", a[i].currentBid, a[i].bidderName);
        else
            printf("-\n");
    }
}

int main() {
    struct Auction auction[10];
    int choice, itemNo, bidAmount, winner=0, maxBid=0, flag=0, count=0;
    char bidderName[50];

    // Seed for generating random base prices
    srand(time(0));

    // Initializing auction details
    for(int i=0; i<10; i++) {
        auction[i].itemNumber = i+1;
        sprintf(auction[i].itemDescription, "Item %d", i+1);
        auction[i].basePrice = rand()%5000 + 1000; // Random base price between 1000 and 6000
        auction[i].currentBid = 0;
        auction[i].bidderName[0] = '\0';
    }

    while(1) {
        printf("\n--------------------------------------\n");
        printf("Welcome to the Digital Auction System");
        printf("\n--------------------------------------\n");

        printf("\n1. Display available items for auction");
        printf("\n2. Place a bid");
        printf("\n3. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: displayAuction(auction, 10);
                    break;

            case 2: printf("\nEnter the item number: ");
                    scanf("%d", &itemNo);

                    if(itemNo > 0 && itemNo <= 10) {
                        if(auction[itemNo-1].currentBid == 0) {
                            printf("\nStarting bid for Item %d is %.2f", itemNo, auction[itemNo-1].basePrice);
                            flag = 1;
                        }
                        else {
                            printf("\nCurrent highest bid for Item %d is %.2f by %s", itemNo, auction[itemNo-1].currentBid, auction[itemNo-1].bidderName);
                            flag = 0;
                        }

                        if(flag) {
                            printf("\nWhat is your name? ");
                            scanf("%s", bidderName);
                            printf("\nWhat amount would you like to bid? ");
                            scanf("%d", &bidAmount);

                            if(bidAmount < auction[itemNo-1].basePrice || bidAmount <= auction[itemNo-1].currentBid)
                                printf("\nYour bid is not valid");
                            else {
                                auction[itemNo-1].currentBid = bidAmount;
                                sprintf(auction[itemNo-1].bidderName, "%s", bidderName);
                                printf("\nCongratulation %s, you have placed a bid of %.2f on Item %d", bidderName, auction[itemNo-1].currentBid, itemNo);
                            }
                        }
                        else {
                            printf("\nWhat is your name? ");
                            scanf("%s", bidderName);
                            printf("\nWhat amount would you like to bid? ");
                            scanf("%d", &bidAmount);

                            if(bidAmount <= auction[itemNo-1].currentBid)
                                printf("\nYour bid is not valid");
                            else {
                                // Finding the maximum bid
                                if(bidAmount > maxBid) {
                                    maxBid = bidAmount;
                                    winner = itemNo-1;
                                }

                                auction[itemNo-1].currentBid = bidAmount;
                                sprintf(auction[itemNo-1].bidderName, "%s", bidderName);
                                printf("\nCongratulation %s, you have placed a bid of %.2f on Item %d", bidderName, auction[itemNo-1].currentBid, itemNo);
                            }
                        }
                    }
                    else
                        printf("\nInvalid item number");

                    break;

            case 3: // Finding the winner of the auction
                    for(int i=0; i<10; i++) {
                        if(auction[i].currentBid != 0)
                            count++;
                    }

                    if(count == 0)
                        printf("\nNo bids placed");

                    else {
                        printf("\nWinner of the auction : %s\n", auction[winner].bidderName);

                        printf("\nAuction summary :");
                        printf("\nItem Number\tItem Description\tBase Price\tCurrent Bid\tBidder Name\n");
                        for(int i=0; i<10; i++) {
                            printf("%d\t\t%s\t\t%.2f\t\t", auction[i].itemNumber, auction[i].itemDescription, auction[i].basePrice);
                            if(auction[i].currentBid > 0)
                                printf("%.2f\t\t%s\n", auction[i].currentBid, auction[i].bidderName);
                            else
                                printf("-\n");
                        }
                    }

                    exit(0);

            default: printf("\nInvalid choice");
        }
    }
    return 0;
}