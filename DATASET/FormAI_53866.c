//FormAI DATASET v1.0 Category: Digital Auction System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//structure to store details of each auction item
struct Item {
    int item_id;
    char item_name[50];
    char item_description[100];
    float starting_bid;
    int minimum_increment;
    float current_bid;
    int bidding_open;
    int bidder_id;
};

struct Item auction_items[10];//maximum 10 items can be auctioned

//initialize auction_items array
void init_items() {
    for(int i = 0; i < 10; i++) {
        auction_items[i].item_id = i+1;
        sprintf(auction_items[i].item_name,"Item %d",i+1);
        sprintf(auction_items[i].item_description,"Description of item %d",i+1);
        auction_items[i].starting_bid = 100.0*(i+1);
        auction_items[i].minimum_increment = 10*(i+1);
        auction_items[i].current_bid = 0.0;
        auction_items[i].bidding_open = 0;
        auction_items[i].bidder_id = -1;
    }
}

//function to display details of a single item
void display_item(struct Item item) {
    printf("Item ID: %d\n",item.item_id);
    printf("Item Name: %s\n",item.item_name);
    printf("Item Description: %s\n",item.item_description);
    printf("Starting Bid: %.2f\n",item.starting_bid);
    printf("Minimum Increment: %d\n",item.minimum_increment);
    printf("Current Bid: %.2f\n",item.current_bid);
    if(item.bidding_open == 0) {
        printf("Bidding is not open for this item\n");
    }
    else {
        printf("Bidding is open for this item\n");
    }
    if(item.bidder_id == -1) {
        printf("No bids for this item yet\n");
    }
    else {
        printf("Highest Bidder: Bidder %d\n",item.bidder_id);
    }
    printf("-------------------------------------\n");
}

//function to display details of all auction items
void display_items() {
    for(int i = 0; i < 10; i++) {
        display_item(auction_items[i]);
    }
}

//function to open bidding for a particular item
void open_bidding(int item_id) {
    auction_items[item_id-1].bidding_open = 1;
}

//function to close bidding for a particular item
void close_bidding(int item_id) {
    auction_items[item_id-1].bidding_open = 0;
}

//function to place a bid on a particular item
void place_bid(int item_id, int bidder_id, float bid_amount) {
    float current_bid = auction_items[item_id-1].current_bid;
    int minimum_increment = auction_items[item_id-1].minimum_increment;
    if(bid_amount > current_bid && (bid_amount-current_bid) >= minimum_increment) {
        auction_items[item_id-1].current_bid = bid_amount;
        auction_items[item_id-1].bidder_id = bidder_id;
        printf("Bid of %.2f accepted for Item %d by Bidder %d\n",bid_amount,item_id,bidder_id);
    }
    else {
        printf("Bid of %.2f not accepted for Item %d by Bidder %d\n",bid_amount,item_id,bidder_id);
    }
}

int main() {
    init_items();//initialize auction items
    int choice;
    printf("Welcome to the Digital Auction System!\n");
    do {
        printf("Menu:\n");
        printf("1. Display all items\n");
        printf("2. Open bidding for an item\n");
        printf("3. Close bidding for an item\n");
        printf("4. Place bid for an item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                display_items();//display all items
                break;
            case 2:
                {
                    int item_id;
                    printf("Enter item ID to open bidding: ");
                    scanf("%d",&item_id);
                    open_bidding(item_id);//open bidding for specified item
                }
                break;
            case 3:
                {
                    int item_id;
                    printf("Enter item ID to close bidding: ");
                    scanf("%d",&item_id);
                    close_bidding(item_id);//close bidding for specified item
                }
                break;
            case 4:
                {
                    int item_id, bidder_id;
                    float bid_amount;
                    printf("Enter item ID to place bid: ");
                    scanf("%d",&item_id);
                    printf("Enter bidder ID: ");
                    scanf("%d",&bidder_id);
                    printf("Enter bid amount: ");
                    scanf("%f",&bid_amount);
                    place_bid(item_id,bidder_id,bid_amount);//place bid for specified item by specified bidder
                    break;
                }
            case 5:
                printf("Thank you for using the Digital Auction System!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 5);//continue menu until user chooses to exit
    return 0;
}