//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num[75], call[75], check[5][5], i, j, counter = 0, guess;

    srand(time(0));

    for (i = 0; i < 75; i++) {
        num[i] = i + 1;
        call[i] = 0;
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            check[i][j] = num[counter];
            counter++;
        }
    }

    printf("Welcome to the Surrealist Bingo Simulator\n");

    while (1) {

        int flag = 0;

        for (i = 0; i < 5; i++) {
            printf("   B  I  N  G  O\n");

            for (j = 0; j < 5; j++) {
                if (check[i][j] == 0) {
                    printf("    * ");
                } else {
                    printf("%5d ", check[i][j]);
                }
            }

            printf("\n");
        }

        printf("\nPlease enter your guess: ");
        scanf("%d", &guess);

        for (i = 0; i < 75; i++) {
            if (num[i] == guess) {
                call[i] = 1;
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            printf("\nSorry, your guess %d is not present in the list.\n", guess);
            continue;
        }

        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (check[i][j] == guess) {
                    check[i][j] = 0;
                }
            }
        }

        printf("\n");

        for (i = 0; i < 75; i++) {
            if (call[i] == 0) {
                break;
            }
        }

        if (i == 75) {
            printf("\nCongratulations! You have won Surrealist Bingo.\n");
            break;
        }

    }

    return 0;
}