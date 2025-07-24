//FormAI DATASET v1.0 Category: Digital Auction System ; Style: relaxed
#include <stdio.h> // Include standard input/output header file
#include <stdlib.h> // Include standard library header file

struct Auction { // Create a struct Auction to store data
    int id; // Auction ID
    char item[50]; // Auction item name
    int highestBid; // Highest bid value
    char bidderName[50]; // Name of the highest bidder
};

int main() {
    int n; // Number of auctions
    printf("Enter the number of auctions: ");
    scanf("%d", &n);
    
    struct Auction arr[n]; // Create an array of Auction structs
    
    printf("\nEnter details of each auction:\n");
    for (int i = 0; i < n; i++) { // Loop through each auction
        printf("\nAuction %d:\n", i+1);
        
        // Get input from user and store in Auction struct
        printf("Enter auction ID: ");
        scanf("%d", &arr[i].id);
        printf("Enter auction item: ");
        scanf("%s", &arr[i].item);
        printf("Enter starting bid value: ");
        scanf("%d", &arr[i].highestBid);
        printf("Enter bidder name: ");
        scanf("%s", &arr[i].bidderName);
    }
    
    int choice = 0; // Initialize choice variable
    
    while (choice != 4) { // Loop until user chooses to exit
        printf("\nMenu:\n");
        printf("1. Display all auctions\n");
        printf("2. Display auction with highest bid\n");
        printf("3. Make a bid\n");
        printf("4. Exit\n");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: // Display all auctions
                printf("\nAll auctions:\n");
                for (int i = 0; i < n; i++) {
                    printf("Auction ID: %d\n", arr[i].id);
                    printf("Auction item: %s\n", arr[i].item);
                    printf("Highest bid: %d\n", arr[i].highestBid);
                    printf("Highest bidder: %s\n", arr[i].bidderName);
                    printf("\n");
                }
                break;
                
            case 2: // Display auction with highest bid
                // Initialize variables to store highest bid
                int maxBid = arr[0].highestBid;
                int maxIndex = 0;
                
                for (int i = 1; i < n; i++) {
                    if (arr[i].highestBid > maxBid) { // If current bid is higher than current max bid
                        maxBid = arr[i].highestBid; // Update max bid value
                        maxIndex = i; // Update index of highest bid
                    }
                }
                printf("\nAuction with highest bid:\n");
                printf("Auction ID: %d\n", arr[maxIndex].id);
                printf("Auction item: %s\n", arr[maxIndex].item);
                printf("Highest bid: %d\n", arr[maxIndex].highestBid);
                printf("Highest bidder: %s\n", arr[maxIndex].bidderName);
                break;
                
            case 3: // Make a bid
                int id;
                printf("\nEnter auction ID: ");
                scanf("%d", &id);
                
                // Find index of auction with specified ID
                int index;
                for (int i = 0; i < n; i++) {
                    if (arr[i].id == id) { // If auction ID matches
                        index = i; // Store index of matching auction
                        break;
                    }
                }
                
                // Get new bid from user and update Auction struct
                int newBid;
                printf("Enter new bid value: ");
                scanf("%d", &newBid);
                
                if (newBid > arr[index].highestBid) { // If new bid is higher than previous highest
                    printf("Enter bidder name: ");
                    scanf("%s", &arr[index].bidderName); // Update highest bidder name
                    arr[index].highestBid = newBid; // Update highest bid value
                    printf("Bid accepted!\n");
                }
                else { // If bid is lower than previous highest
                    printf("Bid must be higher than current highest bid!\n");
                }
                break;
                
            case 4: // Exit program
                printf("\nGoodbye!");
                break;
                
            default: // If choice is not 1-4
                printf("\nInvalid choice! Please enter a number from 1 to 4.\n");
                break;
        }
    }
    
    return 0; // Return 0 to indicate successful program execution
}