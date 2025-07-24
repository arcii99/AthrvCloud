//FormAI DATASET v1.0 Category: Memory Game ; Style: random
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main() {
    int n, i, j;
    int score = 0;
    printf("Welcome to the Memory Game!\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n][n];
    srand(time(0));
    printf("Remember the following numbers carefully:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            a[i][j] = rand()%10;
            printf("%d ", a[i][j]);
            delay(700); //Delay for better visibility
        }
        printf("\n");
    }

    printf("Enter the remembered numbers:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            int temp;
            scanf("%d", &temp);
            if(temp == a[i][j]) {
                score++;
                printf("Correct!\n");
            }
            else {
                printf("Incorrect! The correct answer was %d\n", a[i][j]);
            }
            delay(700); //Delay for better visibility
        }
    }

    printf("Your score is %d out of %d\n", score, n*n);

    return 0;
}