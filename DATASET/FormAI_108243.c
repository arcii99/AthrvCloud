//FormAI DATASET v1.0 Category: Poker Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef struct{
    int rank;
    int suit;
} card;

typedef struct{
    card hand[HAND_SIZE];
} player;

void initialize_deck(card deck[DECK_SIZE]){
    int i, j, count = 0;
    for(i=2; i<=14; i++){
        for(j=1; j<=4; j++){
            deck[count].rank = i;
            deck[count].suit = j;
            count++;
        }
    }
}

void shuffle_deck(card deck[DECK_SIZE]){
    int i, j;
    card temp;
    for(i=0;i<DECK_SIZE;i++){
        j = rand()%DECK_SIZE;
        temp = deck[i];
        deck[i]=deck[j];
        deck[j]=temp;
    }
}

void deal_cards(player* players, int num_players, card deck[DECK_SIZE]){
    int i, j, count=0;
    for(i=0; i<num_players; i++){
        for(j=0; j<HAND_SIZE; j++){
            players[i].hand[j] = deck[count];
            count++;
        }
    }
}

void print_hand(player p){
    int i;
    for(i=0; i<HAND_SIZE; i++){
        printf("%d of %d\n", p.hand[i].rank, p.hand[i].suit);
    }
}

int is_flush(player p){
    int i;
    int suit = p.hand[0].suit;
    for(i=1; i<HAND_SIZE; i++){
        if(p.hand[i].suit!=suit) return 0;
    }
    return 1;
}

int is_straight(player p){
    int i;
    int rank = p.hand[0].rank;
    for(i=1; i<HAND_SIZE; i++){
        if(p.hand[i].rank!=rank+i) return 0;
    }
    return 1;
}

int evaluate_hand(player p){
    int i;
    int rank_count[15] = {0}; // initialize all to 0
    int num_pairs=0, three_kind=0, four_kind=0;

    // Count number of each rank
    for(i=0; i<HAND_SIZE; i++){
        rank_count[p.hand[i].rank]++;
    }

    // Determine number of pairs, three of a kind, and four of a kind
    for(i=2; i<=14; i++){
        if(rank_count[i]==2) num_pairs++;
        else if(rank_count[i]==3) three_kind=1;
        else if(rank_count[i]==4) four_kind=1;
    }

    // Check for flush and straight
    int is_flushed = is_flush(p);
    int is_straighted = is_straight(p);

    // Evaluate hand
    if(is_flushed && is_straighted) return 100; // Royal flush
    else if(four_kind) return 90; // Four of a kind
    else if(num_pairs==1 && three_kind==1) return 80; // Full house
    else if(is_flushed) return 70; // Flush
    else if(is_straighted) return 60; // Straight
    else if(three_kind) return 50; // Three of a kind
    else if(num_pairs==2) return 40; // Two pairs
    else if(num_pairs==1) return 30; // Pair
    else return p.hand[4].rank; // High Card
}

void determine_winner(player* players, int num_players){
    int i;
    int max_score = 0;
    int winning_player = 0;

    // Determine highest score
    for(i=0; i<num_players; i++){
        int score = evaluate_hand(players[i]);
        if(score > max_score){
            max_score = score;
            winning_player = i;
        }
    }

    // Print winner
    printf("The winner is player %d!\n", winning_player+1);
    printf("Score: %d\n", max_score);
    printf("Hand: ");
    print_hand(players[winning_player]);
}

int main(){
    srand(time(NULL)); // seed random number generator
    
    // Create and shuffle deck
    card deck[DECK_SIZE];
    initialize_deck(deck);
    shuffle_deck(deck);
    
    // Initialize players
    int num_players;
    printf("How many players? ");
    scanf("%d", &num_players);
    player players[num_players];

    // Deal cards
    deal_cards(players, num_players, deck);
    
    // Evaluate hands and determine winner
    determine_winner(players, num_players);
    
    return 0;
}