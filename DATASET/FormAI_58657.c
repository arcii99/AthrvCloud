//FormAI DATASET v1.0 Category: Recursive ; Style: peaceful
#include <stdio.h>

void peaceful_recursive_function(int n);

int main() {
    int n = 10;
    printf("Starting the peaceful recursive function with n = %d\n", n);
    peaceful_recursive_function(n);
    return 0;
}

void peaceful_recursive_function(int n){
    if(n == 0){
        printf("Peaceful end of recursion\n");
        return;
    }
    printf("Peaceful recursive function is counting down %d...\n", n);
    peaceful_recursive_function(n-1);
}