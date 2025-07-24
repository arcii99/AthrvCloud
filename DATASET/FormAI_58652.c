//FormAI DATASET v1.0 Category: Recursive ; Style: surprised
#include <stdio.h>

int factorial(int n) {
    if(n < 0) {
        printf("Oh boy! Negative numbers aren't allowed here. :O\n");
        return -1;
    }
    else if(n == 0) {
        printf("Wait, what?! Factorial of 0 is 1? Mind-blowing! :O\n");
        return 1;
    }
    else if(n > 12) {
        printf("Woah, woah, woah! I'm not a genie, I can't handle such big numbers. :(\n");
        return -1;
    }
    else {
        printf("Hold on tight, here comes recursion! :D\n");
        return n * factorial(n - 1);
    }
}

int main() {
    int num;
    printf("Give me a number and I'll give you its factorial: ");
    scanf("%d", &num);
    int result = factorial(num);
    printf("The factorial of %d is %d\n", num, result);
    return 0;
}