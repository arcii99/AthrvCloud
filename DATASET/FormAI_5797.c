//FormAI DATASET v1.0 Category: Poker Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum card_rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
enum card_suit {CLUBS, DIAMONDS, HEARTS, SPADES};
enum hand_rank {HIGH_CARD, PAIR, TWO_PAIR, THREE_OF_A_KIND, STRAIGHT, FLUSH, FULL_HOUSE, FOUR_OF_A_KIND, STRAIGHT_FLUSH};
typedef struct card {
    enum card_rank rank;
    enum card_suit suit;
} Card;

void print_card(Card card) {
    switch (card.rank) {
        case ACE:
            printf("A");
            break;
        case JACK:
            printf("J");
            break;
        case QUEEN:
            printf("Q");
            break;
        case KING:
            printf("K");
            break;
        default:
            printf("%d", card.rank);
            break;
    }
    switch (card.suit) {
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

void print_card_array(Card *cards, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        print_card(cards[i]);
        printf(" ");
    }
}

int cmp_card_rank(const void *a, const void *b) {
    Card *card_a = (Card *)a;
    Card *card_b = (Card *)b;
    if (card_a->rank < card_b->rank) {
        return -1;
    } else if (card_a->rank > card_b->rank) {
        return 1;
    } else {
        return 0;
    }
}

int cmp_card_suit(const void *a, const void *b) {
    Card *card_a = (Card *)a;
    Card *card_b = (Card *)b;
    if (card_a->suit < card_b->suit) {
        return -1;
    } else if (card_a->suit > card_b->suit) {
        return 1;
    } else {
        return cmp_card_rank(a, b);
    }
}

int is_ace_low_straight(Card *cards) {
    if (cards[0].rank != ACE) {
        return 0;
    }
    int is_straight = 1;
    for (int i = 1; i < 5; i++) {
        if (cards[i].rank != i + 9) {
            is_straight = 0;
            break;
        }
    }
    return is_straight;
}

int is_straight(Card *cards) {
    int is_straight = 1;
    for (int i = 0; i < 4; i++) {
        if (cards[i].rank != cards[i+1].rank - 1) {
            is_straight = 0;
            break;
        }
    }
    if (!is_straight) {
        is_straight = is_ace_low_straight(cards);
    }
    return is_straight;
}

int is_flush(Card *cards) {
    for (int i = 1; i < 5; i++) {
        if (cards[i].suit != cards[0].suit) {
            return 0;
        }
    }
    return 1;
}

int is_straight_flush(Card *cards) {
    return is_straight(cards) && is_flush(cards);
}

int get_num_ranks(Card *cards, int rank) {
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (cards[i].rank == rank) {
            count++;
        }
    }
    return count;
}

int get_pair_rank(Card *cards) {
    for (int i = 0; i < 5; i++) {
        if (get_num_ranks(cards, cards[i].rank) == 2) {
            return cards[i].rank;
        }
    }
    return 0;
}

int get_three_of_a_kind_rank(Card *cards) {
    for (int i = 0; i < 5; i++) {
        if (get_num_ranks(cards, cards[i].rank) == 3) {
            return cards[i].rank;
        }
    }
    return 0;
}

int get_four_of_a_kind_rank(Card *cards) {
    for (int i = 0; i < 5; i++) {
        if (get_num_ranks(cards, cards[i].rank) == 4) {
            return cards[i].rank;
        }
    }
    return 0;
}

int get_high_card(Card *cards) {
    int high_card = 0;
    for (int i = 0; i < 5; i++) {
        if (cards[i].rank > high_card) {
            high_card = cards[i].rank;
        }
    }
    return high_card;
}

enum hand_rank get_hand_rank(Card *cards) {
    qsort(cards, 5, sizeof(Card), cmp_card_rank);
    if (is_straight_flush(cards)) {
        return STRAIGHT_FLUSH;
    } else if (get_four_of_a_kind_rank(cards)) {
        return FOUR_OF_A_KIND;
    } else if (get_num_ranks(cards, get_three_of_a_kind_rank(cards)) == 3) {
        return FULL_HOUSE;
    } else if (is_flush(cards)) {
        return FLUSH;
    } else if (is_straight(cards)) {
        return STRAIGHT;
    } else if (get_three_of_a_kind_rank(cards)) {
        return THREE_OF_A_KIND;
    } else if (get_num_ranks(cards, get_pair_rank(cards)) == 4) {
        return TWO_PAIR;
    } else if (get_num_ranks(cards, get_pair_rank(cards)) == 2) {
        return PAIR;
    } else {
        return HIGH_CARD;
    }
}

void print_hand_rank(enum hand_rank rank) {
    switch (rank) {
        case STRAIGHT_FLUSH:
            printf("Straight Flush");
            break;
        case FOUR_OF_A_KIND:
            printf("Four of a Kind");
            break;
        case FULL_HOUSE:
            printf("Full House");
            break;
        case FLUSH:
            printf("Flush");
            break;
        case STRAIGHT:
            printf("Straight");
            break;
        case THREE_OF_A_KIND:
            printf("Three of a Kind");
            break;
        case TWO_PAIR:
            printf("Two Pair");
            break;
        case PAIR:
            printf("Pair");
            break;
        case HIGH_CARD:
            printf("High Card");
            break;
    }
}

int main() {
    srand(time(NULL));
    Card deck[52];
    int num_dealt = 0;
    for (int i = 0; i < 13; i++) {
        deck[i].rank = i + 1;
        deck[i].suit = CLUBS;
        deck[i+13].rank = i + 1;
        deck[i+13].suit = DIAMONDS;
        deck[i+26].rank = i + 1;
        deck[i+26].suit = HEARTS;
        deck[i+39].rank = i + 1;
        deck[i+39].suit = SPADES;
    }
    Card player_hand[5];
    Card computer_hand[5];
    printf("Dealing cards...\n");
    while (num_dealt < 10) {
        int card_index = rand() % 52;
        if (deck[card_index].rank != 0) {
            if (num_dealt % 2 == 0) {
                player_hand[num_dealt/2] = deck[card_index];
            } else {
                computer_hand[(num_dealt-1)/2] = deck[card_index];
            }
            deck[card_index].rank = 0;
            num_dealt++;
        }
    }
    printf("Your hand: ");
    print_card_array(player_hand, 5);
    printf("\n");
    printf("Computer's hand: ");
    print_card_array(computer_hand, 5);
    printf("\n");
    enum hand_rank player_rank = get_hand_rank(player_hand);
    enum hand_rank computer_rank = get_hand_rank(computer_hand);
    printf("Your hand rank: ");
    print_hand_rank(player_rank);
    printf("\n");
    printf("Computer's hand rank: ");
    print_hand_rank(computer_rank);
    printf("\n");
    if (player_rank > computer_rank) {
        printf("You win!");
    } else if (player_rank < computer_rank) {
        printf("Computer wins!");
    } else {
        int player_high_card = get_high_card(player_hand);
        int computer_high_card = get_high_card(computer_hand);
        if (player_high_card > computer_high_card) {
            printf("You win!");
        } else if (player_high_card < computer_high_card) {
            printf("Computer wins!");
        } else {
            printf("It's a tie!");
        }
    }
    return 0;
}