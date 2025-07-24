//FormAI DATASET v1.0 Category: Digital Auction System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDDERS 10
#define MAX_ITEMS 5
#define MAX_BID 10000

typedef struct {
    char name[20];
    int bid;
} Bid;

typedef struct {
    char name[20];
    int value;
    Bid bids[MAX_BIDDERS];
    int num_bidders;
} Item;

int main() {
    Item items[MAX_ITEMS];
    int num_items = 0;
    char input[20];
    int i, j, winning_bid, winner_index;
    char winner_name[20];
    Bid current_bid;

    while (1) {
        printf("Enter a command: ");
        fgets(input, 20, stdin);
        if (strncmp(input, "add item", 8) == 0) {
            if (num_items == MAX_ITEMS) {
                printf("Error: maximum number of items reached\n");
            }
            else {
                printf("Enter the name of the item: ");
                fgets(items[num_items].name, 20, stdin);
                printf("Enter the starting value of the item: ");
                scanf("%d", &items[num_items].value);
                getchar(); // clear input buffer
                items[num_items].num_bidders = 0;
                num_items++;
            }
        }
        else if (strncmp(input, "list items", 10) == 0) {
            printf("Items currently up for auction:\n");
            for (i = 0; i < num_items; i++) {
                printf("%d. %s (starting value: %d)\n", i+1, items[i].name, items[i].value);
            }
        }
        else if (strncmp(input, "add bidder", 10) == 0) {
            if (num_items == 0) {
                printf("Error: no items currently up for auction\n");
            }
            else if (items[num_items-1].num_bidders == MAX_BIDDERS) {
                printf("Error: maximum number of bidders reached for this item\n");
            }
            else {
                printf("Enter the bidder's name: ");
                fgets(current_bid.name, 20, stdin);
                current_bid.bid = 0;
                items[num_items-1].bids[items[num_items-1].num_bidders] = current_bid;
                items[num_items-1].num_bidders++;
            }
        }
        else if (strncmp(input, "list bidders", 12) == 0) {
            if (num_items == 0) {
                printf("Error: no items currently up for auction\n");
            }
            else {
                printf("Bidders for item %d (%s):\n", num_items, items[num_items-1].name);
                for (i = 0; i < items[num_items-1].num_bidders; i++) {
                    printf("%d. %s\n", i+1, items[num_items-1].bids[i].name);
                }
            }
        }
        else if (strncmp(input, "bid", 3) == 0) {
            if (num_items == 0) {
                printf("Error: no items currently up for auction\n");
            }
            else {
                printf("Enter your bid: ");
                scanf("%d", &current_bid.bid);
                getchar(); // clear input buffer
                if (current_bid.bid > items[num_items-1].value && current_bid.bid <= MAX_BID) {
                    for (i = 0; i < items[num_items-1].num_bidders; i++) {
                        if (strcmp(items[num_items-1].bids[i].name, current_bid.name) == 0) {
                            items[num_items-1].bids[i].bid = current_bid.bid;
                            break;
                        }
                    }
                    if (i == items[num_items-1].num_bidders) {
                        items[num_items-1].bids[items[num_items-1].num_bidders] = current_bid;
                        items[num_items-1].num_bidders++;
                    }
                    printf("Bid accepted.\n");
                }
                else if (current_bid.bid <= items[num_items-1].value) {
                    printf("Error: bid must be greater than the starting value (%d)\n", items[num_items-1].value);
                }
                else {
                    printf("Error: bid exceeds maximum allowed value (%d)\n", MAX_BID);
                }
            }
        }
        else if (strncmp(input, "end auction", 11) == 0) {
            if (num_items == 0) {
                printf("Error: no items currently up for auction\n");
            }
            else {
                printf("Auction ended for item %d (%s).\n", num_items, items[num_items-1].name);
                winning_bid = items[num_items-1].value;
                winner_index = -1;
                for (i = 0; i < items[num_items-1].num_bidders; i++) {
                    if (items[num_items-1].bids[i].bid > winning_bid) {
                        winning_bid = items[num_items-1].bids[i].bid;
                        winner_index = i;
                    }
                }
                if (winner_index == -1) {
                    printf("No bids were placed for this item.\n");
                }
                else {
                    printf("Winner: %s with a bid of %d.\n", items[num_items-1].bids[winner_index].name, winning_bid);
                }
                num_items--;
            }
        }
        else if (strncmp(input, "quit", 4) == 0) {
            break;
        }
        else {
            printf("Error: invalid command\n");
        }
    }

    return 0;
}