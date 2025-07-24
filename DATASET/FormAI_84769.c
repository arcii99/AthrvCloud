//FormAI DATASET v1.0 Category: Chess AI ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 4

int scores[6] = {0, 1, 3, 3, 5, 9}; //scores for each type of chess piece
int level = 0; //current level depth for minimax algorithm

//structure for chess piece
typedef struct {
    int row;
    int col;
    char type;
    bool team; //true for white, false for black
} ChessPiece;

//structure for chess board
typedef struct {
    ChessPiece pieces[BOARD_SIZE][BOARD_SIZE];
    bool current_team; //true for white, false for black
    int white_score; //total score for white team
    int black_score; //total score for black team
} ChessBoard;

//function to print the current chess board
void print_board(const ChessBoard* board) {
    printf("\n   A B C D E F G H\n");
    printf("  -----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d| ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->pieces[i][j].type == ' ') printf("- ");
            else printf("%c ", board->pieces[i][j].type);
        }
        printf("|%d\n", i+1);
    }
    printf("  -----------------\n");
    printf("   A B C D E F G H\n");
}

//function to check if a move is valid
bool valid_move(const ChessBoard* board, int start_row, int start_col, int end_row, int end_col) {
    //check if move is within the board
    if (start_row < 0 || start_row >= BOARD_SIZE || start_col < 0 || start_col >= BOARD_SIZE ||
        end_row < 0 || end_row >= BOARD_SIZE || end_col < 0 || end_col >= BOARD_SIZE) return false;
    
    //check if start and end positions are different
    if (start_row == end_row && start_col == end_col) return false;

    //check if start position has a piece belonging to the current team
    if (board->pieces[start_row][start_col].type == ' ' || board->pieces[start_row][start_col].team != board->current_team) return false;
    
    //check if end position has a piece belonging to the opposite team
    if (board->pieces[end_row][end_col].team == board->current_team) return false;

    int row_diff = end_row - start_row;
    int col_diff = end_col - start_col;
    char type = board->pieces[start_row][start_col].type;

    //check if move is valid based on the type of piece
    switch (type) {
        case 'P': //pawn
            if (col_diff == 0) { //moving forward
                if (row_diff == 1 && board->pieces[end_row][end_col].type == ' ') return true; //moving one square forward
                else if (row_diff == 2 && start_row == 1 && board->pieces[2][start_col].type == ' ' && board->pieces[3][start_col].type == ' ') return true; //moving two squares forward from starting position
            }
            else if (abs(col_diff) == 1 && row_diff == 1 && board->pieces[end_row][end_col].type != ' ') return true; //attacking a piece
            break;
        case 'R': //rook
            if (row_diff == 0) { //moving left or right
                int dir = col_diff > 0 ? 1 : -1;
                for (int i = start_col + dir; i != end_col; i += dir) if (board->pieces[start_row][i].type != ' ') return false; //check if any pieces in the way
                return true;
            }
            else if (col_diff == 0) { //moving up or down
                int dir = row_diff > 0 ? 1 : -1;
                for (int i = start_row + dir; i != end_row; i += dir) if (board->pieces[i][start_col].type != ' ') return false; //check if any pieces in the way
                return true;
            }
            break;
        case 'N': //knight
            if ((abs(row_diff) == 1 && abs(col_diff) == 2) || (abs(row_diff) == 2 && abs(col_diff) == 1)) return true;
            break;
        case 'B': //bishop
            if (abs(row_diff) == abs(col_diff)) {
                int row_dir = row_diff > 0 ? 1 : -1;
                int col_dir = col_diff > 0 ? 1 : -1;
                int i = start_row + row_dir;
                int j = start_col + col_dir;
                while (i != end_row && j != end_col) {
                    if (board->pieces[i][j].type != ' ') return false; //check if any pieces in the way
                    i += row_dir;
                    j += col_dir;
                }
                return true;
            }
            break;
        case 'Q': //queen
            if (row_diff == 0) { //moving left or right
                int dir = col_diff > 0 ? 1 : -1;
                for (int i = start_col + dir; i != end_col; i += dir) if (board->pieces[start_row][i].type != ' ') return false; //check if any pieces in the way
                return true;
            }
            else if (col_diff == 0) { //moving up or down
                int dir = row_diff > 0 ? 1 : -1;
                for (int i = start_row + dir; i != end_row; i += dir) if (board->pieces[i][start_col].type != ' ') return false; //check if any pieces in the way
                return true;
            }
            else if (abs(row_diff) == abs(col_diff)) {
                int row_dir = row_diff > 0 ? 1 : -1;
                int col_dir = col_diff > 0 ? 1 : -1;
                int i = start_row + row_dir;
                int j = start_col + col_dir;
                while (i != end_row && j != end_col) {
                    if (board->pieces[i][j].type != ' ') return false; //check if any pieces in the way
                    i += row_dir;
                    j += col_dir;
                }
                return true;
            }
            break;
        case 'K': //king
            if (abs(row_diff) <= 1 && abs(col_diff) <= 1) return true;
            break;
        default:
            return false;
    }
    return false;
}

