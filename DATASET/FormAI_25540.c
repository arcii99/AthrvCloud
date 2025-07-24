//FormAI DATASET v1.0 Category: Error handling ; Style: recursive
#include <stdlib.h>
#include <stdio.h>

void recursive_error_function(int i) {
    if(i < 0) {
        printf("Error: i is negative!\n");
        exit(EXIT_FAILURE);
    }
    else {
        printf("Recursive call with i = %d\n", i);
        recursive_error_function(i-1);
    }
}

int main() {
    int i = 10;
    recursive_error_function(i);
    return 0;
}