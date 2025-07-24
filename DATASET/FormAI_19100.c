//FormAI DATASET v1.0 Category: Recursive ; Style: cheerful
#include <stdio.h>

int recursiveFunction(int num){
    if(num <= 1){ // base case
        return 1;
    }else{ // recursive case
        return num * recursiveFunction(num-1);
    }
}

int main(){
    int n;
    printf("Welcome to my cheerful recursive program!\n");
    printf("Give me a number and I'll calculate its factorial: ");
    scanf("%d", &n);
    
    if(n < 0){
        printf("Oops! Cannot calculate the factorial of a negative number. Please enter a positive number.\n");
        return 1;
    }
    
    int result = recursiveFunction(n);
    printf("The factorial of %d is: %d\n", n, result);
    printf("Yay! Hope you enjoyed the program. Bye bye!\n");
    
    return 0;
}