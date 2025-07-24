//FormAI DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ITEMS 10
#define MAX_BIDDERS 5

struct Item {
    char name[50];
    int id;
    float price;
    int status; // 0 if still available, 1 if sold
};

struct Bidder {
    char name[50];
    float budget;
    int item_id;
    float bid_amount;
    int has_bid; // 0 if no bid, 1 if has bid
};

void display_items(struct Item items[], int count) {
    printf("\nID\tPRICE\tITEM NAME\n");
    for(int i=0;i<count;i++) {
        if(items[i].status == 0) {
            printf("%d\t%.2f\t%s\n", items[i].id, items[i].price, items[i].name);
        }
    }
}

void display_bids(struct Bidder bidders[], int count) {
    printf("\nBIDDER NAME\tITEM ID\tBID AMOUNT\n");
    for(int i=0;i<count;i++) {
        if(bidders[i].has_bid == 1) {
            printf("%s\t\t%d\t%.2f\n", bidders[i].name, bidders[i].item_id, bidders[i].bid_amount);
        }
    }
}

int get_item_index(struct Item items[], int count, int id) {
    for(int i=0;i<count;i++) {
        if(items[i].id == id) {
            return i;
        }
    }
    return -1;
}

int get_bidder_index(struct Bidder bidders[], int count, char name[]) {
    for(int i=0;i<count;i++) {
        if(strcmp(bidders[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    struct Item items[MAX_ITEMS];
    struct Bidder bidders[MAX_BIDDERS];
    int item_count = 0;
    int bidder_count = 0;
    int choice = 0;
    int item_choice = 0;
    int bidder_choice = 0;
    int bid_choice = 0;
    int item_index = 0;
    int bidder_index = 0;
    char bidder_name[50];
    float bid_amount = 0;
    int item_id = 0;
    int temp = 0;

    // initialize items
    strcpy(items[item_count].name, "Coffee Maker");
    items[item_count].id = 1;
    items[item_count].price = 30.0;
    items[item_count].status = 0;
    item_count++;

    strcpy(items[item_count].name, "Smartphone");
    items[item_count].id = 2;
    items[item_count].price = 500.0;
    items[item_count].status = 0;
    item_count++;

    strcpy(items[item_count].name, "Laptop");
    items[item_count].id = 3;
    items[item_count].price = 800.0;
    items[item_count].status = 0;
    item_count++;

    // start program
    printf("Welcome to the Digital Auction System!\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1- Display available items\n2- Display current bids\n3- Add a bidder\n4- Place a bid\n5- Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_items(items, item_count);
                break;
            case 2:
                display_bids(bidders, bidder_count);
                break;
            case 3:
                // add a new bidder
                if(bidder_count >= MAX_BIDDERS) {
                    printf("Sorry, the maximum number of bidders has been reached.\n");
                    break;
                }
                printf("Enter bidder name: ");
                scanf("%s", bidder_name);
                temp = get_bidder_index(bidders, bidder_count, bidder_name);
                if(temp != -1) {
                    printf("Bidder with same name already exists. Please enter a unique name.\n");
                    break;
                }
                printf("Enter bidder budget: ");
                scanf("%f", &bidders[bidder_count].budget);
                strcpy(bidders[bidder_count].name, bidder_name);
                bidders[bidder_count].has_bid = 0;
                bidder_count++;
                break;
            case 4:
                // place a bid
                if(bidder_count == 0) {
                    printf("Sorry, there are no bidders. No bids can be placed.\n");
                    break;
                }
                printf("Enter bidder name: ");
                scanf("%s", bidder_name);
                bidder_index = get_bidder_index(bidders, bidder_count, bidder_name);
                if(bidder_index == -1) {
                    printf("Bidder does not exist or has been removed.\n");
                    break;
                }
                if(bidders[bidder_index].has_bid == 1) {
                    printf("Bidder already has a current bid on another item.\n");
                    break;
                }
                display_items(items, item_count);
                printf("Enter item ID to bid on: ");
                scanf("%d", &item_id);
                item_index = get_item_index(items, item_count, item_id);
                if(item_index == -1) {
                    printf("Item does not exist or has been removed.\n");
                    break;
                }
                if(items[item_index].status == 1) {
                    printf("Item has already been sold.\n");
                    break;
                }
                printf("Enter bid amount: ");
                scanf("%f", &bid_amount);
                if(bid_amount > bidders[bidder_index].budget) {
                    printf("Bidder does not have enough budget to place this bid.\n");
                    break;
                }
                if(bid_amount <= items[item_index].price) {
                    printf("Bid amount must be greater than the current price of %.2f.\n", items[item_index].price);
                    break;
                }
                // update bid and item information
                items[item_index].price = bid_amount;
                bidders[bidder_index].item_id = item_id;
                bidders[bidder_index].bid_amount = bid_amount;
                bidders[bidder_index].has_bid = 1;
                temp = items[item_index].status;
                items[item_index].status = 1;
                if(temp == 0) {
                    printf("Congratulations, bidder %s has won the auction for item ID %d with a bid of %.2f!\n", bidder_name, item_id, bid_amount);
                } else {
                    printf("Congratulations, bidder %s has taken over the current bid for item ID %d with a bid of %.2f!\n", bidder_name, item_id, bid_amount);
                }
                break;
            case 5:
                printf("Thank you for using Digital Auction System!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}