//FormAI DATASET v1.0 Category: Chess AI ; Style: multiplayer
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Structure for Player information
struct Player {
   char name[15];
   int id;
   int score;
};

// Function to get player turn input
int get_player_input(int player_id, char board[][8]) {
    int row, column;
    printf("Player %d, enter your move row,column : ", player_id);
    scanf("%d,%d", &row, &column);
    if (board[row-1][column-1] != ' ') {
        printf("Invalid Move, try again.\n");
        return get_player_input(player_id, board);
    }
    return row * 10 + column;
}

// Function to make AI move
int get_computer_input(char board[][8]) {
    srand(time(0));
    int row = rand() % 8 + 1;
    int column = rand() % 8 + 1;
    if (board[row-1][column-1] != ' ') {
        return get_computer_input(board);
    }
    return row * 10 + column;
}

// Function to draw chess board
void draw_board(char board[][8]) {
    printf("   1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < 8; i++) {
        printf("%d |", i+1);
        for (int j = 0; j < 8; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check win condition
int check_win(char board[][8], int last_move, int player_id) {
    int row = last_move / 10 - 1;
    int column = last_move % 10 - 1;

    // checking for horizontal win
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (board[row][i] == player_id + '0') {
            count++;
        } else {
            count = 0;
        }
        if (count == 4) {
            return 1;
        }
    }

    // checking for vertical win
    count = 0;
    for (int i = 0; i < 8; i++) {
        if (board[i][column] == player_id + '0') {
            count++;
        } else {
            count = 0;
        }
        if (count == 4) {
            return 1;
        }
    }

    // checking for diagonal win
    count = 0;
    int i = row, j = column;
    while (i < 8 && j < 8 && board[i][j] == player_id + '0') {
        count++;
        i++;
        j++;
    }
    i = row - 1, j = column - 1;
    while (i >= 0 && j >= 0 && board[i][j] == player_id + '0') {
        count++;
        i--;
        j--;
    }
    if (count >= 4) {
        return 1;
    }

    // checking for anti-diagonal win
    count = 0;
    i = row, j = column;
    while (i < 8 && j >= 0 && board[i][j] == player_id + '0') {
        count++;
        i++;
        j--;
    }
    i = row - 1, j = column + 1;
    while (i >= 0 && j < 8 && board[i][j] == player_id + '0') {
        count++;
        i--;
        j++;
    }
    if (count >= 4) {
        return 1;
    }

    // no win condition found
    return 0;
}

// Function to start the game
void start_game() {
    // Initializing Players
    struct Player player1 = {"Player1", 1, 0};
    struct Player player2 = {"Player2", 2, 0};

    // Initializing game variables
    char board[8][8];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = ' ';
        }
    }
    int game_over = 0;
    int current_player = 1; // Player 1 plays the first move

    // Start Game
    printf("Starting Game...\n");
    while (!game_over) {
        draw_board(board);
        int last_move;
        if (current_player == 1) {
            last_move = get_player_input(current_player, board);
        } else {
            last_move = get_computer_input(board);
            printf("Computer makes move at %d,%d\n", last_move/10, last_move%10);
        }
        board[last_move/10-1][last_move%10-1] = current_player + '0';
        if (check_win(board, last_move, current_player)) {
            printf("Player %d has won the game!\n", current_player);
            if (current_player == 1) {
                player1.score++;
            } else {
                player2.score++;
            }
            draw_board(board);
            printf("Scoreboard\n");
            printf("Player1: %d  --- Player2: %d \n", player1.score, player2.score);
            printf("Do you want to play another game? (y/n) : ");
            char choice;
            scanf(" %c", &choice);
            if (choice == 'n') {
                game_over = 1;
                printf("Thanks for playing!\n");
            } else {
                game_over = 0;
                for (int i = 0; i < 8; i++) {
                    for (int j = 0; j < 8; j++) {
                        board[i][j] = ' ';
                    }
                }
            }
        } else {
            current_player = current_player == 1 ? 2 : 1;
        }
    }
}

// Main Function
int main() {
    start_game();
    return 0;
}