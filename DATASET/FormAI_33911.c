//FormAI DATASET v1.0 Category: Digital Auction System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_ITEM_DESC_LEN 50
#define MAX_ITEMS 10
#define MAX_BIDDERS 10

// Item struct
typedef struct item {
    char desc[MAX_ITEM_DESC_LEN];
    int curr_bid;
    pthread_mutex_t lock;
} Item;

// Bidder struct
typedef struct bidder {
    char name[20];
    int num_bids;
    int item_num;
    int bid_val;
} Bidder;

// Global variables
Item items[MAX_ITEMS];
int num_items;
Bidder bidders[MAX_BIDDERS];
int num_bidders;
pthread_mutex_t bidders_lock = PTHREAD_MUTEX_INITIALIZER;

// Helper function to add a bidder
void add_bidder(char *name) {
    pthread_mutex_lock(&bidders_lock);
    bidders[num_bidders].item_num = -1;
    bidders[num_bidders].num_bids = 0;
    bidders[num_bidders].bid_val = 0;
    strcpy(bidders[num_bidders].name, name);
    num_bidders++;
    printf("Added bidder: %s\n", name);
    pthread_mutex_unlock(&bidders_lock);
}

// Helper function to retrieve a bidder by name
Bidder *get_bidder(char *name) {
    for (int i = 0; i < num_bidders; i++) {
        if (strcmp(bidders[i].name, name) == 0) {
            return &bidders[i];
        }
    }
    return NULL;
}

// Helper function to add an item to the auction
void add_item(char *desc, int start_bid) {
    pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
    pthread_mutex_lock(&lock);
    strcpy(items[num_items].desc, desc);
    items[num_items].curr_bid = start_bid;
    items[num_items].lock = lock;
    num_items++;
    printf("Added item: %s\n", desc);
    pthread_mutex_unlock(&lock);
}

// Helper function to retrieve an item by index
Item *get_item(int index) {
    if (index < 0 || index >= num_items) {
        return NULL;
    }
    return &items[index];
}

// Helper function to print a list of items
void print_items() {
    printf("Items up for auction:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%d - %s\n", i, items[i].desc);
    }
}

// Helper function to print a list of bidders and their bids
void print_bidders() {
    printf("Current bidders:\n");
    for (int i = 0; i < num_bidders; i++) {
        printf("%s - Item %d, Bid: %d, Num Bids: %d\n", bidders[i].name, bidders[i].item_num, bidders[i].bid_val, bidders[i].num_bids);
    }
}

