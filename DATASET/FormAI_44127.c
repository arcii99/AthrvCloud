//FormAI DATASET v1.0 Category: Digital Auction System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    int item_id;
    char item_name[50];
    double highest_bid;
    char highest_bidder[50];
    int bidder_count;
} Item;

void display_item(Item item);
void display_items(Item items[], int array_size);
void bid_on_item(Item *item, double bid, char *bidder_name);

int main() {
    int item_count;
    printf("How many items are up for auction? ");
    scanf("%d", &item_count);
    Item *items = (Item*) malloc(sizeof(Item) * item_count);

    for (int i = 0; i < item_count; i++) {
        printf("Enter details for item #%d\n", i+1);
        printf("Item ID: ");
        scanf("%d", &items[i].item_id);
        printf("Item Name: ");
        scanf(" %[^\n]s", items[i].item_name);
        items[i].highest_bid = 0;
        strcpy(items[i].highest_bidder, "None");
        items[i].bidder_count = 0;
        printf("\n");
    }

    int user_choice = 0;
    while (user_choice != 4) {
        printf("\nWhat would you like to do?\n");
        printf("1. See list of items\n");
        printf("2. Place a bid\n");
        printf("3. See details of an item\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &user_choice);
        printf("\n");

        switch (user_choice) {
            case 1:
                display_items(items, item_count);
                break;
            case 2:
                int item_id;
                double bid;
                char bidder_name[50];
                printf("Enter item ID: ");
                scanf("%d", &item_id);
                printf("Enter bid amount: ");
                scanf("%lf", &bid);
                printf("Enter your name: ");
                scanf(" %[^\n]s", bidder_name);
                printf("\n");

                if (item_id < 1 || item_id > item_count) {
                    printf("Invalid Item ID\n");
                    break;
                } else {
                    bid_on_item(&items[item_id-1], bid, bidder_name);
                }
                break;
            case 3:
                int item_choice;
                printf("Enter item ID: ");
                scanf("%d", &item_choice);
                printf("\n");

                if (item_choice < 1 || item_choice > item_count) {
                    printf("Invalid Item ID\n");
                    break;
                } else {
                    display_item(items[item_choice-1]);
                }
                break;
            case 4:
                printf("Thank you for using our auction system!\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    free(items);

    return 0;
}

void display_item(Item item) {
    printf("Item ID: %d\n", item.item_id);
    printf("Item Name: %s\n", item.item_name);
    printf("Highest Bid: %.2lf\n", item.highest_bid);
    printf("Highest Bidder: %s\n", item.highest_bidder);
    printf("Bidder Count: %d\n", item.bidder_count);
}

void display_items(Item items[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        display_item(items[i]);
        printf("\n");
    }
}

void bid_on_item(Item *item, double bid, char *bidder_name) {
    if (bid <= item->highest_bid) {
        printf("Bid amount must be higher than the current highest bid.\n");
        return;
    }

    item->highest_bid = bid;
    strcpy(item->highest_bidder, bidder_name);
    item->bidder_count++;

    printf("Bid successful!\n");
}