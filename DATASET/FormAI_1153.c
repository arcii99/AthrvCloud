//FormAI DATASET v1.0 Category: Digital Auction System ; Style: asynchronous
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>

#define MAX_BID 1000

struct auction_item{
    int id;
    char name[50];
    float start_price;
    float current_bid;
    int time_left;
    int highest_bidder;
}items[10];

int num_items = 0;

void initialize_items(){
    strcpy(items[0].name, "Painting");
    items[0].start_price = 1000.0;
    items[0].current_bid = 0.0;
    items[0].time_left = 30;
    items[0].highest_bidder = -1;
    
    strcpy(items[1].name, "Jewelry");
    items[1].start_price = 5000.0;
    items[1].current_bid = 0.0;
    items[1].time_left = 60;
    items[1].highest_bidder = -1;
    
    num_items = 2;
}

float get_random_bid(){
    float bid = (float)rand()/RAND_MAX;
    bid = bid * MAX_BID;
    return bid;
}

void display_items(){
    printf("\nCurrent Auction Items:\n");
    for(int i = 0; i < num_items; i++){
        printf("Item ID: %d\n", i+1);
        printf("Item Name: %s\n", items[i].name);
        printf("Start Price: %.2f\n", items[i].start_price);
        printf("Current Bid: %.2f\n", items[i].current_bid);
        printf("Time Left: %d seconds\n", items[i].time_left);
        if(items[i].highest_bidder != -1){
            printf("Highest Bidder ID: %d\n", items[i].highest_bidder);
        }
        else{
            printf("No bids yet.\n");
        }
        printf("\n");
    }
}

void* auction(void* arg){
    int item_id = *((int*)arg);
    float bid;
    while(items[item_id].time_left > 0){
        bid = get_random_bid();
        if(bid > items[item_id].current_bid){
            items[item_id].current_bid = bid;
            items[item_id].highest_bidder = rand()%10 + 1;
            printf("New highest bid for item %d: %.2f (Bidder: %d)\n", item_id+1, bid, items[item_id].highest_bidder);
        }
        usleep(500000);
        items[item_id].time_left--;
    }
}

int main()
{
    pthread_t auctions[10];
    int ids[10];
    initialize_items();
    display_items();
    for(int i = 0; i < num_items; i++){
        ids[i] = i;
        pthread_create(&auctions[i], NULL, auction, (void*)&ids[i]);
    }
    for(int i = 0; i < num_items; i++){
        pthread_join(auctions[i], NULL);
    }
    printf("\n\nAuction has ended!\n");
    display_items();
    return 0;
}