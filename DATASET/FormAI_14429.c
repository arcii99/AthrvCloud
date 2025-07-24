//FormAI DATASET v1.0 Category: Poker Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52

static int deck[DECK_SIZE];
static int current_card = 0;
static int player_total = 0;
static int dealer_total = 0;
static int player_wins = 0;
static int dealer_wins = 0;

enum suit {HEARTS, DIAMONDS, CLUBS, SPADES};
enum card {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};

typedef struct {
    enum card card;
    enum suit suit;
} Card;

/**
 * Swap two elements in an array
 * 
 * @param arr The array
 * @param i Index of first element
 * @param j Index of second element
 */
void swap(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/**
 * Shuffle the deck of cards
 */
void shuffle_deck() {
    // Fill the deck with cards
    for(int i = 0; i < DECK_SIZE; i++) {
        deck[i] = i;
    }
  
    // Shuffle the deck
    for(int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        swap(deck, i, j);
    }
}

/**
 * Convert a card's value to a string
 * 
 * @param card_value The card value
 * @return The card's string representation
 */
char* card_to_string(int card_value) {
    enum suit suit = card_value / 13;
    enum card card = card_value % 13;
    char* card_str = malloc(sizeof(char) * 3);
    switch(card) {
        case ACE:
            sprintf(card_str, "%s", "A");
            break;
        case JACK:
            sprintf(card_str, "%s", "J");
            break;
        case QUEEN:
            sprintf(card_str, "%s", "Q");
            break;
        case KING:
            sprintf(card_str, "%s", "K");
            break;
        default:
            sprintf(card_str, "%d", card + 1);
    }
    char* suit_str = "";
    switch(suit) {
        case HEARTS:
            suit_str = "H";
            break;
        case DIAMONDS:
            suit_str = "D";
            break;
        case CLUBS:
            suit_str = "C";
            break;
        case SPADES:
            suit_str = "S";
            break;
    }
    char* full_card_str = malloc(sizeof(char) * 5);
    sprintf(full_card_str, "%s%s", card_str, suit_str);
    return full_card_str;
}

/**
 * Get the value of a card
 * 
 * @param card_value The card value
 * @return The card's value
 */
int get_card_value(int card_value) {
    enum card card = card_value % 13;    
    switch(card) {
        case ACE:
            return 11;
        case JACK:
        case QUEEN:
        case KING:
            return 10;
        default:
            return card + 1;
    }
}

/**
 * Print the current state of the game
 * 
 * @param show_dealer_cards Whether to show the dealer's cards
 */
void print_game_state(int show_dealer_cards) {
    printf("Dealer's hand: ");
    if(show_dealer_cards) {
        for(int i = 0; i < 2; i++) {
            printf("%s ", card_to_string(deck[i]));
        }
        printf("??");
    } else {
        for(int i = 0; i < current_card; i++) {
            printf("%s ", card_to_string(deck[i]));
        }
        printf("(%d)", dealer_total);
    }
    printf("\n");
    printf("Your hand: ");
    for(int i = current_card; i < DECK_SIZE; i++) {
        printf("%s ", card_to_string(deck[i]));
    }
    printf("(%d)", player_total);
    printf("\n");
    printf("Wins: Dealer=%d You=%d\n\n", dealer_wins, player_wins);
}

/**
 * Play the dealer's turn
 */
void dealer_play() {
    while(dealer_total < 17) {
        dealer_total += get_card_value(deck[current_card]);
        current_card++;
    }
}

/**
 * Play another round of poker
 * 
 * @return 1 if the game continues, 0 if it ends
 */
int play_round() {
    // Check if the deck needs to be reshuffled
    if(DECK_SIZE - current_card < 10) {
        shuffle_deck();
        printf("Deck reshuffled\n");
    }
  
    // Deal first cards to player and dealer
    player_total = 0;
    dealer_total = 0;
    for(int i = 0; i < 2; i++) {
        player_total += get_card_value(deck[current_card]);
        current_card++;
        dealer_total += get_card_value(deck[current_card]);
        current_card++;
    }
  
    printf("NEW ROUND\n");
    print_game_state(1);
  
    // Player's turn
    while(1) {
        printf("Hit or stand? ");
        char input[10];
        fgets(input, 10, stdin);
        if(input[0] == 'h') {
            player_total += get_card_value(deck[current_card]);
            current_card++;
            print_game_state(1);
            if(player_total > 21) {
                printf("You bust! Dealer wins\n");
                dealer_wins++;
                return 1;
            }
        } else {
            printf("You stand with a total of %d\n", player_total);
            break;
        }
    }
  
    // Dealer's turn
    dealer_play();
    print_game_state(0);
  
    // Determine winner
    if(dealer_total > 21) {
        printf("Dealer busts! You win\n");
        player_wins++;
    } else if(player_total > dealer_total) {
        printf("You win!\n");
        player_wins++;
    } else if(player_total < dealer_total) {
        printf("Dealer wins\n");
        dealer_wins++;
    } else {
        printf("It's a tie\n");
    }
  
    return 1;
}

/**
 * Play the game until the player decides to quit
 */
void play_game() {
    while(1) {
        printf("Play another round? (y or n) ");
        char input[10];
        fgets(input, 10, stdin);
        if(input[0] == 'n') {
            printf("Thanks for playing!\n");
            break;
        }
        if(!play_round()) {
            break;
        }
    }
}

int main() {
    // Initialize random number generator
    srand(time(NULL));
  
    // Shuffle the deck
    shuffle_deck();
  
    // Play the game
    play_game();
    return 0;
}