//FormAI DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>

int main()
{
    printf("Welcome to the Amazing Math Exercise Program!\n");
    printf("Let's start with a warm-up exercise.\n");

    // Warm-up exercise
    int a = 4, b = 3, c = 2, result;
    result = a - b / c;
    printf("What is the value of a - b / c, where a = %d, b = %d, c = %d?\n", a, b, c);
    printf("Enter your answer: ");
    int user_answer;
    scanf("%d", &user_answer);
    if (user_answer == result)
    {
        printf("Congratulations! You have the correct answer.\n");
    }
    else
    {
        printf("Oops! Your answer is wrong. The correct answer is %d.\n", result);
    }

    printf("Now, let's move on to a more challenging exercise.\n");

    // Challenging exercise
    int x, y, z, a1, a2, a3, a4, result2;
    printf("Find the value of (x / y) - (z * a1) + (a2 / a3) * a4, where\n");
    printf("x = 10, y = 4, z = 3, a1 = 5, a2 = 8, a3 = 2, a4 = 6.\n");
    printf("Enter your answer: ");
    scanf("%d", &result2);
    if (result2 == ((x / y) - (z * a1) + (a2 / a3) * a4))
    {
        printf("Wow! You've got the right answer!");
    }
    else
    {
        printf("Your answer's incorrect! The correct answer is %d.", ((x / y) - (z * a1) + (a2 / a3) * a4));
    }

    return 0;
}