//FormAI DATASET v1.0 Category: Recursive ; Style: paranoid
#include <stdio.h>

void recurse(int x);
void check_input(int x);

int main(void) {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Paranoia check on user input
    check_input(num);

    // Recursive call
    recurse(num);
    return 0;
}

void recurse(int x) {
    // Paranoia check on parameter value
    if (x < 0) {
        printf("Error: negative input detected!\n");
        // Infinite loop to prevent program from continuing
        while (1) {}
    }
    // Base case
    if (x == 0) {
        printf("Recursion complete.\n");
        return;
    }
    // Recursive case
    printf("Recursive call with value %d.\n", x);
    recurse(x - 1);
}

void check_input(int x) {
    // Paranoia check on user input
    if (x > 1000) {
        printf("Warning: input value exceeds 1000!\n");
        // Sleep for 5 seconds to simulate processing delay
        sleep(5);
    }
    if (x < 1) {
        printf("Error: invalid input value!\n");
        // Infinite loop to prevent program from continuing
        while (1) {}
    }
    printf("Input value verified.\n");
}