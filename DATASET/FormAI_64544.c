//FormAI DATASET v1.0 Category: Error handling ; Style: funny
#include<stdio.h>

int main(){
    int a, b, c;

    printf("Enter two numbers to divide (a/b): ");
    scanf("%d/%d", &a, &b);

    if(b == 0){
        printf("Did you really think I would divide by zero? Try again.\n");
        return 1;
    }

    c = a/b;
    printf("The result of %d/%d is %d\n", a, b, c);

    return 0;
}

//I won't make you sorry for trying to divide by zero, I'll just make you try again.