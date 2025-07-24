//FormAI DATASET v1.0 Category: Memory Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

void initializeBoard(char board[][BOARD_SIZE]);
void shuffleBoard(char board[][BOARD_SIZE]);
void printBoard(char board[][BOARD_SIZE], int revealed[]);
int checkRevealed(int revealed[]);
void revealCards(char board[][BOARD_SIZE], int revealed[], int x1, int y1, int x2, int y2);

int main() {
    srand(time(NULL));
    char board[BOARD_SIZE][BOARD_SIZE];
    int revealed[BOARD_SIZE * BOARD_SIZE / 2] = {0};
    
    initializeBoard(board);
    shuffleBoard(board);
    
    printf("Welcome to Memory Game in Medieval Style!\n\n");
    printf("You will be shown a board with hidden cards. Your goal is to uncover all the pairs of identical cards by entering their coordinates.\n");
    printf("Example: 1 2 3 4\n        A ? ? ?\n        B ? ? ?\n        C ? ? ?\n        D ? ? ?\n");
    printf("Enter the coordinates of the first card: B 2\n");
    printf("If the cards match, they will be removed from the board. If not, they will be hidden again.\n");
    printf("You win the game if you uncover all the matching pairs.\n");
    printf("Let's begin!\n\n");
    
    int moves = 0;
    while (1) {
        printBoard(board, revealed);
        printf("Enter the coordinates of the first card: ");
        int x1, y1, x2, y2;
        char a, b;
        scanf("%c %d %c %d", &a, &y1, &b, &y2);
        x1 = a - 'A';
        x2 = b - 'A';
        y1--;
        y2--;
        if (x1 < 0 || x1 >= BOARD_SIZE || x2 < 0 || x2 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE || x1 == x2 && y1 == y2) {
            printf("Invalid input, please try again.\n");
            continue;
        }
        if (revealed[x1 * BOARD_SIZE + y1] || revealed[x2 * BOARD_SIZE + y2]) {
            printf("The card has already been revealed. Choose another card.\n");
            continue;
        }
        printf("   1 2 3 4 5 6 7 8 9 10\n");
        printf("   -------------------\n");
        printf("A |");
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (i == y1 || i == y2) {
                printf(" %c |", board[x1][i]);
            } else if (revealed[x1 * BOARD_SIZE + i]) {
                printf("   |");
            } else {
                printf(" ? |");
            }
        }
        printf("\nB |");
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (i == y1 || i == y2) {
                printf(" %c |", board[x2][i]);
            } else if (revealed[x2 * BOARD_SIZE + i]) {
                printf("   |");
            } else {
                printf(" ? |");
            }
        }
        printf("\nC |");
        for (int i = 0; i < BOARD_SIZE; i++) {
            printf("---+");
        }
        printf("\n");
        if (board[x1][y1] == board[x2][y2]) {
            printf("The cards match!\n");
            revealed[x1 * BOARD_SIZE + y1] = 1;
            revealed[x2 * BOARD_SIZE + y2] = 1;
        } else {
            printf("The cards do not match.\n");
        }
        moves++;
        if (checkRevealed(revealed)) {
            printf("Congratulations, you have won the game in %d moves!\n", moves);
            break;
        }
    }
    
    return 0;
}

void initializeBoard(char board[][BOARD_SIZE]) {
    char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (count >= BOARD_SIZE * BOARD_SIZE / 2) {
                board[i][j] = ' ';
            } else {
                board[i][j] = letters[count % 26];
                count++;
            }
        }
    }
}

void shuffleBoard(char board[][BOARD_SIZE]) {
    int n = BOARD_SIZE * BOARD_SIZE;
    while (n > 1) {
        int k = rand() % n;
        n--;
        int i = n / BOARD_SIZE;
        int j = n % BOARD_SIZE;
        int x = k / BOARD_SIZE;
        int y = k % BOARD_SIZE;
        char temp = board[i][j];
        board[i][j] = board[x][y];
        board[x][y] = temp;
    }
}

void printBoard(char board[][BOARD_SIZE], int revealed[]) {
    printf("   1 2 3 4 5 6 7 8 9 10\n");
    printf("   -------------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c |", i + 'A');
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i * BOARD_SIZE + j]) {
                printf(" %c |", board[i][j]);
            } else {
                printf(" ? |");
            }
        }
        printf("\n");
    }
}

int checkRevealed(int revealed[]) {
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE / 2; i++) {
        if (!revealed[i]) {
            return 0;
        }
    }
    return 1;
}