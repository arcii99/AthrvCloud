//FormAI DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>

int recursiveFunction(int a, int b, int c) {
    if(a==0) {
        return b+c;
    } else {
        return recursiveFunction(a-1, b+c, c);
    }
}

int main() {
    int a=10, b=5, c=3; 
    printf("The result of the recursive function with parameters %d, %d, %d is: %d\n", a, b, c, recursiveFunction(a,b,c));
    return 0;
}