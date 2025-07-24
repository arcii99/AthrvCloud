//FormAI DATASET v1.0 Category: Digital Auction System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct bidder {
    char name[50];
    int bid;
};

int main() {
    struct bidder person[10];
    int num_bidders;

    printf("Welcome to the Digital Auction System!\n\n");

    printf("Enter the number of bidders (maximum 10): ");
    scanf("%d", &num_bidders);

    for (int i = 0; i < num_bidders; i++) {
        printf("\nBidder # %d details:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", person[i].name);
        printf("Enter bid amount: ");
        scanf("%d", &person[i].bid);
    }

    printf("\n\nAuction Results: \n\n");
    int highest_bidder = 0;
    for (int i = 1; i < num_bidders; i++) {
        if (person[highest_bidder].bid < person[i].bid) {
            highest_bidder = i;
        }
    }

    printf("The highest bidder is %s with a bid of $%d.\n", person[highest_bidder].name, person[highest_bidder].bid);

    return 0;
}