//FormAI DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

//Define the maximum number of bids allowed for an auction
#define MAX_BIDS 10 
//Maximum length of the item name
#define ITEM_NAME_LENGTH 50

//Define a struct for the bid
typedef struct Bid{
    char bidder_name[50];
    float bid_amount;
} Bid;

//Define a struct for the auction item
typedef struct AuctionItem{
    char name[ITEM_NAME_LENGTH];
    float starting_price;
    Bid bids[MAX_BIDS]; 
    int num_bids;
    Bid highest_bid;
} AuctionItem;

//Function to add a bid to an auction item
void bid_on_item(AuctionItem* item, char* bidder_name, float bid_amount){
    if(item->num_bids == MAX_BIDS){
        printf("Bidding limit for this item has been reached\n");
        return;
    }
    Bid new_bid;
    new_bid.bid_amount = bid_amount;
    strcpy(new_bid.bidder_name, bidder_name);
    item->bids[item->num_bids++] = new_bid;
    if(bid_amount > item->highest_bid.bid_amount){
        item->highest_bid = new_bid;
    }
    printf("Added a bid of %.2f from %s to %s\n", bid_amount, bidder_name, item->name);
}

//Function to print the auction item details
void print_item(AuctionItem* item){
    printf("%s (starting price: %.2f)\n", item->name, item->starting_price);
    printf("%d bids:\n", item->num_bids);
    for(int i=0; i<item->num_bids; i++){
        printf("- %.2f from %s\n", item->bids[i].bid_amount, item->bids[i].bidder_name);
    }
    printf("Highest bid: %.2f from %s\n", item->highest_bid.bid_amount, item->highest_bid.bidder_name);
}

int main(){
    //Create an auction item to sell
    AuctionItem item_to_sell;
    strcpy(item_to_sell.name, "Vintage LP Record Collection");
    item_to_sell.starting_price = 1000.00;
    item_to_sell.num_bids = 0;

    //Print the item details
    print_item(&item_to_sell);

    //Attempt to bid on the item
    bid_on_item(&item_to_sell, "John Smith", 1200.00);
    bid_on_item(&item_to_sell, "Jane Doe", 1500.00);

    //Print the updated item details
    print_item(&item_to_sell);

    return 0;
}