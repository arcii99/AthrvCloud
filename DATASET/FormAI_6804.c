//FormAI DATASET v1.0 Category: Memory Game ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 8

void print(char arr[][SIZE], int show[]);
int play_game(char arr[][SIZE], int show[], int pos1, int pos2);

int main() {
    srand(time(NULL));
    char cards[SIZE][SIZE] = {
        {'R', 'O', 'M', 'E', 'O', ' ', ' ', ' '},
        {'J', 'U', 'L', 'I', 'E', 'T', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };

    int show[SIZE * SIZE];
    for (int i = 0; i < SIZE * SIZE; i++) {
        show[i] = 0;
    }

    print(cards, show);

    int pos1 = -1, pos2 = -1, success = 0, wrong_attempt = 0;
    while (success < SIZE * SIZE / 2) {
        printf("\nEnter 2 positions to open the cards: ");
        scanf("%d %d", &pos1, &pos2);

        if (play_game(cards, show, pos1, pos2)) {
            printf("\nMatched! Romeo and Juliet's luck is with you!");
            success++;
        } 
        else {
            printf("\nOops! You broke Romeo and Juliet's hearts!");
            wrong_attempt++;
            if (wrong_attempt >= 3) {
                printf("\nYou failed too many times! Romeo and Juliet are sad now :( ");
                exit(0);
            }
        }
        print(cards, show);
    }

    printf("\nCongratulations! You brought Romeo and Juliet together <3\n");
    return 0;
}

void print(char arr[][SIZE], int show[]) {
    printf("\nCurrent game status:\n\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (show[i * SIZE + j] == 1) {
                printf("%c ", arr[i][j]);
            } 
            else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

int play_game(char arr[][SIZE], int show[], int pos1, int pos2) {
    pos1 -= 1;
    pos2 -= 1;
    if (pos1 < 0 || pos1 >= SIZE * SIZE || pos2 < 0 || pos2 >= SIZE * SIZE) {
        printf("\nInvalid positions! Please try again.");
        return 0;
    }
    if (show[pos1] == 1 || show[pos2] == 1) {
        printf("\nThe card(s) is already open! Please try again.");
        return 0;
    }
    show[pos1] = 1;
    show[pos2] = 1;
    if (arr[pos1 / SIZE][pos1 % SIZE] == arr[pos2 / SIZE][pos2 % SIZE]) {
        return 1;
    }
    show[pos1] = 0;
    show[pos2] = 0;
    return 0;
}