//FormAI DATASET v1.0 Category: Recursive ; Style: imaginative
#include <stdio.h>

// A recursive function that prints out an imaginary world filled with strange creatures.

void strangeWorld(int depth, int x, int y) {
    int i, j;
    
    if (depth == 0) {
        printf("You are at (%d,%d)\n", x, y);
        return;
    }
    
    printf("You are in a strange world. It is very deep here, and you are currently in level %d\n", depth);
    
    printf("You see some strange creatures around you:\n");
    for (i = 0; i < depth; i++) {
        printf(" ");
    }
    printf("[ ");
    for (j = 0; j < depth; j++) {
        printf("^");
    }
    printf(" ]\n");
    
    printf("You decide to take a step forward...\n");
    strangeWorld(depth-1, x+1, y);
}

int main() {
    strangeWorld(5, 0, 0);
    return 0;
}