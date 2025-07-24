//FormAI DATASET v1.0 Category: Poker Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4

#define CLUBS 0
#define DIAMONDS 1
#define HEARTS 2
#define SPADES 3

#define JACK 11
#define QUEEN 12
#define KING 13
#define ACE 14

typedef struct {
    int value;
    int suit;
} Card;

typedef struct {
    Card hand[5];
    int score;
} Hand;

Card deck[NUM_CARDS];
int num_cards_drawn = 0;
Hand player_hand, dealer_hand;

// Function prototypes
void shuffle();
Card draw_card();
void print_card(Card card);
void print_hand(Hand hand);
void evaluate_hand(Hand *hand);
void player_turn();
void dealer_turn();

int main() {
    srand(time(NULL));
    shuffle();

    // Deal two cards to the player and dealer
    player_hand.hand[0] = draw_card();
    player_hand.hand[1] = draw_card();
    dealer_hand.hand[0] = draw_card();
    dealer_hand.hand[1] = draw_card();

    // Print the initial hands
    printf("Your hand:\n");
    print_hand(player_hand);
    printf("\nDealer's hand:\n");
    print_card(dealer_hand.hand[0]);
    printf(" [HIDDEN]\n\n");

    // Player turn
    player_turn();

    // If the player hasn't busted, it's the dealer's turn
    if (player_hand.score <= 21) {
        dealer_turn();
    }

    // Determine winner
    if (dealer_hand.score > 21) {
        printf("Dealer busts! You win!\n");
    } else if (player_hand.score > dealer_hand.score) {
        printf("You win!\n");
    } else if (player_hand.score < dealer_hand.score) {
        printf("Dealer wins!\n");
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}

void shuffle() {
    int i, j, temp_value, temp_suit;
    for (i = 0; i < NUM_CARDS; i++) {
        deck[i].value = (i % NUM_RANKS) + 2;
        deck[i].suit = i / NUM_RANKS;
    }
    for (i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp_value = deck[i].value;
        temp_suit = deck[i].suit;
        deck[i].value = deck[j].value;
        deck[i].suit = deck[j].suit;
        deck[j].value = temp_value;
        deck[j].suit = temp_suit;
    }
}

Card draw_card() {
    Card card = deck[num_cards_drawn];
    num_cards_drawn++;
    return card;
}

void print_card(Card card) {
    switch (card.value) {
        case JACK:
            printf("J");
            break;
        case QUEEN:
            printf("Q");
            break;
        case KING:
            printf("K");
            break;
        case ACE:
            printf("A");
            break;
        default:
            printf("%d", card.value);
            break;
    }
    switch (card.suit) {
        case CLUBS:
            printf("C ");
            break;
        case DIAMONDS:
            printf("D ");
            break;
        case HEARTS:
            printf("H ");
            break;
        case SPADES:
            printf("S ");
            break;
    }
}

void print_hand(Hand hand) {
    int i;
    for (i = 0; i < 5; i++) {
        if (hand.hand[i].value != 0) {
            print_card(hand.hand[i]);
            printf(" ");
        }
    }
    printf("(%d)", hand.score);
}

void evaluate_hand(Hand *hand) {
    int i, num_aces = 0, total = 0;
    // Count number of Aces in the hand
    for (i = 0; i < 5; i++) {
        if (hand->hand[i].value == ACE) {
            num_aces++;
        }
    }
    // Calculate score without Aces
    for (i = 0; i < 5; i++) {
        if (hand->hand[i].value != ACE) {
            total += hand->hand[i].value > 10 ? 10 : hand->hand[i].value;
        }
    }
    // Determine whether to count Aces as 1 or 11
    if (num_aces == 1 && total + 11 > 21) {
        total += 1;
    } else if (num_aces > 1) {
        total += num_aces - 1;
        if (total + 11 <= 21) {
            total += 11;
        } else {
            total += 1;
        }
    } else {
        total += num_aces * 11;
    }
    hand->score = total;
}

void player_turn() {
    char input;
    while (1) {
        printf("Would you like to hit (h) or stand (s)? ");
        input = getchar();
        while (getchar() != '\n'); // Clear input buffer
        if (input == 'h') {
            player_hand.hand[2] = draw_card();
            evaluate_hand(&player_hand);
            printf("Your hand:\n");
            print_hand(player_hand);
            if (player_hand.score > 21) {
                printf("\nBusted!\n");
                break;
            }
        } else if (input == 's') {
            break;
        }
    }
}

void dealer_turn() {
    dealer_hand.hand[1].value *= -1; // Reveal dealer's hidden card
    printf("Dealer's hand:\n");
    print_hand(dealer_hand);
    while (dealer_hand.score < 17) {
        printf("\nDealer hits!\n");
        dealer_hand.hand[2] = draw_card();
        evaluate_hand(&dealer_hand);
        print_hand(dealer_hand);
        if (dealer_hand.score > 21) {
            printf("\nDealer busts!\n");
            break;
        }
    }
}