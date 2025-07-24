//FormAI DATASET v1.0 Category: Recursive ; Style: enthusiastic
#include <stdio.h>

//Welcome to the world of recursion!
//Here, we take our ordinary functions and make them extraordinary, oh yeah!

//Behold, the mighty recursive function!
int recursiveFunction(int n){
    if(n<=1){
        return 1; //this is our base case, and it will help us stop the recursion
    }
    else{
        return (n * recursiveFunction(n-1)); //this is where the magic happens, we call the function again and again
    }
}

int main(){
    int num;
    printf("Welcome! Let's do some recursion!\n");
    printf("Please input a number: ");
    scanf("%d", &num);
    printf("The factorial of %d is %d\n", num, recursiveFunction(num)); //Outputting the answer after the recursion is complete
    printf("Thanks for joining us today. Keep on recursing!\n");
    return 0;
}