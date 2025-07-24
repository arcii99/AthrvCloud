//FormAI DATASET v1.0 Category: Recursive ; Style: funny
#include <stdio.h>

int recursive_function(int n) {
    if(n < 1) { // Base case
        printf("I don't think this is a good idea. Let's just stop here.\n");
        return 0;
    } else if(n == 1) { // Another base case
        printf("Oh, just one more time!\n");
        return 1;
    } else { // Recursive case
        int result = n * recursive_function(n-1);
        printf("Let's do it again! (%d times left)\n", n-1);
        return result;
    }
}

int main() {
    int input;
    printf("Hello there, I'm a recursive function! How many times do you want me to repeat?\n");
    scanf("%d", &input);
    printf("Here we go... (press CTRL+C to stop)\n");
    recursive_function(input);
    printf("Finished! That was fun, wasn't it?\n");
    return 0;
}