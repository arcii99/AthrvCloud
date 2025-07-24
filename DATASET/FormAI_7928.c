//FormAI DATASET v1.0 Category: Poker Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 4 // Number of Players
#define CARD_COUNT 52 // Total Number of cards

sem_t semaphore; // Semaphore to indicate game turn

int deck[CARD_COUNT]; // Array to represent deck of cards
int top = -1; // Index of top card in the deck
int *playerCards; // Array to store each player's cards
int currentPlayer = 0; // Index to track current player
int winner = -1; // Index of winner
int gameOn = 1; // Flag to indicate if game is still on

void shuffleDeck(){
    // Function to create a shuffled deck of cards
    for(int i = 0; i < CARD_COUNT; i++){
        deck[i] = i + 1; // Assign each card a unique value
    }
    for(int i = CARD_COUNT-1; i > 0; i--){
        int j = rand() % (i+1); // Randomly select a card to swap with
        int temp = deck[i]; // Swap the cards
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void distributeCards(){
    // Function to distribute the cards among players
    playerCards = malloc(sizeof(int) * NUM_THREADS);
    for(int i = 0; i < NUM_THREADS; i++){
        playerCards[i] = 0;
    }
    for(int i = 0; i < CARD_COUNT; i++){
        playerCards[i%NUM_THREADS]++; // Distribute cards in round-robin fashion
    }
}

void drawCard(){
    // Function to draw a card from the deck
    if(top == CARD_COUNT-1){ // Check if no more cards are available
        gameOn = 0;
        return;
    }
    top++; // Move the top card index
}

int evaluateHand(){
    // Function to evaluate the hand of the current player
    int handValue = 0;
    for(int i = 0; i < playerCards[currentPlayer]; i++){
        int cardValue = deck[top-i]; // Get the value of the card
        if(cardValue > 39){ // Assign value to face cards
            cardValue = 10;
        }
        else{ // Assign value to number cards
            cardValue = (cardValue % 13) + 1;
        }
        handValue += cardValue; // Add up the total hand value
    }
    return handValue;
}

void *playerTurn(void *threadId){
    // Function to handle each player's turn
    long id = (long)threadId;
    while(gameOn){
        sem_wait(&semaphore); // Wait for the semaphore signal
        if(currentPlayer == id){
            drawCard(); // Draw a new card
            int handValue = evaluateHand(); // Evaluate the hand
            printf("Player %ld drew a card and has a hand value of %d.\n", id, handValue);
            if(handValue >= 21){ // Check if the player has busted
                printf("Player %ld has busted!\n", id);
            }
            else if(handValue == 21){ // Check if the player has won
                winner = id;
                gameOn = 0;
            }
        }
        sem_post(&semaphore); // Signal that the turn has ended
    }
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    srand(time(NULL)); // Initialize random seed
    sem_init(&semaphore, 0, 1); // Initialize the semaphore
    shuffleDeck(); // Shuffle the deck
    distributeCards(); // Distribute the cards
    for(long t = 0; t < NUM_THREADS; t++){ // Create player threads
        pthread_create(&threads[t], NULL, playerTurn, (void *)t);
    }
    for(int i = 0; i < CARD_COUNT; i++){ // Loop through each round
        currentPlayer = i%NUM_THREADS; // Set current player index
        sem_post(&semaphore); // Signal the first player's turn
        while(sem_trywait(&semaphore) != 0){ // Wait for each player's turn to finish
            if(!gameOn){
                break; // End game if all cards have been played
            }
        }
        if(!gameOn){
            break; // End game if all cards have been played
        }
    }
    for(int i = 0; i < NUM_THREADS; i++){ // Join player threads
        pthread_join(threads[i], NULL);
    }
    if(winner != -1){ // Declare the winner
        printf("Player %d has won the game!\n", winner);
    }
    else{
        printf("No winner! All players have busted.\n");
    }
    sem_destroy(&semaphore); // Destroy the semaphore
    free(playerCards); // Free memory allocated for player cards
    return 0;
}