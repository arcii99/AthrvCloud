//FormAI DATASET v1.0 Category: Digital Auction System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int num_of_bidders;
    printf("Enter the number of bidders: ");
    scanf("%d", &num_of_bidders);

    char bidder_names[num_of_bidders][20];

    for(int i = 0; i<num_of_bidders; i++){
        printf("Enter bidder name %d: ", i+1);
        scanf("%s", &bidder_names[i]);
    }

    int bid_amount[num_of_bidders];
    for(int i = 0; i<num_of_bidders; i++){
        printf("Enter bid amount for %s: ", bidder_names[i]);
        scanf("%d", &bid_amount[i]);
    }

    // Randomly generating the winning bid amount
    srand(time(NULL));
    int winning_bid = bid_amount[rand()%num_of_bidders];

    printf("\nThe winning bid is: %d\n", winning_bid);

    // Checking the winners
    int winners[num_of_bidders];
    int num_winners = 0;

    for(int i = 0; i<num_of_bidders; i++){
        if(bid_amount[i] == winning_bid){
            winners[num_winners] = i;
            num_winners++;
        }
    }

    // Printing the winners
    printf("The winner(s) is/are: \n");
    for(int i = 0; i<num_winners; i++){
        printf("%s\n", bidder_names[winners[i]]);
    }

    return 0;
}