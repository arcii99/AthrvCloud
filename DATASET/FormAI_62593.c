//FormAI DATASET v1.0 Category: Digital Auction System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about an item
typedef struct{
    int itemnumber;
    char name[50];
    char description[100];
    float price;
    char seller[50];
    char buyer[50];
    int status; // 0 - not sold, 1 - sold
}auction_item;

// Function to display the details of an item
void display_item(auction_item item){
    printf("\nItem Number: %d", item.itemnumber);
    printf("\nName: %s", item.name);
    printf("\nDescription: %s", item.description);
    printf("\nPrice: %.2f", item.price);
    printf("\nSeller: %s", item.seller);
    if(item.status == 1){
        printf("\nBuyer: %s", item.buyer);
    }
}

int main(){
    int option;
    int item_count = 0;
    auction_item items[50];

    do{
        printf("\n\n********** Digital Auction System **********");
        printf("\n1. Add Item for Auction");
        printf("\n2. Display All Items on Auction");
        printf("\n3. Bid on an item");
        printf("\n4. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                // Add item
                printf("\nEnter the item name: ");
                scanf("%s", items[item_count].name);
                printf("\nEnter the item description: ");
                scanf("%s", items[item_count].description);
                printf("\nEnter the item price: ");
                scanf("%f", &items[item_count].price);
                printf("\nEnter your name as seller: ");
                scanf("%s", items[item_count].seller);
                items[item_count].itemnumber = item_count + 1;
                items[item_count].status = 0; // Item not yet sold
                item_count++;
                printf("\nItem added for auction successfully!");
                break;

            case 2:
                // Display all items
                if(item_count == 0){
                    printf("\nNo items for auction at the moment!");
                }
                else{
                    printf("\n\n***** All Items on Auction *****");
                    for(int i=0;i<item_count;i++){
                        display_item(items[i]);
                    }
                }
                break;

            case 3:
                // Bid on an item
                int item_number;
                float bid_amount;
                char bidder_name[50];
                printf("\nEnter the item number for bidding: ");
                scanf("%d", &item_number);

                // Check if item number is valid
                if(item_number <= 0 || item_number > item_count){
                    printf("\nInvalid item number!");
                    break;
                }

                // Check if item is already sold
                if(items[item_number-1].status == 1){
                    printf("\nItem already sold!");
                    break;
                }

                // Place bid on item
                printf("\nEnter your name: ");
                scanf("%s", bidder_name);
                printf("\nEnter the bid amount: ");
                scanf("%f", &bid_amount);
                if(bid_amount > items[item_number-1].price){
                    items[item_number-1].price = bid_amount;
                    strcpy(items[item_number-1].buyer, bidder_name);
                    printf("\nBid placed successfully!");
                }
                else{
                    printf("\nBid amount should be higher than the current price!");
                }
                break;

            case 4:
                // Exit program
                printf("\nThank you for using our Digital Auction System!");
                exit(0);

            default:
                printf("\nInvalid option selected!");
                break;
        }

    }while(1);

    return 0;
}