//FormAI DATASET v1.0 Category: Chess AI ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

// Initialize board with starting position
void init_board() {
    char start_pieces[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    for (int rank = 0; rank < BOARD_SIZE; rank++) {
        for (int file = 0; file < BOARD_SIZE; file++) {
            if (rank == 0) {
                board[rank][file] = start_pieces[file];
            } else if (rank == 1) {
                board[rank][file] = 'P';
            } else if (rank == 6) {
                board[rank][file] = 'p';
            } else if (rank == 7) {
                board[rank][file] = start_pieces[file] + 32;
            } else {
                board[rank][file] = ' ';
            }
        }
    }
}

// Print board
void print_board() {
    printf("  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int rank = 0; rank < BOARD_SIZE; rank++) {
        printf("%d|", BOARD_SIZE - rank);
        for (int file = 0; file < BOARD_SIZE; file++) {
            char piece = board[rank][file];
            printf("%c|", piece);
        }
        printf("%d\n", BOARD_SIZE - rank);
        printf(" +----------------+\n");
    }
    printf("  a b c d e f g h\n");
}

// Check if move is valid
bool is_valid_move(int rank, int file, int new_rank, int new_file) {
    char piece = board[rank][file];
    char new_piece = board[new_rank][new_file];
    
    if (new_rank < 0 || new_rank >= BOARD_SIZE || new_file < 0 || new_file >= BOARD_SIZE) {
        return false;
    }
    
    if (new_piece >= 'a' && new_piece <= 'z' && piece >= 'a' && piece <= 'z') {
        return false; // Same color pieces cannot capture each other
    } else if (new_piece >= 'A' && new_piece <= 'Z' && piece >= 'A' && piece <= 'Z') {
        return false; // Same color pieces cannot capture each other
    }
    
    if (piece == 'P' || piece == 'p') {
        // Moving forward
        if (new_file == file && new_piece == ' ') {
            if (piece == 'P' && new_rank == rank - 1) {
                return true;
            } else if (piece == 'p' && new_rank == rank + 1) {
                return true;
            }
            if (piece == 'P' && new_rank == rank - 2 && rank == 6) {
                return true;
            } else if (piece == 'p' && new_rank == rank + 2 && rank == 1) {
                return true;
            }
        }
        // Capturing
        else if ((new_rank == rank - 1 && new_file == file - 1 && new_piece >= 'A' && new_piece <= 'Z' && piece == 'P') || 
                (new_rank == rank + 1 && new_file == file - 1 && new_piece >= 'a' && new_piece <= 'z' && piece == 'p') ||
                (new_rank == rank - 1 && new_file == file + 1 && new_piece >= 'A' && new_piece <= 'Z' && piece == 'P') || 
                (new_rank == rank + 1 && new_file == file + 1 && new_piece >= 'a' && new_piece <= 'z' && piece == 'p')) {
            return true;
        }
    }
    
    if (piece == 'R' || piece == 'r') {
        // Moving horizontally or vertically
        if ((new_rank == rank && new_file != file) || 
                (new_rank != rank && new_file == file)) {
            if (new_rank > rank) {
                for (int i = rank + 1; i < new_rank; i++) {
                    if (board[i][file] != ' ') {
                        return false;
                    }
                }
            } else if (new_rank < rank) {
                for (int i = rank - 1; i > new_rank; i--) {
                    if (board[i][file] != ' ') {
                        return false;
                    }
                }
            } else if (new_file > file) {
                for (int i = file + 1; i < new_file; i++) {
                    if (board[rank][i] != ' ') {
                        return false;
                    }
                }
            } else if (new_file < file) {
                for (int i = file - 1; i > new_file; i--) {
                    if (board[rank][i] != ' ') {
                        return false;
                    }
                }
            }
            return true;
        }
    }
    
    if (piece == 'N' || piece == 'n') {
        // Moving to L-shaped location
        if ((new_rank == rank - 2 && new_file == file - 1) || 
                (new_rank == rank - 1 && new_file == file - 2) || 
                (new_rank == rank + 1 && new_file == file - 2) || 
                (new_rank == rank + 2 && new_file == file - 1) ||
                (new_rank == rank + 2 && new_file == file + 1) || 
                (new_rank == rank + 1 && new_file == file + 2) || 
                (new_rank == rank - 1 && new_file == file + 2) || 
                (new_rank == rank - 2 && new_file == file + 1)) {
            return true;
        }
    }
    
    if (piece == 'B' || piece == 'b') {
        // Moving diagonally
        if (abs(new_rank - rank) == abs(new_file - file)) {
            int rstep = (new_rank > rank) ? 1 : -1;
            int fstep = (new_file > file) ? 1 : -1;
            int r = rank + rstep;
            int f = file + fstep;
            while(r != new_rank && f != new_file) {
                if (board[r][f] != ' ') {
                    return false;
                }
                r += rstep;
                f += fstep;
            }
            return true;
        }
    }
    
    if (piece == 'Q' || piece == 'q') {
        // Moving horizontally, vertically, or diagonally
        if ((new_rank == rank && new_file != file) || 
                (new_rank != rank && new_file == file) ||
                abs(new_rank - rank) == abs(new_file - file)) {
            if (new_rank != rank && new_file != file) {
                int rstep = (new_rank > rank) ? 1 : -1;
                int fstep = (new_file > file) ? 1 : -1;
                int r = rank + rstep;
                int f = file + fstep;
                while(r != new_rank && f != new_file) {
                    if (board[r][f] != ' ') {
                        return false;
                    }
                    r += rstep;
                    f += fstep;
                }
            } else if (new_rank > rank) {
                for (int i = rank + 1; i < new_rank; i++) {
                    if (board[i][file] != ' ') {
                        return false;
                    }
                }
            } else if (new_rank < rank) {
                for (int i = rank - 1; i > new_rank; i--) {
                    if (board[i][file] != ' ') {
                        return false;
                    }
                }
            } else if (new_file > file) {
                for (int i = file + 1; i < new_file; i++) {
                    if (board[rank][i] != ' ') {
                        return false;
                    }
                }
            } else if (new_file < file) {
                for (int i = file - 1; i > new_file; i--) {
                    if (board[rank][i] != ' ') {
                        return false;
                    }
                }
            }       
            return true;
        }
    }
    
    if (piece == 'K' || piece == 'k') {
        // Moving one square in any direction
        int dr = abs(new_rank - rank);
        int df = abs(new_file - file);
        if ((dr == 0 && df == 1) || 
                (dr == 1 && df == 0) ||
                (dr == 1 && df == 1)) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

// Move piece
bool move_piece(int rank, int file, int new_rank, int new_file) {
    if (!is_valid_move(rank, file, new_rank, new_file)) {
        return false;
    }
    
    char piece = board[rank][file];
    board[rank][file] = ' ';
    board[new_rank][new_file] = piece;
    return true;
}

int main() {
    init_board();
    print_board();
    
    char input[256];
    while (true) {
        printf("Enter move: ");
        fgets(input, 256, stdin);
        char* rank_file = strtok(input, " \n");
        int file = rank_file[0] - 'a';
        int rank = BOARD_SIZE - (rank_file[1] - '0');
        rank_file = strtok(NULL, " \n");
        int new_file = rank_file[0] - 'a';
        int new_rank = BOARD_SIZE - (rank_file[1] - '0');
        if (move_piece(rank, file, new_rank, new_file)) {
            print_board();
        } else {
            printf("Invalid move\n");
        }
    }
    return 0;
}