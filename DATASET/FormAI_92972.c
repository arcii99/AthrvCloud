//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Board{
    char s[3][3];
    char human;
    char computer;
};

void displayBoard(struct Board *board)
{
    printf("\n");
    printf(" %c | %c | %c \n", board->s[0][0], board->s[0][1], board->s[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board->s[1][0], board->s[1][1], board->s[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board->s[2][0], board->s[2][1], board->s[2][2]);
    printf("\n");
}

bool gameIsOver(struct Board *b)
{
    if ((b->s[0][0] == b->human && b->s[0][1] == b->human && b->s[0][2] == b->human) ||
           (b->s[1][0] == b->human && b->s[1][1] == b->human && b->s[1][2] == b->human) || 
           (b->s[2][0] == b->human && b->s[2][1] == b->human && b->s[2][2] == b->human) || 
           (b->s[0][0] == b->human && b->s[1][0] == b->human && b->s[2][0] == b->human) || 
           (b->s[0][1] == b->human && b->s[1][1] == b->human && b->s[2][1] == b->human) || 
           (b->s[0][2] == b->human && b->s[1][2] == b->human && b->s[2][2] == b->human) ||
           (b->s[0][0] == b->human && b->s[1][1] == b->human && b->s[2][2] == b->human) ||
           (b->s[0][2] == b->human && b->s[1][1] == b->human && b->s[2][0] == b->human))
    {
        printf("Congratulations!! You win!!!\n");
        return true;
    }
    else if ((b->s[0][0] == b->computer && b->s[0][1] == b->computer && b->s[0][2] == b->computer) ||
               (b->s[1][0] == b->computer && b->s[1][1] == b->computer && b->s[1][2] == b->computer) ||
               (b->s[2][0] == b->computer && b->s[2][1] == b->computer && b->s[2][2] == b->computer) || 
               (b->s[0][0] == b->computer && b->s[1][0] == b->computer && b->s[2][0] == b->computer) || 
               (b->s[0][1] == b->computer && b->s[1][1] == b->computer && b->s[2][1] == b->computer) || 
               (b->s[0][2] == b->computer && b->s[1][2] == b->computer && b->s[2][2] == b->computer) ||
               (b->s[0][0] == b->computer && b->s[1][1] == b->computer && b->s[2][2] == b->computer) ||
               (b->s[0][2] == b->computer && b->s[1][1] == b->computer && b->s[2][0] == b->computer))
    {
        printf("You lose!!! Better luck next time...\n");
        return true;
    }
    else {
        bool full = true;
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (b->s[i][j] == ' ') {
                    full = false;
                }
            }
        }
        if (full) {
            printf("It's a tie!!!\n");
            return true;
        }
        return false;
    }
}

int evaluate(struct Board *b)
{
    int i;
    for (i = 0; i < 3; i++) {
        if ((b->s[i][0] == b->computer && b->s[i][1] == b->computer && b->s[i][2] == ' ') ||
            (b->s[i][0] == b->computer && b->s[i][2] == b->computer && b->s[i][1] == ' ') ||
            (b->s[i][1] == b->computer && b->s[i][2] == b->computer && b->s[i][0] == ' '))
        {
            return 1;
        }
        else if ((b->s[i][0] == b->human && b->s[i][1] == b->human && b->s[i][2] == ' ') ||
                 (b->s[i][0] == b->human && b->s[i][2] == b->human && b->s[i][1] == ' ') ||
                 (b->s[i][1] == b->human && b->s[i][2] == b->human && b->s[i][0] == ' '))
        {
            return -1;
        }
    }
    for (i = 0; i < 3; i++) {
        if ((b->s[0][i] == b->computer && b->s[1][i] == b->computer && b->s[2][i] == ' ') ||
            (b->s[0][i] == b->computer && b->s[2][i] == b->computer && b->s[1][i] == ' ') ||
            (b->s[1][i] == b->computer && b->s[2][i] == b->computer && b->s[0][i] == ' '))
        {
            return 1;
        }
        else if ((b->s[0][i] == b->human && b->s[1][i] == b->human && b->s[2][i] == ' ') ||
                 (b->s[0][i] == b->human && b->s[2][i] == b->human && b->s[1][i] == ' ') ||
                 (b->s[1][i] == b->human && b->s[2][i] == b->human && b->s[0][i] == ' '))
        {
            return -1;
        }
    }
    if ((b->s[0][0] == b->human && b->s[1][1] == b->human && b->s[2][2] == ' ') ||
        (b->s[0][0] == b->human && b->s[2][2] == b->human && b->s[1][1] == ' ') ||
        (b->s[1][1] == b->human && b->s[2][2] == b->human && b->s[0][0] == ' '))
        return -1;
    if ((b->s[0][2] == b->human && b->s[1][1] == b->human && b->s[2][0] == ' ') ||
        (b->s[0][2] == b->human && b->s[2][0] == b->human && b->s[1][1] == ' ') ||
        (b->s[1][1] == b->human && b->s[2][0] == b->human && b->s[0][2] == ' '))
        return -1;
    if ((b->s[0][0] == b->computer && b->s[1][1] == b->computer && b->s[2][2] == ' ') ||
        (b->s[0][0] == b->computer && b->s[2][2] == b->computer && b->s[1][1] == ' ') ||
        (b->s[1][1] == b->computer && b->s[2][2] == b->computer && b->s[0][0] == ' '))
        return 1;
    if ((b->s[0][2] == b->computer && b->s[1][1] == b->computer && b->s[2][0] == ' ') ||
        (b->s[0][2] == b->computer && b->s[2][0] == b->computer && b->s[1][1] == ' ') ||
        (b->s[1][1] == b->computer && b->s[2][0] == b->computer && b->s[0][2] == ' '))
        return 1;
    return 0;
}

