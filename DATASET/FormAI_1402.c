//FormAI DATASET v1.0 Category: Educational ; Style: puzzling
#include <stdio.h>

int main() {
    // A puzzle for you to solve
    
    int x = 5;
    int y = 10;
    int z = 15;

    int result1 = (x + y) * z;
    int result2 = x * y + y * z;

    printf("Which is greater: result1 = %d or result2 = %d?\n", result1, result2);
    
    // Your code goes here
    
    if (result1 > result2) {
        printf("Congratulations! You solved the puzzle!\n");
    } else {
        printf("Sorry, that's not the correct answer.\n");
    }
    
    return 0;
}