//FormAI DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_ITEMS 10
#define BIDDING_TIME 10 // in seconds

struct Item {
    int id;
    char name[20];
    int current_bid;
    int highest_bidder;
    int bid_count;
};

void auction(struct Item *items);
void print_items(struct Item *items);
void print_item(struct Item item);
void print_winner(struct Item item);

int main() {
    struct Item items[NUM_ITEMS] = {
        {1, "Painting", 100, -1, 0},
        {2, "Watch", 200, -1, 0},
        {3, "Camera", 300, -1, 0},
        {4, "Guitar", 400, -1, 0},
        {5, "Phone", 500, -1, 0},
        {6, "Laptop", 600, -1, 0},
        {7, "Car", 7000, -1, 0},
        {8, "House", 80000, -1, 0},
        {9, "Jewelry", 9000, -1, 0},
        {10, "Antique", 1000, -1, 0}
    };

    auction(items);

    return 0;
}

void auction(struct Item *items) {
    int i, j, time_left;
    time_t start_time, current_time;
    struct tm * time_info;

    printf("Welcome to the digital auction system!\n\n");
    print_items(items);

    time(&start_time);
    time_left = BIDDING_TIME;
    while (time_left > 0) {
        time(&current_time);
        time_info = localtime(&current_time);
        printf("\nTime left: %d seconds\t\t%s", time_left, asctime(time_info));
        for (i = 0; i < NUM_ITEMS; i++) {
            printf("\n\n%s:\n", items[i].name);
            printf("\tCurrent bid: $%d", items[i].current_bid);
            printf("\tHighest bidder: %d", items[i].highest_bidder);
            printf("\tNumber of bids: %d", items[i].bid_count);
            printf("\n\nEnter your bid for this item (enter -1 to skip): ");
            scanf("%d", &j);
            if (j >= 0 && j > items[i].current_bid) {
                items[i].current_bid = j;
                printf("Congratulations! You are now the highest bidder!\n");
                items[i].highest_bidder = 1;
                items[i].bid_count++;
            } else if (j >= 0) {
                printf("Sorry, your bid is too low. The current bid is $%d.\n", items[i].current_bid);
            }
        }
        time_left = BIDDING_TIME - (current_time - start_time);
    }

    printf("\n\nBidding is over! Here are the winners:");
    for (i = 0; i < NUM_ITEMS; i++) {
        if (items[i].highest_bidder == 1) {
            print_winner(items[i]);
        }
    }
}

void print_items(struct Item *items) {
    int i;
    printf("Items up for auction:\n\n");
    for (i = 0; i < NUM_ITEMS; i++) {
        print_item(items[i]);
    }
}

void print_item(struct Item item) {
    printf("%d. %s\t\t$%d\n", item.id, item.name, item.current_bid);
}

void print_winner(struct Item item) {
    printf("\n%s:\n", item.name);
    printf("\tSold to bidder %d for $%d!\n", item.highest_bidder, item.current_bid);
}