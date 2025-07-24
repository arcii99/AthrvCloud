//FormAI DATASET v1.0 Category: Digital Auction System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10 // Maximum number of bids
#define MAX_BIDDERS 5 // Maximum number of bidders

struct bid {
    int amount;
    char bidder_name[20];
};

struct item {
    char name[20];
    int current_bid;
    struct bid bids[MAX_BIDS];
    int num_bids;
};

struct auction {
    struct item items[5];
    int num_items;
    char bidders[MAX_BIDDERS][20];
    int num_bidders;
};

void print_items(struct auction auction);
void print_bidders(struct auction auction);
struct bid get_bid(char *bidder_name);
void add_bid(struct item *item_ptr, struct bid bid);

int main() {
    struct auction auction;
    auction.num_items = 0;
    auction.num_bidders = 0;
    char input[20];
    int choice, item_choice, bidder_choice;

    // Main menu loop
    while (1) {
        printf("\nWelcome to the Digital Auction System.\n");
        printf("Please choose an option:\n");
        printf("1. Add item\n");
        printf("2. List items\n");
        printf("3. Add bidder\n");
        printf("4. List bidders\n");
        printf("5. Place bid\n");
        printf("6. Exit\n");

        fgets(input, sizeof(input), stdin);
        sscanf(input, "%d", &choice);

        switch (choice) {
            case 1:
                if (auction.num_items >= 5) {
                    printf("Sorry, you cannot add more than 5 items.\n");
                    break;
                }

                struct item new_item;
                printf("Enter item name: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%s", new_item.name);

                new_item.current_bid = 0;
                new_item.num_bids = 0;

                auction.items[auction.num_items++] = new_item;

                printf("Item added successfully.\n");
                break;
            case 2:
                if (auction.num_items == 0) {
                    printf("There are no items currently up for auction.\n");
                    break;
                }

                print_items(auction);
                break;
            case 3:
                if (auction.num_bidders >= MAX_BIDDERS) {
                    printf("Sorry, you cannot add more than %d bidders.\n", MAX_BIDDERS);
                    break;
                }

                printf("Enter bidder name: ");
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%s", auction.bidders[auction.num_bidders++]);

                printf("Bidder added successfully.\n");
                break;
            case 4:
                if (auction.num_bidders == 0) {
                    printf("There are no bidders currently registered.\n");
                    break;
                }

                print_bidders(auction);
                break;
            case 5:
                if (auction.num_items == 0 || auction.num_bidders == 0) {
                    printf("Error: There are no items or bidders currently available.\n");
                    break;
                }

                printf("Please choose an item:\n");
                print_items(auction);
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%d", &item_choice);
                item_choice--;

                printf("Please choose a bidder:\n");
                print_bidders(auction);
                fgets(input, sizeof(input), stdin);
                sscanf(input, "%d", &bidder_choice);
                bidder_choice--;

                struct bid new_bid = get_bid(auction.bidders[bidder_choice]);
                add_bid(&auction.items[item_choice], new_bid);

                printf("Bid successfully placed.\n");
                break;
            case 6:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}

void print_items(struct auction auction) {
    printf("Items:\n");
    for (int i = 0; i < auction.num_items; i++) {
        printf("%d. %s - %d bids\n", i + 1, auction.items[i].name, auction.items[i].num_bids);
    }
}

void print_bidders(struct auction auction) {
    printf("Bidders:\n");
    for (int i = 0; i < auction.num_bidders; i++) {
        printf("%d. %s\n", i + 1, auction.bidders[i]);
    }
}

struct bid get_bid(char *bidder_name) {
    struct bid new_bid;
    printf("Enter amount bid by %s: ", bidder_name);
    char input[20];
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &new_bid.amount);
    strcpy(new_bid.bidder_name, bidder_name);
    return new_bid;
}

void add_bid(struct item *item_ptr, struct bid bid) {
    if (bid.amount > item_ptr->current_bid) {
        item_ptr->current_bid = bid.amount;
    }

    if (item_ptr->num_bids >= MAX_BIDS) {
        for (int i = 1; i < MAX_BIDS; i++) {
            item_ptr->bids[i - 1] = item_ptr->bids[i];
        }
        item_ptr->num_bids--;
    }

    item_ptr->bids[item_ptr->num_bids++] = bid;
}