//FormAI DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    int auction_item_num;
    float base_bid_price, current_bid_price=0.0, increment_price, max_bid_price=0.0;
    char bidder_name[20];

    printf("*** Welcome to the Futuristic Digital Auction System! ***\n");
    printf("Enter the auction item number: ");
    scanf("%d", &auction_item_num);
    printf("Enter the base bid price (in USD): ");
    scanf("%f", &base_bid_price);
    printf("Enter the increment price (in USD): ");
    scanf("%f", &increment_price);

    printf("*** Bidding for item %d has started! ***\n", auction_item_num);

    while(current_bid_price < base_bid_price) {
        printf("\nCurrent bid price: %.2f USD\n", current_bid_price);
        printf("Enter your bid (in USD): ");
        scanf("%f", &max_bid_price);
        if(max_bid_price > current_bid_price + increment_price) {
            current_bid_price += increment_price; // increment the bid price
            printf("Bid successful! Current bid price is now %.2f USD\n", current_bid_price);
        } else {
            printf("Bid too low! Please enter a bid higher than %.2f USD\n", current_bid_price + increment_price);
        }
    }
    printf("\n*** The bidding for item %d has ended! ***\n", auction_item_num);
    printf("Final bid price: %.2f USD\n", current_bid_price);
    printf("Winner: %s\n", bidder_name);

    return 0;
}