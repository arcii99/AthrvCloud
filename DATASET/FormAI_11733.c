//FormAI DATASET v1.0 Category: Digital Auction System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_AUCTIONS 50
#define MAX_BIDS_PER_AUCTION 10

struct User {
    int id;
    char name[50];
    float balance;
};

struct Auction {
    int id;
    char item_name[100];
    struct User* seller;
    float start_price;
    float current_price;
    struct User* current_bidder;
    time_t start_time;
    time_t end_time;
    struct User* bidders[MAX_BIDS_PER_AUCTION];
    int num_bids;
};

struct User users[MAX_USERS];
int num_users = 0;

struct Auction auctions[MAX_AUCTIONS];
int num_auctions = 0;

void clear_input_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct User* get_user(int id) {
    for (int i = 0; i < num_users; i++) {
        if (users[i].id == id) {
            return &users[i];
        }
    }
    return NULL;
}

void print_user(struct User* user) {
    printf("ID: %d\n", user->id);
    printf("Name: %s\n", user->name);
    printf("Balance: %f\n", user->balance);
}

void print_auction(struct Auction* auction) {
    printf("ID: %d\n", auction->id);
    printf("Item: %s\n", auction->item_name);
    printf("Seller: %s\n", auction->seller->name);
    printf("Start Price: %f\n", auction->start_price);
    printf("Current Price: %f\n", auction->current_price);
    if (auction->current_bidder != NULL) {
        printf("Current Bidder: %s\n", auction->current_bidder->name);
    } else {
        printf("Current Bidder: None\n");
    }
    printf("Start Time: %s", ctime(&auction->start_time));
    printf("End Time: %s", ctime(&auction->end_time));
}

void create_user(int id, char* name, float balance) {
    struct User* user = &users[num_users++];
    user->id = id;
    snprintf(user->name, 50, "%s", name);
    user->balance = balance;
}

void create_auction(int id, char* item_name, int seller_id, float start_price, time_t start_time, time_t end_time) {
    struct User* seller = get_user(seller_id);
    if (seller == NULL) {
        printf("User not found!\n");
        return;
    }
    struct Auction* auction = &auctions[num_auctions++];
    auction->id = id;
    snprintf(auction->item_name, 100, "%s", item_name);
    auction->seller = seller;
    auction->start_price = start_price;
    auction->current_price = start_price;
    auction->current_bidder = NULL;
    auction->start_time = start_time;
    auction->end_time = end_time;
    auction->num_bids = 0;
}

int place_bid(int auction_id, int bidder_id, float price) {
    struct Auction* auction = NULL;
    for (int i = 0; i < num_auctions; i++) {
        if (auctions[i].id == auction_id) {
            auction = &auctions[i];
            break;
        }
    }
    if (auction == NULL) {
        printf("Auction not found!\n");
        return 0;
    }
    if (auction->start_time > time(NULL) || auction->end_time < time(NULL)) {
        printf("Auction not active!\n");
        return 0;
    }
    struct User* bidder = get_user(bidder_id);
    if (bidder == NULL) {
        printf("Bidder not found!\n");
        return 0;
    }
    if (bidder->balance < price) {
        printf("Insufficient funds!\n");
        return 0;
    }
    if (price <= auction->current_price) {
        printf("Bid too low!\n");
        return 0;
    }
    auction->current_price = price;
    auction->current_bidder = bidder;
    auction->bidders[auction->num_bids++] = bidder;
    bidder->balance -= price;
    auction->seller->balance += price;
    return 1;
}

int main() {
    create_user(1, "Alice", 1000);
    create_user(2, "Bob", 500);
    create_user(3, "Charlie", 2000);

    create_auction(1, "Painting", 1, 500, time(NULL) + 3600, time(NULL) + 7200);
    create_auction(2, "Guitar", 2, 200, time(NULL) + 7200, time(NULL) + 10800);
    create_auction(3, "Camera", 3, 1000, time(NULL), time(NULL) + 3600);

    while (1) {
        printf("\n=========\n");
        printf("1: List Users\n");
        printf("2: List Auctions\n");
        printf("3: Place Bid\n");
        printf("4: Exit\n");
        printf("Enter choice: ");
        fflush(stdout);

        int choice;
        scanf("%d", &choice);
        clear_input_buffer();
        printf("\n");

        switch (choice) {
            case 1: {
                for (int i = 0; i < num_users; i++) {
                    print_user(&users[i]);
                    printf("\n");
                }
                break;
            }
            case 2: {
                for (int i = 0; i < num_auctions; i++) {
                    print_auction(&auctions[i]);
                    printf("\n");
                }
                break;
            }
            case 3: {
                printf("Enter user ID: ");
                fflush(stdout);
                int bidder_id;
                scanf("%d", &bidder_id);
                clear_input_buffer();

                printf("Enter auction ID: ");
                fflush(stdout);
                int auction_id;
                scanf("%d", &auction_id);
                clear_input_buffer();

                printf("Enter bid amount: ");
                fflush(stdout);
                float price;
                scanf("%f", &price);
                clear_input_buffer();

                if (place_bid(auction_id, bidder_id, price)) {
                    printf("Bid successful!\n");
                } else {
                    printf("Bid unsuccessful!\n");
                }
                break;
            }
            case 4: {
                exit(0);
            }
            default: {
                printf("Invalid choice!\n");
            }
        }
    }

    return 0;
}