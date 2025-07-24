//FormAI DATASET v1.0 Category: Poker Game ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

char *suits[]={"Hearts","Diamonds","Spades","Clubs"};
char *ranks[]={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};

typedef struct {
    char *suit;
    char *rank;
} Card;

typedef struct {
    Card cards[DECK_SIZE];
    int top_card;
} Deck;

typedef struct {
    Card hand[HAND_SIZE];
    int rank;
} Hand;

int compare_cards(const void *a, const void *b) {
    Card *card_a=(Card *)a;
    Card *card_b=(Card *)b;

    int rank_a=0,rank_b=0;

    for(int i=0;i<13;i++){
        if(*card_a->rank == *ranks[i]){
            rank_a=i;
        }
        if(*card_b->rank == *ranks[i]){
            rank_b=i;
        }
    }

    return rank_a-rank_b;
}

void shuffle(Deck *deck) {
    srand(time(NULL));

    for(int i = 0; i < DECK_SIZE; i++){
        int j = rand() % DECK_SIZE;

        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void initialize_deck(Deck *deck) {
    deck->top_card = 0;

    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            deck->cards[i*13+j].suit = suits[i];
            deck->cards[i*13+j].rank = ranks[j];
        }
    }

    shuffle(deck);
}

void display_card(Card card) {
    printf("%s of %s\n",card.rank,card.suit);
}

void display_deck(Deck deck) {
    for(int i=0;i<DECK_SIZE;i++){
        display_card(deck.cards[i]);
    }
}

void initialize_hand(Hand *hand) {
    for(int i=0;i<HAND_SIZE;i++){
        hand->hand[i].rank = "";
        hand->hand[i].suit = "";
    }

    hand->rank = 0;
}

void display_hand(Hand hand) {
    for(int i=0;i<HAND_SIZE;i++){
        display_card(hand.hand[i]);
    }
}

void deal(Deck *deck, Hand *hand) {
    int current_card=deck->top_card;

    for(int i=0;i<HAND_SIZE;i++){
        hand->hand[i] = deck->cards[current_card++];
    }

    deck->top_card = current_card;
}

int is_royal_flush(Hand hand) {
    int i;

    for(i=0;i<HAND_SIZE;i++){
        if(*hand.hand[i].rank == 'A' || *hand.hand[i].rank == 'K' || *hand.hand[i].rank == 'Q' || *hand.hand[i].rank == 'J' || *hand.hand[i].rank == 'T') {
            if (i == HAND_SIZE - 1){
                return 1;
            }
        }
        else {
            break;
        }
    }

    return 0;
}

int is_straight_flush(Hand hand) {
    int i, j, count=1;

    for(i=0;i<HAND_SIZE-1;i++){
        for(j=1;j<HAND_SIZE-i;j++){
            if(*hand.hand[i].suit == *hand.hand[i+j].suit && abs(*hand.hand[i].rank - *hand.hand[i+j].rank) == j) {
                count++;
            }
        }
    }

    return count == HAND_SIZE;
}

int is_four_of_a_kind(Hand hand) {
    int i;

    for(i=0;i<2;i++){
        if(*hand.hand[i].rank == *hand.hand[i+3].rank){
            return 1;
        }
    }

    return 0;
}

int is_full_house(Hand hand) {
    int i;

    if((*hand.hand[0].rank == *hand.hand[1].rank && *hand.hand[2].rank == *hand.hand[3].rank && *hand.hand[3].rank == *hand.hand[4].rank) || (*hand.hand[0].rank == *hand.hand[1].rank && *hand.hand[1].rank == *hand.hand[2].rank && *hand.hand[3].rank == *hand.hand[4].rank)) {
        return 1;
    }

    return 0;
}

int is_flush(Hand hand) {
    int i;

    for(i=1;i<HAND_SIZE;i++){
        if(*hand.hand[0].suit != *hand.hand[i].suit){
            return 0;
        }
    }

    return 1;
}

