//FormAI DATASET v1.0 Category: Online Examination System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, ans, p, score;
    int num[5];
    printf("Welcome to the Multiplayer Online Examination System!\n");

    while (1) {
        score = 0;
        printf("\nEnter the number of players (maximum 5): ");
        scanf("%d", &n);

        if (n <= 5 && n > 0) {
            for (i = 0; i < n; i++) {
                printf("\nPlayer %d: ", i+1);
                scanf("%d", &num[i]);
            }
            printf("\nThe questions will begin now!");

            srand(time(0));
            for (i = 0; i < 5; i++) {
                printf("\nQuestion %d: What is %d + %d?", i+1, rand()%101, rand()%101);
                scanf("%d", &ans);
                
                for (p = 0; p < n; p++) {
                    if (ans == num[p] + num[(p+1)%n]) {
                        printf("\nAnswer by Player %d is correct!", p+1);
                        score++;
                    }
                    else {
                        printf("\nAnswer by Player %d is wrong!", p+1);
                    }
                }
            }
            printf("\n\nGame over! Final score: %d\n", score);
        }
        else {
            printf("\nInvalid input. Please try again.\n");
        }

    }
    return 0;
}