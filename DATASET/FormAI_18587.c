//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>

int do_something(int n) {
    if (n == 0) {
        printf("BOOM SHAKALAKA\n");
        return 0;
    } else {
        printf("%d little monkeys jumping on the bed\n", n);
        return do_something(n-1);
    }
}

int main() {
    int n = 5;
    printf("Welcome to Monkey Land!\n");
    printf("We have %d monkeys waiting for you\n", n);
    printf("Are you ready to count down with them?\n");
    printf("Press any key to start!\n");
    getchar();

    do_something(n);

    printf("Thank you for counting down with our monkeys!\n");
    printf("We hope you had a fun time!\n");
    return 0;
}