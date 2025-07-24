//FormAI DATASET v1.0 Category: Recursive ; Style: multivariable
#include <stdio.h>

int recursiveMultiply(int a, int b){
    if(b == 0){
        return 0;
    }
    else if(b % 2 == 0){
        return recursiveMultiply(a+a, b/2);
    }
    else{
        return a + recursiveMultiply(a+a, b/2);
    }
}

int recursivePower(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    else if(exponent % 2 == 0){
        int res = recursivePower(base, exponent/2);
        return res * res;
    }
    else{
        int res = recursivePower(base, (exponent-1)/2);
        return base * res * res;
    }
}

int recursiveCombination(int n, int k){
    if(k == 0 || k == n){
        return 1;
    }
    else{
        return recursiveCombination(n-1, k-1) + recursiveCombination(n-1, k);
    }
}

int main(){
    // Recursive multiplication
    int x = 14, y = 7;
    int product = recursiveMultiply(x, y);
    printf("The product of %d and %d is: %d\n", x, y, product);
    
    // Recursive power
    int base = 2, exponent = 6;
    int power = recursivePower(base, exponent);
    printf("%d raised to the power of %d is: %d\n", base, exponent, power);
    
    // Recursive combination
    int n = 5, k = 2;
    int combination = recursiveCombination(n, k);
    printf("The combination of %d objects taken %d at a time is: %d\n", n, k, combination);

    return 0;
}