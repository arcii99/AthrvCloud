//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>

int recursive(int n) {
    if (n == 0) {
        printf("Did you really need to do this?\n");
        return 0;
    } else if (n == 1) {
        printf("You got a lot of free time to be doing this\n");
        return 1;
    } else if (n < 0) {
        printf("You must be a software developer, because this is truly negative\n");
        return -1;
    } else {
        printf("Are you sure this is what you want to do? Press y to continue:");
        char choice;
        scanf("%s", &choice);
        if (choice == 'y') {
            printf("Fine, I'll do it, but don't blame me if things go south\n");
            return recursive(n-1) + recursive(n-2);
        } else {
            printf("I knew you couldn't handle the heat. I'm out\n");
            return -1;
        }
    }
}

int main() {
    int n;
    printf("Welcome to the recursion madness!\nEnter a positive integer to continue:");
    scanf("%d", &n);
    int result = recursive(n);
    printf("The result is: %d\n", result);

    return 0;
}