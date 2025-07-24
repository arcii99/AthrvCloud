//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// define constants
#define MAX_AUCTIONS 10
#define MAX_BIDS 100
#define MAX_NAME_LENGTH 25
#define MAX_ITEM_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100
#define AUCTION_TIME 60

// define structs
typedef struct {
    char name[MAX_NAME_LENGTH];
} Bidder;

typedef struct {
    char item[MAX_ITEM_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int num_bidders;
    Bidder bidders[MAX_BIDS];
    float current_bid;
    time_t end_time;
} Auction;

// function prototypes
void print_menu();
void create_auction(Auction auctions[], int *num_auctions);
void join_auction(Auction auctions[], int num_auctions);
void display_auctions(Auction auctions[], int num_auctions);
void auction_menu(Auction *auction);
void place_bid(Auction *auction, Bidder *bidder);
void end_auction(Auction *auction);

int main() {
    // initialize variables
    Auction auctions[MAX_AUCTIONS];
    int num_auctions = 0;
    char input[2];

    // print welcome message and menu
    printf("Welcome to the Digital Auction System!\n\n");
    print_menu();

    // get user input and act accordingly
    while (1) {
        printf("Enter your choice: ");
        fgets(input, 2, stdin);

        switch (atoi(input)) {
            case 1:
                create_auction(auctions, &num_auctions);
                break;
            case 2:
                join_auction(auctions, num_auctions);
                break;
            case 3:
                display_auctions(auctions, num_auctions);
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

// functions

void print_menu() {
    printf("1. Create an auction\n");
    printf("2. Join an auction\n");
    printf("3. Display all auctions\n");
    printf("4. Quit\n\n");
}

void create_auction(Auction auctions[], int *num_auctions) {
    // initialize auction variables
    Auction auction;
    Bidder bidder;
    char input[2];

    // get item and description from user
    printf("Enter the item for auction (max %d characters): ", MAX_ITEM_LENGTH);
    fgets(auction.item, MAX_ITEM_LENGTH, stdin);
    auction.item[strcspn(auction.item, "\n")] = 0;
    printf("Enter the description (max %d characters): ", MAX_DESCRIPTION_LENGTH);
    fgets(auction.description, MAX_DESCRIPTION_LENGTH, stdin);
    auction.description[strcspn(auction.description, "\n")] = 0;

    // add creator as bidder
    printf("Enter your name (max %d characters): ", MAX_NAME_LENGTH);
    fgets(bidder.name, MAX_NAME_LENGTH, stdin);
    bidder.name[strcspn(bidder.name, "\n")] = 0;
    auction.bidders[0] = bidder;
    auction.num_bidders = 1;

    // get starting bid from user
    printf("Enter the starting bid: ");
    scanf("%f", &auction.current_bid);
    while (getchar() != '\n');

    // set end time
    auction.end_time = time(NULL) + AUCTION_TIME;

    // add auction to array
    auctions[*num_auctions] = auction;
    *num_auctions += 1;

    // display auction menu
    auction_menu(&auction);
}

void join_auction(Auction auctions[], int num_auctions) {
    // initialize variables
    Bidder bidder;
    int auction_num;
    char input[2];

    // get bidder name
    printf("Enter your name (max %d characters): ", MAX_NAME_LENGTH);
    fgets(bidder.name, MAX_NAME_LENGTH, stdin);
    bidder.name[strcspn(bidder.name, "\n")] = 0;

    // display auctions and get user input for which auction to join
    display_auctions(auctions, num_auctions);
    printf("Enter the number of the auction you want to join: ");
    fgets(input, 2, stdin);
    auction_num = atoi(input) - 1;

    // check if auction is valid
    if (auction_num < 0 || auction_num >= num_auctions) {
        printf("Invalid auction number!\n");
        return;
    }

    // add bidder to auction
    auctions[auction_num].bidders[auctions[auction_num].num_bidders] = bidder;
    auctions[auction_num].num_bidders += 1;

    // display auction menu
    auction_menu(&auctions[auction_num]);
}

void display_auctions(Auction auctions[], int num_auctions) {
    // print header
    printf("Auctions:\n");
    printf("#  Item                    Description\n");

    // print each auction
    for (int i = 0; i < num_auctions; i++) {
        printf("%-2d %-24s%s\n", i + 1, auctions[i].item, auctions[i].description);
    }

    // print footer
    printf("\n");
}

void auction_menu(Auction *auction) {
    // initialize variables
    Bidder *bidder;
    char input[2];

    // print auction information
    printf("Item: %s\n", auction->item);
    printf("Description: %s\n", auction->description);
    printf("Starting bid: $%.2f\n", auction->current_bid);
    printf("End time: %s", ctime(&auction->end_time));

    // get user input and act accordingly
    while (time(NULL) < auction->end_time) {
        printf("\n");
        printf("1. Place a bid\n");
        printf("2. End auction\n");
        printf("Enter your choice: ");
        fgets(input, 2, stdin);

        switch (atoi(input)) {
            case 1:
                bidder = &auction->bidders[auction->num_bidders - 1];
                place_bid(auction, bidder);
                break;
            case 2:
                end_auction(auction);
                return;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    // if auction ended, end it
    end_auction(auction);
}

void place_bid(Auction *auction, Bidder *bidder) {
    // initialize variable
    float bid;

    // get bid from user
    printf("Enter your bid: ");
    scanf("%f", &bid);
    while (getchar() != '\n');

    // check if bid is higher than current bid
    if (bid <= auction->current_bid) {
        printf("Your bid must be higher than the current bid!\n");
        return;
    }

    // set new current bid and bidder
    auction->current_bid = bid;
    *bidder = auction->bidders[auction->num_bidders - 1];

    // display new current bid
    printf("Current bid: $%.2f\n", auction->current_bid);
}

void end_auction(Auction *auction) {
    // initialize variables
    Bidder *winner = NULL;

    // print winner and winning bid
    printf("Auction ended!\n");
    printf("Item: %s\n", auction->item);
    printf("Description: %s\n", auction->description);
    printf("Starting bid: $%.2f\n", auction->bidders[0].name);
    printf("Winning bidder: ");

    // find winning bidder
    for (int i = 0; i < auction->num_bidders; i++) {
        if (winner == NULL || strcmp(auction->bidders[i].name, winner->name) > 0) {
            winner = &auction->bidders[i];
        }
    }

    // print winner
    printf("%s\n", winner->name);
    printf("Winning bid: $%.2f\n", auction->current_bid);
}