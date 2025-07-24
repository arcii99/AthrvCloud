//FormAI DATASET v1.0 Category: Memory Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, int size) {
    srand(time(NULL));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void print_card(int card) {
    if (card == -1) {
        printf("  X  ");
    } else {
        printf("  %d  ", card);
    }
}

void print_row(int *cards, int start, int end) {
    for (int i = start; i <= end; i++) {
        print_card(cards[i]);
    }
    printf("\n");
}

void print_board(int *cards, int size) {
    printf("\n");
    printf("     A     B     C     D\n");
    printf("   ----- ----- ----- -----\n");
    print_row(cards, 0, 3);
    printf("   ----- ----- ----- -----\n");
    print_row(cards, 4, 7);
    printf("   ----- ----- ----- -----\n");
    print_row(cards, 8, 11);
    printf("   ----- ----- ----- -----\n");
    print_row(cards, 12, 15);
    printf("   ----- ----- ----- -----\n");
    printf("\n");
}

int get_selection() {
    int selection;
    do {
        printf("Enter the letter and number of the card to flip (e.g. A1): ");
        char input[10];
        scanf("%s", input);
        selection = (input[0] - 'A') * 4 + input[1] - '1';
    } while (selection < 0 || selection > 15);
    return selection;
}

int is_match(int *cards, int index1, int index2) {
    return cards[index1] == cards[index2];
}

void play_game() {
    int cards[16] = {0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
    shuffle(cards, 16);

    int selections[2] = {-1, -1};
    int flipped_count = 0;
    int matches_count = 0;

    while (matches_count < 8) {
        print_board(cards, 16);

        if (flipped_count == 2) {
            if (is_match(cards, selections[0], selections[1])) {
                printf("MATCH!\n\n");
                cards[selections[0]] = -1;
                cards[selections[1]] = -1;
                matches_count += 1;
            } else {
                printf("NO MATCH!\n\n");
            }
            flipped_count = 0;
        }

        int selection = get_selection();
        if (cards[selection] == -1) {
            printf("Card already flipped, select another.\n\n");
        } else {
            selections[flipped_count] = selection;
            flipped_count += 1;
            cards[selection] *= -1;
        }
    }

    printf("CONGRATULATIONS, YOU WON!");
}

int main() {
    printf("Welcome to the Cyberpunk Memory Game\n\n");
    printf("Match all the pairs to win!\n\n");
    play_game();
    return 0;
}