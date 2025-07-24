//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5
#define MAX_NUMBER 75

void print_card(int card[ROWS][COLS], int card_marked[ROWS][COLS]);
int check_win(int card_marked[ROWS][COLS]);
int is_marked(int number, int card[ROWS][COLS], int card_marked[ROWS][COLS]);
void generate_numbers(int numbers[MAX_NUMBER]);
int get_number(int numbers[MAX_NUMBER], int called_numbers[MAX_NUMBER]);
void mark_card(int card[ROWS][COLS], int card_marked[ROWS][COLS], int number);
int is_bingo(int rows[ROWS], int cols[COLS], int diagnols[2]);

int main() {
    int card[ROWS][COLS] = {0};
    int card_marked[ROWS][COLS] = {0};
    int numbers[MAX_NUMBER] = {0};
    int called_numbers[MAX_NUMBER] = {0};
    srand(time(NULL));
    generate_numbers(numbers);
    int number, count = 0, winner = 0;
    while (!winner && count < MAX_NUMBER) {
        printf("Next number: ");
        number = get_number(numbers, called_numbers);
        printf("%d\n", number);
        mark_card(card, card_marked, number);
        print_card(card, card_marked);
        winner = check_win(card_marked);
        called_numbers[count++] = number;
    }
    if (winner) {
        printf("Congratulations! You are the winner!\n");
    } else {
        printf("Sorry, you lost...\n");
    }
    return 0;
}

void print_card(int card[ROWS][COLS], int card_marked[ROWS][COLS]) {
    printf("-----------------------------\n");
    printf("B   I   N   G   O\n");
    printf("-----------------------------\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card_marked[i][j]) {
                printf("| X ");
            } else {
                printf("| %d ", card[i][j]);
            }
        }
        printf("|\n");
        printf("-----------------------------\n");
    }
}

int check_win(int card_marked[ROWS][COLS]) {
    int rows[ROWS] = {0};
    int cols[COLS] = {0};
    int diagnols[2] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card_marked[i][j]) {
                rows[i]++;
                cols[j]++;
                if (i == j) {
                    diagnols[0]++;
                }
                if (i == ROWS - j - 1) {
                    diagnols[1]++;
                }
            }
        }
    }
    return is_bingo(rows, cols, diagnols);
}

int is_marked(int number, int card[ROWS][COLS], int card_marked[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == number && !card_marked[i][j]) {
                return 1;
            }
        }
    }
    return 0;
}

void generate_numbers(int numbers[MAX_NUMBER]) {
    for (int i = 0; i < MAX_NUMBER; i++) {
        numbers[i] = i + 1;
    }
}

int get_number(int numbers[MAX_NUMBER], int called_numbers[MAX_NUMBER]) {
    int number = -1;
    while (number == -1) {
        int index = rand() % MAX_NUMBER;
        if (!is_marked(numbers[index], NULL, called_numbers)) {
            number = numbers[index];
        }
    }
    return number;
}

void mark_card(int card[ROWS][COLS], int card_marked[ROWS][COLS], int number) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == number && !card_marked[i][j]) {
                card_marked[i][j] = 1;
                return;
            }
        }
    }
}

int is_bingo(int rows[ROWS], int cols[COLS], int diagnols[2]) {
    int i;
    for (i = 0; i < ROWS; i++) {
        if (rows[i] == ROWS) {
            return 1;
        }
    }
    for (i = 0; i < COLS; i++) {
        if (cols[i] == ROWS) {
            return 1;
        }
    }
    for (i = 0; i < 2; i++) {
        if (diagnols[i] == ROWS) {
            return 1;
        }
    }
    return 0;
}