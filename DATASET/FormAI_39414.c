//FormAI DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Struct for storing items
typedef struct {
    char name[50];
    int price;
} Item;

// Function for placing a bid
void placeBid(Item *item, int bid) {
    if(bid > item->price)
        item->price = bid;
    else
        printf("Your bid isn't high enough!\n");
}

int main() {
    // Initialize items
    Item item1 = {"Microwave", 50};
    Item item2 = {"Computer monitor", 100};
    Item item3 = {"Gaming mouse", 30};
    Item items[] = {item1, item2, item3};

    // Print available items
    printf("Items available for bidding:\n");
    for(int i = 0; i < 3; i++) {
        printf("%d. %s - Current bid: $%d\n", i+1, items[i].name, items[i].price);
    }

    // Prompt user for item selection and bid
    int itemSelection, bid;
    printf("Enter item number to bid on: ");
    scanf("%d", &itemSelection);
    printf("Current bid for %s: $%d\n", items[itemSelection-1].name, items[itemSelection-1].price);
    printf("Enter your bid: $");
    scanf("%d", &bid);
    placeBid(&items[itemSelection-1], bid);
    printf("New bid for %s: $%d\n", items[itemSelection-1].name, items[itemSelection-1].price);

    return 0;
}