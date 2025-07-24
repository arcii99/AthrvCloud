//FormAI DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

int divide(int x, int y){
    if(y==0){
        perror("Division by zero error:");
        exit(EXIT_FAILURE);
    }
    return x/y;
}

int add(int x, int y){
    return x+y;
}

int main(){
    int a,b,c,d;

    printf("Enter value of a:");
    scanf("%d",&a);

    printf("Enter value of b:");
    scanf("%d",&b);

    printf("Enter value of c:");
    scanf("%d",&c);

    printf("Enter value of d:");
    scanf("%d",&d);

    int result1 = divide(a,b);

    int result2 = divide(c,d);

    int result3 = add(result1,result2);

    printf("The result of %d/%d + %d/%d is %d\n",a,b,c,d,result3);

    return 0;
}