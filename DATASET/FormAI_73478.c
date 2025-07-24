//FormAI DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct item{
    char itemName[30];
    char itemDesc[100];
    float basePrice;
    float currentBid;
    char bidderName[30];
    int auctionEndTime;
};

int main(){
    int numItems;
    printf("Welcome to the Digital Auction System!\n");

    printf("How many items are you auctioning off today?\n");
    scanf("%d",&numItems);

    struct item items[numItems];
    for(int i=0;i<numItems;i++){
        printf("What is the name of the item you are auctioning off? ");
        scanf("%s",items[i].itemName);

        printf("Please provide a brief description of the item: ");
        scanf("%s",items[i].itemDesc);

        printf("What is the base price? ");
        scanf("%f",&items[i].basePrice);

        items[i].currentBid = items[i].basePrice;
        strcpy(items[i].bidderName,"N/A");

        printf("When does the auction for this item end (in seconds from now)? ");
        scanf("%d",&items[i].auctionEndTime);
    }

    int currentTime=0;
    while(currentTime<=items[numItems-1].auctionEndTime){
        printf("\n\n");
        for(int i=0;i<numItems;i++){
            if(currentTime==items[i].auctionEndTime){
                printf("%s auction has ended. Highest bid: $%.2f, Bidder: %s\n",items[i].itemName,items[i].currentBid,items[i].bidderName);
            }
            else{
                printf("%s (Base Price: $%.2f Current Bid: $%.2f Bidder: %s) \nDescription: %s \nTime Left: %d seconds\n",items[i].itemName,items[i].basePrice,items[i].currentBid,items[i].bidderName,items[i].itemDesc,items[i].auctionEndTime-currentTime);
                if(strcmp(items[i].bidderName,"N/A")==0){
                    printf("To place a bid on this item, please enter your name and the bid amount (ex: John $50.00): ");
                    char input[50];
                    scanf("%s",input);
                    char *tokens[2];
                    char *token = strtok(input," ");
                    int j=0;
                    while(token!=NULL){
                        tokens[j++] = token;
                        token = strtok(NULL," ");
                    }
                    float bidAmount = atof(tokens[1]);
                    if(bidAmount>items[i].currentBid){
                        items[i].currentBid = bidAmount;
                        strcpy(items[i].bidderName,tokens[0]);
                        printf("Bid of $%.2f accepted from %s for %s\n",bidAmount,tokens[0],items[i].itemName);
                    }
                    else{
                        printf("Bid not accepted. Your bid must be higher than the current bid of $%.2f\n",items[i].currentBid);
                    }
                }
                else{
                    printf("Highest Bid: $%.2f, Bidder: %s\n",items[i].currentBid,items[i].bidderName);
                }
            }
        }
        currentTime++;
    }
    printf("All auctions have ended. Thank you for using the Digital Auction System! \n");
    return 0;
}