//FormAI DATASET v1.0 Category: Educational ; Style: energetic
#include <stdio.h>

int main() { // This is the main function
    int number, sum = 0;
    printf("Let's play a game!\nEnter a positive integer: ");
    scanf("%d", &number);

    if(number <= 0) { // If input is not positive
        printf("The input is not valid.\n");
        return 1;
    }

    printf("You entered %d.\n", number);
    printf("I'm going to add all the even numbers from 1 to %d, and you will do the same for the odd numbers.\n", number);

    for(int i=2; i<=number; i+=2) { // Adding even numbers
        sum += i;
    }

    printf("My sum of even numbers is %d.\n", sum);
    printf("Now it's your turn. Let's see if you can do better!\n");

    int userSum = 0, current; // User's turn
    for(int i=1; i<=number; i+=2) { // Adding odd numbers
        printf("Enter the %dth odd number: ", i);
        scanf("%d", &current);
        if(current < 0) { // Input is not positive
            printf("You entered a negative number. Game over!\n");
            return 1;
        }
        userSum += current;
    }

    printf("You entered %d odd numbers and the sum of your numbers is %d.\n", number/2, userSum);

    if(sum > userSum) {
        printf("I win! My sum of even numbers is greater than your sum of odd numbers.\n");
    }
    else if(userSum > sum) {
        printf("Congratulations! You win! Your sum of odd numbers is greater than my sum of even numbers.\n");
    }
    else {
        printf("It's a tie! We both have the same sum.\n");
    }

    return 0;
}