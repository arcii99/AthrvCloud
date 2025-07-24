//FormAI DATASET v1.0 Category: Digital Auction System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BIDS 10

/* structure to hold a bid */
typedef struct Bid {
    int bid_id;
    char bidder[50];
    float amount;
} Bid;

/* function to display the menu */
void display_menu() {
    printf("Welcome to the Digital Auction System\n");
    printf("------------------------------------\n");
    printf("1. Display current bids\n");
    printf("2. Add a new bid\n");
    printf("3. Remove a bid\n");
    printf("4. Exit\n");
}

int main() {
    Bid bids[MAX_BIDS];
    int num_bids = 0;
    int option;

    /* loop through the menu until the user chooses to exit */
    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Current Bids:\n");
                printf("--------------\n");
                for (int i = 0; i < num_bids; i++) {
                    printf("Bid ID: %d\n", bids[i].bid_id);
                    printf("Bidder: %s\n", bids[i].bidder);
                    printf("Amount: $%.2f\n", bids[i].amount);
                    printf("\n");
                }
                break;
            case 2:
                /* check if there is space in the bids array */
                if (num_bids == MAX_BIDS) {
                    printf("Sorry, no more bids can be added.\n");
                    break;
                }
                /* get input for the new bid */
                Bid new_bid;
                new_bid.bid_id = num_bids + 1;
                printf("Enter bidder name: ");
                scanf("%s", new_bid.bidder);
                printf("Enter bid amount: $");
                scanf("%f", &new_bid.amount);
                /* add the new bid to the bids array */
                bids[num_bids] = new_bid;
                num_bids++;
                printf("Bid successfully added!\n");
                break;
            case 3:
                /* get input for the bid to remove */
                int remove_id;
                printf("Enter the bid ID to remove: ");
                scanf("%d", &remove_id);
                /* loop through the bids array to find the bid to remove */
                int found_bid = 0;
                for (int i = 0; i < num_bids; i++) {
                    if (bids[i].bid_id == remove_id) {
                        found_bid = 1;
                        /* shift all bids after the removed bid back by one */
                        for (int j = i; j < num_bids - 1; j++) {
                            bids[j] = bids[j+1];
                        }
                        num_bids--;
                        printf("Bid %d successfully removed!\n", remove_id);
                        break;
                    }
                }
                if (!found_bid) {
                    printf("Bid %d not found.\n", remove_id);
                }
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}