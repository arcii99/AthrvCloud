//FormAI DATASET v1.0 Category: Checkers Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

enum Player {
    NONE = 0,
    PLAYER1 = 1,
    PLAYER2 = 2
};

struct Game{
    char board[BOARD_SIZE][BOARD_SIZE];
    enum Player turn;
};

char* getPlayer(enum Player player){
    return player == PLAYER1 ? "Player 1" : "Player 2";
}

void initBoard(struct Game* game){
    int i, j;
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            if((i+j)%2 == 0 && i<3){
                game->board[i][j] = '1';
            }else if((i+j)%2 == 0 && i>4){
                game->board[i][j] = '2';
            }else{
                game->board[i][j] = '-';
            }
        }
    }
}

void printBoard(struct Game* game){
    int i, j;
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(struct Game* game, int fromX, int fromY, int toX, int toY){
    if(toX < 0 || toX >= BOARD_SIZE || toY < 0 || toY >= BOARD_SIZE){
        return 0;
    }
    if(game->board[toX][toY] != '-'){
        return 0;
    }
    if(game->turn == PLAYER1 && game->board[fromX][fromY] != '1' &&
       game->board[fromX][fromY] != '3'){
        return 0;
    }
    if(game->turn == PLAYER2 && game->board[fromX][fromY] != '2' &&
       game->board[fromX][fromY] != '4'){
        return 0;
    }
    if(abs(fromX-toX) == 1 && abs(fromY-toY) == 1 &&
       game->board[fromX][fromY]%2 != game->board[toX][toY]%2){
        return 1;
    }
    int i, j, count = 0;
    if(abs(fromX-toX) == 2 && abs(fromY-toY) == 2 &&
       game->board[fromX][fromY]%2 != game->board[(fromX+toX)/2][(fromY+toY)/2]%2){
        for(i=(fromX < toX ? fromX : toX)+1, j=(fromY < toY ? fromY : toY)+1;
            i<(fromX < toX ? toX : fromX); i++, j++){
            if(game->board[i][j] != '-'){
                count++;
            }
        }
        return count == 1;
    }
    return 0;
}

int hasValidMove(struct Game* game, int x, int y){
    int i, j;
    for(i=-2; i<=2; i++){
        for(j=-2; j<=2; j++){
            if(abs(i) == 2 && abs(j) == 2){
                if(isValidMove(game, x, y, x+i, y+j)){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int isEnd(struct Game* game){
    int countPlayer1 = 0, countPlayer2 = 0, i, j;
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            if(game->board[i][j] == '1' || game->board[i][j] == '3'){
                countPlayer1++;
            }else if(game->board[i][j] == '2' || game->board[i][j] == '4'){
                countPlayer2++;
            }
        }
    }
    if(countPlayer1 == 0){
        return PLAYER2;
    }else if(countPlayer2 == 0){
        return PLAYER1;
    }
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            if(game->board[i][j] == '1' && !hasValidMove(game, i, j)){
                return PLAYER2;
            }
            if(game->board[i][j] == '2' && !hasValidMove(game, i, j)){
                return PLAYER1;
            }
        }
    }
    return NONE;
}

void makeMove(struct Game* game, int fromX, int fromY, int toX, int toY){
    if(isValidMove(game, fromX, fromY, toX, toY)){
        game->board[toX][toY] = game->board[fromX][fromY];
        game->board[fromX][fromY] = '-';
        if(game->board[toX][toY] == '1' && toX == BOARD_SIZE-1){
            game->board[toX][toY] = '3';
        }
        if(game->board[toX][toY] == '2' && toX == 0){
            game->board[toX][toY] = '4';
        }
        game->turn = game->turn == PLAYER1 ? PLAYER2 : PLAYER1;
    }
}

void startGame(struct Game* game){
    int fromX, fromY, toX, toY;
    while(isEnd(game) == NONE){
        system("clear");
        printf("It's %s's turn\n", getPlayer(game->turn));
        printBoard(game);
        printf("Enter the coordinates of the piece you want to move (row column): ");
        scanf("%d %d", &fromX, &fromY);
        printf("Enter the coordinates of your desired move (row column): ");
        scanf("%d %d", &toX, &toY);
        makeMove(game, fromX, fromY, toX, toY);
    }
    system("clear");
    printf(isEnd(game) == PLAYER1 ? "Player 1 wins!\n" : "Player 2 wins!\n");
    printBoard(game);
}

int main(){
    struct Game game;
    game.turn = PLAYER1;
    initBoard(&game);
    startGame(&game);
    return 0;
}