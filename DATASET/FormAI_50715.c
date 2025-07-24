//FormAI DATASET v1.0 Category: Arithmetic ; Style: excited
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Let's start by declaring some variables
    int a, b, c, d, e, result;

    // We want to get the user's input, so let's ask some questions
    printf("Hey there! I heard you are interested in some arithmetic magic. \n");
    printf("Why don't you tell me five numbers you want me to work with? \n");

    // Ask for user input and store in variables
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);

    // Let's do some calculations!
    result = (a + b) * (c / d) % e;

    // Wow, that was fast! Let's show the user the result
    printf("The result of the calculation is %d\n", result);

    // But wait, there's more! We can also do some logical operations
    if (result == 0) {
        printf("Wowie zowie, the result is zero!\n");
    } else if (result > 100) {
        printf("Whoa, that's a big number!\n");
    } else {
        printf("That's a pretty average number.\n");
    }

    // Finally, let's say goodbye and end the program
    printf("Thanks for playing! Have a great day.\n");
    return 0;
}