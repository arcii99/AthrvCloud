//FormAI DATASET v1.0 Category: Educational ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("The Adventure of the C Programming Language\n");

    printf("It was a cold and dark night, Dr. Watson.\n");
    printf("I was sitting in my armchair, thinking about the new language I wanted to learn.\n");
    printf("Suddenly, there was a knock on the door.\n");

    printf("\"Come in,\" I said.\n");

    printf("A man entered my apartment. He was wearing a tweed jacket and a deerstalker hat.\n");
    printf("It was my old friend, Watson.\n");

    printf("\"What brings you here at this late hour, Watson?\" I asked.\n");

    printf("Watson handed me a piece of paper.\n");

    printf("\"This is a message from the Criminal Mastermind,\" said Watson.\n");
    printf("\"He has challenged you to solve his puzzle in the C Programming Language.\"\n");

    printf("I examined the piece of paper. It read:\n");
    printf("\"To prove your intelligence,\n");
    printf("You must calculate the sum of consecutive integers,\n");
    printf("From 1 to n, inclusive.\n");
    printf("In C, of course.\"\n");

    printf("\"I accept the challenge,\" I said.\n");

    int n;
    printf("Please enter n: ");
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }

    printf("The sum of consecutive integers from 1 to %d is %d.\n", n, sum);

    printf("\"Excellent work, my dear Holmes,\" said Watson.\n");

    printf("I smiled. \"Elementary, my dear Watson.\"\n");

    return EXIT_SUCCESS;
}