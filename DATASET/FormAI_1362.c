//FormAI DATASET v1.0 Category: Recursive ; Style: excited
#include<stdio.h>
#include<stdlib.h>

// Recursive function that prints the fibonacci series with a twist
void fibonacci(int n, int a, int b){
    if(n == 0){
        printf("\nThat's the end of the fibonacci series! Hope you enjoyed it :D");
        return;
    }

    // If n is odd, print a and recursively call the function with new values of a and b
    if(n%2 != 0){
        printf("%d ", a);
        fibonacci(n-1, b, a+b);
    }

    // If n is even, just recursively call the function with new values of a and b
    else{
        fibonacci(n-1, b, a+b);
    }
}

int main(){
    int n;

    printf("Welcome to my fibonacci series program with a twist!\n");
    printf("Enter the number of terms you want me to generate: ");
    scanf("%d", &n);

    if(n < 0){
        printf("Sorry, I cannot generate negative terms. Bye :(");
        exit(0);
    }

    printf("\nHere's your fibonacci series with a twist:\n");
    fibonacci(n, 0, 1);

    printf("\n\nWow, that was an amazing experience! Hope to see you again. Bye :)");
    return 0;
}