//FormAI DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// data structure for an auction item
typedef struct {
    char name[50];
    int price;
    int bids;
    char highest_bidder[50];
} AuctionItem;

// function to generate a random number between min and max
int rand_int(int min, int max)
{
    return min + rand() % (max - min + 1);
}

int main()
{
    srand(time(NULL)); // seed the random number generator with current time

    AuctionItem item;
    printf("Enter item name: ");
    fgets(item.name, 50, stdin);
    item.name[strcspn(item.name, "\n")] = '\0'; // remove newline character
    
    item.price = rand_int(100, 1000); // generate a random price between $100 and $1000
    item.bids = 0;
    
    printf("Starting price for %s is $%d\n", item.name, item.price);

    int sold = 0;
    while (!sold) {
        printf("\nCurrent highest bid: $%d by %s\n", item.price, item.highest_bidder);
        printf("Enter your bid (or 'q' to quit): ");
        char input[50];
        fgets(input, 50, stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "q") == 0) {
            break;
        }

        int bid = atoi(input);
        if (bid <= item.price) {
            printf("Bid must be higher than current highest bid of $%d\n", item.price);
        } else {
            item.price = bid;
            printf("New highest bid of $%d by you!\n", bid);
            strcpy(item.highest_bidder, "You");

            // simulate other bidders
            int num_bidders = rand_int(1, 5);
            for (int i = 0; i < num_bidders; i++) {
                int other_bid = rand_int(item.price + 1, item.price + 100); // other bids are between current highest bid and $100 more
                printf("Other bidder %d bids $%d\n", i + 1, other_bid);
                if (other_bid > item.price) {
                    strcpy(item.highest_bidder, "Other Bidder");
                    item.price = other_bid;
                }
            }

            item.bids++;
        }

        if (item.bids == 10 || item.price > rand_int(2000, 5000)) { // end auction after 10 bids or if price goes over $2000-$5000
            sold = 1;
            printf("\nSold to %s for $%d!\n", item.highest_bidder, item.price);
        }
    }

    return 0;
}