//FormAI DATASET v1.0 Category: Digital Auction System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Cyberpunk themed Digital Auction System */

/* Declarations */
void menu();
void registration();
void login();
void auction();
void leaderboard();
void exitProgram();

/* Structure to store user details */
struct user {
    char username[25];
    char password[25];
    int wins;
    float balance;
} users[10];

/* Structure to store auction items */
struct item {
    char name[50];
    float price;
} items[10];

/* Global variables */
int numUsers = 0;
int numItems = 0;
int currentUser = -1;

/* Main function */
int main() {
    int choice;

    /* Initializing an item for testing purposes */
    strcpy(items[0].name, "Cyberdeck");
    items[0].price = 2000.00;
    numItems++;

    /* Main menu */
    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                registration();
                break;
            case 2:
                login();
                break;
            case 3:
                auction();
                break;
            case 4:
                leaderboard();
                break;
            case 5:
                exitProgram();
                break;
            default:
                printf("Invalid input!\n");
        }
    } while (choice != 5);

    return 0;
}

/* Function to display the main menu */
void menu() {
    printf("\n-----------------------\n");
    printf("CYBERPUNK AUCTION SYSTEM\n");
    printf("-----------------------\n");
    printf("1. Register\n");
    printf("2. Login\n");
    printf("3. Auction\n");
    printf("4. Leaderboard\n");
    printf("5. Exit\n");
    printf("-----------------------\n");
    printf("Enter your choice: ");
}

/* Function to register a new user */
void registration() {
    char name[25];
    char password[25];

    /* Checking if the max limit of users has been reached */
    if (numUsers == 10) {
        printf("Sorry, the maximum number of users has been reached.\n");
        return;
    }

    printf("-----------------------\n");
    printf("REGISTRATION\n");
    printf("-----------------------\n");

    /* Accepting user details from user */
    printf("Enter your username: ");
    scanf("%s", name);
    printf("Enter your password: ");
    scanf("%s", password);

    /* Storing the user details */
    strcpy(users[numUsers].username, name);
    strcpy(users[numUsers].password, password);
    users[numUsers].wins = 0;
    users[numUsers].balance = 5000.00;

    /* Updating number of users */
    numUsers++;
    printf("Registration successful!\n");
}

/* Function to login */
void login() {
    char name[25];
    char password[25];

    printf("-----------------------\n");
    printf("LOGIN\n");
    printf("-----------------------\n");

    /* Accepting user credentials */
    printf("Enter your username: ");
    scanf("%s", name);
    printf("Enter your password: ");
    scanf("%s", password);

    /* Checking if user exists */
    int i;
    for (i = 0; i < numUsers; i++) {
        if (strcmp(users[i].username, name) == 0 && strcmp(users[i].password, password) == 0) {
            currentUser = i;
            printf("Login successful!\n");
            return;
        }
    }
    printf("Invalid username/password!\n");
}

/* Function to start an auction */
void auction() {
    int i;
    int choice;
    float bid;

    /* Checking if user is logged in */
    if (currentUser == -1) {
        printf("Please login to participate in auction!\n");
        return;
    }

    printf("-----------------------\n");
    printf("AUCTION\n");
    printf("-----------------------\n");

    /* Displaying available items */
    printf("Available Items:\n");
    for (i = 0; i < numItems; i++) {
        printf("%d. %s - $%.2f\n", i+1, items[i].name, items[i].price);
    }

    /* Accepting user choice */
    printf("Enter the item you want to bid on: ");
    scanf("%d", &choice);
    choice--;

    /* Checking if item is valid */
    if (choice < 0 || choice >= numItems) {
        printf("Invalid item!\n");
        return;
    }

    /* Accepting user bid */
    printf("Enter your bid in dollars: $");
    scanf("%f", &bid);

    /* Checking if bid is higher than the current price */
    if (bid <= items[choice].price) {
        printf("Bid rejected. Your bid must be higher than the current price. Current price: $%.2f\n", items[choice].price);
        return;
    }

    /* Updating item price */
    items[choice].price = bid;
    printf("New bid accepted!\n");

    /* Selecting a winner if auction time has ended */
    srand(time(NULL));
    int winner = rand() % numUsers;  // Choosing a winner at random
    users[winner].balance -= items[choice].price;
    users[winner].wins++;
    printf("Auction for %s has ended. %s has won the auction for $%.2f!\n", items[choice].name, users[winner].username, items[choice].price);

    /* Updating user balance */
    users[currentUser].balance += items[choice].price;
}

/* Function to display leaderboard */
void leaderboard() {
    int i;

    printf("-----------------------\n");
    printf("LEADERBOARD\n");
    printf("-----------------------\n");

    /* Sorting users based on number of wins */
    for (i = 0; i < numUsers; i++) {
        int j = i;
        while (j > 0 && users[j-1].wins < users[j].wins) {
            struct user temp = users[j];
            users[j] = users[j-1];
            users[j-1] = temp;
            j--;
        }
    }

    /* Displaying the leaderboard */
    printf("Rank\tUsername\tWins\tBalance\n");
    for (i = 0; i < numUsers; i++) {
        printf("%d\t%s\t%d\t%.2f\n", i+1, users[i].username, users[i].wins, users[i].balance);
    }
}

/* Function to exit the program */
void exitProgram() {
    printf("Exiting program. Goodbye!\n");
}