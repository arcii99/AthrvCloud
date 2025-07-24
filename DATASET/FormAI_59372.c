//FormAI DATASET v1.0 Category: Recursive ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printRandomNums(int n, int i) {
    if(i == n) {
        return;
    }
    srand(time(NULL));
    int randomNum = (rand() % (1000 - 1 + 1)) + 1;
    printf("Random Number %d: %d\n", i+1, randomNum);
    printRandomNums(n, i+1);
}

int main() {
    int n;
    printf("Enter number of random numbers you want to generate: ");
    scanf("%d", &n);
    printf("Generating %d random numbers:\n", n);
    printRandomNums(n, 0);
    printf("Program executed successfully!");
    return 0;
}