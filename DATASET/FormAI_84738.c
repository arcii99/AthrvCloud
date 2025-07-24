//FormAI DATASET v1.0 Category: Digital Auction System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ITEMS 20
#define MAX_BIDDERS 10

typedef struct {
    char name[50];
    int value;
    int max_bid;
    char highest_bidder[50];
} Item;

void print_items(Item items[], int count) {
    printf("\nCurrent Auction Items:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - Starting value: %d\n", i+1, items[i].name, items[i].value);
    }
}

void print_bidders(char bidders[MAX_BIDDERS][50], int count) {
    printf("\nCurrent Bidders:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i+1, bidders[i]);
    }
}

void handle_bid(Item* item, char bidder[50], int value) {
    if (value > item->max_bid) {
        item->max_bid = value;
        strcpy(item->highest_bidder, bidder);
        printf("\nHighest bid for %s now: %d - Bidder: %s\n", item->name, item->max_bid, item->highest_bidder);
    } else {
        printf("\nBid for %s too low - Current highest bid: %d\n", item->name, item->max_bid);
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed
    Item items[MAX_ITEMS];
    char bidders[MAX_BIDDERS][50];
    int num_bidders = 0;
    int num_items = 0;
    char input[50];
    int item_choice;
    int bidder_choice;
    int bid_value;

    printf("Welcome to the Digital Auction System!\n\n");

    while (1) {
        printf("What would you like to do?\n1. Add item\n2. View items\n3. Add bidder\n4. View bidders\n5. Make bid\n0. Exit\n");
        fgets(input, 50, stdin);
        int choice = atoi(input);
        
        switch (choice) {
            case 1:
                if (num_items >= MAX_ITEMS) {
                    printf("\nMaximum number of items has been reached!\n");
                    break;
                }
                printf("\nEnter item name: ");
                fgets(items[num_items].name, 50, stdin);
                items[num_items].name[strcspn(items[num_items].name, "\n")] = 0; // Remove trailing newline
                items[num_items].value = rand() % 1000; // Generate random starting value
                items[num_items].max_bid = 0;
                num_items++;
                break;
            case 2:
                if (num_items == 0) {
                    printf("\nNo items found!\n");
                    break;
                }
                print_items(items, num_items);
                printf("\nEnter item number to view details (0 to cancel): ");
                fgets(input, 50, stdin);
                item_choice = atoi(input);
                if (item_choice == 0) break;
                item_choice--;
                printf("\nItem: %s\nStarting value: %d\nHighest bid: %d - Bidder: %s\n", items[item_choice].name, items[item_choice].value, items[item_choice].max_bid, items[item_choice].highest_bidder);
                break;
            case 3:
                if (num_bidders >= MAX_BIDDERS) {
                    printf("\nMaximum number of bidders has been reached!\n");
                    break;
                }
                printf("\nEnter bidder name: ");
                fgets(bidders[num_bidders], 50, stdin);
                bidders[num_bidders][strcspn(bidders[num_bidders], "\n")] = 0; // Remove trailing newline
                num_bidders++;
                break;
            case 4:
                if (num_bidders == 0) {
                    printf("\nNo bidders found!\n");
                    break;
                }
                print_bidders(bidders, num_bidders);
                break;
            case 5:
                if (num_items == 0) {
                    printf("\nNo items found!\n");
                    break;
                }
                if (num_bidders == 0) {
                    printf("\nNo bidders found!\n");
                    break;
                }
                print_items(items, num_items);
                printf("\nEnter item number to bid on (0 to cancel): ");
                fgets(input, 50, stdin);
                item_choice = atoi(input);
                if (item_choice == 0) break;
                item_choice--;
                printf("\nEnter bidder number (0 to cancel): ");
                fgets(input, 50, stdin);
                bidder_choice = atoi(input);
                if (bidder_choice == 0) break;
                bidder_choice--;
                printf("\nEnter bid value: ");
                fgets(input, 50, stdin);
                bid_value = atoi(input);
                handle_bid(&items[item_choice], bidders[bidder_choice], bid_value);
                break;
            case 0:
                printf("\nThank you for using the Digital Auction System!\n");
                return 0;
            default:
                printf("\nInvalid input, please try again.\n");
                break;
        }
    }
}