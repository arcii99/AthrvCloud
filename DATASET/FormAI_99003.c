//FormAI DATASET v1.0 Category: Table Game ; Style: calm
#include <stdio.h>

int main() {
    int player1_score = 0, player2_score = 0;
    int is_player1_turn = 1;
    int score_table[10][10];
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            score_table[i][j] = (i + 1) * (j + 1);
        }
    }

    printf("Welcome to C Table Game!\n");
    printf("Player 1, please enter your name: ");
    char player1_name[50];
    scanf("%s", player1_name);
    printf("Player 2, please enter your name: ");
    char player2_name[50];
    scanf("%s", player2_name);

    while(1) {
        if(is_player1_turn) {
            printf("%s's turn:\n", player1_name);
        } else {
            printf("%s's turn:\n", player2_name);
        }
        printf("Enter the row number and column number (0-9) separated by a space: ");
        int row, col;
        scanf("%d %d", &row, &col);
        if(row < 0 || row > 9 || col < 0 || col > 9) {
            printf("Invalid input, please enter again.\n");
            continue;
        }
        if(score_table[row][col] == -1) {
            printf("This cell has already been chosen, please enter again.\n");
            continue;
        }
        int score = score_table[row][col];
        if(is_player1_turn) {
            player1_score += score;
        } else {
            player2_score += score;
        }
        score_table[row][col] = -1;
        printf("Scored %d points!\n", score);
        printf("%s's score: %d, %s's score: %d\n", player1_name, player1_score, player2_name, player2_score);
        if(player1_score >= 200 || player2_score >= 200) {
            break;
        }
        is_player1_turn = !is_player1_turn;
    }

    if(player1_score > player2_score) {
        printf("%s wins!\n", player1_name);
    } else if(player1_score < player2_score) {
        printf("%s wins!\n", player2_name);
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}