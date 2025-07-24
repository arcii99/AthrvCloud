//FormAI DATASET v1.0 Category: Chess AI ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int eval(unsigned char *position) {
    // Function to evaluate the position. Returns positive score if white is winning, negative if black is winning.

    // To keep things simple, let's just count the number of pieces on each side and return the difference.
    int wcount = 0, bcount = 0;
    for (int i=0;i<64;i++) {
        switch (position[i]) {
            case 'P':
                wcount++;
                break;
            case 'p':
                bcount++;
                break;
            case 'N':
            case 'B':
            case 'R':
            case 'Q':
                wcount++;
                break;
            case 'n':
            case 'b':
            case 'r':
            case 'q':
                bcount++;
                break;
        }
    }
    return wcount-bcount;
}

int minimax(unsigned char *position, int depth, int alpha, int beta, int maximizingPlayer) {
    // Implementation of minimax algorithm with alpha-beta pruning. Returns the best score the maximizing player can achieve.

    if (depth == 0 || eval(position) >= 10000 || eval(position) <= -10000) {
        return eval(position);
    }

    int score;
    unsigned char new_position[64];

    if (maximizingPlayer) { // maximizing player (white)

        // Trying every move, and recursively getting best score.
        for (int i=0;i<64;i++) {
            if (position[i] >= 'A' && position[i] <= 'Z') { // white piece
                switch (position[i]) {
                    case 'P': // white pawn
                        // TODO: implement pawn moves
                        break;
                    case 'N': // white knight
                        // TODO: implement knight moves
                        break;
                    case 'B': // white bishop
                        // TODO: implement bishop moves
                        break;
                    case 'R': // white rook
                        // TODO: implement rook moves
                        break;
                    case 'Q': // white queen
                        // TODO: implement queen moves
                        break;
                }
            }
        }

        // Assume the first move is the best.
        score = -10000;
        int tmp_score;
        for (int i=0;i<64;i++) {
            if (new_position[i] != position[i]) { // this is the move that was made
                tmp_score = minimax(new_position, depth-1, alpha, beta, 0);
                score = score > tmp_score ? score : tmp_score;
                alpha = alpha > score ? alpha : score;
                if (beta <= alpha) {
                    break;
                }
            }
        }
    } else { // minimizing player (black)

        // Trying every move, and recursively getting best score.
        for (int i=0;i<64;i++) {
            if (position[i] >= 'a' && position[i] <= 'z') { // black piece
                switch (position[i]) {
                    case 'p': // black pawn
                        // TODO: implement pawn moves
                        break;
                    case 'n': // black knight
                        // TODO: implement knight moves
                        break;
                    case 'b': // black bishop
                        // TODO: implement bishop moves
                        break;
                    case 'r': // black rook
                        // TODO: implement rook moves
                        break;
                    case 'q': // black queen
                        // TODO: implement queen moves
                        break;
                }
            }
        }

        // Assume the first move is the best.
        score = 10000;
        int tmp_score;
        for (int i=0;i<64;i++) {
            if (new_position[i] != position[i]) { // this is the move that was made
                tmp_score = minimax(new_position, depth-1, alpha, beta, 1);
                score = score < tmp_score ? score : tmp_score;
                beta = beta < score ? beta : score;
                if (beta <= alpha) {
                    break;
                }
            }
        }
    }

    return score;
}

int main() {
    unsigned char position[64];
    // Initialize position with starting position.

    srand(time(NULL)); // seed the random number generator

    while (1) {
        // White's turn
        int best_score = -10000;
        unsigned char best_move[64];
        unsigned char new_position[64];
        for (int i=0;i<64;i++) {
            if (position[i] >= 'A' && position[i] <= 'Z') { // white piece
                // Trying every move, and getting the best score.
                switch (position[i]) {
                    case 'P': // white pawn
                        // TODO: implement pawn moves
                        break;
                    case 'N': // white knight
                        // TODO: implement knight moves
                        break;
                    case 'B': // white bishop
                        // TODO: implement bishop moves
                        break;
                    case 'R': // white rook
                        // TODO: implement rook moves
                        break;
                    case 'Q': // white queen
                        // TODO: implement queen moves
                        break;
                }
            }
        }
        // Applying the best move found.
        for (int i=0;i<64;i++) {
            position[i] = new_position[i];
        }

        // Black's turn
        best_score = 10000;
        for (int depth=1;depth<4;depth++) { // trying every move up to depth 3, and getting the best score.
            unsigned char tmp_position[64];
            for (int i=0;i<64;i++) {
                tmp_position[i] = position[i];
            }
            unsigned char tmp_move[64];
            for (int i=0;i<64;i++) {
                if (tmp_position[i] >= 'a' && tmp_position[i] <= 'z') { // black piece
                    switch (tmp_position[i]) {
                        case 'p': // black pawn
                            // TODO: implement pawn moves
                            break;
                        case 'n': // black knight
                            // TODO: implement knight moves
                            break;
                        case 'b': // black bishop
                            // TODO: implement bishop moves
                            break;
                        case 'r': // black rook
                            // TODO: implement rook moves
                            break;
                        case 'q': // black queen
                            // TODO: implement queen moves
                            break;
                    }
                }
            }
            // Applying the best move found.
            for (int i=0;i<64;i++) {
                tmp_position[i] = tmp_move[i];
            }
            int tmp_score = minimax(tmp_position, depth, -10000, 10000, 1);
            if (tmp_score < best_score) {
                best_score = tmp_score;
                for (int i=0;i<64;i++) {
                    best_move[i] = tmp_move[i];
                }
            }
        }
        // Applying the best move found.
        for (int i=0;i<64;i++) {
            position[i] = best_move[i];
        }

        // TODO: check for checkmate/stalemate/draw

        // Printing the current position.
        for (int i=0;i<8;i++) {
            for (int j=0;j<8;j++) {
                printf("%c", position[i*8+j]);
            }
            printf("\n");
        }
    }
    return 0;
}