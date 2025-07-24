//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int n, i, t1 = 0, t2 = 1, nextTerm;
    printf("Welcome to Fibonacci Sequence Visualizer!\n");
    printf("Enter the number of terms you would like to see: ");
    scanf("%d", &n);
    printf("\n");

    if (n <= 0) {
        printf("Incorrect Input\n");
        sleep(2);
        printf("Just kidding, I'm a computer program. There's no such thing as incorrect input, but for demonstration purposes, please enter a value larger than 0\n");
        scanf("%d", &n);
        printf("\n");
    }
    printf("Hold onto your hats, folks. Here comes the Fibonacci Sequence visualization!\n");

    for (i = 1; i <= n; ++i) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        printf("%5d", nextTerm);
        int j;
        for(j = 1; j <= (nextTerm % 10); j++){
            printf("*");
        }
        printf("\n");
        usleep(50000);
    }
    printf("\n");
    printf("Thank you for using Fibonacci Sequence Visualizer!");
    return 0;
}