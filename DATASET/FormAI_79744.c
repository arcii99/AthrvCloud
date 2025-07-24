//FormAI DATASET v1.0 Category: Recursive ; Style: complex
#include <stdio.h>

int complex_recursion(int n, int m){

    if(n <= 0){   //base case
        return m;
    }
    else{
        if(n % 2 == 0){  //even case
            return complex_recursion(n/2, m+1);  //recursive call
        }
        else{     //odd case
            return complex_recursion(n-1, m+1) + complex_recursion(n-2, m+1); //two recursive calls
        }
    }
}

int main(){

    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    int result = complex_recursion(n, 0);

    printf("The result of recursive function is %d", result);

    return 0;
}