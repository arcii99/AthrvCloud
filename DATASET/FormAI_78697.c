//FormAI DATASET v1.0 Category: Chess AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];
const int pawn_row[2] = {1, 6};
const int other_row[2] = {0, 7};
const char pieces[] = "PNBRQKpnbrqk";

int abs(int n){
    return (n < 0) ? -n : n;
}

bool is_lower(char c){
    return (c >= 'a' && c <= 'z');
}

bool is_upper(char c){
    return (c >= 'A' && c <= 'Z');
}

bool is_valid_position(int x, int y){
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

bool is_empty(int x, int y){
    return (is_valid_position(x, y) && board[x][y] == 0);
}

bool is_opponent(int x, int y, int color){
    if(is_valid_position(x, y)){
        if(is_lower(pieces[board[x][y]]) && color == 1){
            return true;
        }
        if(is_upper(pieces[board[x][y]]) && color == -1){
            return true;
        }
    }
    return false;
}

bool is_friendly(int x, int y, int color){
    if(is_valid_position(x, y)){
        if(is_lower(pieces[board[x][y]]) && color == -1){
            return true;
        }
        if(is_upper(pieces[board[x][y]]) && color == 1){
            return true;
        }
    }
    return false;
}

bool is_pawn(int x, int y, int color){
    if(is_valid_position(x, y)){
        if(pieces[board[x][y]] == 'P' && color == 1){
            return true;
        }
        if(pieces[board[x][y]] == 'p' && color == -1){
            return true;
        }
    }
    return false;
}

bool is_king(int x, int y, int color){
    if(is_valid_position(x, y)){
        if(pieces[board[x][y]] == 'K' && color == 1){
            return true;
        }
        if(pieces[board[x][y]] == 'k' && color == -1){
            return true;
        }
    }
    return false;
}

bool is_attacked(int x, int y, int color){
    int i, j, dx, dy;

    // check for pawns
    if(color == 1){
        if(is_opponent(x-1, y-1, color) || is_opponent(x-1, y+1, color)){
            return true;
        }
    }
    else{
        if(is_opponent(x+1, y-1, color) || is_opponent(x+1, y+1, color)){
            return true;
        }
    }

    // check for knights
    for(i=-2; i<=2; i++){
        for(j=-2; j<=2; j++){
            if(abs(i) + abs(j) == 3){
                dx = x + i;
                dy = y + j;
                if(is_opponent(dx, dy, color) && pieces[board[dx][dy]] == 'N'){
                    return true;
                }
            }
        }
    }

    // check for bishops and queens
    for(dx=-1; dx<=1; dx++){
        for(dy=-1; dy<=1; dy++){
            if(!(dx == 0 && dy == 0) && abs(dx) + abs(dy) <= 1){
                i = x + dx;
                j = y + dy;
                while(is_empty(i, j)){
                    i += dx;
                    j += dy;
                }
                if(is_opponent(i, j, color) && (pieces[board[i][j]] == 'B' || pieces[board[i][j]] == 'Q')){
                    return true;
                }
            }
        }
    }

    // check for rooks and queens
    for(dx=-1; dx<=1; dx++){
        for(dy=-1; dy<=1; dy++){
            if(!(dx == 0 && dy == 0) && (dx == 0 || dy == 0)){
                i = x + dx;
                j = y + dy;
                while(is_empty(i, j)){
                    i += dx;
                    j += dy;
                }
                if(is_opponent(i, j, color) && (pieces[board[i][j]] == 'R' || pieces[board[i][j]] == 'Q')){
                    return true;
                }
            }
        }
    }

    // check for kings
    for(i=-1; i<=1; i++){
        for(j=-1; j<=1; j++){
            if(i != 0 || j != 0){
                dx = x + i;
                dy = y + j;
                if(is_opponent(dx, dy, color) && is_king(dx, dy, color)){
                    return true;
                }
            }
        }
    }

    return false;
}

bool is_check(int color){
    int i, j, x, y;

    // find king
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            if(is_king(i, j, color)){
                x = i;
                y = j;
            }
        }
    }

    return is_attacked(x, y, color);
}

