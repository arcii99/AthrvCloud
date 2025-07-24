//FormAI DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int *array, int n) {
    srand(time(NULL));
    if (n > 1) {
        int i;
        for (i = 0; i < n - 1; i++) {
            int j = i + rand() / (RAND_MAX / (n - i) + 1);
            int temp = array[j];
            array[j] = array[i];
            array[i] = temp;
        }
    }
}

void print_game_board(int *game_board, int size) {
    printf("Current game board:\n");
    int i;
    for (i = 0; i < size; i++) {
        if (game_board[i] == -1) {
            printf("X ");
        }
        else {
            printf("%d ", game_board[i]);
        }
    }
    printf("\n");
}

void get_user_move(int *game_board, int size, int *position, int *value) {
    printf("Enter a position to flip (0-%d): ", size - 1);
    scanf("%d", position);

    // The selected position can either be already flipped or out of bounds
    while (game_board[*position] != -1 || *position < 0 || *position > size - 1) {
        printf("Invalid position, try again: ");
        scanf("%d", position);
    }

    printf("Enter the value at this position: ");
    scanf("%d", value);
}

int is_game_over(int *game_board, int size) {
    int i;
    // If there is any value -1 on the game board, it means the game is not over
    for (i = 0; i < size; i++) {
        if (game_board[i] == -1) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int size = 4;
    int game_board[size];
    int values[size / 2];
    int i, j, position, value1, value2;

    // Initialize the game board with -1
    for (i = 0; i < size; i++) {
        game_board[i] = -1;
    }

    // Initialize the values that will appear on the game board
    for (i = 0; i < size / 2; i++) {
        values[i] = i + 1;
    }

    // Shuffle the values randomly
    shuffle(values, size / 2);

    // Populate the game board with the shuffled values
    for (i = 0; i < size / 2; i++) {
        game_board[i] = values[i];
        game_board[size / 2 + i] = values[i];
    }

    // Shuffle the game board randomly
    shuffle(game_board, size);

    // Start the game loop
    while (!is_game_over(game_board, size)) {
        print_game_board(game_board, size);
        get_user_move(game_board, size, &position, &value1);
        game_board[position] = value1;
        print_game_board(game_board, size);
        get_user_move(game_board, size, &position, &value2);
        game_board[position] = value2;
        if (value1 != value2) {
            game_board[position] = -1;
        }
    }

    printf("Congratulations, you won the game!\n");
    return 0;
}