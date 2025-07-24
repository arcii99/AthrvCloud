//FormAI DATASET v1.0 Category: Poker Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52
#define NUM_SUITS 4
#define NUM_RANKS 13
#define MAX_HAND 5

typedef enum suit{
    CLUBS, DIAMONDS, HEARTS, SPADES
} Suit;

typedef enum rank{
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
} Rank;

typedef struct card{
    Suit suit;
    Rank rank;
} Card;

typedef struct hand{
    Card cards[MAX_HAND];
    int num_cards;
} Hand;

void swap(Card* a, Card* b){
    Card temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle(Card* deck){
    srand(time(NULL));
    int i, j;
    for(i = 0; i < NUM_CARDS; i++){
        j = rand() % NUM_CARDS;
        swap(&deck[i], &deck[j]);
    }
}

void print_card(Card card){
    if(card.rank <= TEN){
        printf("%d", card.rank+2);
    }else{
        switch(card.rank){
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
        }
    }
    switch(card.suit){
        case CLUBS:
            printf("C");
            break;
        case DIAMONDS:
            printf("D");
            break;
        case HEARTS:
            printf("H");
            break;
        case SPADES:
            printf("S");
            break;
    }
}

void print_hand(Hand hand){
    int i;
    for(i = 0; i < hand.num_cards; i++){
        print_card(hand.cards[i]);
        printf(" ");
    }
    printf("\n");
}

int compare_cards(const void* a, const void* b){
    Card* cardA = (Card*)a;
    Card* cardB = (Card*)b;
    return cardA->rank - cardB->rank;
}

int is_straight(Hand hand){
    qsort(hand.cards, hand.num_cards, sizeof(Card), compare_cards);
    int i;
    for(i = 1; i < hand.num_cards; i++){
        if(hand.cards[i].rank != hand.cards[i-1].rank+1)
            return 0;
    }
    return 1;
}

int is_flush(Hand hand){
    int i;
    for(i = 1; i < hand.num_cards; i++){
        if(hand.cards[i].suit != hand.cards[i-1].suit)
            return 0;
    }
    return 1;
}

int evaluate_hand(Hand hand){
    if(hand.num_cards != MAX_HAND){
        printf("Error: Hand must contain %d cards\n", MAX_HAND);
        exit(0);
    }
    if(is_straight(hand) && is_flush(hand))
        return 1; // Straight flush
    if(hand.cards[0].rank == hand.cards[3].rank || hand.cards[1].rank == hand.cards[4].rank)
        return 2; // Four of a kind
    if(hand.cards[0].rank == hand.cards[2].rank && hand.cards[3].rank == hand.cards[4].rank ||
       hand.cards[0].rank == hand.cards[1].rank && hand.cards[2].rank == hand.cards[4].rank)
        return 3; // Full house
    if(is_flush(hand))
        return 4; // Flush
    if(is_straight(hand))
        return 5; // Straight
    if(hand.cards[0].rank == hand.cards[2].rank || hand.cards[1].rank == hand.cards[3].rank ||
       hand.cards[2].rank == hand.cards[4].rank)
        return 6; // Three of a kind
    int num_pairs = 0;
    int i;
    for(i = 0; i < hand.num_cards-1; i++){
        if(hand.cards[i].rank == hand.cards[i+1].rank){
            num_pairs++;
            i++;
        }
    }
    if(num_pairs == 2)
        return 7; // Two pairs
    if(num_pairs == 1)
        return 8; // One pair
    return 9; // High card
}

int main(){
    Card deck[NUM_CARDS];
    int i, j;
    for(i = 0; i < NUM_SUITS; i++){
        for(j = 0; j < NUM_RANKS; j++){
            deck[i*NUM_RANKS+j].suit = i;
            deck[i*NUM_RANKS+j].rank = j;
        }
    }
    shuffle(deck);
    Hand player_hand = {{deck[0], deck[1], deck[2], deck[3], deck[4]}, MAX_HAND};
    Hand dealer_hand = {{deck[5], deck[6], deck[7], deck[8], deck[9]}, MAX_HAND};
    printf("Dealer's hand: ");
    print_hand(dealer_hand);
    printf("Player's hand: ");
    print_hand(player_hand);
    int player_score = evaluate_hand(player_hand);
    printf("Player's score: %d\n", player_score);
    int dealer_score = evaluate_hand(dealer_hand);
    printf("Dealer's score: %d\n", dealer_score);
    if(player_score < dealer_score){
        printf("Dealer wins!\n");
    }else if(player_score > dealer_score){
        printf("Player wins!\n");
    }else{
        printf("Tie game!\n");
    }
    return 0;
}