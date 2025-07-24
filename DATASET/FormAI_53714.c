//FormAI DATASET v1.0 Category: Memory Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16

void clear_screen() {
    system("cls"); // for windows
    //system("clear"); // for linux
}

void print_board(int board[], int size) {
    clear_screen();
    printf("Memory game board:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", board[i]);
        if ((i + 1) % 4 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

void shuffle(int arr[], int n) {
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int select_card(int board[], int size, int index, int *attempt) {
    int value = 0;
    if (board[index] > 0) {
        value = board[index];
        board[index] = -1 * board[index];
        (*attempt)++;
    } else {
        board[index] = -1 * board[index];
    }
    print_board(board, size);
    return value;
}

int main() {
    int board[BOARD_SIZE];
    int selected[2] = {-1, -1};
    int attempt = 0;
    int num_match = 0;

    // init board
    for (int i = 0; i < BOARD_SIZE / 2; i++) {
        board[i] = i;
        board[i + BOARD_SIZE / 2] = i;
    }
    shuffle(board, BOARD_SIZE);

    clear_screen();
    printf("Memory game:\n");
    print_board(board, BOARD_SIZE);

    while (num_match < BOARD_SIZE / 2) {
        printf("Select a card (0 - 15): ");
        int index;
        scanf("%d", &index);
        if (index < 0 || index >= BOARD_SIZE) {
            printf("Invalid input. Try again.\n");
            continue;
        }
        int value = select_card(board, BOARD_SIZE, index, &attempt);
        if (selected[0] == -1) {
            selected[0] = index;
        } else {
            selected[1] = index;
            if (board[selected[0]] == board[selected[1]]) {
                printf("Match!\n");
                num_match++;
            } else {
                printf("Not a match.\n");
                select_card(board, BOARD_SIZE, selected[0], &attempt);
                select_card(board, BOARD_SIZE, selected[1], &attempt);
            }
            selected[0] = -1; selected[1] = -1;
        }
    }

    printf("You won the game with %d attempts!\n", attempt);
    return 0;
}