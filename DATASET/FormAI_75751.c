//FormAI DATASET v1.0 Category: Poker Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/* Define the maximum number of players */
#define MAX_PLAYERS 4

/* Define the maximum number of cards in a deck */
#define MAX_CARDS 52

/* Define the maximum length of player names */
#define MAX_NAME_LENGTH 20

/* Define the structure of a card */
typedef struct {
    char suit[10];
    char rank[5];
} Card;

/* Define the structure of a player */
typedef struct {
    char name[MAX_NAME_LENGTH];
    Card hand[5];
    int hand_value;
} Player;

/* Define the deck of cards */
Card deck[MAX_CARDS];

/* Define the players */
Player players[MAX_PLAYERS];
int num_players = 0;

/* Shuffle the deck of cards */
void shuffle_deck() {
    int i, j;
    Card temp;
    
    srand(time(NULL));
    
    for(i = 0; i < MAX_CARDS; i++) {
        j = rand() % MAX_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

/* Print a single card */
void print_card(Card card) {
    printf("| %s of %s   ", card.rank, card.suit);
}

/* Print a player's hand */
void print_hand(Player player) {
    int i;
    
    printf("%s's hand:\n", player.name);
    for(i = 0; i < 5; i++) {
        print_card(player.hand[i]);
    }
    printf("|\n");
}

/* Deal the initial hands to all players */
void deal_hands() {
    int i, j, k;
    
    for(i = 0; i < 5; i++) {
        for(j = 0; j < num_players; j++) {
            players[j].hand[i] = deck[i * num_players + j];
        }
    }
    
    for(k = 0; k < num_players; k++) {
        print_hand(players[k]);
    }
}

/* Calculate the value of a player's hand */
int calculate_hand_value(Player player) {
    int i, j;
    int num_aces = 0;
    int hand_value = 0;
    
    /* Calculate the value of the cards in the hand */
    for(i = 0; i < 5; i++) {
        if(strcmp(player.hand[i].rank, "Ace") == 0) {
            num_aces++;
            hand_value += 11;
        } else if(strcmp(player.hand[i].rank, "King") == 0 ||
                  strcmp(player.hand[i].rank, "Queen") == 0 ||
                  strcmp(player.hand[i].rank, "Jack") == 0) {
            hand_value += 10;
        } else {
            hand_value += atoi(player.hand[i].rank);
        }
    }
    
    /* Account for any aces that need to be counted as 1 instead of 11 */
    for(j = 0; j < num_aces; j++) {
        if(hand_value > 21) {
            hand_value -= 10;
        }
    }
    
    return hand_value;
}

/* Determine the winner of the game */
void determine_winner() {
    int i;
    int max_hand_value = 0;
    Player winner;
    
    /* Calculate the value of each player's hand */
    for(i = 0; i < num_players; i++) {
        players[i].hand_value = calculate_hand_value(players[i]);
    }
    
    /* Find the player with the highest hand value */
    for(i = 0; i < num_players; i++) {
        if(players[i].hand_value > max_hand_value && players[i].hand_value <= 21) {
            max_hand_value = players[i].hand_value;
            winner = players[i];
        }
    }
    
    /* Print the winner of the game */
    printf("\n%s wins with a hand value of %d!\n", winner.name, winner.hand_value);
}

int main() {
    int i;
    
    /* Initialize the deck of cards */
    char suits[4][10] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char ranks[13][5] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
    
    for(i = 0; i < MAX_CARDS; i++) {
        strcpy(deck[i].suit, suits[i / 13]);
        strcpy(deck[i].rank, ranks[i % 13]);
    }
    
    /* Prompt the user for the number of players */
    printf("Welcome to the Poker Game! Please enter the number of players (1-4): ");
    scanf("%d", &num_players);
    
    /* Prompt the user for each player's name */
    for(i = 0; i < num_players; i++) {
        printf("Enter your name Player %d: ", i+1);
        scanf("%s", players[i].name);
    }
    
    /* Shuffle the deck of cards */
    shuffle_deck();
    
    /* Deal the initial hands to all players */
    deal_hands();
    
    /* Determine the winner of the game */
    determine_winner();
    
    return 0;
}