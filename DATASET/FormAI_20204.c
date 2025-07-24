//FormAI DATASET v1.0 Category: Poker Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DECK_SIZE 52
#define HAND_SIZE 2
#define MAX_PLAYERS 6

typedef struct player {
    char name[100];
    int chips;
    int handValue;
    int hand[HAND_SIZE];
} player;

void shuffleDeck(int *deck) {
    srand(time(0));
    int temp, randIndex;
    for(int i = 0; i < DECK_SIZE; i++) {
        randIndex = rand() % DECK_SIZE;
        temp = deck[i];
        deck[i] = deck[randIndex];
        deck[randIndex] = temp;
    }
}

void printDeck(int *deck) {
    printf("Deck:\n");
    for(int i = 0; i < DECK_SIZE; i++) {
        printf("%d ", deck[i]);
        if((i+1) % 13 == 0) printf("\n");
    }
    printf("\n");
}

void dealCards(int *deck, int numPlayers, player *players) {
    for(int i = 0; i < numPlayers; i++) {
        for(int j = 0; j < HAND_SIZE; j++) {
            players[i].hand[j] = deck[(i*HAND_SIZE) + j];
        }
    }
}

int getFaceValue(int card) {
    return card % 13;
}

int getHandValue(int hand[]) {
    int handValue = 0, numAces = 0;
    for(int i = 0; i < HAND_SIZE; i++) {
        int faceValue = getFaceValue(hand[i]);
        if(faceValue > 9) handValue += 10;
        else if(faceValue == 0) { handValue += 11; numAces++; }
        else handValue += faceValue + 1;
    }
    while(handValue > 21 && numAces > 0) {
        handValue -= 10;
        numAces--;
    }
    return handValue;
}

void printHand(player p) {
    printf("%s's Hand: ", p.name);
    for(int i = 0; i < HAND_SIZE; i++) {
        int card = p.hand[i];
        int faceValue = getFaceValue(card);
        if(faceValue == 0) printf("A");
        else if(faceValue == 10) printf("T");
        else if(faceValue == 11) printf("J");
        else if(faceValue == 12) printf("Q");
        else if(faceValue == 13) printf("K");
        else printf("%d", faceValue + 1);
        printf((i == HAND_SIZE - 1) ? "\n" : " ");
    }
}

void printPlayers(int numPlayers, player *players) {
    for(int i = 0; i < numPlayers; i++) {
        printf("%s (%d chips) - Hand Value: %d\n", players[i].name, players[i].chips, players[i].handValue);
        printHand(players[i]);
    }
}

void placeBets(int numPlayers, player *players) {
    for(int i = 0; i < numPlayers; i++) {
        printf("%s, how many chips do you want to bet? ", players[i].name);
        scanf("%d", &players[i].chips);
        while(players[i].chips < 1 || players[i].chips > players[i].chips) {
            printf("Invalid bet, please bet between 1 and %d: ", players[i].chips);
            scanf("%d", &players[i].chips);
        }
    }
    printf("\n");
}

void playHand(int numPlayers, player *players, int *deck) {
    for(int i = 0; i < numPlayers; i++) {
        players[i].handValue = getHandValue(players[i].hand);
        printf("\n=====================================\n");
        printHand(players[i]);
        printf("Hand Value: %d\n", players[i].handValue);
        if(players[i].handValue == 21) {
            printf("BLACKJACK! %s wins %d chips!\n", players[i].name, players[i].chips);
            players[i].chips *= 2;
            continue;
        }
        char choice[10];
        printf("What do you want to do? (hit/stay) ");
        scanf("%s", choice);
        while(strcmp(choice, "hit") != 0 && strcmp(choice, "stay") != 0) {
            printf("Invalid choice, please choose hit or stay: ");
            scanf("%s", choice);
        }
        while(strcmp(choice, "hit") == 0) {
            int newCard = deck[rand() % DECK_SIZE];
            printf("Hit! Card: ");
            if(getFaceValue(newCard) == 0) printf("A\n");
            else if(getFaceValue(newCard) == 10) printf("T\n");
            else if(getFaceValue(newCard) == 11) printf("J\n");
            else if(getFaceValue(newCard) == 12) printf("Q\n");
            else if(getFaceValue(newCard) == 13) printf("K\n");
            else printf("%d\n", getFaceValue(newCard) + 1);
            players[i].hand[2] = newCard;
            players[i].handValue = getHandValue(players[i].hand);
            printf("New Hand Value: %d\n", players[i].handValue);
            if(players[i].handValue > 21) {
                printf("BUST! %s loses %d chips.\n", players[i].name, players[i].chips);
                players[i].chips = 0;
                break;
            }
            printf("What do you want to do? (hit/stay) ");
            scanf("%s", choice);
            while(strcmp(choice, "hit") != 0 && strcmp(choice, "stay") != 0) {
                printf("Invalid choice, please choose hit or stay: ");
                scanf("%s", choice);
            }
        }
    }
}

void declareWinner(int numPlayers, player *players) {
    int maxHandValue = -1, numWinners = 0;
    player *winners[MAX_PLAYERS];
    for(int i = 0; i < numPlayers; i++) {
        if(players[i].handValue > maxHandValue) {
            maxHandValue = players[i].handValue;
            numWinners = 1;
            winners[0] = &players[i];
        } else if(players[i].handValue == maxHandValue) {
            winners[numWinners] = &players[i];
            numWinners++;
        }
    }
    printf("\n=====================================\n");
    printf("Results:\n");
    for(int i = 0; i < numWinners; i++) {
        int winnings = winners[i]->chips * 2;
        printf("%s wins the hand with %d chips and a hand value of %d!\n", winners[i]->name, winners[i]->chips, winners[i]->handValue);
        winners[i]->chips = winnings;
    }
    printf("=====================================\n");
}

int main() {
    int deck[DECK_SIZE];
    for(int i = 0; i < DECK_SIZE; i++) deck[i] = (i % 13) + 1;
    shuffleDeck(deck);

    int numPlayers;
    printf("Welcome to C Poker Game! How many players are playing? ");
    scanf("%d", &numPlayers);
    while(numPlayers < 1 || numPlayers > 6) {
        printf("Invalid number of players, please choose between 1 and 6: ");
        scanf("%d", &numPlayers);
    }
    printf("\n");

    player players[MAX_PLAYERS];
    for(int i = 0; i < numPlayers; i++) {
        printf("Player %d, enter your name: ", i+1);
        scanf("%s", players[i].name);
        players[i].chips = 50;
    }

    int round = 1;
    while(1) {
        printf("Round %d:\n", round);
        shuffleDeck(deck);
        dealCards(deck, numPlayers, players);
        printPlayers(numPlayers, players);
        placeBets(numPlayers, players);
        playHand(numPlayers, players, deck);
        declareWinner(numPlayers, players);
        int numPlayersLeft = 0;
        for(int i = 0; i < numPlayers; i++) {
            if(players[i].chips > 0) numPlayersLeft++;
        }
        if(numPlayersLeft == 1) {
            printf("Game over, %s has won with a total of %d chips!\n", players[0].name, players[0].chips);
            break;
        }
        printf("=====================================\n\n");
        round++;
    }
    return 0;
}