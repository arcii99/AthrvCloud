//FormAI DATASET v1.0 Category: Memory Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16
#define NUM_PAIRS 8

void shuffle(int *array, int size);
void print_board(int *values, int *status);
void reset_board(int *values, int *status);

int main() {
    int values[NUM_PAIRS * 2];
    int status[NUM_PAIRS * 2];
    int current[2];
    int pairs_found = 0;

    srand(time(0));

    for (int i = 0; i < NUM_PAIRS * 2; i++) {
        values[i] = (i % NUM_PAIRS) + 1;
        status[i] = 0;
    }

    shuffle(values, NUM_PAIRS * 2);

    reset_board(values, status);
    print_board(values, status);

    while (pairs_found < NUM_PAIRS) {
        printf("Enter two coordinates separated by a space (ex: 2 3): ");
        scanf("%d %d", &current[0], &current[1]);

        current[0]--;
        current[1]--;

        if (status[current[0] * 4 + current[1]] == 0) {
            status[current[0] * 4 + current[1]] = 1;
            print_board(values, status);

            if (current[0] > 0 && status[(current[0]-1) * 4 + current[1]] == 1) {
                if (values[current[0] * 4 + current[1]] == values[(current[0]-1) * 4 + current[1]]) {
                    pairs_found++;
                    printf("Pair found!\n");
                } else {
                    printf("No pair found.\n");
                    status[current[0] * 4 + current[1]] = 0;
                    status[(current[0]-1) * 4 + current[1]] = 0;
                }
            }

            if (current[0] < 3 && status[(current[0]+1) * 4 + current[1]] == 1) {
                if (values[current[0] * 4 + current[1]] == values[(current[0]+1) * 4 + current[1]]) {
                    pairs_found++;
                    printf("Pair found!\n");
                } else {
                    printf("No pair found.\n");
                    status[current[0] * 4 + current[1]] = 0;
                    status[(current[0]+1) * 4 + current[1]] = 0;
                }
            }

            if (current[1] > 0 && status[current[0] * 4 + current[1]-1] == 1) {
                if (values[current[0] * 4 + current[1]] == values[current[0] * 4 + current[1]-1]) {
                    pairs_found++;
                    printf("Pair found!\n");
                } else {
                    printf("No pair found.\n");
                    status[current[0] * 4 + current[1]] = 0;
                    status[current[0] * 4 + current[1]-1] = 0;
                }
            }

            if (current[1] < 3 && status[current[0] * 4 + current[1]+1] == 1) {
                if (values[current[0] * 4 + current[1]] == values[current[0] * 4 + current[1]+1]) {
                    pairs_found++;
                    printf("Pair found!\n");
                } else {
                    printf("No pair found.\n");
                    status[current[0] * 4 + current[1]] = 0;
                    status[current[0] * 4 + current[1]+1] = 0;
                }
            }
        } else {
            printf("Already matched or out of bounds.\n");
        }
    }

    printf("Congratulations, you win!\n");

    return 0;
}

void shuffle(int *array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}

void print_board(int *values, int *status) {
    system("clear");

    printf("  | 1 2 3 4\n");
    printf("--+--------\n");

    for (int i = 0; i < 4; i++) {
        printf("%d | ", i+1);

        for (int j = 0; j < 4; j++) {
            if (status[i*4+j] == 0) {
                printf("? ");
            } else {
                printf("%d ", values[i*4+j]);
            }
        }

        printf("\n");
    }
}

void reset_board(int *values, int *status) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        status[i] = 0;
    }
}