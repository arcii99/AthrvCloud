//FormAI DATASET v1.0 Category: Digital Auction System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int min_bid = 1000; // minimum bid amount
    int current_bid = min_bid;
    int highest_bidder_id = 0; // ID of the highest bidder
    int bidder_count = 0; // keeps count of the number of bidders
    int auction_time = 60; // 60 seconds for the auction

    time_t start_time, current_time;
    time(&start_time);

    printf("Welcome to the Digital Auction System!\n\n");
    printf("The starting bid is $%d.\n", min_bid);

    while(difftime(time(&current_time), start_time) < auction_time)
    {
        int user_bid;
        printf("Enter your bid: $");
        scanf("%d", &user_bid);

        if(user_bid >= current_bid)
        {
            current_bid = user_bid;
            highest_bidder_id = bidder_count + 1;
            printf("Bid accepted!\n");
        }
        else
        {
            printf("Your bid must be higher than the current bid of $%d\n", current_bid);
        }

        bidder_count++;
    }

    printf("\nThe auction has ended!\n");
    printf("Highest bidder is ID %d with a bid of $%d.\n", highest_bidder_id, current_bid);

    return 0;
}