//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

char board[3][3]; // 3x3 Tic Tac Toe board
int moves = 0; // Number of moves played so far
char player = 'x'; // Player starts as 'x'

void print_board() {
    printf("\n");
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner() { // Return 1 if 'x' wins, -1 if 'o' wins, 0 if no winner yet
    for(int i=0; i<3; i++) { // Check rows
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if(board[i][0] == 'x') return 1;
            else if(board[i][0] == 'o') return -1;
        }
    }

    for(int j=0; j<3; j++) { // Check columns
        if(board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if(board[0][j] == 'x') return 1;
            else if(board[0][j] == 'o') return -1;
        }
    }

    // Check diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if(board[0][0] == 'x') return 1;
        else if(board[0][0] == 'o') return -1;
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if(board[0][2] == 'x') return 1;
        else if(board[0][2] == 'o') return -1;
    }

    return 0; // No winner yet
}

int evaluate(char board[3][3]) { // Evaluate board for current player
    int winner = check_winner();
    if(winner == 1) return 10; // If 'x' wins, return high score
    if(winner == -1) return -10; // If 'o' wins, return low score
    return 0; // If no winner yet, return neutral score
}

int minimax(char board[3][3], int depth, int maximizing_player) {
    int score = evaluate(board);

    if(score == 10) return score - depth; // Maximizer wins
    if(score == -10) return score + depth; // Minimizer wins
    if(moves == 9) return 0; // Draw

    if(maximizing_player) { // Maximizing player ('x')
        int max_score = -1000;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = player;
                    moves++;
                    int curr_score = minimax(board, depth+1, 0); // Minimizer's turn
                    board[i][j] = ' '; // Undo move
                    moves--;
                    if(curr_score > max_score) max_score = curr_score;
                }
            }
        }
        return max_score;

    } else { // Minimizing player ('o')
        int min_score = 1000;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = 'o';
                    moves++;
                    int curr_score = minimax(board, depth+1, 1); // Maximizer's turn
                    board[i][j] = ' '; // Undo move
                    moves--;
                    if(curr_score < min_score) min_score = curr_score;
                }
            }
        }
        return min_score;
    }
}

void ai_move() { // Let AI player ('o') make a move
    int best_score = -1000;
    int best_move_i, best_move_j;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                board[i][j] = 'o';
                moves++;
                int score = minimax(board, 0, 1); // Maximizing player ('x')'s turn
                board[i][j] = ' '; // Undo move
                moves--;
                if(score > best_score) {
                    best_score = score;
                    best_move_i = i;
                    best_move_j = j;
                }
            }
        }
    }
    board[best_move_i][best_move_j] = 'o';
    player = 'x'; // Switch back to human player
}

int main() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
    while(moves < 9) {
        if(player == 'x') { // Human player's turn
            int move_i, move_j;
            printf("Enter your move (row column): ");
            scanf("%d %d", &move_i, &move_j);
            if(board[move_i][move_j] == ' ') {
                board[move_i][move_j] = 'x';
                player = 'o'; // Switch to AI player
            } else {
                printf("Invalid move. Try again.\n");
            }
        } else { // AI player's turn
            ai_move();
            player = 'x'; // Switch back to human player
        }
        print_board();
        int winner = check_winner();
        if(winner == 1) {
            printf("Congratulations, you win!\n");
            break;
        } else if(winner == -1) {
            printf("Sorry, you lose.\n");
            break;
        } else if(moves == 9) {
            printf("It's a tie.\n");
            break;
        }
    }
    return 0;
}