//FormAI DATASET v1.0 Category: Digital Auction System ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct to hold auction item information
typedef struct auction_item
{
    char name[50];
    char description[200];
    double starting_bid;
    double current_bid;
    char highest_bidder[50];
    int time_left;
} auction_item;

// Function to display auction item information
void display_item(auction_item item)
{
    printf("\n%s - Current Bid: %.2f\n", item.name, item.current_bid);
    printf("Description: %s\n", item.description);
    printf("Current Highest Bidder: %s\n", item.highest_bidder);
    printf("Time Left (in minutes): %d\n", item.time_left);
}

// Function to place a bid on an auction item
void place_bid(auction_item *item, char bidder[50], double bid_amount)
{
    if (bid_amount > item->current_bid)
    {
        item->current_bid = bid_amount;
        strcpy(item->highest_bidder, bidder);
        printf("Congratulations! You are now the highest bidder.\n");
    }
    else
    {
        printf("Sorry, your bid must be higher than the current bid.\n");
    }
}

int main()
{
    // Initialize random seed
    srand(time(0));

    // Array of sample auction items
    auction_item items[3];

    // Set item information
    strcpy(items[0].name, "Vintage Rolex");
    strcpy(items[0].description, "A classic timepiece from the 1960s");
    items[0].starting_bid = 5000.00;
    items[0].current_bid = items[0].starting_bid;
    strcpy(items[0].highest_bidder, "");
    items[0].time_left = rand() % 60 + 1;

    strcpy(items[1].name, "Diamond Necklace");
    strcpy(items[1].description, "14k white gold necklace with diamond pendant");
    items[1].starting_bid = 10000.00;
    items[1].current_bid = items[1].starting_bid;
    strcpy(items[1].highest_bidder, "");
    items[1].time_left = rand() % 60 + 1;

    strcpy(items[2].name, "Limited Edition Artwork");
    strcpy(items[2].description, "Signed and numbered lithograph by famous artist");
    items[2].starting_bid = 7500.00;
    items[2].current_bid = items[2].starting_bid;
    strcpy(items[2].highest_bidder, "");
    items[2].time_left = rand() % 60 + 1;

    // Display auction item information
    printf("Welcome to the digital auction!\n");
    int choice;
    do
    {
        printf("\nPlease select an item to bid on:\n");
        for (int i = 0; i < 3; i++)
        {
            printf("%d. %s\n", i + 1, items[i].name);
        }
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                display_item(items[0]);
                printf("Please enter your name: ");
                char bidder[50];
                scanf("%s", bidder);
                printf("Please enter your bid: ");
                double bid;
                scanf("%lf", &bid);
                place_bid(&items[0], bidder, bid);
                break;
            case 2:
                display_item(items[1]);
                printf("Please enter your name: ");
                scanf("%s", bidder);
                printf("Please enter your bid: ");
                scanf("%lf", &bid);
                place_bid(&items[1], bidder, bid);
                break;
            case 3:
                display_item(items[2]);
                printf("Please enter your name: ");
                scanf("%s", bidder);
                printf("Please enter your bid: ");
                scanf("%lf", &bid);
                place_bid(&items[2], bidder, bid);
                break;
            case 4:
                printf("Thank you for participating in our auction!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}