//FormAI DATASET v1.0 Category: Recursive ; Style: romantic
#include<stdio.h>

int fact(int num){
    if(num==1 || num==0){//base cases
        return 1;
    }
    else{
        return num*fact(num-1);//recursion
    }
}

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d",&n);
    printf("Factorial of %d is: %d\n",n,fact(n));
    return 0;
}