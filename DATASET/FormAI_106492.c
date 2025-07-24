//FormAI DATASET v1.0 Category: Memory Game ; Style: paranoid
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void fill_board(char *board, int size) {
    int i, j, r;
    int chars[26] = {0}; //count how many times each character was chosen

    //fill with random uppercase letters
    for (i = 0; i < size; i++) {
        j = 0;
        do {
            r = rand() % 26; //random number from 0-25
            j++;
        } while (chars[r] > size/26 + 1 && j < 100); //reject if too common
        board[i] = r + 'A'; //convert to letter
        chars[r]++; //record choice
    }
}

void print_board(char *board, int size) {
    int i;
    printf(" 0123456789ABCDEF\n");
    for (i = 0; i < size; i++) {
        if (i % 16 == 0) printf("\n%01X ", i/16);
        printf("%c", board[i]);
    }
    printf("\n");
}

int main() {
    char board[256];
    int size = 256;
    int i, pos1, pos2, moves = 0;

    printf("C Memory Game by paranoidbot\n");
    srand(time(NULL));

    while(1) {
        fill_board(board, size);
        print_board(board, size);
        printf("Enter the positions of two cards to reveal (e.g. AB):\n");

        do {
            printf("First card:");
            pos1 = getchar();
            if (pos1 >= 'a' && pos1 <= 'f') pos1 -= 'a' - 'A'; //convert to uppercase
            pos1 -= '0'; //convert to number
            pos1 *= 16; //move to upper nibble
            pos2 = getchar();
            if (pos2 >= 'a' && pos2 <= 'f') pos2 -= 'a' - 'A'; //convert to uppercase
            pos2 -= '0'; //convert to number
            pos1 += pos2; //combine upper and lower nibbles
        } while (pos1 >= size || board[pos1] == '*'); //reject if out of range or already guessed

        board[pos1] = '*'; //mark as guessed
        do {
            printf("Second card:");
            pos1 = getchar();
            if (pos1 >= 'a' && pos1 <= 'f') pos1 -= 'a' - 'A'; //convert to uppercase
            pos1 -= '0'; //convert to number
            pos1 *= 16; //move to upper nibble
            pos2 = getchar();
            if (pos2 >= 'a' && pos2 <= 'f') pos2 -= 'a' - 'A'; //convert to uppercase
            pos2 -= '0'; //convert to number
            pos1 += pos2; //combine upper and lower nibbles
        } while (pos1 >= size || board[pos1] == '*'); //reject if out of range or already guessed

        board[pos1] = '*'; //mark as guessed
        printf("\n");
        print_board(board, size);
        moves++;

        //game over if all cards guessed
        for (i = 0; i < size; i++) {
            if (board[i] != '*') break;
        }
        if (i == size) break;
    }

    printf("You won in %d moves!\n", moves);

    return 0;
}