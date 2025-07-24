//FormAI DATASET v1.0 Category: Error handling ; Style: puzzling
#include <stdio.h>

int main() {

    int x = 10, y = 0;

    int result = divide(x, y);
    
    printf("Result: %d\n", result);

    return 0;
}

int divide(int x, int y) {
    if(y == 0) {
        printf("Uh-oh! Something went wrong, can't divide by 0\n");
        return -1;
    }
    else {
        printf("Phew! That was close, we can divide by %d\n", y);
        return x/y;
    }
}