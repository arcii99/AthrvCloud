//FormAI DATASET v1.0 Category: Poker Game ; Style: multivariable
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 
  
#define DECK_SIZE 52 
#define HAND_SIZE 5 
  
char *deckSuit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"}; 
char *deckRank[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"}; 
  
typedef struct card { 
    int rank; 
    int suit; 
} Card; 
  
int getPlayerBet(int* playerChips); 
  
void createDeck(Card deck[]){ 
    int card = 0, suit = 0, rank = 0; 
  
    for (card = 0; card < DECK_SIZE; card++) { 
        deck[card].rank = card % 13; 
        deck[card].suit = card % 4; 
    } 
} 
  
void shuffleDeck(Card deck[]){ 
    srand(time(NULL)); 
    int i, j; 
    Card temp; 
  
    for (i = 0; i < DECK_SIZE; i++) { 
        j = rand() % DECK_SIZE; 
        temp = deck[i]; 
        deck[i] = deck[j]; 
        deck[j] = temp; 
    } 
} 
  
int getCardValue(Card card){ 
    if (card.rank >= 9){ 
        return 10; 
    } 
    else{ 
        return card.rank + 2; 
    } 
} 
  
int getHandValue(Card hand[]){ 
    int i, value = 0, aces = 0; 
    for (i = 0; i < HAND_SIZE; i++){ 
        value += getCardValue(hand[i]); 
        if (hand[i].rank == 12){ 
            aces++; 
        } 
    } 
    while (value > 21 && aces > 0){ 
        value -= 10; 
        aces--; 
    } 
    return value; 
} 
  
void printCard(Card card){ 
    printf("%s of %s", deckRank[card.rank], deckSuit[card.suit]); 
} 
  
void printHand(Card hand[]){ 
    int i; 
    for (i = 0; i < HAND_SIZE; i++){ 
        printCard(hand[i]); 
        printf("\n"); 
    } 
} 
  
void dealCards(Card deck[], Card dealerHand[], Card playerHand[]){ 
    dealerHand[0] = deck[0]; 
    dealerHand[1] = deck[1]; 
    playerHand[0] = deck[2]; 
    playerHand[1] = deck[3]; 
} 
  
void hit(Card deck[], Card hand[]){ 
    int i; 
    i = rand() % DECK_SIZE; 
    hand[HAND_SIZE] = deck[i]; 
} 
  
int getPlayerChoice(Card deck[], Card hand[], int* playerChips){ 
    int choice, playerValue; 
    printf("\nCurrent Hand:\n"); 
    printHand(hand); 
    playerValue = getHandValue(hand); 
    printf("Total value: %d\n", playerValue); 
    printf("What would you like to do?\n"); 
    printf("1 - Hit\n"); 
    printf("2 - Stand\n"); 
    printf("Your choice: "); 
    scanf("%d", &choice); 
    while (choice < 1 || choice > 2){ 
        printf("Invalid choice. Please try again.\n"); 
        printf("Your choice: "); 
        scanf("%d", &choice); 
    } 
    if (choice == 1){ 
        hit(deck, hand); 
        playerValue = getHandValue(hand); 
        printf("Your new card is:\n"); 
        printCard(hand[HAND_SIZE]); 
        printf("\n"); 
        printf("Your new total value is: %d\n", playerValue); 
        if (playerValue > 21){ 
            printf("Bust!\n"); 
            *playerChips -= getPlayerBet(playerChips); 
            return 0; 
        } 
        else{ 
            getPlayerChoice(deck, hand, playerChips); 
        } 
    } 
    else{ 
        printf("You stand.\n"); 
        return 1; 
    } 
} 
  
int getDealerChoice(Card deck[], Card hand[]){ 
    int dealerValue; 
    dealerValue = getHandValue(hand); 
    printf("\nDealer's Hand:\n"); 
    printHand(hand); 
    printf("Total value: %d\n", dealerValue); 
    while (dealerValue < 17){ 
        printf("Dealer hits.\n"); 
        hit(deck, hand); 
        dealerValue = getHandValue(hand); 
        printf("Dealer's new card is:\n"); 
        printCard(hand[HAND_SIZE]); 
        printf("\n"); 
        printf("Dealer's new total value is: %d\n", dealerValue); 
        if (dealerValue > 21){ 
            printf("Dealer busts!\n"); 
            return 1; 
        } 
    } 
    printf("Dealer stands.\n"); 
    return 0; 
} 
  
int playGame(int* playerChips){ 
    Card deck[DECK_SIZE]; 
    createDeck(deck); 
    shuffleDeck(deck); 
    Card dealerHand[HAND_SIZE]; 
    Card playerHand[HAND_SIZE]; 
    dealCards(deck, dealerHand, playerHand); 
    int dealerChoice, playerChoice, dealerValue, playerValue; 
    printf("\nDealer's Hand:\n"); 
    printCard(dealerHand[0]); 
    printf("\n\n"); 
    playerValue = getHandValue(playerHand); 
    dealerValue = getHandValue(dealerHand); 
    while (1){ 
        playerChoice = getPlayerChoice(deck, playerHand, playerChips); 
        if (playerChoice == 0){ 
            return 0; 
        } 
        dealerChoice = getDealerChoice(deck, dealerHand); 
        if (dealerChoice == 1){ 
            *playerChips += getPlayerBet(playerChips); 
            return 1; 
        } 
        if (playerValue > dealerValue){ 
            printf("You win!\n"); 
            *playerChips += getPlayerBet(playerChips); 
            return 1; 
        } 
        else{ 
            printf("Dealer wins.\n"); 
            *playerChips -= getPlayerBet(playerChips); 
            return 0; 
        } 
    } 
} 
  
int getPlayerBet(int* playerChips){ 
    int bet; 
    printf("You currently have %d chips.\n", *playerChips); 
    printf("How much would you like to bet? "); 
    scanf("%d", &bet); 
    while (bet < 1 || bet > *playerChips){ 
        printf("Invalid bet amount. Please try again.\n"); 
        scanf("%d", &bet); 
    } 
    *playerChips -= bet; 
    return bet; 
} 
  
int main(){ 
    int playerChips = 100; 
    char playAgain; 
    printf("Welcome to the C Poker Game!\n"); 
    printf("You will start with 100 chips.\n"); 
    while (playerChips > 0){ 
        playGame(&playerChips); 
        if (playerChips == 0){ 
            printf("\nYou're out of chips! Game over.\n"); 
        } 
        else{ 
            printf("\nWould you like to play again? (y/n) "); 
            scanf(" %c", &playAgain); 
            if (playAgain == 'n' || playAgain == 'N'){ 
                printf("\nYou ended with %d chips. Thanks for playing!\n", playerChips); 
                return 0; 
            } 
        } 
    } 
    return 0; 
}