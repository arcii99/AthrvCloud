//FormAI DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item {
    char name[50];
    int start_bid;
    int current_bid;
    char bidder[50];
};

int main() {
    int num_items;
    printf("Welcome to the Digital Auction System!\n");
    printf("How many items do you want to auction?\n");
    scanf("%d", &num_items);

    struct Item items[num_items];

    int i;
    for (i = 0; i < num_items; i++) {
        printf("Enter the name of item #%d\n", i+1);
        scanf("%s", items[i].name);

        printf("Enter the starting bid for %s\n", items[i].name);
        scanf("%d", &items[i].start_bid);

        items[i].current_bid = items[i].start_bid;
        strcpy(items[i].bidder, "");
    }

    printf("--------------------\n");
    printf("Auction has started!\n");
    printf("--------------------\n");

    int num_bids = 0;
    while (num_bids < num_items) {
        int choice;
        printf("Which item do you want to bid on? (Enter 0 to exit)\n");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }

        printf("Enter your bid:\n");
        int bid;
        scanf("%d", &bid);

        if (bid > items[choice-1].current_bid) {
            items[choice-1].current_bid = bid;
            printf("Congratulations! You are the new highest bidder for %s with a bid of %d.\n", items[choice-1].name, bid);
            printf("--------------------\n");
            printf("Highest bid for %s is now %d.\n", items[choice-1].name, items[choice-1].current_bid);
            printf("--------------------\n");

            printf("Enter your name:\n");
            scanf("%s", items[choice-1].bidder);
        }
        else {
            printf("Your bid is not higher than the current highest bid for %s.\n", items[choice-1].name);
            printf("--------------------\n");
            printf("Highest bid for %s is still %d.\n", items[choice-1].name, items[choice-1].current_bid);
            printf("--------------------\n");
        }
        num_bids++;
    }

    printf("--------------------\n");
    printf("Auction has ended!\n");
    printf("--------------------\n");

    printf("Results:\n");
    for (i = 0; i < num_items; i++) {
        printf("%s was sold for %d to %s.\n", items[i].name, items[i].current_bid, items[i].bidder);
    }

    return 0;
}