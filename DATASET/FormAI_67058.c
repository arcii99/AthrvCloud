//FormAI DATASET v1.0 Category: Digital Auction System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// Define Item struct
struct Item {
    char name[50];
    int price;
};

// Define Bid struct
struct Bid {
    char name[50];
    int amount;
};

// Define Auction struct
struct Auction {
    struct Item item;
    struct Bid highest_bid;
    bool sold;
};

// Function to generate random integer within range
int generate_random(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to display auction details
void display_auction(struct Auction auction) {
    printf("%s\n", auction.item.name);
    printf("Current Highest Bid: %d\n", auction.highest_bid.amount);
    printf("Sold: %s\n", auction.sold ? "Yes" : "No");
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create Item objects
    struct Item items[5];
    strcpy(items[0].name, "Scrap Metal");
    items[0].price = generate_random(10, 20);
    strcpy(items[1].name, "Gasoline");
    items[1].price = generate_random(30, 40);
    strcpy(items[2].name, "Ammo");
    items[2].price = generate_random(50, 60);
    strcpy(items[3].name, "Water");
    items[3].price = generate_random(70, 80);
    strcpy(items[4].name, "Food");
    items[4].price = generate_random(90, 100);

    // Create Auction objects
    struct Auction auctions[5];
    for(int i = 0; i < 5; i++) {
        auctions[i].item = items[i];
        auctions[i].highest_bid.amount = generate_random(5, 15);
        auctions[i].sold = false;
    }

    // Start bidding
    while(true) {
        // Display available auctions
        printf("Available auctions:\n");
        for(int i = 0; i < 5; i++) {
            if(!auctions[i].sold) {
                printf("%d. ", i + 1);
                display_auction(auctions[i]);
            }
        }

        // Get user input for auction selection
        int choice;
        printf("\nEnter auction number to bid on (-1 to quit): ");
        scanf("%d", &choice);

        if(choice == -1) {
            break;
        }

        // Validate user input
        if(choice < 1 || choice > 5) {
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
            continue;
        }

        // Get user input for bid amount
        int amount;
        printf("Enter bid amount: ");
        scanf("%d", &amount);

        // Validate bid
        if(amount < auctions[choice-1].highest_bid.amount + 1) {
            printf("Bid amount must be greater than current highest bid.\n");
            continue;
        }

        // Update highest bid
        strcpy(auctions[choice-1].highest_bid.name, "Player");
        auctions[choice-1].highest_bid.amount = amount;

        // Check if item is sold
        if(auctions[choice-1].highest_bid.amount >= auctions[choice-1].item.price) {
            auctions[choice-1].sold = true;
            printf("Congratulations! You won the auction for %s.\n", auctions[choice-1].item.name);
            printf("Total amount paid: %d\n", auctions[choice-1].highest_bid.amount);
        } else {
            printf("Bid accepted for %s.\n", auctions[choice-1].item.name);
            printf("Current highest bid: %d\n", auctions[choice-1].highest_bid.amount);
        }
    }

    return 0;
}