//function to execute a move and update the board
ChessBoard make_move(const ChessBoard* board, int start_row, int start_col, int end_row, int end_col) {
    ChessBoard new_board = *board;
    char type = new_board.pieces[start_row][start_col].type;
    bool team = new_board.current_team;
    
    //add score for capturing a piece
    if (new_board.pieces[end_row][end_col].type != ' ') {
        int score = scores[new_board.pieces[end_row][end_col].type - 'P'];
        if (new_board.pieces[end_row][end_col].team) new_board.white_score -= score;
        else new_board.black_score -= score;
    }

    //execute move
    new_board.pieces[end_row][end_col] = new_board.pieces[start_row][start_col];
    new_board.pieces[start_row][start_col] = (ChessPiece) {0, 0, ' ', false};
    new_board.current_team = !new_board.current_team;

    //update score for moving a pawn to the last row
    if (type == 'P' && ((team && end_row == BOARD_SIZE-1) || (!team && end_row == 0))) {
        new_board.current_team = team;
        if (team) new_board.white_score += scores['Q' - 'P']; //promote to a queen
        else new_board.black_score += scores['Q' - 'P'];
        new_board.pieces[end_row][end_col].type = 'Q';
    }

    return new_board;
}

//function to get all possible valid moves for a given team on the current board
int get_all_moves(const ChessBoard* board, bool team, ChessBoard moves[200]) {
    int num_moves = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->pieces[i][j].type != ' ' && board->pieces[i][j].team == team) {
                for (int k = 0; k < BOARD_SIZE; k++) {
                    for (int l = 0; l < BOARD_SIZE; l++) {
                        if (valid_move(board, i, j, k, l)) {
                            ChessBoard new_board = make_move(board, i, j, k, l);
                            moves[num_moves++] = new_board;
                        }
                    }
                }
            }
        }
    }
    return num_moves;
}

//function to evaluate the score of a given board for the current team
int evaluate_board(const ChessBoard* board) {
    if (board->current_team) return board->white_score - board->black_score;
    else return board->black_score - board->white_score;
}

//function to recursively apply minimax algorithm to determine the best move for the current team
int minimax(const ChessBoard* board, int depth, bool maximizing_team, int alpha, int beta) {
    if (depth == 0) return evaluate_board(board);

    ChessBoard moves[200];
    int num_moves = get_all_moves(board, maximizing_team, moves);
    level += 1;

    if (maximizing_team) {
        int max_score = -99999;
        for (int i = 0; i < num_moves; i++) {
            int score = minimax(&moves[i], depth-1, false, alpha, beta);
            if (score > max_score) max_score = score;
            if (score > alpha) alpha = score;
            if (beta <= alpha) break; //pruning
        }
        level -= 1;
        return max_score;
    }
    else {
        int min_score = 99999;
        for (int i = 0; i < num_moves; i++) {
            int score = minimax(&moves[i], depth-1, true, alpha, beta);
            if (score < min_score) min_score = score;
            if (score < beta) beta = score;
            if (beta <= alpha) break; //pruning
        }
        level -= 1;
        return min_score;
    }
}

//function to get the best move for the current team using minimax algorithm with alpha-beta pruning
ChessBoard get_best_move(const ChessBoard* board) {
    ChessBoard best_move = *board;
    bool team = board->current_team;
    int max_score = -99999;
    int alpha = -99999;
    int beta = 99999;

    //get all valid moves for the current team
    ChessBoard moves[200];
    int num_moves = get_all_moves(board, team, moves);

    //apply minimax to find the best move
    for (int i = 0; i < num_moves; i++) {
        int score = minimax(&moves[i], MAX_DEPTH, false, alpha, beta); //minimax with alpha-beta pruning
        if (score > max_score) {
            max_score = score;
            best_move = moves[i];
        }
        if (score > alpha) alpha = score;
    }

    return best_move;
}

int main() {
    //initialize chess board
    ChessBoard board = {
        .pieces = {
            {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
            {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
            {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
            {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
        },
        .current_team = true,
        .white_score = 39,
        .black_score = 39
    };

    printf("Initial Board:\n");
    print_board(&board);

    //play the game
    int num_moves = 0;
    while (true) {
        if (board.current_team) {
            printf("WHITE's MOVE\n");
            if (num_moves > 0) board = get_best_move(&board);
            else board = make_move(&board, 6, 4, 4, 4); //initial move for white
        }
        else {
            printf("BLACK's MOVE\n");
            int start_row, start_col, end_row, end_col;
            printf("Enter start position (ex: 'a1'): ");
            scanf("%c%d", &start_col, &start_row);
            start_col -= 'a';
            start_row--;
            printf("Enter end position (ex: 'a1'): ");
            scanf("%c%d", &end_col, &end_row);
            end_col -= 'a';
            end_row--;
            if (!valid_move(&board, start_row, start_col, end_row, end_col)) {
                printf("Invalid move! Try again.\n");
                continue;
            }
            board = make_move(&board, start_row, start_col, end_row, end_col);
        }
        print_board(&board);
        num_moves++;

        //check for winner or draw
        if (board.white_score <= 0) {
            printf("BLACK WINS!\n");
            break;
        }
        else if (board.black_score <= 0) {
            printf("WHITE WINS!\n");
            break;
        }
        else if (num_moves == 50) {
            printf("DRAW!\n");
            break;
        }
    }

    return 0;
}