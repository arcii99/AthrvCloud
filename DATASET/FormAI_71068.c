//FormAI DATASET v1.0 Category: Memory Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4
#define MAX_VALUE 8

void create_cards(int cards[][COLS]);
void print_cards(int cards[][COLS], int revealed[][COLS]);
void swap(int *a, int *b);
void shuffle_cards(int cards[][COLS]);
void play_game(int cards[][COLS]);

int main() {
    srand(time(NULL));
    int cards[ROWS][COLS];
    create_cards(cards);
    shuffle_cards(cards);
    play_game(cards);
    return 0;
}

void create_cards(int cards[][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            cards[i][j] = (i*COLS + j) / 2 + 1;
        }
    }
}

void print_cards(int cards[][COLS], int revealed[][COLS]) {
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(revealed[i][j]) {
                printf("%d ", cards[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shuffle_cards(int cards[][COLS]) {
    for(int i=ROWS*COLS-1; i>0; i--) {
        int r = rand() % (i+1);
        int row1 = r / COLS;
        int col1 = r % COLS;
        int row2 = i / COLS;
        int col2 = i % COLS;
        swap(&cards[row1][col1], &cards[row2][col2]);
    }
}

void play_game(int cards[][COLS]) {
    int attempts = 0;
    int revealed[ROWS][COLS] = {0};
    while(1) {
        print_cards(cards, revealed);
        int x1, y1, x2, y2;
        printf("Enter the first card location (row column): ");
        scanf("%d %d", &x1, &y1);
        if(revealed[x1][y1]) {
            printf("Location already revealed. Choose another location.\n");
            continue;
        }
        revealed[x1][y1] = 1;
        print_cards(cards, revealed);
        printf("Enter the second card location (row column): ");
        scanf("%d %d", &x2, &y2);
        if(revealed[x2][y2]) {
            printf("Location already revealed. Choose another location.\n");
            continue;
        }
        revealed[x2][y2] = 1;
        if(cards[x1][y1] != cards[x2][y2]) {
            printf("Wrong match. Try again.\n");
            attempts++;
            revealed[x1][y1] = 0;
            revealed[x2][y2] = 0;
        } else {
            printf("Correct match. Well done!\n");
            attempts++;
            int remaining = 0;
            for(int i=0; i<ROWS; i++) {
                for(int j=0; j<COLS; j++) {
                    if(!revealed[i][j]) {
                        remaining = 1;
                        break;
                    }
                }
                if(remaining) {
                    break;
                }
            }
            if(!remaining) {
                printf("You won! Congratulations! You took %d attempts.\n", attempts);
                break;
            }
        }
    }
}