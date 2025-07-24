//FormAI DATASET v1.0 Category: Digital Auction System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct bidder{
    int id;
    char name[50];
    int amount;
};

struct auction{
    int item_id;
    char name[100];
    int base_price;
    int curr_price;
    struct bidder highest_bidder;
    int num_bidders;
    struct bidder *bidders;
};

void add_bidder(struct auction *auction){
    auction->num_bidders++;
    auction->bidders = (struct bidder *)realloc(auction->bidders, sizeof(struct bidder)*auction->num_bidders);

    printf("\nEnter bidder details:\n");
    printf("Bidder ID: ");
    scanf("%d", &auction->bidders[auction->num_bidders-1].id);
    printf("Name: ");
    scanf("%s", &auction->bidders[auction->num_bidders-1].name);
    printf("Amount: ");
    scanf("%d", &auction->bidders[auction->num_bidders-1].amount);
}

void display_bidders(struct auction *auction){
    printf("\nList of bidders:\n");
    for(int i=0; i<auction->num_bidders; i++){
        printf("\nBidder ID: %d\n", auction->bidders[i].id);
        printf("Name: %s\n", auction->bidders[i].name);
        printf("Amount: %d\n", auction->bidders[i].amount);
    }
}

void auction_menu(struct auction *auction){
    int choice;
    do{
        printf("\n\n++++++++++ Auction Menu ++++++++++\n");
        printf("1. Add Bidder\n");
        printf("2. Display Bidders\n");
        printf("3. Show Item Details\n");
        printf("4. Place Bid\n");
        printf("5. Exit Auction\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: add_bidder(auction); break;
            case 2: display_bidders(auction); break;
            case 3:
                printf("\n\nItem Details\n");
                printf("Item ID: %d\n", auction->item_id);
                printf("Item Name: %s\n", auction->name);
                printf("Base Price: %d\n", auction->base_price);
                printf("Current Price: %d\n", auction->curr_price);
                printf("Highest Bidder: %s\n", auction->highest_bidder.name);
                printf("Number of Bidders: %d\n", auction->num_bidders);
                break;
            case 4:
                if(auction->num_bidders == 0){
                    printf("\nNo bidders available!\n");
                }
                else{
                    struct bidder b;
                    printf("\nEnter bidder ID who wants to place the bid: ");
                    scanf("%d", &b.id);
                    int flag = 0;
                    for(int i=0; i<auction->num_bidders; i++){
                        if(auction->bidders[i].id == b.id){
                            flag = 1;
                            printf("\nEnter amount: ");
                            scanf("%d", &b.amount);

                            if(b.amount > auction->curr_price){
                                auction->curr_price = b.amount;
                                auction->highest_bidder = auction->bidders[i];
                            }
                            break;
                        }
                    }
                    if(flag == 0){
                        printf("\nInvalid bidder ID!\n");
                    }
                }
                break;
            case 5: printf("\nExiting auction...\n"); break;
            default: printf("\nInvalid choice!\n"); break;
        }

    }while(choice != 5);
}

int main(){
    struct auction auction;
    auction.item_id = 1001;
    strcpy(auction.name, "Antique Vase");
    auction.base_price = 1000;
    auction.curr_price = auction.base_price;
    auction.highest_bidder.id = -1;
    strcpy(auction.highest_bidder.name, "No bidder");
    auction.num_bidders = 0;
    auction.bidders = NULL;

    printf("\nWelcome to the Auction system for %s with ID %d!\n", auction.name, auction.item_id);
    auction_menu(&auction);

    free(auction.bidders);
    return 0;
}