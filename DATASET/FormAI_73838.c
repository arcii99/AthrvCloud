//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: lively
#include <stdio.h>

// Function to check if the game has ended
int gameEnded(char board[3][3]) {
    int i, j, count;
    
    // Check the rows
    for(i=0; i<3; i++) {
        count = 0;
        for(j=0; j<3; j++) {
            if(board[i][j] == 'O') count--;
            else if(board[i][j] == 'X') count++;
        }
        if(count == 3) return 1;
        else if(count == -3) return -1;
    }
    
    // Check the columns
    for(i=0; i<3; i++) {
        count = 0;
        for(j=0; j<3; j++) {
            if(board[j][i] == 'O') count--;
            else if(board[j][i] == 'X') count++;
        }
        if(count == 3) return 1;
        else if(count == -3) return -1;
    }
    
    // Check diagonal
    count = 0;
    for(i=0; i<3; i++) {
        if(board[i][i] == 'O') count--;
        else if(board[i][i] == 'X') count++;
    }
    if(count == 3) return 1;
    else if(count == -3) return -1;
    
    // Check anti-diagonal
    count = 0;
    for(i=0; i<3; i++) {
        if(board[i][2-i] == 'O') count--;
        else if(board[i][2-i] == 'X') count++;
    }
    if(count == 3) return 1;
    else if(count == -3) return -1;
    
    // Check for tie
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == ' ') return 0;
        }
    }
    return 2;
}

// Function to evaluate the minimax score of the board
int evaluate(char board[3][3], int depth, int isMax) {
    int result = gameEnded(board);
    if(result != 0) {
        if(result == 1) return 10 - depth;
        else if(result == -1) return depth - 10;
        else return 0;
    }
    if(isMax) {
        int max = -10000, score;
        int i, j;
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = 'X';
                    score = evaluate(board, depth+1, 0);
                    if(score > max) max = score;
                    board[i][j] = ' ';
                }
            }
        }
        return max;
    }
    else {
        int min = 10000, score;
        int i, j;
        for(i=0; i<3; i++) {
            for(j=0; j<3; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = 'O';
                    score = evaluate(board, depth+1, 1);
                    if(score < min) min = score;
                    board[i][j] = ' ';
                }
            }
        }
        return min;
    }
}

// Function to make a move
void move(char board[3][3], int* row, int* col) {
    int max = -10000, score;
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'X';
                score = evaluate(board, 0, 0);
                if(score > max) {
                    max = score;
                    *row = i;
                    *col = j;
                }
                board[i][j] = ' ';
            }
        }
    }
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int row, col, i, j;
    
    printf("Welcome to Tic Tac Toe!\n\n");
    printf("Player = O, Computer = X\n\n");
    printf("     1   2   3  \n");
    printf("   +---+---+---+\n");
    for(i=0; i<3; i++) {
        printf(" %d |", i+1);
        for(j=0; j<3; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n   +---+---+---+\n");
    }
    
    while(gameEnded(board) == 0) {
        printf("\nPlayer's Move (Enter row and column): ");
        scanf("%d%d", &row, &col);
        while(row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
            printf("\nInvalid Move! Please try again.\n");
            printf("Player's Move (Enter row and column): ");
            scanf("%d%d", &row, &col);
        }
        board[row-1][col-1] = 'O';
        printf("\n     1   2   3  \n");
        printf("   +---+---+---+\n");
        for(i=0; i<3; i++) {
            printf(" %d |", i+1);
            for(j=0; j<3; j++) {
                printf(" %c |", board[i][j]);
            }
            printf("\n   +---+---+---+\n");
        }
        
        if(gameEnded(board) != 0) break;
        
        printf("\nComputer's Move:\n");
        move(board, &row, &col);
        board[row][col] = 'X';
        printf("     1   2   3  \n");
        printf("   +---+---+---+\n");
        for(i=0; i<3; i++) {
            printf(" %d |", i+1);
            for(j=0; j<3; j++) {
                printf(" %c |", board[i][j]);
            }
            printf("\n   +---+---+---+\n");
        }
    }
    
    if(gameEnded(board) == 1) printf("\nThe Computer has won!\n\n");
    else if(gameEnded(board) == -1) printf("\nYou have won!\n\n");
    else printf("\nIt's a tie!\n\n");
    
    return 0;
}