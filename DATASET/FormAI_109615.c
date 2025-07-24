//FormAI DATASET v1.0 Category: Math exercise ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand((unsigned) time(NULL));
    int a = rand() % 100 + 1;
    int b = rand() % 100 + 1;
    int c = rand() % 100 + 1;

    int result = a * b + c;
    int guess;

    printf("Hey there CyberPunk, let's test your math skills!\n");
    printf("Solve for x in the following equation: x = %d * %d + %d\n", a, b, c);
    printf("Enter your answer (integer only): ");
    scanf("%d", &guess);

    if (guess == result) {
        printf("Congratulations! You have successfully solved the equation and proven your CyberPunk math skills!\n");
    } else {
        printf("Incorrect answer, the correct value of x is %d. Better luck next time, CyberPunk!\n", result);
    }

    return 0;
}