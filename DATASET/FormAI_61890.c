//FormAI DATASET v1.0 Category: Memory Game ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define BOARD_SIZE ROWS*COLS

void clear_screen() {
    system("cls");
}

void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC) {}
}

void display_board(char board[][COLS]) {
    printf("\n\n");
    for (int i = 0; i < ROWS; i++) {
        printf("\t\t\t\t\t|-----|-----|-----|-----|\n");
        printf("\t\t\t\t\t|     |     |     |     |\n");
        for (int j = 0; j < COLS; j++) {
            printf("\t\t\t\t\t|  %c  ", board[i][j]);
        }
        printf("|\n\t\t\t\t\t|     |     |     |     |\n");
    }
    printf("\t\t\t\t\t|-----|-----|-----|-----|\n\n");
}

void shuffle_board(char board[][COLS]) {
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i++) {
        int r_1 = rand() % ROWS;
        int c_1 = rand() % COLS;
        int r_2 = rand() % ROWS;
        int c_2 = rand() % COLS;
        char temp = board[r_1][c_1];
        board[r_1][c_1] = board[r_2][c_2];
        board[r_2][c_2] = temp;
    }
}

int get_pos(char board[][COLS], char letter) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == letter) {
                return i * COLS + j;
            }
        }
    }
    return -1;
}

char* get_choice() {
    char* choice = (char*)malloc(3*sizeof(char));
    printf("\n\nEnter a position to reveal (e.g. 'A1'): ");
    scanf("%s", choice);
    return choice;
}

void split_choice(char* choice, int* row, int* col) {
    *row = choice[0] - 'A';
    *col = choice[1] - '1';
}

int main() {
    char board[ROWS][COLS] = {'A','B','C','D',
                              'E','F','G','H',
                              'A','B','C','D',
                              'E','F','G','H'};
    char revealed[ROWS][COLS] = {{0}};
    shuffle_board(board);
    clear_screen();
    display_board(revealed);

    int score = 0;
    while (score < BOARD_SIZE/2) {
        char* choice_1 = get_choice();
        int row_1, col_1;
        split_choice(choice_1, &row_1, &col_1);
        free(choice_1);
        if (revealed[row_1][col_1]) {
            printf("\n\nThat position has already been revealed! Please try again.\n");
            delay(2);
            clear_screen();
            display_board(revealed);
            continue;
        }
        revealed[row_1][col_1] = board[row_1][col_1];
        clear_screen();
        display_board(revealed);

        char* choice_2 = get_choice();
        int row_2, col_2;
        split_choice(choice_2, &row_2, &col_2);
        free(choice_2);
        if (revealed[row_2][col_2]) {
            printf("\n\nThat position has already been revealed! Please try again.\n");
            delay(2);
            clear_screen();
            display_board(revealed);
            continue;
        }
        revealed[row_2][col_2] = board[row_2][col_2];
        clear_screen();
        display_board(revealed);

        if (board[row_1][col_1] != board[row_2][col_2]) {
            revealed[row_1][col_1] = revealed[row_2][col_2] = 0;
            delay(2);
            clear_screen();
            display_board(revealed);
        } else {
            score++;
            printf("\n\n Match found! Your score is: %d\n", score);
            delay(2);
            clear_screen();
            display_board(revealed);
        }
    }
    printf("\n\nCongratulations! You've won!\n");
    return 0;
}