//FormAI DATASET v1.0 Category: Digital Auction System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct auction_item {
    int item_id;
    char item_name[50];
    float start_price;
    float current_bid;
    char bidder_name[50];
    bool is_sold;
} AuctionItem;

int main() {
    AuctionItem items[10];
    int num_items = 0;

    while (true) {
        int choice;

        printf("\nAuction System\n");
        printf("1. Add Item\n");
        printf("2. View Items\n");
        printf("3. Place Bid\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_items == 10) {
                    printf("Maximum items reached. Cannot add more items.\n");
                    break;
                } else {
                    AuctionItem new_item;
                    printf("Enter Item ID: ");
                    scanf("%d", &new_item.item_id);
                    printf("Enter Item Name: ");
                    scanf("%s", new_item.item_name);
                    printf("Enter Starting Price: ");
                    scanf("%f", &new_item.start_price);

                    new_item.current_bid = 0.0;
                    strncpy(new_item.bidder_name, "No bids yet", 50);
                    new_item.is_sold = false;

                    items[num_items++] = new_item;
                    printf("Item added successfully.\n");
                    break;
                }

            case 2:
                printf("\nItem ID\tItem Name\tStarting Price\tCurrent Bid\tBidder Name\tSold?\n");
                printf("----------------------------------------------------------------------------------\n");
                for (int i = 0; i < num_items; i++) {
                    printf("%d\t%s\t%.2f\t%.2f\t%s\t%s\n",
                           items[i].item_id, items[i].item_name, items[i].start_price, items[i].current_bid,
                           items[i].bidder_name, items[i].is_sold ? "Yes" : "No");
                }
                break;

            case 3:
                int item_id;
                printf("Enter Item ID: ");
                scanf("%d", &item_id);

                int item_index = -1;
                for (int i = 0; i < num_items; i++) {
                    if (items[i].item_id == item_id) {
                        item_index = i;
                        break;
                    }
                }

                if (item_index == -1) {
                    printf("Invalid Item ID.\n");
                } else {
                    printf("Enter Bid Amount: ");
                    float bid_amount;
                    scanf("%f", &bid_amount);

                    if (bid_amount <= items[item_index].current_bid) {
                        printf("Bid amount should be higher than the current bid.\n");
                    } else {
                        strncpy(items[item_index].bidder_name, "Anonymous", 50);
                        items[item_index].current_bid = bid_amount;
                        printf("Bid placed successfully.\n");
                    }
                }
                break;

            case 4:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }

    return 0;
}