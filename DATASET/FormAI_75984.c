//FormAI DATASET v1.0 Category: Poker Game ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/*Function to generate random card*/
int generateCard() {
    int card = rand() % 13 + 1;     //generating a random number between 1 and 13
    return card;
}

/*Function to convert card number to face value*/
char* getCardFaceValue(int card) {
    switch(card) {
        case 1: return "Ace";
        case 2: return "2";
        case 3: return "3";
        case 4: return "4";
        case 5: return "5";
        case 6: return "6";
        case 7: return "7";
        case 8: return "8";
        case 9: return "9";
        case 10: return "10";
        case 11: return "Jack";
        case 12: return "Queen";
        case 13: return "King";
    }
}

/*Function to generate card suit*/
char* generateSuit() {
    char* suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int index = rand() % 4;
    return suit[index];
}

/*Main function*/
int main() {
    int playerCard1 = generateCard();
    int playerCard2 = generateCard();
    int dealerCard1 = generateCard();
    int dealerCard2 = generateCard();

    printf("Player Cards: ");
    printf("%s of %s, ", getCardFaceValue(playerCard1), generateSuit());
    printf("%s of %s\n", getCardFaceValue(playerCard2), generateSuit());

    printf("Dealer Cards: ");
    printf("%s of %s, ", getCardFaceValue(dealerCard1), generateSuit());
    printf("%s of %s\n", getCardFaceValue(dealerCard2), generateSuit());

    return 0;
}