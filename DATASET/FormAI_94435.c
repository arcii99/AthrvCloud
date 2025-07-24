//FormAI DATASET v1.0 Category: Digital Auction System ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

//Structure to hold information about an auction item
typedef struct {
  char name[100];
  float starting_bid;
  char description[500];
  float current_bid;
  char current_bidder[100];
} auction_item;

//Function to display the details of an auction item
void display_item(auction_item item){
  printf("Name: %s\n", item.name);
  printf("Starting Bid: $%.2f\n", item.starting_bid);
  printf("Description: %s\n", item.description);
  printf("Current Bid: $%.2f\n", item.current_bid);
  printf("Current Bidder: %s\n\n", item.current_bidder);
}

//Function to place a bid on an auction item
void place_bid(auction_item* item, float bid, char bidder[100]){
  if (bid > item->current_bid){
    item->current_bid = bid;
    strcpy(item->current_bidder, bidder);
  }
  else{
    printf("Your bid must be higher than the current bid of $%.2f\n\n", item->current_bid);
  }
}

int main(){

  srand(time(NULL)); //Seed random number generator

  //Create an array of 5 auction items
  auction_item items[5];

  //Initialize each auction item
  strcpy(items[0].name, "Original Oil Painting");
  items[0].starting_bid = 100.00;
  strcpy(items[0].description, "Beautiful landscape painting by an up and coming artist.");
  items[0].current_bid = 0.00;
  strcpy(items[0].current_bidder, "");

  strcpy(items[1].name, "Limited Edition Sports Memorabilia");
  items[1].starting_bid = 50.00;
  strcpy(items[1].description, "Rare collectible signed by your favorite athlete.");
  items[1].current_bid = 0.00;
  strcpy(items[1].current_bidder, "");

  strcpy(items[2].name, "Vintage Jewelry Set");
  items[2].starting_bid = 200.00;
  strcpy(items[2].description, "Classic necklace and earrings perfect for any special occasion.");
  items[2].current_bid = 0.00;
  strcpy(items[2].current_bidder, "");

  strcpy(items[3].name, "Antique Clock");
  items[3].starting_bid = 150.00;
  strcpy(items[3].description, "Beautiful timepiece from the turn of the century.");
  items[3].current_bid = 0.00;
  strcpy(items[3].current_bidder, "");

  strcpy(items[4].name, "Rare Book");
  items[4].starting_bid = 75.00;
  strcpy(items[4].description, "First edition copy of a literary classic.");
  items[4].current_bid = 0.00;
  strcpy(items[4].current_bidder, "");

  int choice = 0;
  float bid = 0.00;
  char bidder[100];

  while (choice != 6){

    printf("Select an option:\n");
    printf("1. Display All Items\n");
    printf("2. Display Item Details\n");
    printf("3. Place Bid\n");
    printf("4. Generate Random Bid\n");
    printf("5. Reset Auction\n");
    printf("6. Quit\n");

    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("Items Currently Up for Auction:\n\n");
        for (int i = 0; i < 5; i++){
          printf("%d. %s\n", i + 1, items[i].name);
        }
        printf("\n");
        break;

      case 2:
        printf("Enter the number of the item you want to see details for: ");
        scanf("%d", &choice);
        if (choice > 0 && choice <= 5){
          display_item(items[choice - 1]);
        }
        else{
          printf("Invalid Choice\n\n");
        }
        break;

      case 3:
        printf("Enter the number of the item you want to bid on: ");
        scanf("%d", &choice);
        if (choice > 0 && choice <= 5){
          printf("Enter your bid: ");
          scanf("%f", &bid);
          printf("Enter your name: ");
          scanf("%s", bidder);
          place_bid(&items[choice - 1], bid, bidder);
        }
        else{
          printf("Invalid Choice\n\n");
        }
        break;

      case 4:
        printf("Generating random bid...\n\n");
        choice = rand() % 5 + 1; //Choose a random item to bid on
        bid = (rand() % 100 + 1) * 0.01 * items[choice - 1].starting_bid; //Generate a random bid between 1.00 and the starting bid of the item
        sprintf(bidder, "Random Bidder %d", rand() % 100); //Generate a random bidder name
        printf("Placing bid of $%.2f on %s by %s\n\n", bid, items[choice - 1].name, bidder);
        place_bid(&items[choice - 1], bid, bidder);
        break;

      case 5:
        printf("Resetting Auction...\n\n");
        for (int i = 0; i < 5; i++){
          items[i].current_bid = 0.00;
          strcpy(items[i].current_bidder, "");
        }
        break;

      case 6:
        printf("Goodbye!\n");
        break;

      default:
        printf("Invalid Choice\n\n");
        break;
    }

  }

  return 0;
}