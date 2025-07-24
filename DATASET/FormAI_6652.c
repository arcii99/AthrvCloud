//FormAI DATASET v1.0 Category: Chess AI ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

int PLAYER, WHITE=1, BLACK=-1;

int board[BOARD_SIZE][BOARD_SIZE] = 
{
    {-2,-3,-4,-5,-6,-4,-3,-2},
    {-1,-1,-1,-1,-1,-1,-1,-1},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1},
    {2,3,4,5,6,4,3,2}
};

int pawn[BOARD_SIZE][BOARD_SIZE] = 
{
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {1,1,1,1,1,1,1,1},
    {0,0,0,0,0,0,0,0}
};

void print_board() {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] < 0) {
                if (board[i][j] == -1) {
                    printf("\u265F ");
                } else if (board[i][j] == -2) {
                    printf("\u265C ");
                } else if (board[i][j] == -3) {
                    printf("\u265E ");
                } else if (board[i][j] == -4) {
                    printf("\u265D ");
                } else if (board[i][j] == -5) {
                    printf("\u265A ");
                } else if (board[i][j] == -6) {
                    printf("\u265B ");
                }
            } else if (board[i][j] > 0) {
                if (board[i][j] == 1) {
                    printf("\u2659 ");
                } else if (board[i][j] == 2) {
                    printf("\u2656 ");
                } else if (board[i][j] == 3) {
                    printf("\u2658 ");
                } else if (board[i][j] == 4) {
                    printf("\u2657 ");
                } else if (board[i][j] == 5) {
                    printf("\u2654 ");
                } else if (board[i][j] == 6) {
                    printf("\u2655 ");
                }
            } else {
                printf(". ");
            }
        }
        printf("%d\n", BOARD_SIZE - i);
    }
    printf("  A B C D E F G H\n");
}

void init_board() {
    print_board();
    PLAYER = WHITE;
}

