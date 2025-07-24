//FormAI DATASET v1.0 Category: Error handling ; Style: excited
#include<stdio.h>

int main(){
    int x, y;
    printf("Enter the first number: ");
    scanf("%d", &x);
    printf("Enter the second number: ");
    scanf("%d", &y);
    
    if(y==0)
    {
        printf("Cannot divide by zero!");
        return 0;
    }
    else
    {
        int result = x/y;
        printf("%d divided by %d is %d\n", x, y, result);
    }

    return 0;
}