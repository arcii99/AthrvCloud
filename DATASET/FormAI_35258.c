//FormAI DATASET v1.0 Category: Chess AI ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the board and pieces
char board[8][8] = {{'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
                    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}};

int ai_play();

int main() {
    srand((unsigned)time(NULL));
    int winner = 0;
    int turn_count = 0;
    while (winner == 0){
        printf("Turn: %d\n", turn_count);
        // Display the board
        for (int i = 0; i < 8; i++){
            for (int j = 0; j < 8; j++){
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }
        // Ask the user for their move
        char user_move[5];
        printf("Enter your move: ");
        scanf("%s", user_move);
        // Parse user's move and make it on the board
        int from_file = user_move[0] - 'a';
        int from_rank = 8 - (user_move[1] - '0');
        int to_file = user_move[2] - 'a';
        int to_rank = 8 - (user_move[3] - '0');
        board[to_rank][to_file] = board[from_rank][from_file];
        board[from_rank][from_file] = ' ';
        // Check if the user won
        if (board[to_rank][to_file] == 'k'){
            printf("Congratulations! You won!\n");
            winner = 1;
            break;
        }
        // Make the AI move
        ai_play();
        // Check if the AI won
        if (board[to_rank][to_file] == 'K'){
            printf("Sorry, you lost. Try again!\n");
            winner = -1;
            break;
        }
        turn_count++;
    }
    return 0;
}

int ai_play() {
    printf("AI is thinking...\n");
    // Pick a random move
    int from_rank = rand() % 8;
    int from_file = rand() % 8;
    int to_rank = rand() % 8;
    int to_file = rand() % 8;
    // Check if the move is valid, otherwise try again
    while (board[from_rank][from_file] == ' ' || from_rank == to_rank || from_file == to_file) {
        from_rank = rand() % 8;
        from_file = rand() % 8;
        to_rank = rand() % 8;
        to_file = rand() % 8;
    }
    // Make the AI move
    printf("AI moved: %c%d%c%d\n", from_file + 'a', 8 - from_rank, to_file + 'a', 8 - to_rank);
    board[to_rank][to_file] = board[from_rank][from_file];
    board[from_rank][from_file] = ' ';
    return 0;
}