int is_straight(Hand hand) {
    int i, j, diff;

    for(i=0;i<HAND_SIZE-1;i++){
        for(j=1;j<HAND_SIZE-i;j++){
            diff = abs(*hand.hand[i].rank - *hand.hand[i+j].rank);

            if(diff == j || diff == 9){
                if(j == HAND_SIZE - 2){
                    return 1;
                }
            }
            else {
                break;
            }
        }
    }

    return 0;
}

int is_three_of_a_kind(Hand hand) {
    int i, j, k;

    for(i=0;i<HAND_SIZE-2;i++){
        for(j=i+1;j<HAND_SIZE-1;j++){
            if(*hand.hand[i].rank == *hand.hand[j].rank) {
                for(k=j+1;k<HAND_SIZE;k++){
                    if(*hand.hand[i].rank == *hand.hand[k].rank){
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

int is_two_pairs(Hand hand) {
    int i, j, counter=0;

    for(i=0;i<HAND_SIZE-1;i++){
        for(j=i+1;j<HAND_SIZE;j++){
            if(*hand.hand[i].rank == *hand.hand[j].rank) {
                counter++;
            }
        }
    }

    return counter == 2;
}

int is_pair(Hand hand) {
    int i, j;

    for(i=0;i<HAND_SIZE-1;i++){
        for(j=i+1;j<HAND_SIZE;j++){
            if(*hand.hand[i].rank == *hand.hand[j].rank) {
                return 1;
            }
        }
    }

    return 0;
}

void determine_hand_rank(Hand *hand) {
    qsort(hand->hand, HAND_SIZE, sizeof(Card), compare_cards);

    if(is_royal_flush(*hand)) {
        hand->rank = 10;
    }
    else if(is_straight_flush(*hand)) {
        hand->rank = 9;
    }
    else if(is_four_of_a_kind(*hand)) {
        hand->rank = 8;
    }
    else if(is_full_house(*hand)) {
        hand->rank = 7;
    }
    else if(is_flush(*hand)) {
        hand->rank = 6;
    }
    else if(is_straight(*hand)) {
        hand->rank = 5;
    }
    else if(is_three_of_a_kind(*hand)) {
        hand->rank = 4;
    }
    else if(is_two_pairs(*hand)) {
        hand->rank = 3;
    }
    else if(is_pair(*hand)) {
        hand->rank = 2;
    }
    else {
        hand->rank = 1;
    }
}

void display_hand_ranks(Hand player_hand, Hand dealer_hand) {
    printf("\nPlayer Hand Ranks: %d\n", player_hand.rank);
    display_hand(player_hand);
    printf("\nDealer Hand Ranks: %d\n", dealer_hand.rank);
    display_hand(dealer_hand);
}

void determine_winner(Hand player_hand, Hand dealer_hand) {
    if(player_hand.rank > dealer_hand.rank){
        printf("\nCongratulations! Player Wins!\n");
    }
    else if(player_hand.rank < dealer_hand.rank) {
        printf("\nDealer Wins! Better luck next time.\n");
    }
    else{
        printf("\nIt’s a tie! You both have %s. \n", player_hand.rank==1?"no combinations":player_hand.rank==2?"a pair":player_hand.rank==3?"two pairs":player_hand.rank==4?"three of a kind":player_hand.rank==5?"a straight":player_hand.rank==6?"a flush":player_hand.rank==7?"a full house":player_hand.rank==8?"four of a kind":player_hand.rank==9?"a straight flush":"a royal flush");
    }
}

int main() {
    Deck deck;
    Hand player_hand;
    Hand dealer_hand;

    initialize_deck(&deck);
    initialize_hand(&player_hand);
    initialize_hand(&dealer_hand);

    deal(&deck,&player_hand);
    deal(&deck,&dealer_hand);

    determine_hand_rank(&player_hand);
    determine_hand_rank(&dealer_hand);

    display_hand_ranks(player_hand, dealer_hand);

    determine_winner(player_hand, dealer_hand);

    return 0;
}