//FormAI DATASET v1.0 Category: Digital Auction System ; Style: real-life
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 

// Structure to store the item details
struct Item {
    int id;
    char name[50];
    char description[256];
    float initial_price;
    float current_price;
    char seller_name[50];
    char bidder_name[50];
    int minutes_remaining;
    int seconds_remaining;
};

// Function to display the item details
void display_item(struct Item item) {
    printf("ID: %d\n", item.id);
    printf("Name: %s\n", item.name);
    printf("Description: %s\n", item.description);
    printf("Initial Price: %.2f\n", item.initial_price);
    printf("Current Price: %.2f\n", item.current_price);
    printf("Seller Name: %s\n", item.seller_name);
    printf("Bidder Name: %s\n", item.bidder_name);
    printf("Time Remaining: %d:%d\n", item.minutes_remaining, item.seconds_remaining);
}

// Function to get the current time
time_t get_current_time() {
    time_t current_time;
    time(&current_time);
    return current_time;
}

int main() {
    // Initializing the items
    struct Item item1 = {1, "Smartphone", "Brand new smartphone", 200.00, 200.00, "John Doe", "", 5, 0};
    struct Item item2 = {2, "Laptop", "High-end gaming laptop", 1000.00, 1000.00, "Jane Doe", "", 10, 0};
    struct Item item3 = {3, "Car", "Luxury car in mint condition", 50000.00, 50000.00, "Bob Smith", "", 15, 0};

    struct Item auction_items[3] = {item1, item2, item3};

    // Randomly selecting the starting bidder
    srand(time(NULL));
    int starting_bidder_index = rand() % 3;
    strcpy(auction_items[starting_bidder_index].bidder_name, "Current Leader");

    int items_remaining = 3;
    int current_item_index = 0;
    time_t start_time = get_current_time();
    time_t current_time = start_time;

    // Running the auction
    while(items_remaining > 0) {
        // Checking if the current item's time has expired
        if(difftime(current_time, start_time) >= auction_items[current_item_index].minutes_remaining * 60 + auction_items[current_item_index].seconds_remaining) {
            // Displaying the winning bidder
            printf("The winning bidder for %s is %s with a bid of %.2f\n", auction_items[current_item_index].name, auction_items[current_item_index].bidder_name, auction_items[current_item_index].current_price);

            // Removing the item from the list of items remaining
            for(int i = current_item_index; i < items_remaining - 1; i++) {
                auction_items[i] = auction_items[i + 1];
            }

            items_remaining--;
        } else {
            // Displaying the current item details
            printf("\n");
            display_item(auction_items[current_item_index]);

            // Asking for a bid
            printf("Enter your bid: ");
            float bid;
            scanf("%f", &bid);

            // Checking if the bid is greater than the current price
            if(bid > auction_items[current_item_index].current_price) {
                strcpy(auction_items[current_item_index].bidder_name, "You");
                auction_items[current_item_index].current_price = bid;

                // Randomly selecting the next item to be auctioned
                srand(time(NULL));
                current_item_index = rand() % items_remaining;

                // Updating the remaining time of the current item
                time_t time_elapsed = difftime(current_time, start_time);
                auction_items[current_item_index].minutes_remaining = auction_items[current_item_index].minutes_remaining - time_elapsed / 60;
                auction_items[current_item_index].seconds_remaining = auction_items[current_item_index].seconds_remaining - time_elapsed % 60;

                // Updating the starting time for the next item
                start_time = get_current_time();

                // Randomly selecting the starting bidder for the next item
                starting_bidder_index = rand() % 3;
                strcpy(auction_items[starting_bidder_index].bidder_name, "Current Leader");
            }
        }

        current_time = get_current_time();
    }

    printf("\nThe auction has ended!");

    return 0;
}