//FormAI DATASET v1.0 Category: Checkers Game ; Style: synchronous
#include <stdio.h>

char board[8][8];
char turn = 'r';
int gameover = 0;

void print_board() {
    printf("  ");
    for(int i=0;i<8;i++) printf("%d ", i+1);
    printf("\n");
    for(int i=0;i<8;i++) {
        printf("%d ", i+1);
        for(int j=0;j<8;j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int legal_move(int x1, int y1, int x2, int y2) {
    if(board[x2][y2]!='-') return 0;
    int dirx = x2 > x1 ? 1 : -1;
    int diry = y2 > y1 ? 1 : -1;
    if(board[x1][y1]==turn) {
        if(x2==x1+2*dirx && y2==y1+2*diry && board[x1+dirx][y1+diry]!='-' && board[x1+dirx][y1+diry]!=turn) {
            board[x1][y1] = '-';
            board[x1+dirx][y1+diry] = '-';
            board[x2][y2] = turn;
            if(x2==7) board[x2][y2] = 'R';
            if(is_endgame()) gameover = 1;
            return 1;
        }
        else if(x2==x1+dirx && y2==y1+diry && board[x2][y2]=='-') {
            board[x1][y1] = '-';
            board[x2][y2] = turn;
            if(x2==7) board[x2][y2] = 'R';
            if(is_endgame()) gameover = 1;
            return 1;
        }
    }
    else if(board[x1][y1]==toupper(turn)) {
        if(abs(x1-x2)!=abs(y1-y2)) return 0;
        int j = y1 + diry;
        for(int i=x1+dirx;i!=x2;i+=dirx) {
            if(board[i][j]!= '-') return 0;
            j += diry;
        }
        board[x1][y1] = '-';
        board[x2][y2] = toupper(turn);
        if(is_endgame()) gameover = 1;
        return 1;
    }
    return 0;
}

int is_endgame() {
    int num_r = 0, num_b = 0;
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(board[i][j]=='r' || board[i][j]=='R') num_r++;
            if(board[i][j]=='b' || board[i][j]=='B') num_b++;
        }
    }
    if(num_r==0 || num_b==0) return 1;
    return 0;
}

int main() {
    for(int i=0;i<8;i++) {
        for(int j=0;j<8;j++) {
            if(i<3 && (i+j)%2==0) board[i][j] = 'b';
            else if(i>4 && (i+j)%2==0) board[i][j] = 'r';
            else board[i][j] = '-';
        }
    }
    do {
        print_board();
        printf("%c's turn.\n", turn);
        int x1, x2, y1, y2;
        printf("Enter starting row and column:\n");
        scanf("%d%d", &x1, &y1);
        x1--;
        y1--;
        printf("Enter ending row and column:\n");
        scanf("%d%d", &x2, &y2);
        x2--;
        y2--;
        if(legal_move(x1, y1, x2, y2)) {
            if(gameover) {
                printf("%c wins!\n", turn);
                return 0;
            }
            turn = turn=='r' ? 'b' : 'r';
        }
        else {
            printf("Invalid move, try again.\n");
        }
    } while(1);
    return 0;
}