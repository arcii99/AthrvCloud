//FormAI DATASET v1.0 Category: Poker Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Global Variables
int chips = 500;
int playerHand[11];
int dealerHand[11];
int deck[52];

//Function Prototypes 
void createDeck();
void shuffleDeck();
void dealCards();
int calculateHand(int hand[], int cardCount);
void playGame();

int main(){
    srand(time(NULL));
    printf("Welcome to the Poker Game!\n");
    playGame();
    return 0;
}

void createDeck(){
    int index = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 2; j <= 14; j++){
            deck[index] = j;
            index++;
        }
    }
}

void shuffleDeck(){
    for(int i = 0; i < 52; i++){
        int randomIndex = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp; 
    }
}

void dealCards(){
    playerHand[0] = deck[0];
    dealerHand[0] = deck[1];
    playerHand[1] = deck[2];
    dealerHand[1] = deck[3];
}

int calculateHand(int hand[], int cardCount){
    int handValue = 0;
    int aceCount = 0;
    for(int i = 0; i < cardCount; i++){
        if(hand[i] >= 2 && hand[i] <= 10){
            handValue += hand[i];
        } else if(hand[i] >= 11 && hand[i] <= 13){
            handValue += 10;
        } else if(hand[i] == 14){
            aceCount++;
            handValue += 11;
        }
    }
    while(handValue > 21 && aceCount > 0){
        handValue -= 10;
        aceCount--;
    }
    return handValue;
}

void playGame(){
    while(1){
        createDeck();
        shuffleDeck();
        dealCards();

        int playerCards = 2;
        int dealerCards = 2;
        int playerHandValue = calculateHand(playerHand, playerCards);
        int dealerHandValue = calculateHand(dealerHand, dealerCards);
        int playerWin = 1; //0: tie, 1: player wins, 2: dealer wins

        printf("\nPlayer Hand: %d %d\n", playerHand[0], playerHand[1]);
        printf("Dealer Hand: %d X\n", dealerHand[0]);

        while(1){
            char input;
            printf("Would you like to hit or stand? (h/s): ");
            scanf(" %c", &input);

            if(input == 'h'){
                playerHand[playerCards] = deck[playerCards + dealerCards];
                printf("Player drew a %d\n", playerHand[playerCards]);
                playerCards++;
                playerHandValue = calculateHand(playerHand, playerCards);
                if(playerHandValue > 21){
                    printf("Player busts\n");
                    dealerHandValue = 0;
                    playerWin = 2;
                    break;
                }
            } else if(input == 's'){
                printf("Player stands\n");
                break;
            } else {
                printf("Invalid input. Try again.\n");
            }
        }

        if(playerWin != 2){
            printf("Dealer reveals his hand. It is %d %d\n", dealerHand[0], dealerHand[1]);
            while(dealerHandValue < 17){
                dealerHand[dealerCards] = deck[playerCards + dealerCards];
                printf("Dealer drew a %d\n", dealerHand[dealerCards]);
                dealerCards++;
                dealerHandValue = calculateHand(dealerHand, dealerCards);
                if(dealerHandValue > 21){
                    printf("Dealer busts\n");
                    playerWin = 1;
                }
            }
        }

        if(playerWin == 1){
            if(playerHandValue > dealerHandValue){
                printf("Player wins!\n");
            } else if(playerHandValue == dealerHandValue){
                printf("Tie!\n");
            } else {
                printf("Dealer wins!\n");
            }
            chips += 10;
        } else {
            printf("Dealer wins!\n");
            chips -= 10;
        }

        if(chips == 0){
            printf("You have run out of chips. Game over.\n");
            break;
        } else {
            printf("You now have %d chips.\n", chips);
        }

        char playAgain;
        printf("Would you like to play again? (y/n): ");
        scanf(" %c", &playAgain);
        if(playAgain == 'n'){
            break;
        }
    }
}