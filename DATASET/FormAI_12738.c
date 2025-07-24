//FormAI DATASET v1.0 Category: Arithmetic ; Style: immersive
#include <stdio.h>

int main() {
    printf("Welcome to the magical world of numbers!\n");
    printf("Enter a number and I will perform some arithmetic magic on it: ");
    int num;
    scanf("%d", &num);

    printf("You have chosen %d. Now, watch closely as I perform some arithmetic magic:\n", num);

    int sum = 0;
    for (int i = 1; i <= num; i++) {
        printf("%d + ", i);
        sum += i;
    }

    printf("\b\b= %d\n", sum);
    printf("See? I've just added up all the numbers up to %d and the result is %d. Now, let me show you a few more tricks.\n\n", num, sum);

    printf("If I subtract 3 from your number, I get %d. And if I multiply it by 5, I get %d.\n\n", num-3, (num-3)*5);

    printf("Let's move on to some division magic. I'm going to divide your number by 2 and show you the remainder: %d %% 2 = %d. See how easy it is?\n\n", num, num%2);

    printf("Now, let's play a game. I'm thinking of a number between 1 and 10. Can you guess what it is? ");
    int guess;
    scanf("%d", &guess);
    if (guess == (num % 10) + 1) {
        printf("Wow, you're a mind reader! My number was indeed %d. You win!\n", num % 10 + 1);
    } else {
        printf("Sorry, that's not my number. My number was %d. Better luck next time!\n", num % 10 + 1);
    }
    
    return 0;
}