//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: happy
#include<stdio.h>
#define N 3

char board[N][N] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

void printBoard() {
    printf("\n");
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n\n");
}

int checkWin() {
    
    for(int i=0; i<N; i++) {
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return 1;
    }
    
    for(int i=0; i<N; i++) {
        if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return 1;
    }
    
    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return 1;
    
    if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return 1;
    
    return 0;
}

int checkDraw() {
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == ' ') return 0;
        }
    }
    
    return 1;
}

int evaluate(char mark) {
    if(mark == 'X') return 1;
    if(mark == 'O') return -1;
    return 0;
}

int minmax(char mark) {
    
    int score;
    
    if(checkWin() == 1) {
        score = evaluate(mark);
        return score;
    }
    
    if(checkDraw() == 1) return 0;
    
    if(mark == 'X') {
        int bestScore = -10000;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = mark;
                    int currentScore = minmax('O');
                    if(currentScore > bestScore) bestScore = currentScore;
                    board[i][j] = ' ';
                }
            }
        }
        return bestScore;
    }
    
    if(mark == 'O') {
        int bestScore = 10000;
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = mark;
                    int currentScore = minmax('X');
                    if(currentScore < bestScore) bestScore = currentScore;
                    board[i][j] = ' ';
                }
            }
        }
        return bestScore;
    }
}

void makeMove(char mark) {
    int bestScore = -10000, x, y;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = mark;
                int currentScore = minmax('O');
                if(currentScore > bestScore) {
                    bestScore = currentScore;
                    x = i;
                    y = j;
                }
                board[i][j] = ' ';
            }
        }
    }
    board[x][y] = mark;
}

int main() {
    
    char player = 'X';
    int x, y;
    
    printf("Welcome to the Tic-Tac-Toe game!\n\n");
    
    while(checkDraw() == 0 && checkWin() == 0) {
        
        if(player == 'X') {
            printf("Your turn!\n");
            printf("Enter the row (0-2): ");
            scanf("%d", &x);
            printf("Enter the column (0-2): ");
            scanf("%d", &y);
            if(board[x][y] != ' ') {
                printf("The move is not valid. Try Again!\n\n");
                continue;
            }
            board[x][y] = player;
            printBoard();
        }
        
        else {
            printf("My turn!\n");
            makeMove(player);
            printBoard();
        }
        
        if(checkWin() == 1) {
            printf("Congratulations! ");
            if(player == 'X') printf("You");
            else printf("I");
            printf(" won!\n");
            break;
        }
        
        if(checkDraw() == 1) {
            printf("The game is a draw!\n");
            break;
        }
        
        if(player == 'X') player = 'O';
        else player = 'X';
    }
    
    return 0;
}