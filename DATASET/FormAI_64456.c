//FormAI DATASET v1.0 Category: Random ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    printf("Welcome to my unique C random example program!\n");
    printf("Today, I will use my random number generator to help you pick a lucky number.\n");

    srand(time(NULL)); //set random seed based on current time

    int num1 = rand() % 10; //generate random number between 0 and 9
    int num2 = rand() % 10; //generate another random number between 0 and 9
    int luckyNum = num1 * 10 + num2; //combine the two numbers to get a two-digit lucky number

    printf("Your lucky number is: %d\n", luckyNum);
    printf("I hope this number brings you good fortune!\n");

    return 0;
}