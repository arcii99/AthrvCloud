//FormAI DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>

void braveRecursion(int num) {
    if(num <= 0) {
        printf("You have reached the end of the recursion, congratulations!\n");
    } else {
        printf("You are a brave soul to continue down this recursive path.\n");
        braveRecursion(num - 1);
    }
}

int main() {
    int num;
    printf("How brave are you feeling today? Enter a number to find out: ");
    scanf("%d", &num);

    printf("You are about to embark on a journey of recursion. Brace yourself!\n");

    braveRecursion(num);

    printf("Congratulations, you have made it through the recursion! That was quite brave!\n");

    return 0;
}