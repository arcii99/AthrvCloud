//FormAI DATASET v1.0 Category: Recursive ; Style: brave
#include<stdio.h>

void braveFunction(int n){ // function to display brave message recursively
    if(n == 0){ // base case
        printf("Stay brave and keep fighting!\n");
        return;
    }
    else if(n == 1){
        printf("You are strong and capable!\n");
        braveFunction(n-1); // recursive call
        printf("No challenge is too big for you.\n");
    }
    else{
        printf("Do not be afraid to take risks!\n");
        braveFunction(n-1); // recursive call
        printf("You are capable of achieving greatness.\n");
    }
}

int main(){
    int count;
    printf("How brave are you feeling today? (Enter a number): ");
    scanf("%d", &count);
    printf("\n");
    braveFunction(count); // calling the recursion function
    return 0;
}