//FormAI DATASET v1.0 Category: Poker Game ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void shuffle(int deck[52]) { //shuffling the deck
    srand(time(NULL));
    for (int i = 0; i < 52; i++) {
        int r = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

void deal(int deck[52], int players[][2], int n) { //distributing cards to each player
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            players[i][j] = deck[k];
            k++;
        }
    }
}

void print_card(int card) { //displaying individual card
    char suits[4] = {'C', 'D', 'H', 'S'};
    char ranks[13] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    char cardname[3];
    int suit = card / 13;
    int rank = card % 13;
    sprintf(cardname, "%c%c", suits[suit], ranks[rank]);
    printf("%s ", cardname);
}

int get_rank(int card) { //extracting rank from individual card
    return card % 13;
}

int get_suit(int card) { //extracting suit from individual card
    return card / 13;
}

int is_flush(int hand[][2]) { //checking flush
    int suit = get_suit(hand[0][0]);
    for (int i = 1; i < 5; i++) {
        if (get_suit(hand[i][0]) != suit) {
            return 0;
        }
    }
    return 1;
}

int is_straight(int hand[][2]) { //checking straight
    int ranks[5];
    for (int i = 0; i < 5; i++) {
        ranks[i] = get_rank(hand[i][0]);
    }
    for (int i = 0; i < 5; i++) {
        int flag = 0;
        for (int j = 1; j < 5; j++) {
            if (ranks[j] < ranks[j-1]) {
                int temp = ranks[j];
                ranks[j] = ranks[j-1];
                ranks[j-1] = temp;
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
    if (ranks[4] == 12 && ranks[3] == 3 && ranks[2] == 2 && ranks[1] == 1 && ranks[0] == 0) {
        return 1;
    }
    for (int i = 1; i < 5; i++) {
        if (ranks[i] != ranks[i-1]+1) {
            return 0;
        }
    }
    return 1;
}

int is_straight_flush(int hand[][2]) { //checking straight flush
    if (is_flush(hand) == 1 && is_straight(hand) == 1) {
        return 1;
    }
    return 0;
}

int is_four_of_a_kind(int hand[][2]) { //checking four of a kind
    int ranks[5];
    for (int i = 0; i < 5; i++) {
        ranks[i] = get_rank(hand[i][0]);
    }
    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++) {
            if (ranks[i] == ranks[j]) {
                count++;
            }
        }
        if (count == 4) {
            return 1;
        }
    }
    return 0;
}

int is_full_house(int hand[][2]) { //checking full house
    int ranks[5];
    for (int i = 0; i < 5; i++) {
        ranks[i] = get_rank(hand[i][0]);
    }
    for (int i = 0; i < 5; i++) {
        int count1 = 0;
        for (int j = 0; j < 5; j++) {
            if (ranks[i] == ranks[j]) {
                count1++;
            }
        }
        if (count1 == 3) {
            for (int k = 0; k < 5; k++) {
                int count2 = 0;
                if (ranks[k] != ranks[i]) {
                    for (int l = 0; l < 5; l++) {
                        if (ranks[k] == ranks[l]) {
                            count2++;
                        }
                    }
                }
                if (count2 == 2) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int is_three_of_a_kind(int hand[][2]) { //checking three of a kind
    int ranks[5];
    for (int i = 0; i < 5; i++) {
        ranks[i] = get_rank(hand[i][0]);
    }
    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++) {
            if (ranks[i] == ranks[j]) {
                count++;
            }
        }
        if (count == 3) {
            return 1;
        }
    }
    return 0;
}

int is_two_pair(int hand[][2]) { //checking two pair
    int ranks[5];
    for (int i = 0; i < 5; i++) {
        ranks[i] = get_rank(hand[i][0]);
    }
    for (int i = 0; i < 5; i++) {
        int count1 = 0;
        for (int j = 0; j < 5; j++) {
            if (ranks[i] == ranks[j]) {
                count1++;
            }
        }
        if (count1 == 2) {
            for (int k = i+1; k < 5; k++) {
                int count2 = 0;
                if (ranks[k] != ranks[i]) {
                    for (int l = 0; l < 5; l++) {
                        if (ranks[k] == ranks[l]) {
                            count2++;
                        }
                    }
                }
                if (count2 == 2) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int is_pair(int hand[][2]) { //checking pair
    int ranks[5];
    for (int i = 0; i < 5; i++) {
        ranks[i] = get_rank(hand[i][0]);
    }
    for (int i = 0; i < 5; i++) {
        int count = 0;
        for (int j = 0; j < 5; j++) {
            if (ranks[i] == ranks[j]) {
                count++;
            }
        }
        if (count == 2) {
            return 1;
        }
    }
    return 0;
}

int get_hand_score(int hand[][2]) { //determining the best combination of cards in hand
    if (is_straight_flush(hand) == 1) {
        return 9;
    }
    if (is_four_of_a_kind(hand) == 1) {
        return 8;
    }
    if (is_full_house(hand) == 1) {
        return 7;
    }
    if (is_flush(hand) == 1) {
        return 6;
    }
    if (is_straight(hand) == 1) {
        return 5;
    }
    if (is_three_of_a_kind(hand) == 1) {
        return 4;
    }
    if (is_two_pair(hand) == 1) {
        return 3;
    }
    if (is_pair(hand) == 1) {
        return 2;
    }
    return 1;
}

int main() {
    int deck[52];
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }
    int n;
    printf("Enter the number of players (2-6): ");
    scanf("%d", &n);
    int players[n][2];
    shuffle(deck);
    deal(deck, players, n);
    for (int i = 0; i < n; i++) {
        printf("Player %d: ", i+1);
        print_card(players[i][0]);
        print_card(players[i][1]);
        printf("\n");
    }
    int scores[n];
    for (int i = 0; i < n; i++) {
        scores[i] = get_hand_score(players[i]);
    }
    int max_score = scores[0];
    int winner = 1;
    for (int i = 1; i < n; i++) {
        if (scores[i] > max_score) {
            max_score = scores[i];
            winner = i+1;
        }
    }
    printf("Player %d wins with a score of %d\n", winner, max_score);
    return 0;
}