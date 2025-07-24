//FormAI DATASET v1.0 Category: Checkers Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

struct position {
    int row;
    int col;
};

struct move {
    struct position from;
    struct position to;
};

void print_board(int board[SIZE][SIZE]) {
    printf("---------------------------------\n");
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            if (board[i][j] == 0) {
                printf("|   ");
            } else {
                printf("| %d ", board[i][j]);
            }
        }
        printf("|\n---------------------------------\n");
    }
}

int is_valid_move(int board[SIZE][SIZE], int player, struct move m) {
    int i, j;
    
    if (m.from.row < 0 || m.from.row >= SIZE || m.from.col < 0 || m.from.col >= SIZE ||
        m.to.row < 0 || m.to.row >= SIZE || m.to.col < 0 || m.to.col >= SIZE) {
        return 0;
    }
    
    if (board[m.to.row][m.to.col] != 0 || (m.to.row + m.to.col) % 2 == 0) {
        return 0;
    }
    
    if (player == 1) {
        if (board[m.from.row][m.from.col] == 1) {
            if (m.to.row > m.from.row) {
                return 0;
            }
            
            if (m.from.row - m.to.row == 2 && abs(m.from.col - m.to.col) == 2) {
                i = m.from.row - 1;
                j = m.from.col + (m.to.col - m.from.col) / 2;
                if (board[i][j] == 2 || board[i][j] == 4) {
                    return 1;
                }
                return 0;
            }
            
            if (m.from.row - m.to.row == 1 && abs(m.from.col - m.to.col) == 1) {
                return 1;
            }
            
            return 0;
        }
        
        if (board[m.from.row][m.from.col] == 2) {
            if (m.to.row > m.from.row) {
                return 0;
            }
            
            if (abs(m.from.row - m.to.row) == 2 && abs(m.from.col - m.to.col) == 2) {
                i = m.from.row - 1;
                j = m.from.col + (m.to.col - m.from.col) / 2;
                if (board[i][j] == 2 || board[i][j] == 4) {
                    return 1;
                }
                return 0;
            }
            
            if (abs(m.from.row - m.to.row) == 1 && abs(m.from.col - m.to.col) == 1) {
                return 1;
            }
            
            return 0;
        }
        
        if (board[m.from.row][m.from.col] == 3) {
            if (abs(m.from.row - m.to.row) != abs(m.from.col - m.to.col)) {
                return 0;
            }
            
            i = m.from.row > m.to.row ? m.to.row + 1 : m.from.row + 1;
            j = m.from.col > m.to.col ? m.to.col + 1 : m.from.col + 1;
            
            while (i < m.to.row) {
                if (board[i][j] != 0) {
                    return 0;
                }
                i++;
                j++;
            }
            
            return 1;
        }
        
        if (board[m.from.row][m.from.col] == 4) {
            if (abs(m.from.row - m.to.row) != abs(m.from.col - m.to.col)) {
                return 0;
            }
            
            i = m.from.row > m.to.row ? m.to.row + 1 : m.from.row + 1;
            j = m.from.col > m.to.col ? m.to.col + 1 : m.from.col + 1;
            
            while (i < m.to.row) {
                if (board[i][j] != 0) {
                    return 0;
                }
                i++;
                j++;
            }
            
            return 1;
        }
    }
    
    if (player == 2) {
        if (board[m.from.row][m.from.col] == 2) {
            if (m.to.row < m.from.row) {
                return 0;
            }
            
            if (abs(m.from.row - m.to.row) == 2 && abs(m.from.col - m.to.col) == 2) {
                i = m.from.row + 1;
                j = m.from.col + (m.to.col - m.from.col) / 2;
                if (board[i][j] == 1 || board[i][j] == 3) {
                    return 1;
                }
                return 0;
            }
            
            if (abs(m.from.row - m.to.row) == 1 && abs(m.from.col - m.to.col) == 1) {
                return 1;
            }
            
            return 0;
        }
        
        if (board[m.from.row][m.from.col] == 4) {
            if (m.to.row < m.from.row) {
                return 0;
            }
            
            if (abs(m.from.row - m.to.row) == 2 && abs(m.from.col - m.to.col) == 2) {
                i = m.from.row + 1;
                j = m.from.col + (m.to.col - m.from.col) / 2;
                if (board[i][j] == 1 || board[i][j] == 3) {
                    return 1;
                }
                return 0;
            }
            
            if (abs(m.from.row - m.to.row) == 1 && abs(m.from.col - m.to.col) == 1) {
                return 1;
            }
            
            return 0;
        }
        
        if (board[m.from.row][m.from.col] == 1) {
            if (abs(m.from.row - m.to.row) != abs(m.from.col - m.to.col)) {
                return 0;
            }
            
            i = m.from.row > m.to.row ? m.to.row + 1 : m.from.row + 1;
            j = m.from.col > m.to.col ? m.to.col + 1 : m.from.col + 1;
            
            while (i < m.to.row) {
                if (board[i][j] != 0) {
                    return 0;
                }
                i++;
                j++;
            }
            
            return 1;
        }
        
        if (board[m.from.row][m.from.col] == 3) {
            if (abs(m.from.row - m.to.row) != abs(m.from.col - m.to.col)) {
                return 0;
            }
            
            i = m.from.row > m.to.row ? m.to.row + 1 : m.from.row + 1;
            j = m.from.col > m.to.col ? m.to.col + 1 : m.from.col + 1;
            
            while (i < m.to.row) {
                if (board[i][j] != 0) {
                    return 0;
                }
                i++;
                j++;
            }
            
            return 1;
        }
    }
    
    return 0;
}

void move_piece(int board[SIZE][SIZE], struct move m) {
    int temp = board[m.from.row][m.from.col];
    board[m.from.row][m.from.col] = 0;
    board[m.to.row][m.to.col] = temp;
    
    if (abs(m.from.row - m.to.row) == 2 && abs(m.from.col - m.to.col) == 2) {
        int i = m.from.row > m.to.row ? m.to.row + 1 : m.from.row + 1;
        int j = m.from.col > m.to.col ? m.to.col + 1 : m.from.col + 1;
        board[i][j] = 0;
    }
    
    if ((m.to.row == 0 && board[m.to.row][m.to.col] == 2) ||
        (m.to.row == SIZE - 1 && board[m.to.row][m.to.col] == 1)) {
        board[m.to.row][m.to.col] += 2;
    }
}

int main() {
    int board[SIZE][SIZE] = {
        {0, 1, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {2, 0, 2, 0, 2, 0, 2, 0},
        {0, 2, 0, 2, 0, 2, 0, 2},
        {2, 0, 2, 0, 2, 0, 2, 0}
    };
    
    int player = 1;
    struct move m;
    char buffer[1024];
    
    while (1) {
        print_board(board);
        printf("Player %d's turn.\n", player);
        printf("Enter move (e.g. '3 2 4 3'): ");
        fgets(buffer, 1024, stdin);
        sscanf(buffer, "%d %d %d %d", &m.from.row, &m.from.col, &m.to.row, &m.to.col);
        m.from.row--;
        m.from.col--;
        m.to.row--;
        m.to.col--;
        
        if (is_valid_move(board, player, m)) {
            move_piece(board, m);
        } else {
            printf("Invalid move!\n");
            continue;
        }
        
        if (player == 1) {
            player = 2;
        } else {
            player = 1;
        }
    }
    
    return 0;
}