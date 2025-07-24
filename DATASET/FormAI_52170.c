//FormAI DATASET v1.0 Category: Digital Auction System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 50
#define MAX_ITEMS 100

// User struct
typedef struct {
    char username[20];
    char password[20];
    float balance;
    int bids[MAX_ITEMS];
} User;

// Item struct
typedef struct {
    char name[50];
    int seller;
    float price;
    int bids;
    int bidders[MAX_USERS];
} Item;

int main() {
    int num_users = 0;
    User users[MAX_USERS];

    int num_items = 0;
    Item items[MAX_ITEMS];

    // Add user function
    void add_user() {
        printf("Enter username: ");
        scanf("%s", users[num_users].username);

        printf("Enter password: ");
        scanf("%s", users[num_users].password);

        printf("Enter balance: ");
        scanf("%f", &users[num_users].balance);

        // Set bids to -1 to indicate no bids
        for (int i = 0; i < MAX_ITEMS; i++) {
            users[num_users].bids[i] = -1;
        }

        num_users++;
        printf("User added successfully!\n");
    }

    // Add item function
    void add_item() {
        printf("Enter item name: ");
        scanf("%s", items[num_items].name);

        printf("Enter seller ID: ");
        scanf("%d", &items[num_items].seller);

        printf("Enter starting price: ");
        scanf("%f", &items[num_items].price);

        // Set bids and bidders to 0
        items[num_items].bids = 0;
        for (int i = 0; i < MAX_USERS; i++) {
            items[num_items].bidders[i] = 0;
        }

        num_items++;
        printf("Item added successfully!\n");
    }

    // Place bid function
    void place_bid() {
        int item_id;
        printf("Enter item ID: ");
        scanf("%d", &item_id);
        item_id--;

        int user_id;
        printf("Enter user ID: ");
        scanf("%d", &user_id);
        user_id--;

        float bid_amount;
        printf("Enter bid amount: ");
        scanf("%f", &bid_amount);

        // Check if bid is higher than current price
        if (bid_amount > items[item_id].price) {
            items[item_id].bidders[user_id] = 1;
            items[item_id].price = bid_amount;
            items[item_id].bids++;

            // Add bid to user's bids array
            int i = 0;
            while (users[user_id].bids[i] != -1) {
                i++;
            }
            users[user_id].bids[i] = item_id;

            printf("Bid placed successfully!\n");
        } else {
            printf("Bid must be higher than current price!\n");
        }
    }

    // Display items function
    void display_items() {
        for (int i = 0; i < num_items; i++) {
            printf("%d. %s (seller: %s, current price: %.2f)\n", i+1, items[i].name, users[items[i].seller].username, items[i].price);
            
            // Display bidders
            printf("Bidders:");
            for (int j = 0; j < num_users; j++) {
                if (items[i].bidders[j]) {
                    printf(" %s", users[j].username);
                }
            }
            printf("\n\n");
        }
    }

    // Main menu
    int choice;
    while (1) {
        printf("Digital Auction System\n");
        printf("------------------------\n");
        printf("1. Add user\n");
        printf("2. Add item\n");
        printf("3. Place bid\n");
        printf("4. Display items\n");
        printf("0. Exit\n");
        printf("------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_user();
                break;
            case 2:
                add_item();
                break;
            case 3:
                place_bid();
                break;
            case 4:
                display_items();
                break;
            case 0:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}