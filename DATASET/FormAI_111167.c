//FormAI DATASET v1.0 Category: Poker Game ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Function to get the suit name*/
char* getSuit(int s) {
    char* suitName;
    switch(s) {
        case 0:
            suitName = "Hearts";
            break;
        case 1:
            suitName = "Diamonds";
            break;
        case 2:
            suitName = "Clubs";
            break;
        case 3:
            suitName = "Spades";
            break;
        default:
            suitName = "";
            break;
    }
    return suitName;
}

/*Function to get the rank name*/
char* getRank(int r) {
    char* rankName;
    switch(r) {
        case 1:
            rankName = "Ace";
            break;
        case 11:
            rankName = "Jack";
            break;
        case 12:
            rankName = "Queen";
            break;
        case 13:
            rankName = "King";
            break;
        default:
            rankName = (char*) (r+'0');
            break;
    }
    return rankName;
}

int main() {
    int i, j, cardCount, cardDeck[52]; //cardDeck contains 52 cards
    srand(time(0)); //Random seed
    char* rankName, *suitName;
    printf("Welcome to Poker Game!\n");
    printf("We have shuffled the deck, let's start.\n");
    for (i=0; i<52; i++) {
        cardDeck[i] = i; //Assigning the cards
    }
    for (i=51; i>0; i--) {
        j = rand() % (i+1);
        int temp = cardDeck[i];
        cardDeck[i] = cardDeck[j];
        cardDeck[j] = temp; //Swapping the cards randomly
    }
    while(1) {
        char choice;
        int playerHand[5], dealerHand[5], pSum=0, dSum=0;
        /*Initializing player and dealer hands*/
        for (i=0; i<5; i++) {
            playerHand[i] = cardDeck[cardCount];
            cardCount++;
            dealerHand[i] = cardDeck[cardCount];
            cardCount++;
        }
        printf("\nPlayer's Hand:");
        for (i=0; i<5; i++) {
            suitName = getSuit(playerHand[i]/13);
            rankName = getRank(playerHand[i]%13+1);
            printf("\n%s of %s", rankName, suitName);
            pSum += (playerHand[i]%13+1);
        }
        printf("\nTotal: %d", pSum);
        printf("\n\nDealer's Hand:\n");
        suitName = getSuit(dealerHand[0]/13);
        rankName = getRank(dealerHand[0]%13+1);
        printf("\n%s of %s", rankName, suitName);
        printf("\n\nDo you want to hit or stand?(h/s): ");
        scanf(" %c", &choice);
        if (choice == 'h' || choice == 'H') {
            playerHand[4] = cardDeck[cardCount];
            cardCount++;
            printf("\nPlayer's Hand:");
            for (i=0; i<5; i++) {
                suitName = getSuit(playerHand[i]/13);
                rankName = getRank(playerHand[i]%13+1);
                printf("\n%s of %s", rankName, suitName);
                pSum += (playerHand[i]%13+1);
            }
            printf("\nTotal: %d", pSum);
            if (pSum > 21) {
                printf("\nBusted! You have lost!");
                break;
            }
        }
        printf("\n\nDealer's Hand:\n");
        for (i=0; i<5; i++) {
            suitName = getSuit(dealerHand[i]/13);
            rankName = getRank(dealerHand[i]%13+1);
            printf("\n%s of %s", rankName, suitName);
            dSum += (dealerHand[i]%13+1);
        }
        while (dSum < 16) {
            dealerHand[4] = cardDeck[cardCount];
            cardCount++;
            printf("\n\nDealer's draw:");
            suitName = getSuit(dealerHand[4]/13);
            rankName = getRank(dealerHand[4]%13+1);
            printf("\n%s of %s", rankName, suitName);
            dSum += (dealerHand[4]%13+1);
        }
        printf("\n\nDealer's Total: %d", dSum);
        if (dSum > 21) {
            printf("\nDealer busted! You have won!");
        }
        else if (pSum > dSum) {
            printf("\nYou Won!");
        }
        else if (pSum < dSum) {
            printf("\nDealer Wins!");
        }
        else {
            printf("\nIt's a tie!");
        }
        printf("\nDo you want to play again?(y/n): ");
        scanf(" %c", &choice);
        if (choice == 'n' || choice == 'N') {
            printf("\n\nThanks for playing Poker Game!\n");
            break;
        }
    }
    return 0;
}