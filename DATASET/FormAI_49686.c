//FormAI DATASET v1.0 Category: Random ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getRandomNumber(int min, int max) {
    if (min == max) {
        return min;
    }
    return (rand() % (max - min + 1)) + min + getRandomNumber(min, max);
}

int main() {
    int min, max, randomNum;
    printf("Enter the minimum value: ");
    scanf("%d", &min);
    printf("Enter the maximum value: ");
    scanf("%d", &max);
    if (min > max) {
        printf("The minimum value can't be greater than the maximum value.\n");
        return 0;
    }
    srand((unsigned int) time(NULL));
    randomNum = getRandomNumber(min, max);
    printf("The random number between %d and %d is: %d\n", min, max, randomNum);
    return 0;
}