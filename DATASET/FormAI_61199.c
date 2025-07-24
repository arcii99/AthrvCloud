//FormAI DATASET v1.0 Category: Recursive ; Style: multivariable
#include<stdio.h>
int fact(int n, int k){
    if(n == 0 || k == 0 || k > n){
        return 0;   // If any of the conditions not met, return 0
    }
    if(k == 1){
        return n;   // Return the value of n if k is 1
    }
    else{
        return n * fact(n-1, k-1) + fact(n-1, k);  // Recursive call to the function
    }
}
int main(){
    int n, k, result;
    printf("Enter the value of n and k: ");
    scanf("%d%d", &n, &k);
    result = fact(n ,k);
    printf("The result is: %d", result);
    return 0;
}