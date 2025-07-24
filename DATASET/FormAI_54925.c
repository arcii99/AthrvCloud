//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    char fortunes[5][128] = {
        "You will find great success in your career.",
        "An exciting opportunity is just around the corner.",
        "Your luck is about to change.",
        "The future is uncertain, but your resilience will carry you through.",
        "Today is a good day to try something new."
    };
    srand(time(NULL));
    int choice = rand() % 5;
    printf("Welcome to the Automated Fortune Teller!\n");
    printf("Here is your fortune for today:\n");
    printf("%s\n", fortunes[choice]);
    return 0;
}