//FormAI DATASET v1.0 Category: Recursive ; Style: interoperable
#include <stdio.h>

// function prototype
int fibonacci(int num);

int main() {
    int num, result;
    printf("Enter the number of terms you want to generate: ");
    scanf("%d", &num);
    printf("Fibonacci series with %d terms:\n", num);
    for(int i=0; i<num; i++){
        result = fibonacci(i);
        printf("%d ", result);
    }
    return 0;
}

int fibonacci(int num){
    if(num==0)
        return 0;
    else if(num==1)
        return 1;
    else
        return (fibonacci(num-1) + fibonacci(num-2));
}