//FormAI DATASET v1.0 Category: Funny ; Style: energetic
#include <stdio.h>

int main() {

    printf("Welcome to the most energetic C program ever!\n");
    printf("Are you ready for some Crazy calculations?\n\n");

    int x = 5;
    int y = 7;
    int z = 10;

    printf("Let's start with some basic calculations:\n");

    printf("5 times 7 is %d\n", x * y);

    printf("10 divided by 5 is %d\n", z / x);

    printf("Next up, let's square some numbers:\n");

    int a = 3;
    printf("The square of %d is %d\n", a, a * a);

    int b = 8;
    printf("The square of %d is %d\n", b, b * b);

    printf("Now, let's generate a random number:\n");

    int random = 0;
    srand(time(0));
    random = rand() % 100 + 1;

    printf("The random number is: %d\n", random);

    if (random > x && random < y) {
        printf("The random number is between %d and %d!\n", x, y);
    } else {
        printf("The random number is not between %d and %d. Sorry, try again!\n", x, y);
    }

    printf("\nHope you enjoyed this energetic C program!\n");

    return 0;
}