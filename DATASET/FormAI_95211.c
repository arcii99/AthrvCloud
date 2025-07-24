//FormAI DATASET v1.0 Category: Poker Game ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int deck[52];
    char suits[4][9] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char ranks[13][6] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    int hand[2];
    int dealerHand[2];
    int i, j, card, dealerCard;
    int dealerTotal = 0;
    int total = 0;
    char hitOrStand;
    int betAmount;
    int chips = 100;

    srand(time(NULL));

    for(i=0; i<52; i++) {
        deck[i] = i;
    }

    printf("\nWelcome to the Poker table!");
    printf("\nYou have %d chips.", chips);

    while(chips > 0) {
        printf("\n\nHow much would you like to bet? ");
        scanf("%d", &betAmount);

        while(betAmount < 1 || betAmount > chips) {
            printf("\nYour bet must be between 1 and %d. Enter your bet: ", chips);
            scanf("%d", &betAmount);
        }

        printf("\nDealing cards...\n");

        for(i=0; i<2; i++) {
            card = rand() % 52;
            hand[i] = card;
            printf("\nYou were dealt the %s of %s.", ranks[card%13], suits[card/13]);
            total += card%13 + 1;
        }

        printf("\n\nYour current hand total is %d.", total);

        dealerCard = rand() % 52;
        dealerHand[0] = dealerCard;
        printf("\nThe dealer is showing the %s of %s.", ranks[dealerCard%13], suits[dealerCard/13]);

        for(i=1; i<2; i++) {
            dealerCard = rand() % 52;
            dealerHand[i] = dealerCard;
            dealerTotal += dealerCard%13 + 1;
        }

        hitOrStand = 'h';

        while(hitOrStand == 'h') {
            printf("\n\nPress 'h' to hit or 's' to stand: ");
            scanf(" %c", &hitOrStand);

            if(hitOrStand == 'h') {
                card = rand() % 52;
                hand[i] = card;
                printf("\nYou were dealt the %s of %s.", ranks[card%13], suits[card/13]);
                total += card%13 + 1;
                i++;
                printf("\n\nYour current hand total is %d.", total);
            }
        }

        while(dealerTotal < 17) {
            dealerCard = rand() % 52;
            dealerHand[i] = dealerCard;
            dealerTotal += dealerCard%13 + 1;
            i++;
        }

        printf("\n\nThe dealer's hand is: ");

        for(j=0; j<i+1; j++) {
            printf("%s of %s ", ranks[dealerHand[j]%13], suits[dealerHand[j]/13]);
        }

        printf("\nThe dealer's hand total is %d.", dealerTotal);

        if(total > 21) {
            printf("\n\nBust! You lose your bet of %d chips.", betAmount);
            chips -= betAmount;
        }
        else if(dealerTotal > 21) {
            printf("\n\nThe dealer busts! You win %d chips.", betAmount);
            chips += betAmount;
        }
        else if(total > dealerTotal) {
            printf("\n\nYou win %d chips.", betAmount);
            chips += betAmount;
        }
        else if(total < dealerTotal) {
            printf("\n\nYou lose your bet of %d chips.", betAmount);
            chips -= betAmount;
        }
        else {
            printf("\n\nIt's a tie! Your bet is returned to you.");
        }

        printf("\n\nYou now have %d chips.", chips);

        total = 0;
        dealerTotal = 0;
    }

    printf("\n\nYou're all out of chips! Better luck next time.\n\n");

    return 0;
}