//FormAI DATASET v1.0 Category: Chess AI ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DEPTH 5

typedef struct {
    int x, y;
} move_t;

char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

int score_board() {
    int score = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char piece = board[i][j];
            int value = 0;
            switch(piece) {
                case 'P': value = 1; break;
                case 'N': value = 3; break;
                case 'B': value = 3; break;
                case 'R': value = 5; break;
                case 'Q': value = 9; break;
                case 'p': value = -1; break;
                case 'n': value = -3; break;
                case 'b': value = -3; break;
                case 'r': value = -5; break;
                case 'q': value = -9; break;
                default: value = 0; break;
            }
            score += value;
        }
    }
    return score;
}

bool is_valid_move(move_t move) {
    int from_x = move.x / 10;
    int from_y = move.x % 10;
    int to_x = move.y / 10;
    int to_y = move.y % 10;
    char piece = board[from_x][from_y];
    char dest = board[to_x][to_y];
    
    if (from_x == to_x && from_y == to_y) return false;
    if (piece == ' ') return false;
    
    int dx = to_x - from_x;
    int dy = to_y - from_y;
    int adx = abs(dx);
    int ady = abs(dy);
    
    switch (piece) {
        case 'P': 
            if (dy == 0 && dest == ' ') {
                if (dx == 1) return true;
                if (dx == 2 && from_x == 1) return true;
            } else if (adx == 1 && ady == 1 && dest != ' ') {
                return true;
            }
            break;
        case 'p': 
            if (dy == 0 && dest == ' ') {
                if (dx == -1) return true;
                if (dx == -2 && from_x == 6) return true;
            } else if (adx == 1 && ady == 1 && dest != ' ') {
                return true;
            }
            break;
        case 'N': 
        case 'n':
            if ((adx == 1 && ady == 2) || (adx == 2 && ady == 1)) {
                if (dest == ' ' || (isupper(piece) != isupper(dest))) {
                    return true;
                }
            }
            break;
        case 'B': 
        case 'b':
            if (adx == ady) {
                int step_x = dx / adx;
                int step_y = dy / ady;
                for (int i = 1; i < adx; i++) {
                    int x = from_x + i * step_x;
                    int y = from_y + i * step_y;
                    if (board[x][y] != ' ') return false;
                }
                if (dest == ' ' || (isupper(piece) != isupper(dest))) {
                    return true;
                }
            }
            break;
        case 'R': 
        case 'r':
            if (dx == 0 || dy == 0) {
                int step = (dx == 0 ? dy : dx) / abs(dx + dy);
                for (int i = 1; i < abs(dx + dy); i++) {
                    int x = from_x + i * step * (dx == 0 ? 0 : 1);
                    int y = from_y + i * step * (dy == 0 ? 0 : 1);
                    if (board[x][y] != ' ') return false;
                }
                if (dest == ' ' || (isupper(piece) != isupper(dest))) {
                    return true;
                }
            }
            break;
        case 'Q': 
        case 'q':
            if (adx == ady || dx == 0 || dy == 0) {
                int step_x = dx == 0 ? 0 : dx / abs(dx);
                int step_y = dy == 0 ? 0 : dy / abs(dy);
                for (int i = 1; i < (adx == ady ? adx : abs(dx + dy)); i++) {
                    int x = from_x + i * step_x * (adx == ady ? 1 : 0);
                    int y = from_y + i * step_y * (adx == ady ? 1 : 0);
                    if (board[x][y] != ' ') return false;
                }
                if (dest == ' ' || (isupper(piece) != isupper(dest))) {
                    return true;
                }
            }
            break;
        case 'K': 
        case 'k':
            if (adx <= 1 && ady <= 1) {
                if (dest == ' ' || (isupper(piece) != isupper(dest))) {
                    return true;
                }
            }
            break;
        default:
            return false;
    }
    return false;
}

int negamax(int depth, int alpha, int beta, int color) {
    if (depth == 0) {
        return color * score_board();
    }
    
    int max_score = -10000;
    for (int i = 0; i < 64; i++) {
        int x = i / 8;
        int y = i % 8;
        char piece = board[x][y];
        
        if ((isupper(piece) && color > 0) || (!isupper(piece) && color < 0)) {
            for (int j = 0; j < 64; j++) {
                move_t move = {i, j};
                
                if (!is_valid_move(move)) continue;
                
                char temp = board[x][y];
                board[x][y] = ' ';
                int dest_x = j / 8;
                int dest_y = j % 8;
                char dest_piece = board[dest_x][dest_y];
                board[dest_x][dest_y] = temp;
                
                int score = -negamax(depth - 1, -beta, -alpha, -color);
                if (score > max_score) {
                    max_score = score;
                }
                
                board[x][y] = temp;
                board[dest_x][dest_y] = dest_piece;
                
                if (max_score > alpha) {
                    alpha = max_score;
                }
                if (max_score >= beta) {
                    return max_score;
                }
            }
        }
    }
    return max_score;
}

move_t get_best_move() {
    int max_score = -10000;
    move_t best_move = {0};
    for (int i = 0; i < 64; i++) {
        int x = i / 8;
        int y = i % 8;
        char piece = board[x][y];
        
        if (isupper(piece)) {
            for (int j = 0; j < 64; j++) {
                move_t move = {i, j};
                
                if (!is_valid_move(move)) continue;
                
                char temp = board[x][y];
                board[x][y] = ' ';
                int dest_x = j / 8;
                int dest_y = j % 8;
                char dest_piece = board[dest_x][dest_y];
                board[dest_x][dest_y] = temp;
                
                int score = -negamax(MAX_DEPTH, -10000, 10000, -1);
                if (score > max_score) {
                    max_score = score;
                    best_move = move;
                }
                
                board[x][y] = temp;
                board[dest_x][dest_y] = dest_piece;
            }
        }
    }
    return best_move;
}

int main() {
    while (true) {
        move_t move = {0};
        scanf("%d %d", &move.x, &move.y);
        
        char temp = board[move.x / 10][move.x % 10];
        board[move.x / 10][move.x % 10] = ' ';
        board[move.y / 10][move.y % 10] = temp;
        
        move_t best_move = get_best_move();
        
        printf("%d %d %d %d\n", move.x / 10, move.x % 10, move.y / 10, move.y % 10);
        printf("%d %d %d %d\n", best_move.x / 10, best_move.x % 10, best_move.y / 10, best_move.y % 10);
    }
    return 0;
}