int minimax(struct Board *b, bool maximizingPlayer, int alpha, int beta)
{
    if (gameIsOver(b)) {
        return evaluate(b);
    }

    int i, j;
    if (maximizingPlayer) {
        int maxVal = -2;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (b->s[i][j] == ' ') {
                    b->s[i][j] = b->computer;
                    int value = minimax(b, false, alpha, beta);
                    b->s[i][j] = ' ';
                    if (value > maxVal) {
                        maxVal = value;
                    }
                    alpha = alpha > maxVal ? alpha : maxVal;
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return maxVal;
    }
    else {
        int minVal = 2;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (b->s[i][j] == ' ') {
                    b->s[i][j] = b->human;
                    int value = minimax(b, true, alpha, beta);
                    b->s[i][j] = ' ';
                    if (value < minVal) {
                        minVal = value;
                    }
                    beta = beta < minVal ? beta : minVal;
                    if (beta <= alpha) {
                        break;
                    }
                }
            }
        }
        return minVal;
    }
}

void computerTurn(struct Board *b)
{
    int i, j;
    int maxVal = -2;
    int alpha = -2;
    int beta = 2;
    int best_i = -1;
    int best_j = -1;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (b->s[i][j] == ' ') {
                b->s[i][j] = b->computer;
                int value = minimax(b, false, alpha, beta);
                b->s[i][j] = ' ';
                if (value > maxVal) {
                    maxVal = value;
                    best_i = i;
                    best_j = j;
                }
            }
        }
    }

    b->s[best_i][best_j] = b->computer;
}

void humanTurn(struct Board *board)
{
    int row, col;
    printf("Enter your move [row,col] (e.g. 0,2 for top row, right column):\n");
    while (true) {
        scanf("%d,%d", &row, &col);
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board->s[row][col] == ' ') {
            break;
        }
        printf("Invalid move. Enter your move [row,col]:\n");
    }
    board->s[row][col] = board->human;
}

void newGame(struct Board * board)
{
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board->s[i][j] = ' ';
        }
    }
    printf("Would you like to go first?[y/n]:\n");
    char answer;
    scanf("%c", &answer);
    if (answer == 'y') {
        board->human = 'X';
        board->computer = 'O';
        displayBoard(board);
        humanTurn(board);
    } else {
        board->human = 'O';
        board->computer = 'X';
    }
    while (true) {
        displayBoard(board);
        computerTurn(board);
        if (gameIsOver(board)) {
            displayBoard(board);
            return;
        }
        displayBoard(board);
        humanTurn(board);
        if (gameIsOver(board)) {
            displayBoard(board);
            return;
        }
    }
}

int main()
{
    struct Board board;
    printf("Welcome to Tic Tac Toe!\n");
    newGame(&board);
    return 0;
}