//FormAI DATASET v1.0 Category: Poker Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the deck of cards 
void shuffle(int card_deck[], int n) 
{ 
    // Initialize seed rand() 
    srand(time(NULL)); 
  
    // Shuffle the deck 
    for (int i = n - 1; i > 0; i--) { 
        // Generate a random index 
        int j = rand() % (i + 1); 
  
        // Swap the random card with the current card 
        int temp = card_deck[i]; 
        card_deck[i] = card_deck[j]; 
        card_deck[j] = temp; 
    } 
} 

// Function to print the hand of the player 
void print_hand(int hand[], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        printf("%d ", hand[i]); 
    } 
    printf("\n"); 
} 

// Function to determine the winner among the players 
void determine_winner(int player_1[], int player_2[], int n) 
{ 
    int sum_player_1 = 0, sum_player_2 = 0; 
  
    // Calculate the sum of each player's hand 
    for (int i = 0; i < n; i++) { 
        sum_player_1 += player_1[i]; 
        sum_player_2 += player_2[i]; 
    } 
  
    // Determine the winner 
    if (sum_player_1 > sum_player_2) { 
        printf("Player 1 wins!\n"); 
    } 
    else if (sum_player_2 > sum_player_1) { 
        printf("Player 2 wins!\n"); 
    } 
    else { 
        printf("It's a tie!\n"); 
    } 
} 

int main() 
{ 
    int n = 5; // Number of cards in player's hand 
    int card_deck[52]; // Array to represent a deck of cards 
  
    // Populate the deck with cards from 1 to 13 
    for (int i = 0; i < 52; i++) { 
        card_deck[i] = (i % 13) + 1; 
    } 
  
    // Shuffle the deck 
    shuffle(card_deck, 52); 
  
    // Divide the deck among the two players 
    int player_1[n], player_2[n]; 
    for (int i = 0; i < n; i++) { 
        player_1[i] = card_deck[i]; 
        player_2[i] = card_deck[n + i]; 
    } 
  
    // Print each player's hand 
    printf("Player 1 hand: "); 
    print_hand(player_1, n); 
    printf("Player 2 hand: "); 
    print_hand(player_2, n); 
  
    // Determine the winner 
    determine_winner(player_1, player_2, n); 
  
    return 0; 
}