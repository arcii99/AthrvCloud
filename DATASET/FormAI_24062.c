//FormAI DATASET v1.0 Category: Digital Auction System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct auction {
    char item[50];
    int seller_id;
    int current_bid;
    int bidder_id;
    int time_left;
};

int main() {
    struct auction item_list[10];
    int choice, seller_id_count = 1, bidder_id_count = 1, bidder_choice, auction_id, place_bid;
    srand(time(0)); // to generate random time left for the auction

    // initializing item_list array with default values
    for(int i = 0; i < 10; i++) {
        strcpy(item_list[i].item, "New Item");
        item_list[i].seller_id = 0;
        item_list[i].current_bid = 0;
        item_list[i].bidder_id = 0;
        item_list[i].time_left = 0;
    }

    while(1) {
        printf("\n------------------ AUCTION SYSTEM ------------------\n");
        printf("1. New Seller\n2. New Bidder\n3. List Items\n4. Auction Details\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                for(int i = 0; i < 10; i++) {
                    if(item_list[i].seller_id == 0) {
                        item_list[i].seller_id = seller_id_count++;
                        printf("Enter item name for the auction: ");
                        scanf("%s", item_list[i].item);
                        item_list[i].time_left = rand() % 10 + 1; // random time between 1 and 10 minutes
                        printf("Item %s added for auction with %d minutes left.\n", item_list[i].item, item_list[i].time_left);
                        break;
                    }
                }
                break;
            case 2:
                printf("Enter your bidder ID: ");
                scanf("%d", &bidder_choice);
                for(int i = 0; i < 10; i++) {
                    if(item_list[i].seller_id != 0 && item_list[i].bidder_id == 0 && bidder_choice != item_list[i].seller_id) {
                        item_list[i].bidder_id = bidder_choice;
                        printf("You are now bidding for item %s with current bid of %d.\n", item_list[i].item, item_list[i].current_bid);
                        break;
                    }
                    else if(i == 9) {
                        printf("All items are either sold or bidder limit reached.\n");
                    }
                }
                break;
            case 3:
                printf("Seller ID\tItem Name\tCurrent Bid\tBidder ID\tTime Left\n");
                for(int i = 0; i < 10; i++) {
                    if(item_list[i].seller_id != 0) {
                        printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n", item_list[i].seller_id, item_list[i].item, item_list[i].current_bid, item_list[i].bidder_id, item_list[i].time_left);
                    }
                }
                break;
            case 4:
                printf("Enter item ID for auction details: ");
                scanf("%d", &auction_id);
                for(int i = 0; i < 10; i++) {
                    if(item_list[i].seller_id == auction_id) {
                        if(item_list[i].current_bid == 0) {
                            printf("No bids for item %s yet.\n", item_list[i].item);
                            break;
                        }
                        printf("Current bid for item %s is %d by bidder %d with %d minutes left.\n", item_list[i].item, item_list[i].current_bid, item_list[i].bidder_id, item_list[i].time_left);
                        printf("Do you want to place a bid? (1 for yes / 0 for no) ");
                        scanf("%d", &place_bid);
                        if(place_bid == 1) {
                            printf("Enter your bid: ");
                            scanf("%d", &item_list[i].current_bid);
                            item_list[i].bidder_id = bidder_id_count++;
                            printf("Bid of %d for item %s placed by bidder %d.\n", item_list[i].current_bid, item_list[i].item, item_list[i].bidder_id);
                        }
                        break;
                    }
                    else if(i == 9) {
                        printf("Invalid item ID.\n");
                    }
                }
                break;
            case 5:
                printf("Thanks for using the auction system.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}