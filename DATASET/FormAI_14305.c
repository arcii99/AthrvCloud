//FormAI DATASET v1.0 Category: Funny ; Style: sophisticated
#include <stdio.h>

int main() {
    int num_one = 5;
    int num_two = 10;
    printf("The sum of %d and %d is: %d\n", num_one, num_two, num_one+num_two);
    printf("The product of %d and %d is: %d\n", num_one, num_two, num_one*num_two);
    printf("The difference between %d and %d is: %d\n", num_one, num_two, num_two-num_one);

    printf("Now let's play a game. Enter a number between 1 and 100: ");
    int user_input;
    scanf("%d", &user_input);

    if (user_input % 3 == 0) {
        printf("Your number is divisible by 3!\n");
    }
    else if (user_input % 5 == 0) {
        printf("Your number is divisible by 5!\n");
    }
    else if (user_input % 3 == 0 && user_input % 5 == 0) {
        printf("Your number is a multiple of both 3 and 5!\n");
    }
    else {
        printf("Sorry, your number is not a multiple of 3 or 5.\n");
    }

    printf("Thanks for playing!\n");

    return 0;
}