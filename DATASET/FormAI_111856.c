//FormAI DATASET v1.0 Category: Memory Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 4

void display_matrix(int matrix[DIM][DIM]) {
    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            if (matrix[i][j] == -1) {
                printf(" * ");
            } else {
                printf("%2d ", matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void fill_matrix(int matrix[DIM][DIM], int n_pairs) {
    int a, b, pairs_placed = 0;
    while (pairs_placed < n_pairs) {
        a = rand() % DIM;
        b = rand() % DIM;
        if (matrix[a][b] == -1) {
            matrix[a][b] = pairs_placed + 1;
            pairs_placed++;
        }
    }
}

int empty_spaces(int matrix[DIM][DIM]) {
    int count = 0;
    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            if (matrix[i][j] == -1) {
                count++;
            }
        }
    }
    return count;
}

void initialize_matrix(int matrix[DIM][DIM]) {
    for (int i=0; i<DIM; i++) {
        for (int j=0; j<DIM; j++) {
            matrix[i][j] = -1;
        }
    }
}

void play_game(int matrix[DIM][DIM]) {
    int score = 0, x1, y1, x2, y2, guess1, guess2;
    int n_pairs = (DIM * DIM) / 2;
    char again;
    initialize_matrix(matrix);
    fill_matrix(matrix, n_pairs);
    fill_matrix(matrix, n_pairs);
    do {
        system("cls");
        display_matrix(matrix);
        printf("Current score: %d\n", score);
        printf("Enter position of first card: ");
        scanf("%d %d", &x1, &y1);
        guess1 = matrix[x1][y1];
        matrix[x1][y1] = guess1 * 10;
        system("cls");
        display_matrix(matrix);
        printf("Enter position of second card: ");
        scanf("%d %d", &x2, &y2);
        guess2 = matrix[x2][y2];
        matrix[x2][y2] = guess2 * 10;
        system("cls");
        display_matrix(matrix);
        if (guess1 != guess2) {
            matrix[x1][y1] = -1;
            matrix[x2][y2] = -1;
        } else {
            score++;
        }
    } while (empty_spaces(matrix) > 0);
    printf("Game over! Final score: %d\n", score);
}

int main() {
    int matrix[DIM][DIM];
    srand(time(NULL));
    play_game(matrix);
    return 0;
}