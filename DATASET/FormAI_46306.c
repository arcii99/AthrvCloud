//FormAI DATASET v1.0 Category: Table Game ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_PLAYERS 4
#define NUM_CARDS 52

int cards[NUM_CARDS];   // array to keep track of available cards
int num_cards_left = NUM_CARDS;

pthread_mutex_t mutex;  // mutex for thread synchronization

void shuffle_cards() {
    // fill the cards array with values 1 to NUM_CARDS
    for (int i = 0; i < NUM_CARDS; i++) {
        cards[i] = i + 1;
    }
    
    // shuffle the cards randomly
    for (int i = NUM_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void* play_game(void* arg) {
    int player_id = *((int*)arg);
    int num_cards = NUM_CARDS / NUM_PLAYERS;
    int start_index = player_id * num_cards;
    int end_index = start_index + num_cards - 1;
    int sum = 0;
    
    // each player takes turns to draw a card and add its value to their sum
    for (int i = start_index; i <= end_index && num_cards_left > 0; i++) {
        // acquire mutex lock to access shared variables
        pthread_mutex_lock(&mutex);
        
        // check if there are still cards left to draw
        if (num_cards_left > 0) {
            int card_value = cards[i];
            num_cards_left--;
            sum += card_value;
            printf("Player %d draws card %d with value %d. Current sum: %d\n",
                   player_id, i+1, card_value, sum);
        }
        
        // release mutex lock
        pthread_mutex_unlock(&mutex);
    }
    
    printf("Player %d's final sum: %d\n", player_id, sum);
    pthread_exit(NULL);
}

int main() {
    // initialize mutex lock
    pthread_mutex_init(&mutex, NULL);
    
    // initialize random seed
    srand(time(NULL));
    
    // shuffle the cards
    shuffle_cards();
    
    // create threads for each player
    pthread_t threads[NUM_PLAYERS];
    int player_ids[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        player_ids[i] = i;
        pthread_create(&threads[i], NULL, play_game, &player_ids[i]);
    }
    
    // wait for all threads to finish
    for (int i = 0; i < NUM_PLAYERS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    // destroy mutex lock
    pthread_mutex_destroy(&mutex);
    
    return 0;
}