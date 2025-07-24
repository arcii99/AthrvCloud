//FormAI DATASET v1.0 Category: Digital Auction System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Item {
    char name[50];
    int quantity;
    float base_price;
    float current_price;
    char seller_name[50];
    char buyer_name[50];
    int time_left;  // time left in seconds
};

int main()
{
    srand(time(0));  // initialize random seed

    // Initializing Auction Items
    struct Item items[10];
    strcpy(items[0].name, "iPhone XR");
    items[0].quantity = 1;
    items[0].base_price = 999.99;
    items[0].current_price = items[0].base_price;
    strcpy(items[0].seller_name, "John");
    items[0].time_left = 60;

    strcpy(items[1].name, "Samsung Galaxy S10");
    items[1].quantity = 1;
    items[1].base_price = 899.99;
    items[1].current_price = items[1].base_price;
    strcpy(items[1].seller_name, "Mike");
    items[1].time_left = 90;

    strcpy(items[2].name, "MacBook Pro");
    items[2].quantity = 1;
    items[2].base_price = 1599.99;
    items[2].current_price = items[2].base_price;
    strcpy(items[2].seller_name, "Linda");
    items[2].time_left = 120;

    // Start Auction
    int time_passed = 0;
    while (time_passed < 180)  // 3 minutes
    {
        // Display Current Auction Items
        printf("-------------------  Current Auction Items  -------------------\n");
        for (int i = 0; i < 3; i++)
        {
            printf("Item %d: %s\n", i+1, items[i].name);
            printf("Seller: %s\n", items[i].seller_name);
            printf("Base Price: %.2f\n", items[i].base_price);
            printf("Current Price: %.2f\n", items[i].current_price);
            printf("Time Left: %d seconds\n", items[i].time_left);
            printf("-------------------\n");
        }
        printf("Enter Item number (1-3) to Bid, or 0 to Skip: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 0)  // Skip Bid
        {
            printf("Skipping Bid!\n");
        }
        else if (choice > 0 && choice <= 3)  // Place Bid
        {
            choice--;  // Map to array index
            float bid_price;
            printf("Enter Bid Amount: ");
            scanf("%f", &bid_price);
            if (bid_price > items[choice].current_price)  // Accept Bid
            {
                strcpy(items[choice].buyer_name, "You");
                items[choice].current_price = bid_price;
                items[choice].time_left += rand() % 10;  // Increase Time Left randomly
                printf("Bid Accepted!\n");
            }
            else
            {
                printf("Bid Not Accepted! Please Enter a Higher Amount!\n");
            }
        }
        else  // Invalid Choice
        {
            printf("Invalid Choice! Please Enter a Correct Value!\n");
        }

        // Update Auction Items
        for (int i = 0; i < 3; i++)
        {
            if (items[i].time_left > 0)
            {
                items[i].time_left--;
            }
            else  // Auction Ended for Item i
            {
                printf("Auction Ended for Item %d: %s\n", i+1, items[i].name);
                printf("Winner: %s\n", items[i].buyer_name);
                printf("Final Price: %.2f\n", items[i].current_price);
                printf("-------------------\n");

                // Reset Item i
                items[i].quantity--;
                items[i].current_price = items[i].base_price;
                strcpy(items[i].seller_name, items[i].buyer_name);
                strcpy(items[i].buyer_name, "");
                items[i].time_left = rand() % 60 + 60;  // Random Time Left between 60 and 119 seconds
            }
        }

        time_passed++;
        printf("Time Passed: %d seconds\n", time_passed);
        printf("----------------------------------------------------------------\n");
    }

    return 0;
}