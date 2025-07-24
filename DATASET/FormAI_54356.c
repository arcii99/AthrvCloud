//FormAI DATASET v1.0 Category: Recursive ; Style: introspective
#include<stdio.h>

void recursive_function(int n);

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    recursive_function(num);
    return 0;
}

void recursive_function(int n){
    if(n == 0){
        printf("This is the base case\n");
        return;
    }
    else{
        printf("Value of n is: %d, and it is not the base case\n", n);
        recursive_function(n-1);
    }
}