int valid_move(int x1, int y1, int x2, int y2) {

    int i, j, piece, dx, dy, nx1, ny1, nx2, ny2, en_passant, capture;
    piece = board[x1][y1];
    dx = x2 - x1;
    dy = y2 - y1;
    if (dx*PLAYER <= 0) {
        return 0;
    }
    if (piece*PLAYER < 0) {
        return 0; 
    }

    if (piece == 1 && dx == -2*PLAYER) {
        if (x1 != 6 && x1 != 1) {
            return 0;
        }
        if (board[x2][y2] != 0) {
            return 0;
        }
        if (board[x1 - PLAYER][y1] != 0 || board[x1 - 2*PLAYER][y1] != 0) {
            return 0;
        }
        return 1;
    }

    if (piece == -1 && dx == 2*PLAYER) {
        if (x1 != 1 && x1 != 6) {
            return 0;
        }
        if (board[x2][y2] != 0) {
            return 0;
        }
        if (board[x1 + PLAYER][y1] != 0 || board[x1 + 2*PLAYER][y1] != 0) {
            return 0;
        }
        return 1;
    }

    if (piece == 1) { 
        if (dy == 0) {
            if (dx != -PLAYER && (x1 == 6 || board[x1 - 1][y1] != 0)) {
                return 0;
            }
            if (dx == -PLAYER && board[x2][y2] == 0) {
                return 1;
            }
            if (dx == -PLAYER - 1 || dx == -PLAYER + 1) {
                if (board[x2][y2]*PLAYER >= 0) {
                    return 0;
                }
                return 1;
            }
        }
        if (dy*PLAYER < 0 || dy > 1 || dy < -1) {
            return 0;
        }
        capture = board[x2][y2]*PLAYER < 0;
        if (dy == 1 && !capture) {
            return 0;
        }
        if (dy == -1 && capture) {
            return 0;
        }
        return 1;
    }

    if (piece == -1) {
        if (dy == 0) {
            if (dx != PLAYER && (x1 == 1 || board[x1 + 1][y1] != 0)) {
                return 0;
            }
            if (dx == PLAYER && board[x2][y2] == 0) {
                return 1;
            }
            if (dx == PLAYER - 1 || dx == PLAYER + 1) {
                if (board[x2][y2]*PLAYER >= 0) {
                    return 0;
                }
                return 1;
            }
        }
        if (dy*PLAYER < 0 || dy > 1 || dy < -1) {
            return 0;
        }
        capture = board[x2][y2]*PLAYER < 0;
        if (dy == 1 && !capture) {
            return 0;
        }
        if (dy == -1 && capture) {
            return 0;
        }
        return 1;
    }

    if (piece == 2 || piece == -2) { 
        if (dx != 0 && dy != 0) {
            return 0;
        }
        nx1 = nx2 = x1;
        ny1 = ny2 = y1;

        if (dx < 0) {
            en_passant = pawn[x2+1][y2] == -1;
            while (nx1 + dx < x2) {
                nx1 += dx;
                if (!en_passant && board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (dx > 0) {
            en_passant = pawn[x2-1][y2] == 1;
            while (nx1 + dx > x2) {
                nx1 += dx;
                if (!en_passant && board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (dy < 0) {
            en_passant = pawn[x2][y2+1] == -1;
            while (ny1 + dy < y2) {
                ny1 += dy;
                if (!en_passant && board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (dy > 0) {
            en_passant = pawn[x2][y2-1] == 1;
            while (ny1 + dy > y2) {
                ny1 += dy;
                if (!en_passant && board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (board[x2][y2]*PLAYER > 0) {
            return 0;
        }
        return 1;
    }

    if (piece == 3 || piece == -3) { 
        if (abs(dy) != abs(dx)) {
            return 0;
        }
        nx1 = nx2 = x1;
        ny1 = ny2 = y1;
        if (dx > 0 && dy > 0) {
            while (nx1 != x2) {
                nx1 += 1;
                ny1 += 1;
                if (nx1 != x2 && board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (dx > 0 && dy < 0) {
            while (nx1 != x2) {
                nx1 += 1;
                ny1 -= 1;
                if (nx1 != x2 && board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (dx < 0 && dy < 0) { 
            while (nx1 != x2) {
                nx1 -= 1;
                ny1 -= 1;        
                if (nx1 != x2 && board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (dx < 0 && dy > 0) { 
            while (nx1 != x2) {
                nx1 -= 1;
                ny1 += 1;
                if (nx1 != x2 && board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (board[x2][y2]*PLAYER > 0) {
            return 0;
        }
        return 1;
    }

    if (piece == 4 || piece == -4) { 
        if (dx != 0 && dy != 0) {
            return 0;
        }
        nx1 = nx2 = x1;
        ny1 = ny2 = y1;

        if (dx < 0) {
            en_passant = pawn[x2+1][y2] == -1;
            while (nx1 + dx < x2) {
                nx1 += dx;
                if (!en_passant && board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (dx > 0) {
            en_passant = pawn[x2-1][y2] == 1;
            while (nx1 + dx > x2) {
                nx1 += dx;
                if (!en_passant && board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (dy < 0) {
            en_passant = pawn[x2][y2+1] == -1;
            while (ny1 + dy < y2) {
                ny1 += dy;
                if (!en_passant && board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (dy > 0) {
            en_passant = pawn[x2][y2-1] == 1;
            while (ny1 + dy > y2) {
                ny1 += dy;
                if (!en_passant && board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (board[x2][y2]*PLAYER > 0) {
            return 0;
        }
        return 1;
    }

    if (piece == 5 || piece == -5) { 
        if (dx*dy != 0 || dx + dy == 0) {
            return 0;
        }
        nx1 = nx2 = x1;
        ny1 = ny2 = y1;
        if (dx > 0) {
            nx1 = BOARD_SIZE - 1;
            while (nx1 > x2) {
                nx1--;
                ny1--;
                if (board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (dx < 0) {
            nx1 = 0;
            while (nx1 < x2) {
                nx1++;
                ny1++;
                if (board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (dy > 0) {
            ny1 = BOARD_SIZE - 1;
            while (ny1 > y2) {
                nx1--;
                ny1--;
                if (board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (dy < 0) {
            ny1 = 0;
            while (ny1 < y2) {
                nx1++;
                ny1++;
                if (board[nx1][ny1] != 0) {
                    return 0;
                }
            }
        }
        if (board[x2][y2]*PLAYER > 0) {
            return 0;
        }
        return 1;
    }

    if (piece == 6 || piece == -6) { 
        if (dx > 2 || dx < -2 || dy > 2 || dy < -2) {
            return 0;
        }
        if ((dx + dy) % 2 == 0) {
            return 0;
        }
        nx1 = x1 + dx/2;
        ny1 = y1 + dy/2;

        if (board[nx1][ny1]*PLAYER > 0) {
            return 0;
        }
        if (board[x2][y2]*PLAYER > 0) {
            return 0;
        }
        return 1;
    }
    return 0;
}

int move_piece(char* move) {

    int x1, y1, x2, y2;
    x1 = BOARD_SIZE - (move[1] - '0');
    y1 = move[0] - 'A';
    x2 = BOARD_SIZE - (move[3] - '0');
    y2 = move[2] - 'A';

    if (!valid_move(x1, y1, x2, y2)) {
        return 0;
    }
    if (board[x2][y2] == -1 || board[x2][y2] == 1) {
        pawn[x2][y2] = 0;
    }

    board[x2][y2] = board[x1][y1];
    board[x1][y1] = 0;

    if (board[x2][y2] == 6 && y2 == 6 && y1 == 4) { 
        board[x2][y2+1] = board[x2][y2-2];
        board[x2][y2-2] = 0;
        pawn[x2][y2+1] = pawn[x2][y2-2] = 1;
    }
    if (board[x2][y2] == -6 && y2 == 2 && y1 == 4) { 
        board[x2][y2+1] = board[x2][y2-2];
        board[x2][y2-2] = 0;
        pawn[x2][y2+1] = pawn[x2][y2-2] = -1;
    }
    if (board[x2][y2] == 6 && x2 == 0) { 
        board[x2][y2] = 5;
    }
    if (board[x2][y2] == -6 && x2 == 7) { 
        board[x2][y2] = -5;
    }

    return 1;
}

int main() {

    init_board();
    char move[4];
    while (1) {
        printf("Enter move: ");
        scanf("%4s", move);
        if (strlen(move) == 2 && move[0] == 'q') {
            return 0;
        }
        if (!move_piece(move)) {
            printf("Invalid move, try again!\n");
        } else {
            print_board();
            PLAYER = -PLAYER;
        }
    }

    return 0;
}