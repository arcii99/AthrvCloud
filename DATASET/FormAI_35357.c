//FormAI DATASET v1.0 Category: Chess AI ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>

#define KING_WEIGHT 200 // The weightage of a king
#define QUEEN_WEIGHT 9 // The weightage of a queen
#define KNIGHT_WEIGHT 3 // The weightage of a knight
#define BISHOP_WEIGHT 3 // The weightage of a bishop
#define ROOK_WEIGHT 5 // The weightage of a rook
#define PAWN_WEIGHT 1 // The weightage of a pawn

/** Structure to hold a chess piece*/
struct piece {
    char color;
    char type;
    int x;
    int y;
};

/** Function to print the chess board */
void printBoard(char board[][8]) {
    printf("\n  a b c d e f g h\n");
    for(int i=0; i<8; i++) {
      printf("%d ", i+1);
      for(int j=0; j<8; j++) {
          printf("%c ", board[i][j]);
      }
      printf("%d\n", i+1);
    }
    printf("  a b c d e f g h\n\n");
}

/** Function to get the value of a chess piece */
int getValue(char type) {
    if(type == 'K') {
        return KING_WEIGHT;
    } else if(type == 'Q') {
        return QUEEN_WEIGHT;
    } else if(type == 'N') {
        return KNIGHT_WEIGHT;
    } else if(type == 'B') {
        return BISHOP_WEIGHT;
    } else if(type == 'R') {
        return ROOK_WEIGHT;
    } else {
        return PAWN_WEIGHT;
    }
}

/** Function to check if a move is valid */
int isValidMove(char board[][8], struct piece p, int newX, int newY) {
    if(newX < 0 || newX > 7 || newY < 0 || newY > 7) {
        return 0;
    }
    if(p.x == newX && p.y == newY) {
        return 0;
    }
    if(board[newX][newY] != ' ') {
        if(board[newX][newY] == 'K' && p.type != 'P') {
            return 0;
        } else if(board[newX][newY] == p.type && p.type != 'P') {
            return 0;
        } else if(board[newX][newY] != p.type && p.type == 'P') {
            return 0;
        }
    }
    if(p.type == 'K') {
        if(abs(p.x - newX) > 1 || abs(p.y - newY) > 1) {
            return 0;
        }
    } else if(p.type == 'Q') {
        if(p.x != newX && p.y != newY && abs(p.x - newX) != abs(p.y - newY)) {
            return 0;
        }
        int dx = p.x < newX ? 1 : (p.x > newX ? -1 : 0);
        int dy = p.y < newY ? 1 : (p.y > newY ? -1 : 0);
        for(int i=p.x+dx,j=p.y+dy;i!=newX || j!=newY;i+=dx,j+=dy) {
            if(board[i][j] != ' ' && (i != p.x || j != p.y)) {
                return 0;
            }
        }
    } else if(p.type == 'N') {
        if(abs(p.x - newX) == 2 && abs(p.y - newY) == 1) {
            return 1;
        } else if(abs(p.x - newX) == 1 && abs(p.y - newY) == 2) {
            return 1;
        } else {
            return 0;
        }
    } else if(p.type == 'B') {
        if(abs(p.x - newX) != abs(p.y - newY)) {
            return 0;
        }
        int dx = p.x < newX ? 1 : -1;
        int dy = p.y < newY ? 1 : -1;
        for(int i=p.x+dx,j=p.y+dy;i!=newX+dx;i+=dx,j+=dy) {
            if(board[i][j] != ' ' && (i != p.x || j != p.y)) {
                return 0;
            }
        }
    } else if(p.type == 'R') {
        if(p.x != newX && p.y != newY) {
            return 0;
        }
        int dx = p.x == newX ? 0 : (p.x < newX ? 1 : -1);
        int dy = p.y == newY ? 0 : (p.y < newY ? 1 : -1);
        for(int i=p.x+dx,j=p.y+dy;i!=newX+dx || j!=newY+dy;i+=dx,j+=dy) {
            if(board[i][j] != ' ' && (i != p.x || j != p.y)) {
                return 0;
            }
        }
    } else if(p.type == 'P') {
        if(p.color == 'W') {
            if(newY == p.y && newX == p.x-1 && board[newX][newY] == ' ') {
                return 1;
            } else if(newY == p.y+1 && newX == p.x-1 && board[newX][newY] != ' ') {
                return 1;
            } else if(newY == p.y-1 && newX == p.x-1 && board[newX][newY] != ' ') {
                return 1;
            } else if(newY == p.y && newX == p.x-2 && p.x == 6 && board[newX][newY] == ' ' && board[p.x-1][newY] == ' ') {
                return 1;
            } else {
                return 0;
            }
        } else {
            if(newY == p.y && newX == p.x+1 && board[newX][newY] == ' ') {
                return 1;
            } else if(newY == p.y-1 && newX == p.x+1 && board[newX][newY] != ' ') {
                return 1;
            } else if(newY == p.y+1 && newX == p.x+1 && board[newX][newY] != ' ') {
                return 1;
            } else if(newY == p.y && newX == p.x+2 && p.x == 1 && board[newX][newY] == ' ' && board[p.x+1][newY] == ' ') {
                return 1;
            } else {
                return 0;
            }
        }
    }
    return 1;
}

