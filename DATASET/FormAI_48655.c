//FormAI DATASET v1.0 Category: Digital Auction System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_BIDS 10

typedef struct bid{
    char name[50];
    float amount;
}Bid;

typedef struct item{
    char name[50];
    float current_bid;
    Bid bids[MAX_BIDS];
    int num_bids;
}Item;

int main(){
    Item item;
    int num_items;
    printf("How many items will be sold? ");
    scanf("%d",&num_items);
    Item items[num_items];

    for(int i=0;i<num_items;i++){
        printf("\nItem #%d\n",i+1);
        printf("Enter the item name: ");
        scanf("%s",items[i].name);
        items[i].current_bid = 0;
        items[i].num_bids = 0;

        char ans;
        do{
            printf("Add a bid? (Y/N): ");
            scanf(" %c",&ans);
            if(ans == 'Y' || ans == 'y'){
                printf("Enter bidder name: ");
                Bid bid;
                scanf("%s",bid.name);
                printf("Enter bid amount: ");
                scanf("%f",&bid.amount);

                if(bid.amount > items[i].current_bid){
                    items[i].current_bid = bid.amount;
                }

                items[i].bids[items[i].num_bids] = bid;
                items[i].num_bids++;
            }
        }while(ans == 'Y' || ans == 'y');
    }

    printf("\n------- Auction Summary -------\n");
    for(int i=0;i<num_items;i++){
        printf("\nItem #%d: %s\n",i+1,items[i].name);
        if(items[i].num_bids == 0){
            printf("This item has no bids.\n");
        }
        else{
            printf("Current bid: %.2f\n",items[i].current_bid);
            printf("Bids:\n");
            for(int j=0;j<items[i].num_bids;j++){
                printf("(%.2f) %s\n",items[i].bids[j].amount,items[i].bids[j].name);
            }
        }
    }
    return 0;
}