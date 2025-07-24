//FormAI DATASET v1.0 Category: Checkers Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
} Position;

char board[8][8] = {
    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
    {' ', 'r', ' ', 'r', ' ', 'r', ' ', 'r'},
    {'r', ' ', 'r', ' ', 'r', ' ', 'r', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'},
    {'w', ' ', 'w', ' ', 'w', ' ', 'w', ' '},
    {' ', 'w', ' ', 'w', ' ', 'w', ' ', 'w'}
};

Position get_move(char *move){
    Position p;
    p.x = move[0] - 'a';
    p.y = move[1] - '1';
    return p;
}

char current_player = 'r';

void play_move(Position from, Position to){
    board[to.y][to.x] = board[from.y][from.x];
    board[from.y][from.x] = ' ';
}

int check_win(char player){
    for(int y=0; y<8; y++){
        for(int x=0; x<8; x++){
            if(board[y][x] == player || board[y][x] == (player + ('a'-'A'))){
                if(player == 'r' && board[y][x] == 'r'){
                    if(y>0 && x>0 && board[y-1][x-1]==' '){
                        return 0;
                    }
                    if(y>0 && x<7 && board[y-1][x+1]==' '){
                        return 0;
                    }
                    if(y>1 && x>1 && (board[y-1][x-1]=='w' || board[y-1][x-1]=='W') && board[y-2][x-2]==' '){
                        return 0;
                    }
                    if(y>1 && x<6 && (board[y-1][x+1]=='w' || board[y-1][x+1]=='W') && board[y-2][x+2]==' '){
                        return 0;
                    }
                }
                if(player == 'w' && board[y][x] == 'w'){
                    if(y<7 && x>0 && board[y+1][x-1]==' '){
                        return 0;
                    }
                    if(y<7 && x<7 && board[y+1][x+1]==' '){
                        return 0;
                    }
                    if(y<6 && x>1 && (board[y+1][x-1]=='r' || board[y+1][x-1]=='R') && board[y+2][x-2]==' '){
                        return 0;
                    }
                    if(y<6 && x<6 && (board[y+1][x+1]=='r' || board[y+1][x+1]=='R') && board[y+2][x+2]==' '){
                        return 0;
                    }
                }
                if(board[y][x] == (player + ('a'-'A'))){
                    if(y>0 && x>0 && board[y-1][x-1]==' '){
                        return 0;
                    }
                    if(y>0 && x<7 && board[y-1][x+1]==' '){
                        return 0;
                    }
                    if(y<7 && x>0 && board[y+1][x-1]==' '){
                        return 0;
                    }
                    if(y<7 && x<7 && board[y+1][x+1]==' '){
                        return 0;
                    }
                    if(y>1 && x>1 && (board[y-1][x-1]=='w' || board[y-1][x-1]=='W') && board[y-2][x-2]==' '){
                        return 0;
                    }
                    if(y>1 && x<6 && (board[y-1][x+1]=='w' || board[y-1][x+1]=='W') && board[y-2][x+2]==' '){
                        return 0;
                    }
                    if(y<6 && x>1 && (board[y+1][x-1]=='r' || board[y+1][x-1]=='R') && board[y+2][x-2]==' '){
                        return 0;
                    }
                    if(y<6 && x<6 && (board[y+1][x+1]=='r' || board[y+1][x+1]=='R') && board[y+2][x+2]==' '){
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

void print_board(){
    printf("  a b c d e f g h\n");
    for(int y=0; y<8; y++){
        printf("%d ", y+1);
        for(int x=0; x<8; x++){
            printf("%c ", board[y][x]);
        }
        printf("%d", y+1);
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

int main(){
    printf("Welcome to Checkers Game!\n");
    printf("To move a piece, enter the starting position followed by the ending position (e.g. a3 b4)\n");
    int player_won = 0;
    while(!player_won){
        print_board();
        printf("%c's turn: ", current_player);
        char move[5];
        scanf("%s", move);
        Position from = get_move(move);
        scanf("%s", move);
        Position to = get_move(move);
        int from_x = from.x;
        int from_y = from.y;
        int to_x = to.x;
        int to_y = to.y;
        if(board[from_y][from_x] == ' '){
            printf("There is no piece at position %c%c\n", from_x+'a', from_y+'1');
            continue;
        }
        if(board[to_y][to_x] != ' '){
            printf("There is already a piece at position %c%c\n", to_x+'a', to_y+'1');
            continue;
        }
        if(current_player == 'r'){
            if(from_y-to_y == 1 && abs(from_x-to_x) == 1){
                play_move(from, to);
                current_player = 'w';
            }
            else if(from_y-to_y == 2 && abs(from_x-to_x) == 2){
                int mid_x = (from_x+to_x)/2;
                int mid_y = (from_y+to_y)/2;
                if(board[mid_y][mid_x] == 'w' || board[mid_y][mid_x] == 'W'){
                    play_move(from, to);
                    board[mid_y][mid_x] = ' ';
                    current_player = 'w';
                }
                else{
                    printf("Invalid move\n");
                }
            }
            else{
                printf("Invalid move\n");
            }
        }
        else{
            if(to_y-from_y == 1 && abs(from_x-to_x) == 1){
                play_move(from, to);
                current_player = 'r';
            }
            else if(to_y-from_y == 2 && abs(from_x-to_x) == 2){
                int mid_x = (from_x+to_x)/2;
                int mid_y = (from_y+to_y)/2;
                if(board[mid_y][mid_x] == 'r' || board[mid_y][mid_x] == 'R'){
                    play_move(from, to);
                    board[mid_y][mid_x] = ' ';
                    current_player = 'r';
                }
                else{
                    printf("Invalid move\n");
                }
            }
            else{
                printf("Invalid move\n");
            }
        }
        if(check_win(current_player)){
            player_won = 1;
        }
    }
    printf("%c has won the game!\n", current_player);
    return 0;
}