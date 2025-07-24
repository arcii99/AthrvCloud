//FormAI DATASET v1.0 Category: Recursive ; Style: mind-bending
#include <stdio.h>

void recursive_function(int n) {
    if (n < 1) {
        printf("Now I am done.\n");
        return;
    }
    
    printf("I am at the %dth level of recursion.\n", n);
    printf("I can feel my mind bending.\n");
    printf("There's %d levels left to go.\n", n-1);
    
    recursive_function(n-1);
    
    printf("I am at the %dth level of recursion.\n", n);
    printf("I am starting to see things.\n");
    printf("There's %d levels left to go.\n", n-1);
}

int main() {
    printf("Welcome to the recursive journey!\n");
    recursive_function(5);
    printf("We have returned to the main function.\n");
    return 0;
}