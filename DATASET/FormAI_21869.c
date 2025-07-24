//FormAI DATASET v1.0 Category: Digital Auction System ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bidder {
    char name[30];
    int balance;
} Bidder;

typedef struct Item {
    char name[30];
    int price;
    Bidder *highestBidder;
} Item;

int main() {
    int numItems, numBidders;
    
    printf("Enter the number of items: ");
    scanf("%d", &numItems);
    printf("Enter the number of bidders: ");
    scanf("%d", &numBidders);
    
    // Allocate memory for arrays of items and bidders
    Item *items = malloc(sizeof(Item) * numItems);
    Bidder *bidders = malloc(sizeof(Bidder) * numBidders);
    
    // Initialize item and bidder details
    for (int i = 0; i < numItems; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter the starting price of item %d: ", i+1);
        scanf("%d", &items[i].price);
        items[i].highestBidder = NULL;
    }
    
    for (int i = 0; i < numBidders; i++) {
        printf("Enter the name of bidder %d: ", i+1);
        scanf("%s", bidders[i].name);
        printf("Enter the balance of bidder %d: ", i+1);
        scanf("%d", &bidders[i].balance);
    }
    
    // Auction process
    int option;
    do {
        printf("\n\n1 - Display items\n2 - Make a bid\n3 - Quit\n");
        scanf("%d", &option);
        
        switch(option) {
            case 1:
                printf("\n%-20s%-10s\n", "Item", "Price");
                for (int i = 0; i < numItems; i++) {
                    printf("%-20s$%-10d", items[i].name, items[i].price);
                    if (items[i].highestBidder != NULL) {
                        printf(" (Current highest bidder: %s)", items[i].highestBidder->name);
                    }
                    printf("\n");
                }
                break;
                
            case 2:
                char itemName[30], bidderName[30];
                int bidAmount;
                
                printf("Enter the name of item: ");
                scanf("%s", itemName);
                printf("Enter the name of bidder: ");
                scanf("%s", bidderName);
                
                // Find the item and bidder objects
                Item *item = NULL;
                for (int i = 0; i < numItems; i++) {
                    if (strcmp(itemName, items[i].name) == 0) {
                        item = &items[i];
                        break;
                    }
                }
                if (item == NULL) {
                    printf("Error: Item not found.\n");
                    break;
                }
                
                Bidder *bidder = NULL;
                for (int i = 0; i < numBidders; i++) {
                    if (strcmp(bidderName, bidders[i].name) == 0) {
                        bidder = &bidders[i];
                        break;
                    }
                }
                if (bidder == NULL) {
                    printf("Error: Bidder not found.\n");
                    break;
                }
                
                printf("Enter the bid amount: ");
                scanf("%d", &bidAmount);
                
                // Check if the bid amount is valid
                if (bidAmount <= item->price) {
                    printf("Error: Bid amount must be greater than current price.\n");
                    break;
                }
                if (bidAmount > bidder->balance) {
                    printf("Error: Bidder does not have enough balance.\n");
                    break;
                }
                
                // Update the item details
                item->price = bidAmount;
                item->highestBidder = bidder;
                
                // Update the bidder details
                bidder->balance -= bidAmount;
                
                printf("Bid successful!\n");
                break;
                
            case 3:
                printf("Quitting auction.\n");
                break;
                
            default:
                printf("Invalid option. Try again.\n");
        }
        
    } while(option != 3);
    
    // Free memory allocated for arrays
    free(items);
    free(bidders);
    
    return 0;
}