//FormAI DATASET v1.0 Category: Error handling ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

void divide(int a, int b){
    if(b == 0){
        errno = EINVAL;
        perror("Error");
        exit(EXIT_FAILURE);
    }
    int result = a/b;
    printf("The result of %d / %d is %d\n", a, b, result);
}

int main(){
    int a = 5, b = 0;
    divide(a, b);
    return 0;
}