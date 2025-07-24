//FormAI DATASET v1.0 Category: Digital Auction System ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BIDDERS 50
#define MAX_ITEMS 20

struct item_info{
    char item_name[20];
    int base_price;
};

struct bid_info{
    char bidder_name[20];
    int bid_amount;
};

struct auction_info{
    struct item_info item;
    struct bid_info bids[MAX_BIDDERS];
    int current_bid_index;
};

struct auction_info auctions[MAX_ITEMS]; //array of auctions
int total_auctions = 0;

void setup_auction(){
    printf("Setting up new auction...\n");
    printf("Enter item name: ");
    scanf("%s", auctions[total_auctions].item.item_name);
    printf("Enter base price: ");
    scanf("%d", &auctions[total_auctions].item.base_price);
    auctions[total_auctions].current_bid_index = -1;
    printf("%s is up for auction with a base price of %d.\n", auctions[total_auctions].item.item_name, auctions[total_auctions].item.base_price);
    total_auctions++;
}

void place_bid(){
    int auction_index;
    printf("Enter the index of the auction you want to bid on: ");
    scanf("%d", &auction_index);
    if(auction_index >= total_auctions){
        printf("Invalid auction index.\n");
        return;
    }
    struct auction_info* current_auction = &auctions[auction_index];
    current_auction->current_bid_index++;
    printf("Enter your name: ");
    scanf("%s", current_auction->bids[current_auction->current_bid_index].bidder_name);
    printf("Enter your bid amount: ");
    scanf("%d", &current_auction->bids[current_auction->current_bid_index].bid_amount);
    printf("Bid placed! %s has bid %d on %s.\n", current_auction->bids[current_auction->current_bid_index].bidder_name, current_auction->bids[current_auction->current_bid_index].bid_amount, current_auction->item.item_name);
}

void display_auctions(){
    printf("Current auctions:\n");
    for(int i=0; i<total_auctions; i++){
        printf("[%d] %s (base price: %d)\n", i, auctions[i].item.item_name, auctions[i].item.base_price);
    }
}

void display_bids(){
    int auction_index;
    printf("Enter the index of the auction you want to view bids for: ");
    scanf("%d", &auction_index);
    if(auction_index >= total_auctions){
        printf("Invalid auction index.\n");
        return;
    }
    struct auction_info* current_auction = &auctions[auction_index];
    printf("Bids for %s:\n", current_auction->item.item_name);
    for(int i=0; i<=current_auction->current_bid_index; i++){
        printf("%s - %d\n", current_auction->bids[i].bidder_name, current_auction->bids[i].bid_amount);
    }
}

void end_auction(){
    int auction_index;
    printf("Enter the index of the auction you want to end: ");
    scanf("%d", &auction_index);
    if(auction_index >= total_auctions){
        printf("Invalid auction index.\n");
        return;
    }
    struct auction_info* current_auction = &auctions[auction_index];
    if(current_auction->current_bid_index == -1){
        printf("No bids were placed on %s.\n", current_auction->item.item_name);
        return;
    }
    struct bid_info* winning_bid = &current_auction->bids[0];
    for(int i=1; i<=current_auction->current_bid_index; i++){
        if(current_auction->bids[i].bid_amount > winning_bid->bid_amount){
            winning_bid = &current_auction->bids[i];
        }
    }
    printf("The winner of the auction of %s is %s with a bid of %d!\n", current_auction->item.item_name, winning_bid->bidder_name, winning_bid->bid_amount);
    printf("The base price was %d.\n", current_auction->item.base_price);
    printf("The final price is %d.\n", winning_bid->bid_amount);
}

int main(){
    srand(time(0));
    printf("Welcome to the post-apocalyptic auction system!\n");
    while(1){
        printf("\nSelect an option:\n");
        printf("[1] Set up new auction\n");
        printf("[2] Place bid\n");
        printf("[3] Display auctions\n");
        printf("[4] Display bids for an auction\n");
        printf("[5] End auction\n");
        printf("[6] Quit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                setup_auction();
                break;
            case 2:
                place_bid();
                break;
            case 3:
                display_auctions();
                break;
            case 4:
                display_bids();
                break;
            case 5:
                end_auction();
                break;
            case 6:
                printf("Thanks for using the post-apocalyptic auction system!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}