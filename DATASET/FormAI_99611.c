//FormAI DATASET v1.0 Category: Memory Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16
#define MAX_GUESSES 8
#define MAX_NUM 8

int board[BOARD_SIZE];
int num_guesses = 0;
int num_correct = 0;
int num_incorrect = 0;
int last_index = -1;
int guesses[MAX_GUESSES];

void generate_board() {
    int nums[MAX_NUM] = {0, 1, 2, 3, 4, 5, 6, 7};
    int i, j, temp;

    srand(time(NULL));

    for (i = 0; i < MAX_NUM; i++) {
        j = rand() % MAX_NUM;

        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    for (i = 0; i < BOARD_SIZE; i++) {
        board[i] = nums[i / 2];
    }
}

void print_board() {
    int i;

    for (i = 0; i < BOARD_SIZE; i++) {
        if (i % 4 == 0) {
            printf("\n");
        }

        if (board[i] == -1) {
            printf("__ ");
        } else {
            printf("%d ", board[i]);
        }
    }
}

void clear_screen() {
    system("cls||clear");
}

void pause() {
    printf("\n\nPress Enter to continue... ");
    getchar();
}

void game_over() {
    clear_screen();
    printf("\n\nGame over!\n");
    printf("Number of guesses: %d\n", num_guesses);
    printf("Number of correct: %d\n", num_correct);
    printf("Number of incorrect: %d\n", num_incorrect);
}

int check_guess(int guess1, int guess2) {
    num_guesses++;

    if (board[guess1] == board[guess2]) {
        board[guess1] = -1;
        board[guess2] = -1;
        num_correct++;

        return 1;
    } else {
        num_incorrect++;

        return 0;
    }
}

int is_game_over() {
    return num_correct == MAX_NUM;
}

int is_valid_guess(int guess) {
    int i;

    if (guess < 0 || guess > BOARD_SIZE - 1) {
        return 0;
    }

    for (i = 0; i <= last_index; i++) {
        if (guesses[i] == guess) {
            return 0;
        }
    }

    return 1;
}

void get_guesses(int *guess1, int *guess2) {
    do {
        printf("\nYour guess (1-%d): ", BOARD_SIZE);
        scanf("%d %d", guess1, guess2);
        fflush(stdin);
    } while (!is_valid_guess(*guess1 - 1) || !is_valid_guess(*guess2 - 1));
}

void add_guess(int guess) {
    last_index++;

    guesses[last_index] = guess;
}

int main() {
    int guess1, guess2;

    generate_board();

    while (!is_game_over()) {
        clear_screen();

        printf("Number of correct: %d\n", num_correct);
        printf("Number of incorrect: %d\n", num_incorrect);
        printf("Number of guesses: %d\n", num_guesses);
        printf("\n");

        print_board();

        get_guesses(&guess1, &guess2);

        add_guess(guess1 - 1);
        add_guess(guess2 - 1);

        if (!check_guess(guess1 - 1, guess2 - 1)) {
            pause();
            clear_screen();
            print_board();
            guesses[last_index - 1] = -1;
            guesses[last_index] = -1;
            last_index -= 2;
            pause();
        }
    }

    game_over();

    return 0;
}