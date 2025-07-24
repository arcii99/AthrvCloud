//FormAI DATASET v1.0 Category: Checkers Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 8
#define PLAYER_ONE '1'
#define PLAYER_TWO '2'

char board[BOARD_SIZE][BOARD_SIZE];

// Prints the game board
void print_board()
{
    system("clear");
    printf("   A B C D E F G H\n");
    for(int i=0; i<BOARD_SIZE; i++){
        printf("%d  ", i+1);
        for(int j=0; j<BOARD_SIZE; j++){
            printf("%c ", board[i][j]);
        }
        printf(" %d\n", i+1);
    }
    printf("   A B C D E F G H\n");
}

// Initializes the board with pieces
void initialize_board()
{
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE; j++){
            if(i%2==0 && j%2==0){
                if(i<3)
                    board[i][j] = PLAYER_ONE;
                else if(i>4)
                    board[i][j] = PLAYER_TWO;
                else
                    board[i][j] = ' ';
            }
            else if(i%2==1 && j%2==1){
                if(i<3)
                    board[i][j] = PLAYER_ONE;
                else if(i>4)
                    board[i][j] = PLAYER_TWO;
                else
                    board[i][j] = ' ';
            }
            else{
                board[i][j] = ' ';
            }
        }
    }
}

// Gets player move and returns the position as a string
char* get_move(int player)
{
    char* move = malloc(3);
    printf("\nPlayer %d's move: ", player);
    scanf("%s", move);
    while(move[0]<'A' || move[0]>('A'+BOARD_SIZE-1) || move[1]<'1' || move[1]>('1'+BOARD_SIZE-1) || board[move[1]-'1'][move[0]-'A']==' ' || board[move[1]-'1'][move[0]-'A']!=PLAYER_ONE && board[move[1]-'1'][move[0]-'A']!=PLAYER_TWO){
        printf("Invalid move. Enter a valid move: ");
        scanf("%s", move);
    }
    return move;
}

// Moves the piece on the board if it's a valid move
bool move_piece(char* move, int player)
{
    int x = move[0]-'A';
    int y = move[1]-'1';
    if(board[y][x]==PLAYER_ONE && player==1 || board[y][x]==PLAYER_TWO && player==2){
        printf("%c\n", board[y][x]);
        printf("1\n");
        return true;
    } else {
        printf("Invalid move.\n");
        return false;
    }
}

// Main function
int main()
{
    initialize_board();
    print_board();

    int player = 1;
    bool game_over = false;

    while(!game_over){
        char* move = get_move(player);
        if(move_piece(move, player)){
            printf("Valid move.\n");
        }
        player = player==1 ? 2 : 1;
        free(move);
    }
    return 0;
}