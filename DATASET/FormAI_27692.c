//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize array
    int bingo[5][5] = {0};

    // Fill array with random numbers
    srand(time(NULL));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == 2 && j == 2) {
                continue; // Free space
            }
            int num = rand() % 15 + 1 + (j * 15); // Generate number between 1 and 15
            if (j == 1) {
                num += 15; // Second column numbers between 16 and 30
            } else if (j == 2) {
                num += 30; // Third column numbers between 31 and 45
            } else if (j == 3) {
                num += 45; // Fourth column numbers between 46 and 60
            } else if (j == 4) {
                num += 60; // Fifth column numbers between 61 and 75
            }
            bingo[i][j] = num; // Assign number to array
        }
    }

    // Print header
    printf("╔══════╦══════╦══════╦══════╦══════╗\n");
    printf("║ B    ║ I    ║ N    ║ G    ║ O    ║\n");
    printf("╠══════╬══════╬══════╬══════╬══════╣\n");

    // Print array
    for (int i = 0; i < 5; i++) {
        printf("║ ");
        for (int j = 0; j < 5; j++) {
            int num = bingo[i][j];
            if (num == 0) {
                printf("    ║ "); // Free space
            } else {
                printf("%2d  ║ ", num);
            }
        }
        printf("\n");
        if (i != 4) {
            printf("╠══════╬══════╬══════╬══════╬══════╣\n"); // Separate rows
        }
    }

    // Print footer
    printf("╚══════╩══════╩══════╩══════╩══════╝\n");

    // Exit program
    return 0;
}