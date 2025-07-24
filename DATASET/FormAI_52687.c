//FormAI DATASET v1.0 Category: Digital Auction System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Struct to hold information about each auction item*/
struct AuctionItem{
    char name[50];
    float startingPrice;
    float currentBid;
    char currentWinner[50];
};

/*Function to display the list of available auction items*/
void displayItems(struct AuctionItem items[], int numItems){
    int i;
    printf("Available Auction Items:\n");
    for(i=0;i<numItems;i++){
        printf("%d. %s\n",i+1,items[i].name);
    }
}

/*Function to start a new auction*/
void startAuction(struct AuctionItem* item){
    printf("\nStarting Auction for %s\n\n",item->name);
    printf("Starting price: $%.2f\n",item->startingPrice);
    item->currentBid = item->startingPrice;
}

/*Function to place a bid*/
void placeBid(struct AuctionItem* item, char name[], float amount){
    if(amount > item->currentBid){
        printf("%s is the new highest bidder with a bid of $%.2f\n",name,amount);
        item->currentBid = amount;
        strcpy(item->currentWinner,name);
    }
    else{
        printf("Sorry, your bid must be higher than the current bid of $%.2f\n",item->currentBid);
    }
}

int main(){
    /*Example auction items*/
    struct AuctionItem items[3];
    strcpy(items[0].name,"Antique Vase");
    items[0].startingPrice = 1000.00;
    strcpy(items[1].name,"Signed Baseball");
    items[1].startingPrice = 50.00;
    strcpy(items[2].name,"Vintage Comic Book");
    items[2].startingPrice = 200.00;
    
    int numItems = 3; /*Number of items in the auction*/
    int choice; /*Choice from user*/
    int itemChoice; /*Choice of auction item*/
    struct AuctionItem* selectedItem; /*Pointer to selected item*/
    char bidderName[50]; /*Name of bidder*/
    float bidAmount; /*Amount of bid*/
    
    printf("Welcome to the Digital Auction System!\n");
    while(1){
        displayItems(items,numItems);
        printf("%d. Exit\n",numItems+1);
        printf("Please select an option: ");
        scanf("%d",&choice);
        
        if(choice == numItems+1){
            printf("Goodbye!\n");
            break;
        }
        else if(choice < 1 || choice > numItems+1){
            printf("Invalid choice, please try again.\n");
        }
        else{
            selectedItem = &items[choice-1];
            startAuction(selectedItem);
            
            printf("Please enter your name: ");
            scanf("%s",&bidderName);
            printf("Please enter your bid: ");
            scanf("%f",&bidAmount);
            placeBid(selectedItem,bidderName,bidAmount);
            
            /*Option to continue bidding*/
            while(1){
                printf("Would you like to place another bid? (Y/N): ");
                char response;
                scanf(" %c",&response);
                
                if(response == 'Y' || response == 'y'){
                    printf("Please enter your new bid: ");
                    scanf("%f",&bidAmount);
                    placeBid(selectedItem,bidderName,bidAmount);
                }
                else if(response == 'N' || response == 'n'){
                    printf("Thank you for your bid!\n");
                    break;
                }
                else{
                    printf("Invalid response, please try again.\n");
                }
            }
        }
        
    }
    
    return 0;
}