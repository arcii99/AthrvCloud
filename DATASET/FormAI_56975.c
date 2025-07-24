//FormAI DATASET v1.0 Category: Memory Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define TOTAL_CARDS ROWS * COLS / 2

int generate_card() {
    return rand() % TOTAL_CARDS + 1;
}

void shuffle_cards(int* cards, int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
    }
}

void init_board(int board[ROWS][COLS], int* cards, int total_cards) {
    int card_count[TOTAL_CARDS] = {0};
    int count = 0;
    while (count < ROWS * COLS) {
        int index = count / 2;
        int card_number = cards[index];
        if (card_count[card_number - 1] < 2) {
            board[count / COLS][count % COLS] = card_number;
            card_count[card_number - 1]++;
            count++;
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    printf("Current Board:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == -1) {
                printf("X\t");
            } else {
                printf("%d\t", board[i][j]);
            }
        }
        printf("\n");
    }
}

int check_match(int board[ROWS][COLS], int* row_col1, int* row_col2) {
    int card1_row = row_col1[0], card1_col = row_col1[1];
    int card2_row = row_col2[0], card2_col = row_col2[1];
    if (board[card1_row][card1_col] == board[card2_row][card2_col]) {
        return 1;
    } else {
        return 0;
    }
}

void find_card(int board[ROWS][COLS], int card_number, int* row_col) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == card_number) {
                row_col[0] = i;
                row_col[1] = j;
                return;
            }
        }
    }
}

void play_game() {
    int cards[TOTAL_CARDS];
    for (int i = 0; i < TOTAL_CARDS; i++) {
        cards[i] = i + 1;
    }
    shuffle_cards(cards, TOTAL_CARDS);
    
    int board[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = -1;
        }
    }
    
    init_board(board, cards, TOTAL_CARDS);
    
    int matches_found = 0;
    while (matches_found < TOTAL_CARDS) {
        print_board(board);
        
        int card1_number = -1, card2_number = -1;
        int card1_row_col[2], card2_row_col[2];
        while (card1_number == -1 || card2_number == -1) {
            printf("Enter the first card number: ");
            scanf("%d", &card1_number);
            printf("Enter the second card number: ");
            scanf("%d", &card2_number);
        }
        find_card(board, card1_number, card1_row_col);
        find_card(board, card2_number, card2_row_col);
        board[card1_row_col[0]][card1_row_col[1]] = card1_number;
        board[card2_row_col[0]][card2_row_col[1]] = card2_number;
        
        if (check_match(board, card1_row_col, card2_row_col)) {
            printf("Match found!\n");
            matches_found++;
        } else {
            printf("No match, try again.\n");
            board[card1_row_col[0]][card1_row_col[1]] = -1;
            board[card2_row_col[0]][card2_row_col[1]] = -1;
        }
    }
    
    printf("Congratulations, you won!\n");
}

int main() {
    srand(time(NULL));
    printf("Welcome to the Memory Game!\n"
           "You will be presented with a grid of face-down cards.\n"
           "Each card is numbered. You must select two cards at a time,\n"
           "trying to find a matching pair, until you have matched all pairs.\n"
           "Good luck!\n\n");
    play_game();
    return 0;
}