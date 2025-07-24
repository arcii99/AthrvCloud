//FormAI DATASET v1.0 Category: Educational ; Style: funny
#include<stdio.h>
#include<stdlib.h>

int main() {
    printf("This is the beginning of my C program, but I'm already lost!\n");
    printf("I think I need to declare some variables...\n");
    
    int num1 = 10;
    int num2 = 20;
    int sum = num1 + num2;
    printf("Phew, I feel a bit better now that I have some numbers to work with!\n");

    printf("But I still don't know what I want to do with them...\n");
    printf("Maybe I should ask the user for some input!\n");
    printf("Please enter a number: ");
    
    int userInput;
    scanf("%d", &userInput);
    printf("Great, you entered %d!\n", userInput);

    printf("Now let me do some calculations with your number...\n");
    int result = userInput * sum;
    printf("Wow, the result of your number multiplied by the sum of %d and %d is %d\n", num1, num2, result);

    printf("But I'm still feeling a bit stuck...maybe I need to add some randomness to my program!\n");
    int randomNum = rand();
    printf("The random number is %d!\n", randomNum);

    printf("Okay, now I'm feeling a bit more comfortable with this C programming thing...\n");
    printf("In fact, I think I might even be ready to start writing some real code!\n");
    printf("Thanks for helping me get started!\n");

    return 0;
}