//FormAI DATASET v1.0 Category: Digital Auction System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Defining auction details structure
struct auction_details {
    int id;
    char item_name[50];
    char description[100];
    float base_price;
    float highest_bid;
    char bidder_name[50];
    int time_left; //in seconds
};

typedef struct auction_details Auction;

//Function to display the details of an auction
void display_auction(Auction a) {
    printf("Auction ID: %d\n", a.id);
    printf("Item Name: %s\n", a.item_name);
    printf("Description: %s\n", a.description);
    printf("Base Price: %.2f\n", a.base_price);
    printf("Highest Bid: %.2f\n", a.highest_bid);
    printf("Bidder Name: %s\n", a.bidder_name);
    printf("Time Left: %d seconds\n", a.time_left);
}

int main() {
    Auction auctions[5];
    auctions[0].id = 1;
    strcpy(auctions[0].item_name, "Vintage Watch");
    strcpy(auctions[0].description, "A rare vintage watch from the 1940s.");
    auctions[0].base_price = 1000.00;
    auctions[0].highest_bid = 0.00;
    strcpy(auctions[0].bidder_name, "");
    auctions[0].time_left = 60;

    auctions[1].id = 2;
    strcpy(auctions[1].item_name, "Signed Baseball");
    strcpy(auctions[1].description, "A baseball signed by Babe Ruth.");
    auctions[1].base_price = 5000.00;
    auctions[1].highest_bid = 0.00;
    strcpy(auctions[1].bidder_name, "");
    auctions[1].time_left = 120;

    auctions[2].id = 3;
    strcpy(auctions[2].item_name, "Picasso Painting");
    strcpy(auctions[2].description, "A one of a kind Picasso painting.");
    auctions[2].base_price = 100000.00;
    auctions[2].highest_bid = 0.00;
    strcpy(auctions[2].bidder_name, "");
    auctions[2].time_left = 180;

    auctions[3].id = 4;
    strcpy(auctions[3].item_name, "Classic Car");
    strcpy(auctions[3].description, "A 1967 Chevy Impala in mint condition.");
    auctions[3].base_price = 50000.00;
    auctions[3].highest_bid = 0.00;
    strcpy(auctions[3].bidder_name, "");
    auctions[3].time_left = 240;

    auctions[4].id = 5;
    strcpy(auctions[4].item_name, "Diamond Ring");
    strcpy(auctions[4].description, "A one carat diamond ring.");
    auctions[4].base_price = 20000.00;
    auctions[4].highest_bid = 0.00;
    strcpy(auctions[4].bidder_name, "");
    auctions[4].time_left = 300;
    
    //Displaying available auctions
    printf("Available Auctions:\n");
    for(int i=0; i<5; i++) {
        display_auction(auctions[i]);
    }

    //Prompting user for auction ID to bid on
    int auction_id;
    printf("Enter auction ID to bid on: ");
    scanf("%d", &auction_id);
    
    //Getting the index of the auction
    int index = -1;
    for(int i=0; i<5; i++) {
        if(auctions[i].id == auction_id) {
            index = i;
            break;
        }
    }

    if(index == -1) {
        printf("Invalid auction ID entered.\n");
        return 0;
    }

    //Prompting user for bid amount
    float bid_amount;
    printf("Enter bid amount: ");
    scanf("%f", &bid_amount);

    //Checking if bid is higher than current highest bid and base price
    if(bid_amount > auctions[index].highest_bid && bid_amount >= auctions[index].base_price) {
        auctions[index].highest_bid = bid_amount;

        char name[50];
        printf("Enter bidder name: ");
        scanf("%s", name);

        strcpy(auctions[index].bidder_name, name);
        printf("Bid successful!\n");

        //Setting random value for time left
        srand(time(0));
        auctions[index].time_left = (rand() % 60) + 180; //Between 180 and 240 seconds
    } else {
        printf("Bid amount too low or already higher bid present.\n");
        return 0;
    }

    //Displaying updated auction details
    printf("Updated Auction Details: \n");
    display_auction(auctions[index]);
    
    return 0;
}