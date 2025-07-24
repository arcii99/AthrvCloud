//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: romantic
#define PLAYER_X 'X'
#define PLAYER_O 'O'
#define EMPTY_SPACE ' '
#define DRAW 0
#define WIN 10
#define LOSE -10

char board[3][3]; // initialize the 3x3 board

// function to display the current state of the board
void display_board() {
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

// function to check if the game has ended
int game_over() {
    // check for horizontal wins
    for(int i=0; i<3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if(board[i][0] == PLAYER_X) 
                return WIN;
            else if(board[i][0] == PLAYER_O) 
                return LOSE;
        }
    }
    // check for vertical wins
    for(int i=0; i<3; i++) {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if(board[0][i] == PLAYER_X) 
                return WIN;
            else if(board[0][i] == PLAYER_O) 
                return LOSE;
        }
    }
    // check for diagonal wins
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if(board[0][0] == PLAYER_X)
            return WIN;
        else if(board[0][0] == PLAYER_O)
            return LOSE;
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if(board[0][2] == PLAYER_X) 
            return WIN;
        else if(board[0][2] == PLAYER_O) 
            return LOSE;
    }
    // check for tied game
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == EMPTY_SPACE)
                return DRAW;
        }
    }
    // game is not over yet
    return -1;
}

// minimax function to calculate the best move for the AI
int minimax(int depth, int isMax) {
    int score = game_over();
    if(score == WIN)
        return 10;
    if(score == LOSE)
        return -10;
    if(score == DRAW)
        return 0;
    if(isMax) {
        int bestVal = -1000;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == EMPTY_SPACE) {
                    board[i][j] = PLAYER_X;
                    bestVal = fmax(bestVal, minimax(depth+1, !isMax));
                    board[i][j] = EMPTY_SPACE;
                }
            }
        }
        return bestVal;
    } else {
        int bestVal = 1000;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == EMPTY_SPACE) {
                    board[i][j] = PLAYER_O;
                    bestVal = fmin(bestVal, minimax(depth+1, !isMax));
                    board[i][j] = EMPTY_SPACE;
                }
            }
        }
        return bestVal;
    }
}

// function to make the AI's move
void make_move() {
    int bestVal = -1000;
    int row = -1;
    int col = -1;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == EMPTY_SPACE) {
                board[i][j] = PLAYER_X;
                int moveVal = minimax(0, 0);
                board[i][j] = EMPTY_SPACE;
                if(moveVal > bestVal) {
                    row = i;
                    col = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    board[row][col] = PLAYER_X;
}

// main game loop
int main() {
    int player = 0;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = EMPTY_SPACE;
        }
    }
    while(game_over() == -1) {
        display_board();
        if(player == 0) {
            int row, col;
            printf("Player O's turn: Enter row (1-3): ");
            scanf("%d", &row);
            row--;
            printf("Enter column (1-3): ");
            scanf("%d", &col);
            col--;
            if(board[row][col] != EMPTY_SPACE) {
                printf("Invalid move. Please try again.\n");
            } else {
                board[row][col] = PLAYER_O;
                player = 1;
            }
        } else {
            printf("AI's turn:\n");
            make_move();
            player = 0;
        }
    }
    display_board();
    int result = game_over();
    if(result == DRAW) {
        printf("The game is a draw.\n");
    } else if(result == WIN) {
        printf("Congratulations! You win.\n");
    } else if(result == LOSE) {
        printf("Better luck next time. You lose.\n");
    }
    return 0;
}