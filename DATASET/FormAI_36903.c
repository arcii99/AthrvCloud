//FormAI DATASET v1.0 Category: Recursive ; Style: cheerful
#include <stdio.h>

int recursiveFunction(int number) {
    int result;
    if (number == 0) {
        printf("Yay! We reached the end of the recursion!\n");
        result = 0;
    } else {
        printf("This is so much fun! We're at %d in the recursion!\n", number);
        result = number + recursiveFunction(number - 1);
    }
    return result;
}

int main() {
    printf("Welcome to the recursive party!\n");
    printf("Let's start with a number to get the recursion going: ");
    int startingNumber;
    scanf("%d", &startingNumber);
    int finalResult = recursiveFunction(startingNumber);
    printf("And the final result is... %d!\n", finalResult);
    printf("What a fun party, let's do this again sometime!\n");
    return 0;
}