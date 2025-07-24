//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BID_LENGTH 10
#define MAX_USERNAME_LENGTH 20

typedef struct Auction_Item {
    char item_name[50];
    char item_description[100];
    int current_bid;
    char current_winner[MAX_USERNAME_LENGTH];
    int time_remaining;
} Auction_Item;

void print_banner() {
    printf("=================================\n");
    printf("|       CYBERPUNK AUCTIONS      |\n");
    printf("=================================\n\n");
}

void print_item(Auction_Item* item) {
    printf("Item Name: %s\n", item->item_name);
    printf("Description: %s\n", item->item_description);
    printf("Current Highest Bid: %d\n", item->current_bid);
    printf("Current Highest Bidder: %s\n", item->current_winner);
    printf("Time Remaining: %d minutes\n", item->time_remaining);
}

int get_user_bid() {
    char input[MAX_BID_LENGTH];
    printf("Enter your bid: $");
    fgets(input, MAX_BID_LENGTH, stdin);
    return atoi(input);
}

void update_item_bid(Auction_Item* item, char* bidder, int new_bid) {
    item->current_bid = new_bid;
    strcpy(item->current_winner, bidder);
}

void start_auction(Auction_Item* item, int auction_time) {
    time_t start_time, current_time;
    int time_difference;
    char username[MAX_USERNAME_LENGTH];

    time(&start_time);
    current_time = start_time;

    // Auction loop
    while (time_difference < auction_time * 60) {
        print_banner();
        print_item(item);
        printf("\n");

        fgets(username, MAX_USERNAME_LENGTH, stdin);
        int bid = get_user_bid();

        if (bid > item->current_bid) {
            update_item_bid(item, username, bid);
            printf("\nBid accepted!\n");
        } else {
            printf("\nInvalid bid.\n");
        }

        time(&current_time);
        time_difference = (int) difftime(current_time, start_time);
        item->time_remaining = auction_time - (time_difference / 60);

        printf("\nPress enter to continue...\n");
        getchar();
    }

    printf("\nAUCTION OVER!\n\n");
    print_banner();
    print_item(item);
    printf("\n%s won the auction with a bid of $%d!\n", item->current_winner, item->current_bid);
}

int main() {
    Auction_Item item = {
        .item_name = "Cyberdeck",
        .item_description = "The ultimate tool for hacking in the dark cyber alleys.",
        .current_bid = 10,
        .current_winner = "CrimsonShadow",
        .time_remaining = 5
    };

    print_banner();
    printf("Place your username to submit a bid: ");
    start_auction(&item, 5);

    return 0;
}