//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO_CARD_SIZE 5
#define MAX_NUMBER 75
#define ROWS 5
#define COLUMNS 5

void print_card(int card[][BINGO_CARD_SIZE]);
int is_bingo(int card[][BINGO_CARD_SIZE]);
void generate_numbers(int card[][BINGO_CARD_SIZE], int numbers[], int size);

int main() {
    srand(time(NULL));
    int card[BINGO_CARD_SIZE][BINGO_CARD_SIZE] = {0};
    int numbers[MAX_NUMBER] = {0};

    generate_numbers(card, numbers, MAX_NUMBER);
    print_card(card);

    while(!is_bingo(card)) {
        int number = rand() % MAX_NUMBER + 1;

        printf("The number called is: %d\n", number);

        for(int i = 0; i < MAX_NUMBER; i++) {
            if(numbers[i] == number) {
                numbers[i] = 0;
                for(int j = 0; j < BINGO_CARD_SIZE; j++) {
                    for(int k = 0; k < BINGO_CARD_SIZE; k++) {
                        if(card[j][k] == number) {
                            card[j][k] = 0;
                            break;
                        }
                    }
                }
                break;
            }
        }

        print_card(card);
    }

    printf("BINGO!");

    return 0;
}

void generate_numbers(int card[][BINGO_CARD_SIZE], int numbers[], int size) {
    for(int i = 0; i < size; i++) {
        numbers[i] = i + 1;
    }

    for(int i = 0; i < BINGO_CARD_SIZE; i++) {
        for(int j = 0; j < BINGO_CARD_SIZE; j++) {
            int index = rand() % size;
            card[i][j] = numbers[index];
            numbers[index] = numbers[size - 1];
            size--;
        }
    }

    card[BINGO_CARD_SIZE / 2][BINGO_CARD_SIZE / 2] = 0;
}

void print_card(int card[][BINGO_CARD_SIZE]) {
    printf("\n");
    printf("  ----------------------\n");
    for(int i = 0; i < BINGO_CARD_SIZE; i++) {
        printf(" | ");
        for(int j = 0; j < BINGO_CARD_SIZE; j++) {
            if(card[i][j] == 0) {
                printf("  ");
            } else {
              if (card[i][j] / 10 > 0) {
                printf("%d", card[i][j]);
              } else {
                printf(" ");
                printf("%d", card[i][j]);
              }
            }
            printf(" | ");
        }
        printf("\n");
        printf("  ----------------------\n");
    }
}

int is_bingo(int card[][BINGO_CARD_SIZE]) {
    int row_sum = 0;
    int column_sum = 0;
    int diagonal_sum1 = 0;
    int diagonal_sum2 = 0;

    for(int i = 0; i < ROWS; i++) {
        row_sum = 0;
        column_sum = 0;
        for(int j = 0; j < COLUMNS; j++) {
            row_sum += card[i][j];
            column_sum += card[j][i];
        }
        if(row_sum == 0 || column_sum == 0) {
            return 1;
        }
        diagonal_sum1 += card[i][i];
        diagonal_sum2 += card[i][BINGO_CARD_SIZE - i - 1];
    }

    if(diagonal_sum1 == 0 || diagonal_sum2 == 0) {
        return 1;
    }

    return 0;
}