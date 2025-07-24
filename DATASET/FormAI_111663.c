//FormAI DATASET v1.0 Category: Recursive ; Style: brave
#include <stdio.h>

int fibonacci(int n){
    if(n == 0) return 0; //base case 1
    else if(n == 1) return 1; //base case 2
    else return fibonacci(n-1) + fibonacci(n-2); //recursive case
}

int main(){
    int num;
    printf("Enter a number to find its fibonacci sequence: ");
    scanf("%d", &num);

    printf("Fibonacci Sequence up to %d:\n", num);

    for(int i=0; i<num; i++){
        printf("%d ", fibonacci(i));
    }

    return 0;
}