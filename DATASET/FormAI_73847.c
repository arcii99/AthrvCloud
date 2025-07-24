//FormAI DATASET v1.0 Category: Digital Auction System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Auction {
    char item[50];
    int highest_bid;
    char highest_bidder[50];
};

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    bool running = true;
    struct Auction auctions[10];
    int num_auctions = 0;

    while (running) {
        printf("\nDigital Auction System\n");
        printf("--------------------------\n");
        printf("1. Create an auction\n");
        printf("2. View all auctions\n");
        printf("3. Place a bid\n");
        printf("4. Exit\n");
        printf("--------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_auction(auctions, &num_auctions);
                break;
            case 2:
                view_auctions(auctions, num_auctions);
                break;
            case 3:
                place_bid(auctions, num_auctions);
                break;
            case 4:
                running = false;
                break;
            default:
                printf("Invalid choice. Please choose again.\n");
                break;
        }
    }
}

void create_auction(struct Auction auctions[], int *num_auctions) {
    char name[50];
    printf("Enter item name: ");
    scanf("%s", name);

    bool unique_name = true;
    for (int i = 0; i < *num_auctions; i++) {
        if (strcmp(name, auctions[i].item) == 0) {
            printf("Item name already exists. Please choose a unique name.\n");
            unique_name = false;
            break;
        }
    }

    if (unique_name) {
        strcpy(auctions[*num_auctions].item, name);
        auctions[*num_auctions].highest_bid = 0;
        strcpy(auctions[*num_auctions].highest_bidder, "N/A");
        (*num_auctions)++;
        printf("Auction created successfully!\n");
    }
}

void view_auctions(struct Auction auctions[], int num_auctions) {
    if (num_auctions == 0) {
        printf("No auctions to display.\n");
    }
    else {
        printf("%-20s%-20s%-20s\n", "Item", "Highest Bid", "Highest Bidder");
        for (int i = 0; i < num_auctions; i++) {
            printf("%-20s%-20d%-20s\n", auctions[i].item, auctions[i].highest_bid, auctions[i].highest_bidder);
        }
    }
}

void place_bid(struct Auction auctions[], int num_auctions) {
    if (num_auctions == 0) {
        printf("No auctions to place a bid on.\n");
    }
    else {
        char name[50];
        printf("Enter item name to bid on: ");
        scanf("%s", name);

        int index = find_index(auctions, num_auctions, name);
        if (index == -1) {
            printf("Invalid item name. Please try again.\n");
        }
        else {
            int bid;
            printf("Enter bid amount: ");
            scanf("%d", &bid);

            if (bid <= auctions[index].highest_bid) {
                printf("Bid must be higher than the current highest bid.\n");
            }
            else {
                strcpy(auctions[index].highest_bidder, "You");
                auctions[index].highest_bid = bid;
                printf("Bid placed successfully!\n");
            }
        }
    }
}

int find_index(struct Auction auctions[], int num_auctions, char name[]) {
    for (int i = 0; i < num_auctions; i++) {
        if (strcmp(name, auctions[i].item) == 0) {
            return i;
        }
    }
    return -1;
}