//FormAI DATASET v1.0 Category: Digital Auction System ; Style: puzzling
#include<stdio.h>

int main(){

    char itemName[50];
    int basePrice, currentBid, bidderID;
    char bidderName[50];
    int highestBid = 0, highestBidderID = 0;

    printf("Enter item name: ");
    scanf("%s", itemName);
    printf("Enter base price: ");
    scanf("%d", &basePrice);

    printf("\n\nItem: %s \nBase price: %d\n\n", itemName, basePrice);

    while(1){

        printf("Enter your ID: ");
        scanf("%d", &bidderID);
        printf("Enter your name: ");
        scanf("%s", bidderName);
        printf("Enter your bid: ");
        scanf("%d", &currentBid);

        if(currentBid > highestBid){
            highestBid = currentBid;
            highestBidderID = bidderID;
            printf("\nYou are the highest bidder with a bid of %d.\n\n", highestBid);
        }
        else{
            printf("\nYour bid is not high enough. The highest bid is currently %d.\n\n", highestBid);
        }

        printf("Do you want to bid again? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if(choice == 'n' || choice == 'N'){
            break;
        }
    }

    printf("\n\nItem sold to bidder with ID %d, for a final price of %d.\n", highestBidderID, highestBid);

    return 0;
}