//FormAI DATASET v1.0 Category: Checkers Game ; Style: all-encompassing
#include <stdio.h>

#define ROWS 8
#define COLUMNS 8
#define WHITE 'O'
#define BLACK 'X'
#define EMPTY '-'
#define KING 'K'

int player, computer, turn, c_x, c_y, m_x, m_y, kingRow;
char board[ROWS][COLUMNS];

void initializeBoard(){
    for(int row = 0; row < ROWS; row++){
        for(int col = 0; col < COLUMNS; col++){
            if(row < 3 && (row + col) % 2 == 0){
                board[row][col] = BLACK;
            }
            else if(row > 4 && (row + col) % 2 == 0){
                board[row][col] = WHITE;
            }
            else{
                board[row][col] = EMPTY;
            }
        }
    }
}

void printBoard(){
    printf("   1  2  3  4  5  6  7  8\n");
    for(int row = 0; row < ROWS; row++){
        printf("%d ", row+1);
        for(int col = 0; col < COLUMNS; col++){
            printf("[%c]", board[row][col]);
        }
        printf("\n");
    }
}

int isLegalMove(int c_x, int c_y, int m_x, int m_y, char player){
    int dx = m_x - c_x;
    int dy = m_y - c_y;
    if(board[m_x][m_y] != EMPTY){
        return 0;
    }
    if(player == BLACK && dx > 0){
        return 0;
    }
    if(player == WHITE && dx < 0){
        return 0;
    }
    if(dx == 1 || dx == -1){
        if(dy == 1 || dy == -1){
            return 1;
        }
    }
    if(dx == 2 || dx == -2){
        if(dy == 2 || dy == -2){
            int x = c_x + (dx / 2);
            int y = c_y + (dy / 2);
            if(board[x][y] == EMPTY || board[x][y] == player){
                return 0;
            }
            return 1;
        }
    }
    return 0;
}

int isKing(int x, int y, char player){
    if(player == BLACK && x == ROWS-1){
        board[x][y] = KING;
        return 1;
    }
    if(player == WHITE && x == 0){
        board[x][y] = KING;
        return 1;
    }
    return 0;
}

void makeMove(int c_x, int c_y, int m_x, int m_y, char player){
    board[m_x][m_y] = board[c_x][c_y];
    board[c_x][c_y] = EMPTY;
    if(isKing(m_x, m_y, player)){
        printf("%c is now a King!\n", board[m_x][m_y]);
    }
}

void playerTurn(){
    printf("Player %c's turn\n", player);
    int validMoves = 0;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            if(board[i][j] == player || board[i][j] == KING){
                if(isLegalMove(i, j, i+1, j+1, player)){
                    validMoves++;
                }
                if(isLegalMove(i, j, i-1, j+1, player)){
                    validMoves++;
                }
                if(isLegalMove(i, j, i+1, j-1, player)){
                    validMoves++;
                }
                if(isLegalMove(i, j, i-1, j-1, player)){
                    validMoves++;
                }
            }
        }
    }
    if(validMoves == 0){
        printf("No valid moves, turn skipped\n");
        return;
    }
    while(1){
        printf("Enter the coordinates of the checker you want to move: ");
        scanf("%d %d", &c_x, &c_y);
        printf("Enter the coordinates of where you want to move it: ");
        scanf("%d %d", &m_x, &m_y);
        if(isLegalMove(c_x-1, c_y-1, m_x-1, m_y-1, player)){
            makeMove(c_x-1, c_y-1, m_x-1, m_y-1, player);
            turn++;
            break;
        }
        else{
            printf("Illegal move, try again\n");
        }
    }
}

void computerTurn(){
    printf("Computer's turn\n");
    int foundMove = 0;
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            if(board[i][j] == computer || board[i][j] == KING){
                if(isLegalMove(i, j, i+1, j+1, computer)){
                    makeMove(i, j, i+1, j+1, computer);
                    foundMove = 1;
                    turn++;
                    break;
                }
                if(isLegalMove(i, j, i-1, j+1, computer)){
                    makeMove(i, j, i-1, j+1, computer);
                    foundMove = 1;
                    turn++;
                    break;
                }
                if(isLegalMove(i, j, i+1, j-1, computer)){
                    makeMove(i, j, i+1, j-1, computer);
                    foundMove = 1;
                    turn++;
                    break;
                }
                if(isLegalMove(i, j, i-1, j-1, computer)){
                    makeMove(i, j, i-1, j-1, computer);
                    foundMove = 1;
                    turn++;
                    break;
                }
            }
        }
        if(foundMove){
            break;
        }
    }
    if(!foundMove){
        printf("Computer has no legal moves, turn skipped\n");
    }
}

int main(){
    initializeBoard();
    turn = 0;
    kingRow = (ROWS / 2) - 1;
    char input;
    printf("Welcome to Checkers!\n");
    printf("Do you want to play as O or X? (O goes first) ");
    scanf("%c", &input);
    if(input == 'O' || input == 'o'){
        player = WHITE;
        computer = BLACK;
    }
    else{
        player = BLACK;
        computer = WHITE;
    }
    while(1){
        printBoard();
        if(turn % 2 == 0){
            playerTurn();
        }
        else{
            computerTurn();
        }
        if(turn % 2 == 0 && !isKing(m_x-1, m_y-1, player) && isKing(c_x-1, c_y-1, player)){
            kingRow--;
        }
        if(turn % 2 == 1 && !isKing(m_x, m_y, computer) && isKing(c_x, c_y, computer)){
            kingRow++;
        }
        if(kingRow == 0){
            printf("White Wins!\n");
            break;
        }
        if(kingRow == ROWS - 1){
            printf("Black Wins!\n");
            break;
        }
    }
    return 0;
}