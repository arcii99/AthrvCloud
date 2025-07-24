//FormAI DATASET v1.0 Category: Digital Auction System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bidder {
    char name[50];
    float bid;
};

struct auction {
    char item_name[50];
    float base_price;
    struct bidder highest_bidder;
};

int main() {
    int num_auctions, i, j, k;
    printf("Enter the number of auctions: ");
    scanf("%d", &num_auctions);

    struct auction auctions[num_auctions];
    
    // Initializing auctions
    for (i = 0; i < num_auctions; i++) {
        printf("\nEnter the item name for auction %d: ", i + 1);
        scanf("%s", &auctions[i].item_name);
        getchar();
        
        printf("Enter the starting bid for auction %d: ", i + 1);
        scanf("%f", &auctions[i].base_price);
        
        strcpy(auctions[i].highest_bidder.name, "No bids yet");
        auctions[i].highest_bidder.bid = 0;
    }
    
    // Starting bids
    while (1) {
        printf("\n");
        
        for (j = 0; j < num_auctions; j++) {
            printf("Current highest bid for %s: %.2f by %s\n", auctions[j].item_name,
                   auctions[j].highest_bidder.bid, auctions[j].highest_bidder.name);
            
            if (strcmp(auctions[j].highest_bidder.name, "No bids yet") != 0) {
                printf("Enter a new bid for %s (or press enter to skip): ", auctions[j].item_name);
                char input[10];
                fgets(input, sizeof(input), stdin);
                if (input[0] != '\n') {
                    float new_bid = atof(input);
                
                    if (new_bid > auctions[j].highest_bidder.bid) {
                        printf("New highest bid for %s: %.2f by %s", auctions[j].item_name, new_bid, auctions[j].highest_bidder.name);
                        auctions[j].highest_bidder.bid = new_bid;
                        printf("\nEnter your name: ");
                        fgets(auctions[j].highest_bidder.name, sizeof(auctions[j].highest_bidder.name), stdin);
                    }
                }
            } else {
                printf("Enter your name to start bidding for %s: ", auctions[j].item_name);
                fgets(auctions[j].highest_bidder.name, sizeof(auctions[j].highest_bidder.name), stdin);
                printf("Enter your starting bid: ");
                scanf("%f", &auctions[j].highest_bidder.bid);
            }
            printf("\n");
        }
        
        // Ending auctions
        int num_ended_auctions = 0;
        for (k = 0; k < num_auctions; k++) {
            if (strcmp(auctions[k].highest_bidder.name, "No bids yet") != 0 && auctions[k].base_price <= auctions[k].highest_bidder.bid) {
                printf("The winner of %s is %s with a bid of %.2f!\n", auctions[k].item_name, auctions[k].highest_bidder.name, auctions[k].highest_bidder.bid);
                num_ended_auctions++;
            }
        }
        
        if (num_ended_auctions == num_auctions) {
            break;
        }
    }
    
    return 0;
}