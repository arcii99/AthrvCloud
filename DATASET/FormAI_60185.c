//FormAI DATASET v1.0 Category: Recursive ; Style: real-life
// Author: Chatbot
// Date: 2021-10-07
// Description: A recursive program to calculate the total number of possible ways to climb a staircase when taking 1, 2, or 3 steps at a time.


#include <stdio.h>

int countWays(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else {
        return countWays(n - 1) + countWays(n - 2) + countWays(n - 3);
    }
}

int main() {
    int numOfSteps;
    printf("Enter the number of steps in the staircase: ");
    scanf("%d", &numOfSteps);

    printf("\nThe total number of possible ways to climb the staircase is %d.\n", countWays(numOfSteps));

    return 0;
}