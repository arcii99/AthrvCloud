//FormAI DATASET v1.0 Category: Error handling ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

int main(){

    int a, b, c;

    //User input values of a and b
    printf("Enter two integers: ");
    if(scanf("%d %d",&a,&b)!=2){
        printf("Invalid input. Please try again.\n");
        return 1;
    }

    //Handling divide by zero error
    if(b==0){
        printf("Division by zero is not possible.\n");
        return 1;
    }

    //Calculating quotient
    c = a/b;

    //User output of quotient
    printf("%d divided by %d is %d\n",a,b,c);

    return 0;
}