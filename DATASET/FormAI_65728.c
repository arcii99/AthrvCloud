//FormAI DATASET v1.0 Category: Recursive ; Style: ultraprecise
#include <stdio.h>

// define the recursive function
int recursiveFunction(int n){
    if(n == 1){ // base case
        return 1;
    }
    else{
        return n * recursiveFunction(n-1); // recursive case
    }
}

int main(){
    int n, result;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if(n < 0){
        printf("Error: Please enter a positive integer.");
        return 1;
    }
    else{
        result = recursiveFunction(n);

        printf("%d! = %d", n, result);
    }

    return 0;
}