//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    char board[3][3];
    int row, col, i, j;
    char player = 'X';
    srand(time(NULL));
    
    // Initialize Board
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
    
    // Print Board
    printf("Welcome to Tic Tac Toe Game\n");
    printf("You are Playing with X\n");
    printf("###########################\n");
    printf("  0 1 2\n");
    printf(" -------\n");
    for (i = 0; i < 3; i++) {
        printf("%d ", i);
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Game Loop
    while (1) {

        // Player's Turn
        printf("Player's Turn: \n");
        do {
            printf("Enter the Row (0-2): ");
            scanf("%d", &row);
            printf("Enter the Column (0-2): ");
            scanf("%d", &col);
        } while (board[row][col] != '-');

        board[row][col] = player;
        
        // Print Board
        printf("###########################\n");
        printf("  0 1 2\n");
        printf(" -------\n");
        for (i = 0; i < 3; i++) {
            printf("%d ", i);
            for (j = 0; j < 3; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        // Check for Win
        int win = 0;
        if ((board[0][0] == player && board[1][0] == player && board[2][0] == player) ||
            (board[0][1] == player && board[1][1] == player && board[2][1] == player) ||
            (board[0][2] == player && board[1][2] == player && board[2][2] == player) ||
            (board[0][0] == player && board[0][1] == player && board[0][2] == player) ||
            (board[1][0] == player && board[1][1] == player && board[1][2] == player) ||
            (board[2][0] == player && board[2][1] == player && board[2][2] == player) ||
            (board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
            printf("Congratulations! You Won!\n");
            win = 1;
            break;
        }

        // Check for Tie
        int found = 0;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    found = 1;
                    break;
                }
            }
        }
        if (found == 0) {
            printf("It's a Tie!\n");
            break;
        }

        // AI's Turn
        printf("AI's Turn: \n");
        do {
            row = rand() % 3;
            col = rand() % 3;
        } while (board[row][col] != '-');

        board[row][col] = 'O';
        
        // Print Board
        printf("###########################\n");
        printf("  0 1 2\n");
        printf(" -------\n");
        for (i = 0; i < 3; i++) {
            printf("%d ", i);
            for (j = 0; j < 3; j++) {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        
        // Check for Win
        if ((board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
            (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
            (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') ||
            (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') ||
            (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
            (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') ||
            (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
            (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
            printf("Sorry! You Lost!\n");
            win = 1;
            break;
        }
    }
    
    return 0;
}