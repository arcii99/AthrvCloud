//FormAI DATASET v1.0 Category: Checkers Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

void init_board(){
    int i, j;
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            if((i+j) % 2 == 0){
                if(i < 3) board[i][j] = 1;
                else if(i > 4) board[i][j] = 2;
                else board[i][j] = 0;
            }
            else board[i][j] = 0;
        }
    }
}

void print_board(){
    int i, j;
    printf("  ");
    for(i=0; i<BOARD_SIZE; i++) printf("%c ", 'a'+i);
    printf("\n");
    for(i=0; i<BOARD_SIZE; i++){
        printf("%d ", BOARD_SIZE-i);
        for(j=0; j<BOARD_SIZE; j++){
            if(board[i][j] == 1) printf("O ");
            else if(board[i][j] == 2) printf("X ");
            else printf(". ");
        }
        printf("%d", BOARD_SIZE-i);
        printf("\n");
    }
    printf("  ");
    for(i=0; i<BOARD_SIZE; i++) printf("%c ", 'a'+i);
    printf("\n\n");
}

int is_valid(int from_x, int from_y, int to_x, int to_y, int player){
    if(from_x < 0 || from_x >= BOARD_SIZE || to_x < 0 || to_x >= BOARD_SIZE || from_y < 0 || from_y >= BOARD_SIZE || to_y < 0 || to_y >= BOARD_SIZE) return 0;
    if(board[from_x][from_y] != player) return 0;
    if(board[to_x][to_y] != 0) return 0;
    if(player == 1 && from_x > to_x) return 0;
    if(player == 2 && from_x < to_x) return 0;
    if(abs(to_x - from_x) == 2 && abs(to_y - from_y) == 2){
        int middle_x = (to_x + from_x) / 2;
        int middle_y = (to_y + from_y) / 2;
        if(player == 1 && board[middle_x][middle_y] != 2) return 0;
        if(player == 2 && board[middle_x][middle_y] != 1) return 0;
    }
    return 1;
}

int is_there_possible_move(int x, int y, int player){
    if(is_valid(x, y, x+1, y+1, player) || is_valid(x, y, x-1, y+1, player) || is_valid(x, y, x+1, y-1, player) || is_valid(x, y, x-1, y-1, player)){
        return 1;
    }
    if(is_valid(x, y, x+2, y+2, player) || is_valid(x, y, x-2, y+2, player) || is_valid(x, y, x+2, y-2, player) || is_valid(x, y, x-2, y-2, player)){
        return 1;
    }
    return 0;
}

void move(int from_x, int from_y, int to_x, int to_y){
    int player = board[from_x][from_y];
    board[from_x][from_y] = 0;
    board[to_x][to_y] = player;
    if(abs(to_x - from_x) == 2 && abs(to_y - from_y) == 2){
        int middle_x = (to_x + from_x) / 2;
        int middle_y = (to_y + from_y) / 2;
        board[middle_x][middle_y] = 0;
    }
    if(to_x == 0 && player == 2) board[to_x][to_y] = 4;
    if(to_x == BOARD_SIZE-1 && player == 1) board[to_x][to_y] = 3;
}

int count_pieces(int player){
    int count = 0, i, j;
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            if(board[i][j] == player || board[i][j] == player+2){
                count++;
            }
        }
    }
    return count;
}

int get_winner(){
    int p1_pieces = count_pieces(1) + count_pieces(3);
    int p2_pieces = count_pieces(2) + count_pieces(4);
    if(p1_pieces == 0) return 2;
    if(p2_pieces == 0) return 1;
    return 0;
}

int main(){
    int i, j;
    int turn = 1;
    int winner = 0;
    int from_x, from_y, to_x, to_y;
    init_board();
    while(winner == 0){
        print_board();
        printf("Player %d's turn.\n", turn);
        printf("Enter from coordinate (e.g. a1): ");
        scanf("%c%d", &from_y, &from_x);
        getchar(); // to consume the newline character
        from_x = BOARD_SIZE - from_x;
        from_y -= 'a';
        
        printf("Enter to coordinate (e.g. b2): ");
        scanf("%c%d", &to_y, &to_x);
        getchar(); // to consume the newline character
        to_x = BOARD_SIZE - to_x;
        to_y -= 'a';
        
        if(is_valid(from_x, from_y, to_x, to_y, turn)){
            move(from_x, from_y, to_x, to_y);
            if(is_there_possible_move(to_x, to_y, turn)){
                printf("You have another move available!\n");
            }
            else{
                turn = (turn == 1) ? 2 : 1;
            }
        }
        else{
            printf("Invalid move!\n");
        }
        winner = get_winner();
    }
    printf("Game over!\n");
    print_board();
    if(winner == 1) printf("Player 1 wins!\n");
    else if(winner == 2) printf("Player 2 wins!\n");
    else printf("It's a tie!\n");
    return 0;
}