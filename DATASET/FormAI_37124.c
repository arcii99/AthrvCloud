//FormAI DATASET v1.0 Category: Digital Auction System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure for each item being auctioned
struct auctionItem {
    char name[50];
    float startingPrice;
    float currentPrice;
    float bidIncrement;
    int timeLeft;
    int bids;
    char highestBidder[50];
};

// Function to get valid input from user
float getFloatInput() {
    char input[50];
    float output;
    int valid = 0;
    while (!valid) {
        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%f", &output) == 1) {
            valid = 1;
        } else {
            printf("Invalid input, please enter a valid number:\n");
        }
    }
    return output;
}

// Function to print all current auction items
void printAuctionItems(struct auctionItem items[], int numItems) {
    printf("--------------------------------------------------------\n");
    printf("Name\t\tStarting Price\tCurrent Price\tTime Left\tBids\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s\t\t%.2f\t\t%.2f\t\t%d\t\t%d\n", items[i].name, items[i].startingPrice, items[i].currentPrice, items[i].timeLeft, items[i].bids);
    }
    printf("--------------------------------------------------------\n");
}

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Initialize array of auction items
    struct auctionItem items[5] = {
            {"Painting", 50.00, 50.00, 5.00, 60, 0, ""},
            {"Baseball", 10.00, 10.00, 1.00, 120, 0, ""},
            {"Laptop", 500.00, 500.00, 50.00, 30, 0, ""},
            {"Watch", 100.00, 100.00, 10.00, 90, 0, ""},
            {"Car", 1000.00, 1000.00, 100.00, 10, 0, ""}
    };

    int numItems = sizeof (items) / sizeof (items[0]);

    printf("Welcome to the Digital Auction System\n");

    while (1) {
        // Print all current auction items
        printAuctionItems(items, numItems);

        // Get user input for item to bid on
        printf("Enter item name to bid on:\n");
        char itemToBidOn[50];
        fgets(itemToBidOn, sizeof(itemToBidOn), stdin);
        // Remove newline character from input
        int len = strlen(itemToBidOn);
        if (itemToBidOn[len - 1] == '\n') {
            itemToBidOn[len - 1] = '\0';
        }

        // Find item in array
        int itemIndex = -1;
        for (int i = 0; i < numItems; i++) {
            if (strcmp(items[i].name, itemToBidOn) == 0) {
                itemIndex = i;
                break;
            }
        }

        // If item was found
        if (itemIndex != -1) {
            // Check if time is left for auction
            if (items[itemIndex].timeLeft > 0) {
                // Get user bid
                printf("Enter bid amount for %s:\n", items[itemIndex].name);
                float userBid = getFloatInput();

                // Check bid amount is a valid increment
                if (userBid >= items[itemIndex].currentPrice + items[itemIndex].bidIncrement) {
                    // Update item information
                    strcpy(items[itemIndex].highestBidder, "You");
                    items[itemIndex].currentPrice = userBid;
                    items[itemIndex].bids++;
                    // Randomly decrease time left for auction
                    int timeDecrease = (rand() % 10) + 1;
                    items[itemIndex].timeLeft -= timeDecrease;

                    printf("Bid for %s accepted.\n", items[itemIndex].name);
                } else {
                    printf("Bid amount is not a valid increment.\n");
                }
            } else {
                printf("Auction for %s has ended.\n", items[itemIndex].name);
            }
        } else {
            printf("Item not found.\n");
        }
    }

    return 0;
}