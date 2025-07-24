//FormAI DATASET v1.0 Category: Poker Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function prototypes
void shuffleDeck(int deck[]);
int dealCards(int deck[], int hand[]);
void displayHand(int hand[]);
char getRank(int card);
char getSuit(int card);
int evaluateHand(int hand[]);
int checkPair(int hand[]);
int checkTwoPair(int hand[]);
int checkThreeOfAKind(int hand[]);
int checkStraight(int hand[]);
int checkFlush(int hand[]);
int checkFullHouse(int hand[]);
int checkFourOfAKind(int hand[]);
int checkStraightFlush(int hand[]);

//main function
int main(){
    int deck[52], playerHand[5], computerHand[5];
    char playAgain;
    int playerScore = 0, computerScore = 0;
    srand(time(NULL));

    do{
        printf("\n\n********** New Round **********\n");

        //shuffle deck and deal cards
        shuffleDeck(deck);
        dealCards(deck, playerHand);
        dealCards(deck, computerHand);

        //display hands
        printf("\nYour Hand: ");
        displayHand(playerHand);
        printf("\nComputer's Hand: ");
        displayHand(computerHand);

        //evaluate hands and determine winner
        playerScore = evaluateHand(playerHand);
        computerScore = evaluateHand(computerHand);

        if(playerScore > computerScore){
            printf("\nCongratulations! You win!");
        }
        else if(computerScore > playerScore){
            printf("\nSorry, the computer wins!");
        }
        else{
            printf("\nIt's a tie!");
        }

        //ask user if they want to play again
        printf("\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);

    }while(playAgain == 'Y' || playAgain == 'y');

    printf("\nThanks for playing!\n");

    return 0;
}

//function definitions

//shuffle the deck
void shuffleDeck(int deck[]){
    int i, randomIndex, temp;
    //initialize deck
    for(i=0; i<52; i++){
        deck[i] = i;
    }
    //shuffle deck using Fisher-Yates algorithm
    for(i=51; i>0; i--){
        randomIndex = rand() % (i+1);
        temp = deck[randomIndex];
        deck[randomIndex] = deck[i];
        deck[i] = temp;
    }
}

//deal cards to a hand
int dealCards(int deck[], int hand[]){
    static int topCard = 0;
    int i, card;
    for(i=0; i<5; i++){
        card = deck[topCard++];
        hand[i] = card;
    }
    return topCard;
}

//display hand
void displayHand(int hand[]){
    int i;
    char rank, suit;
    for(i=0; i<5; i++){
        rank = getRank(hand[i]);
        suit = getSuit(hand[i]);
        printf("%c%c ", rank, suit);
    }
}

//get the rank of a card
char getRank(int card){
    int rank = card % 13;
    switch(rank){
        case 0: return 'A';
        case 9: return 'T';
        case 10: return 'J';
        case 11: return 'Q';
        case 12: return 'K';
        default: return rank + '1';
    }
}

//get the suit of a card
char getSuit(int card){
    int suit = card / 13;
    switch(suit){
        case 0: return 'C';
        case 1: return 'D';
        case 2: return 'H';
        case 3: return 'S';
        default: return '?';
    }
}

//evaluate a hand and return its score
int evaluateHand(int hand[]){
    int score = 0;
    score = checkPair(hand);
    if(score < 2){
        score = checkTwoPair(hand);
    }
    if(score < 3){
        score = checkThreeOfAKind(hand);
    }
    if(score < 4){
        score = checkStraight(hand);
    }
    if(score < 5){
        score = checkFlush(hand);
    }
    if(score < 6){
        score = checkFullHouse(hand);
    }
    if(score < 7){
        score = checkFourOfAKind(hand);
    }
    if(score < 8){
        score = checkStraightFlush(hand);
    }
    return score;
}

//check for a pair
int checkPair(int hand[]){
    int i, j, pairs = 0;
    for(i=0; i<4; i++){
        for(j=i+1; j<5; j++){
            if(hand[i] % 13 == hand[j] % 13){
                pairs++;
            }
        }
    }
    return pairs;
}

//check for two pairs
int checkTwoPair(int hand[]){
    int i, j, pairs = 0;
    for(i=0; i<4; i++){
        for(j=i+1; j<5; j++){
            if(hand[i] % 13 == hand[j] % 13){
                pairs++;
            }
        }
    }
    if(pairs == 2){
        return 2;
    }
    else{
        return 0;
    }
}

//check for three of a kind
int checkThreeOfAKind(int hand[]){
    int i, j, k;
    for(i=0; i<3; i++){
        for(j=i+1; j<4; j++){
            for(k=j+1; k<5; k++){
                if(hand[i] % 13 == hand[j] % 13 && hand[j] % 13 == hand[k] % 13){
                    return 3;
                }
            }
        }
    }
    return 0;
}

//check for a straight
int checkStraight(int hand[]){
    int i, j, temp;
    //sort hand
    for(i=0; i<5; i++){
        for(j=i+1; j<5; j++){
            if(hand[i] % 13 > hand[j] % 13){
                temp = hand[i];
                hand[i] = hand[j];
                hand[j] = temp;
            }
        }
    }
    //check for Ace, 2, 3, 4, 5 straight
    if(hand[0] % 13 == 0 && hand[1] % 13 == 1 && hand[2] % 13 == 2 && hand[3] % 13 == 3 && hand[4] % 13 == 12){
        return 4;
    }
    //check for other straights
    for(i=0; i<4; i++){
        if(hand[i] % 13 != hand[i+1] % 13 - 1){
            return 0;
        }
    }
    return 4;
}

//check for a flush
int checkFlush(int hand[]){
    int i, suit = hand[0] / 13;
    for(i=1; i<5; i++){
        if(hand[i] / 13 != suit){
            return 0;
        }
    }
    return 5;
}

//check for a full house
int checkFullHouse(int hand[]){
    int i, j, threeOfAKind = 0, pair = 0;
    for(i=0; i<3; i++){
        for(j=i+1; j<4; j++){
            if(hand[i] % 13 == hand[j] % 13){
                if(hand[j] % 13 == hand[j+1] % 13){
                    threeOfAKind = 1;
                }
                else{
                    pair = 1;
                }
            }
        }
    }
    if(threeOfAKind && pair){
        return 6;
    }
    else{
        return 0;
    }
}

//check for four of a kind
int checkFourOfAKind(int hand[]){
    int i, j, k, l;
    for(i=0; i<2; i++){
        for(j=i+1; j<3; j++){
            for(k=j+1; k<4; k++){
                for(l=k+1; l<5; l++){
                    if(hand[i] % 13 == hand[j] % 13 && hand[j] % 13 == hand[k] % 13 && hand[k] % 13 == hand[l] % 13){
                        return 7;
                    }
                }
            }
        }
    }
    return 0;
}

//check for a straight flush
int checkStraightFlush(int hand[]){
    if(checkStraight(hand) && checkFlush(hand)){
        return 8;
    }
    else{
        return 0;
    }
}