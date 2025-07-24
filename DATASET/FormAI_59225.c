//FormAI DATASET v1.0 Category: Checkers Game ; Style: shocked
#include<stdio.h>
#include<string.h>
#define ROW 8
#define COL 8

char board[ROW][COL]; 
int turn = 1; // 1 denotes player 1, 2 denotes player 2
int selected_x, selected_y; // coordinates for currently selected piece

void initialize_board()
{
    // initialize the board with all pieces placed in their starting positions
    int i, j;
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            if(i % 2 == j % 2){
                if(i < 3)
                    board[i][j] = 'p'; // 'p' for player 1 piece
                else if(i > 4)
                    board[i][j] = 'P'; // 'P' for player 2 piece
                else
                    board[i][j] = '.';
            }
            else
                board[i][j] = '.';
        }
    }
}

int check_move_possible(int x, int y, int new_x, int new_y)
{
    // check if the move from (x,y) to (new_x,new_y) is legal
    if(board[new_x][new_y] != '.')
        return 0;
    if(turn == 1){
        if(new_x < x)
            return 0;
        if(new_x > x + 2 || new_y > y + 2 || new_y < y - 2)
            return 0;
        if(new_x == x + 2 && new_y == y - 2 && board[x+1][y-1] != 'P')
            return 0;
        if(new_x == x + 2 && new_y == y + 2 && board[x+1][y+1] != 'P')
            return 0;
    }
    else{
        if(new_x > x)
            return 0;
        if(new_x < x - 2 || new_y > y + 2 || new_y < y - 2)
            return 0;
        if(new_x == x - 2 && new_y == y - 2 && board[x-1][y-1] != 'p')
            return 0;
        if(new_x == x - 2 && new_y == y + 2 && board[x-1][y+1] != 'p')
             return 0;
    }
    return 1;
}

void make_move(int x, int y, int new_x, int new_y)
{
    // make the move from (x,y) to (new_x,new_y) on the board
    board[new_x][new_y] = board[x][y];
    board[x][y] = '.';
    if(turn == 1 && new_x == ROW - 1)
        board[new_x][new_y] = 'P';
    else if(turn == 2 && new_x == 0)
        board[new_x][new_y] = 'p';
    if(abs(x - new_x) == 2){ // capture move
        int middle_x = (x + new_x) / 2, middle_y = (y + new_y) / 2;
        board[middle_x][middle_y] = '.';
    }
}

void select_piece(int x, int y)
{
    // select a piece on the board to move
    if(board[x][y] == 'p' && turn == 1)
        return;
    if(board[x][y] == 'P' && turn == 2)
        return;
    selected_x = x;
    selected_y = y;
}

void move_piece(int x, int y)
{
    // move the currently selected piece to (x,y)
    if(check_move_possible(selected_x, selected_y, x, y)){
        make_move(selected_x, selected_y, x, y);
        turn = (turn == 1) ? 2 : 1;
    }
}

void draw_board()
{
    // print the current state of the board to console
    int i, j;
    printf("  0 1 2 3 4 5 6 7\n");
    for(i = 0; i < ROW; i++){
        printf("%d ", i);
        for(j = 0; j < COL; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_game_over()
{
    // check if the game is over
    int i, j, player1_pieces = 0, player2_pieces = 0;
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            if(board[i][j] == 'p' || board[i][j] == 'P')
                player1_pieces++;
            if(board[i][j] == 'P' || board[i][j] == 'p')
                player2_pieces++;
        }
    }
    if(player1_pieces == 0 || player2_pieces == 0)
        return 1;
    return 0;
}

int main()
{
    initialize_board();
    while(1){
        draw_board();
        if(check_game_over()){
            printf("Game over!\n");
            break;
        }
        printf("Player %d's turn...\n", turn);
        int x, y, new_x, new_y;
        printf("Select a piece to move (row column): ");
        scanf("%d %d", &x, &y);
        select_piece(x, y);
        printf("Move piece to (row column): ");
        scanf("%d %d", &new_x, &new_y);
        move_piece(new_x, new_y);
    }
    return 0;
}