bool can_move(int xi, int yi, int xf, int yf, int color){
    int i, j, dx, dy;

    if(!is_valid_position(xi, yi) || !is_valid_position(xf, yf)){
        return false;
    }
    if(is_empty(xi, yi)){
        return false;
    }
    if(is_friendly(xf, yf, color)){
        return false;
    }
    if(xi == xf && yi == yf){
        return false;
    }

    switch(pieces[board[xi][yi]]){
        case 'P':
        case 'p':
            // move forward
            if(xi + color == xf && yi == yf && is_empty(xf, yf)){
                return true;
            }
            // capture
            if(is_opponent(xf, yf, color) && abs(yf-yi) == 1 && xi + color == xf){
                return true;
            }
            // double move
            if(color == 1 && xi == pawn_row[0] && xf == pawn_row[0]+2 && yi == yf && is_empty(xi+1, yi) && is_empty(xi+2, yi)){
                return true;
            }
            if(color == -1 && xi == pawn_row[1] && xf == pawn_row[1]-2 && yi == yf && is_empty(xi-1, yi) && is_empty(xi-2, yi)){
                return true;
            }
            break;
        case 'N':
        case 'n':
            dx = abs(xf - xi);
            dy = abs(yf - yi);
            if((dx == 2 && dy == 1) || (dx == 1 && dy == 2)){
                if(!is_friendly(xf, yf, color)){
                    return true;
                }
            }
            break;
        case 'B':
        case 'b':
            if(abs(xf-xi) == abs(yf-yi)){
                dx = (xf-xi)/abs(xf-xi);
                dy = (yf-yi)/abs(yf-yi);
                i = xi + dx;
                j = yi + dy;
                while(i != xf && j != yf){
                    if(!is_empty(i, j)){
                        return false;
                    }
                    i += dx;
                    j += dy;
                }
                if(!is_friendly(xf, yf, color)){
                    return true;
                }
            }
            break;
        case 'R':
        case 'r':
            if(xi == xf || yi == yf){
                dx = (xf-xi == 0) ? 0 : (xf-xi)/abs(xf-xi);
                dy = (yf-yi == 0) ? 0 : (yf-yi)/abs(yf-yi);
                i = xi + dx;
                j = yi + dy;
                while(i != xf || j != yf){
                    if(!is_empty(i, j)){
                        return false;
                    }
                    i += dx;
                    j += dy;
                }
                if(!is_friendly(xf, yf, color)){
                    return true;
                }
            }
            break;
        case 'Q':
        case 'q':
            if(xi == xf || yi == yf || abs(xf-xi) == abs(yf-yi)){
                if(xi == xf || yi == yf){
                    dx = (xf-xi == 0) ? 0 : (xf-xi)/abs(xf-xi);
                    dy = (yf-yi == 0) ? 0 : (yf-yi)/abs(yf-yi);
                    i = xi + dx;
                    j = yi + dy;
                    while(i != xf || j != yf){
                        if(!is_empty(i, j)){
                            return false;
                        }
                        i += dx;
                        j += dy;
                    }
                    if(!is_friendly(xf, yf, color)){
                        return true;
                    }
                }
                else{
                    if(abs(xf-xi) == abs(yf-yi)){
                        dx = (xf-xi)/abs(xf-xi);
                        dy = (yf-yi)/abs(yf-yi);
                        i = xi + dx;
                        j = yi + dy;
                        while(i != xf && j != yf){
                            if(!is_empty(i, j)){
                                return false;
                            }
                            i += dx;
                            j += dy;
                        }
                        if(!is_friendly(xf, yf, color)){
                            return true;
                        }
                    }
                }
            }
            break;
        case 'K':
        case 'k':
            dx = abs(xf - xi);
            dy = abs(yf - yi);
            if((dx == 1 && dy == 0) || (dx == 0 && dy == 1) || (dx == 1 && dy == 1)){
                if(!is_friendly(xf, yf, color)){
                    return true;
                }
            }
            break;
        default:
            break;
    }

    return false;
}

bool in_checkmate(int color){
    int i, j, x, y, dx, dy;
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            if(is_friendly(i, j, color)){
                x = i;
                y = j;
                for(dx=-1; dx<=1; dx++){
                    for(dy=-1; dy<=1; dy++){
                        if(dx != 0 || dy != 0){
                            if(can_move(x, y, x+dx, y+dy, color)){
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

bool in_stalemate(int color){
    int i, j, x, y, dx, dy;
    for(i=0; i<BOARD_SIZE; i++){
        for(j=0; j<BOARD_SIZE; j++){
            if(is_friendly(i, j, color)){
                x = i;
                y = j;
                for(dx=-1; dx<=1; dx++){
                    for(dy=-1; dy<=1; dy++){
                        if(dx != 0 || dy != 0){
                            if(can_move(x, y, x+dx, y+dy, color)){
                                return false;
                            }
                        }
                    }
                }
            }
        }
    }
    return !is_check(color);
}

void print_board(){
    int x, y;
    for(y=BOARD_SIZE-1; y>=0; y--){
        printf("%d ", y+1);
        for(x=0; x<BOARD_SIZE; x++){
            printf("%c ", pieces[board[x][y]]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

void setup_board(){
    int i, x, y;

    // set up pawns
    for(i=0; i<2; i++){
        for(x=0; x<BOARD_SIZE; x++){
            board[x][pawn_row[i]] = (i == 0) ? 1 : -1;
        }
    }

    // set up other pieces
    for(i=0; i<2; i++){
        board[0][other_row[i]] = (i == 0) ? 2 : -2;
        board[7][other_row[i]] = (i == 0) ? 2 : -2;
        board[1][other_row[i]] = (i == 0) ? 3 : -3;
        board[6][other_row[i]] = (i == 0) ? 3 : -3;
        board[2][other_row[i]] = (i == 0) ? 4 : -4;
        board[5][other_row[i]] = (i == 0) ? 4 : -4;
        board[3][other_row[i]] = (i == 0) ? 5 : -5;
        board[4][other_row[i]] = (i == 0) ? 6 : -6;
    }
}

void make_move(int xi, int yi, int xf, int yf){
    board[xf][yf] = board[xi][yi];
    board[xi][yi] = 0;
}

int main(){
    int xi, yi, xf, yf, color, winner;

    setup_board();
    color = 1;
    print_board();

    while(true){
        printf("--------------------\n");
        printf("It is %s's turn.\n", (color == 1) ? "white" : "black");
        printf("Enter move (e.g. 'd2 d4'): ");
        scanf("%c%d %c%d", &xi, &yi, &xf, &yf);
        xi -= 'a';
        xf -= 'a';
        yi -= 1;
        yf -= 1;
        getchar();
        if(can_move(xi, yi, xf, yf, color)){
            make_move(xi, yi, xf, yf);
            print_board();
            if(in_checkmate(-color)){
                printf("Checkmate! %s wins!\n", (color == 1) ? "white" : "black");
                break;
            }
            if(in_stalemate(-color)){
                printf("Stalemate!\n");
                break;
            }
            if(is_check(-color)){
                printf("Check!\n");
            }
            color *= -1;
        }
        else{
            printf("Invalid move.\n");
        }
    }

    return 0;
}