/** Function to get the best move for the AI player */
void getBestMove(char board[][8], char color) {
    struct piece pieces[16];
    int pieceCount = 0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j] != ' ' && (color == 'B' ? board[i][j] >= 'a' : board[i][j] <= 'Z')) {
                struct piece p = {
                    .color = board[i][j] >= 'a' ? 'B' : 'W',
                    .type = board[i][j] >= 'a' ? board[i][j] - 32 : board[i][j],
                    .x = i,
                    .y = j
                };
                pieces[pieceCount] = p;
                pieceCount++;
            }
        }
    }
    int bestMoveValue = -1;
    int bestMoveIndex = -1;
    for(int i=0; i<pieceCount; i++) {
        struct piece p = pieces[i];
        for(int a=0; a<8; a++) {
            for(int b=0; b<8; b++) {
                if(isValidMove(board, p, a, b)) {
                    int value = getValue(p.type);
                    if(board[a][b] != ' ') {
                        value += getValue(board[a][b]);
                    }
                    if(value > bestMoveValue) {
                        bestMoveValue = value;
                        bestMoveIndex = i;
                    }
                }
            }
        }
    }
    struct piece p = pieces[bestMoveIndex];
    int newX, newY;
    int bestMoveValueForPiece = -1;
    for(int a=0; a<8; a++) {
        for(int b=0; b<8; b++) {
            if(isValidMove(board, p, a, b)) {
                int value = getValue(p.type);
                if(board[a][b] != ' ') {
                    value += getValue(board[a][b]);
                }
                if(value > bestMoveValueForPiece) {
                    bestMoveValueForPiece = value;
                    newX = a;
                    newY = b;
                }
            }
        }
    }
    printf("\nAI Player moves from %c%d to %c%d\n", p.y+'a', p.x+1, newY+'a', newX+1);
    board[newX][newY] = board[p.x][p.y];
    board[p.x][p.y] = ' ';
}

/** The main function */
int main() {
    char board[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    int gameOver = 0;
    char turn = 'W';
    while(!gameOver) {
        system("clear");
        printf("Chess Game\n");
        printBoard(board);
        if(turn == 'W') {
            printf("White Player's turn\n");
            char start[3], end[3];
            printf("Enter starting position (ex: e2) : ");
            scanf("%s", start);
            printf("Enter ending position (ex: e4) : ");
            scanf("%s", end);
            struct piece p = {
                .color = 'W',
                .type = toupper(board[start[1]-'0'-1][start[0]-'a']),
                .x = start[1]-'0'-1,
                .y = start[0]-'a'
            };
            if(isValidMove(board, p, end[1]-'0'-1, end[0]-'a')) {
                board[end[1]-'0'-1][end[0]-'a'] = board[p.x][p.y];
                board[p.x][p.y] = ' ';
                turn = 'B';
            } else {
                printf("Invalid move.\n");
                getchar();
            }
        } else {
            printf("AI Player's turn\n");
            getBestMove(board, 'B');
            turn = 'W';
            getchar();
        }
        /* Implement game over logic */
    }
    return 0;
}