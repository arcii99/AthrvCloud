//FormAI DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>

int recursive_function(int x, int y, int z) {
    if (x == 0 || y == 0 || z == 0) {
        return 1;
    } else if (x < 0 || y < 0 || z < 0) {
        return 0;
    } else {
        return recursive_function(x-1, y, z) + recursive_function(x, y-1, z) + recursive_function(x, y, z-1);
    }
}

int main() {
    int x, y, z;
    printf("Enter three integers (each greater than or equal to zero): ");
    scanf("%d %d %d", &x, &y, &z);
    int result = recursive_function(x, y, z);
    printf("The result of the multivariable recursive function is %d.", result);
    return 0;
}