// Main function to run the auction
void *auction(void *args) {
    srand(time(NULL));
    while (1) {
        // Wait for a random interval of time before starting a new auction
        int wait_time = rand() % 6 + 5;
        printf("Waiting %d seconds before starting next auction...\n", wait_time);
        sleep(wait_time);

        // Select a random item to sell
        int item_index = rand() % num_items;
        Item *item = get_item(item_index);
        if (item == NULL) {
            printf("Error selecting item to sell\n");
            continue;
        }
        printf("Starting auction for item: %s\n", item->desc);

        // Print current bidders
        print_bidders();

        // Prompt for new bidders
        int new_bidders = 0;
        char input[10];
        printf("Start new auction for %s? (y/n): ", item->desc);
        scanf("%s", input);
        if (strcmp(input, "y") == 0) {
            while (1) {
                printf("Enter bidder name or 'done': ");
                scanf("%s", input);
                if (strcmp(input, "done") == 0) {
                    break;
                }
                Bidder *bidder = get_bidder(input);
                if (bidder == NULL) {
                    printf("Bidder %s not found, adding to the list.\n", input);
                    add_bidder(input);
                    new_bidders = 1;
                } else if (bidder->item_num != -1) {
                    printf("Bidder %s already has an item.\n", input);
                } else {
                    bidder->item_num = item_index;
                    bidder->bid_val = item->curr_bid;
                    printf("Bidder %s added for item %s with current bid %d.\n", input, item->desc, item->curr_bid);
                }
            }
        } else {
            continue;
        }

        // Check if there are any bidders for the current item
        int valid_bidders = 0;
        for (int i = 0; i < num_bidders; i++) {
            if (bidders[i].item_num == item_index) {
                valid_bidders = 1;
                break;
            }
        }
        if (!valid_bidders) {
            printf("No bidders for item %s, auction cancelled.\n", item->desc);
            continue;
        }

        // Auction starts
        while (1) {
            // Prompt for new bid
            int max_bid = 0;
            for (int i = 0; i < num_bidders; i++) {
                if (bidders[i].item_num == item_index && bidders[i].bid_val > max_bid) {
                    max_bid = bidders[i].bid_val;
                }
            }
            int new_bid = 0;
            while (1) {
                printf("Current highest bid: %d, enter new bid or 'done': ", max_bid);
                scanf("%s", input);
                if (strcmp(input, "done") == 0) {
                    break;
                }
                new_bid = atoi(input);
                if (new_bid <= max_bid) {
                    printf("Bid must be higher than current highest bid (%d)\n", max_bid);
                } else {
                    break;
                }
            }
            if (new_bid == 0) {
                break;
            }

            // Update bidder information
            pthread_mutex_lock(&bidders_lock);
            Bidder *bidder = NULL;
            for (int i = 0; i < num_bidders; i++) {
                if (strcmp(bidders[i].name, args) == 0) {
                    bidder = &bidders[i];
                    break;
                }
            }
            if (bidder == NULL) {
                printf("Bidder %s not found, cancelling bid.\n", args);
                break;
            }
            if (bidder->item_num != item_index) {
                printf("Bidder %s not eligible for this item, cancelling bid.\n", args);
                break;
            }
            bidder->num_bids++;
            bidder->bid_val = new_bid;
            printf("Bidder %s updated with new bid: %d\n", args, new_bid);
            pthread_mutex_unlock(&bidders_lock);

            // Update item information
            pthread_mutex_lock(&(item->lock));
            item->curr_bid = new_bid;
            printf("Current highest bid for %s is now %d\n", item->desc, new_bid);
            pthread_mutex_unlock(&(item->lock));
        }

        // Auction ends
        printf("Auction for %s ended.\n", item->desc);

        // Remove bidders who did not bid
        pthread_mutex_lock(&bidders_lock);
        for (int i = 0; i < num_bidders; i++) {
            if (bidders[i].item_num == item_index && bidders[i].bid_val == 0) {
                printf("Removing bidder %s from list...\n", bidders[i].name);
                for (int j = i; j < num_bidders-1; j++) {
                    bidders[j] = bidders[j+1];
                }
                num_bidders--;
                i--;
            }
        }
        pthread_mutex_unlock(&bidders_lock);

        // Check if there are any bidders left for the item
        int remaining_bidders = 0;
        for (int i = 0; i < num_bidders; i++) {
            if (bidders[i].item_num == item_index) {
                remaining_bidders = 1;
                break;
            }
        }
        if (!remaining_bidders) {
            printf("No bidders remaining for item %s, removing from auction.\n", item->desc);
            for (int i = item_index; i < num_items-1; i++) {
                items[i] = items[i+1];
            }
            num_items--;
        }
    }
    return NULL;
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Add items to auction
    add_item("Antique vase", 100);
    add_item("Signed baseball", 50);
    add_item("Vintage comic book", 200);

    // Prompt for initial bidders
    while (1) {
        printf("Enter bidder name or 'done': ");
        char input[10];
        scanf("%s", input);
        if (strcmp(input, "done") == 0) {
            break;
        }
        add_bidder(input);
    }

    // Print initial items and bidders
    print_items();
    print_bidders();

    // Create threads for each bidder
    pthread_t tid[num_bidders];
    for (int i = 0; i < num_bidders; i++) {
        pthread_create(&tid[i], NULL, auction, bidders[i].name);
    }

    // Wait for all threads to finish
    for (int i = 0; i < num_bidders; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}