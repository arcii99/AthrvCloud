//FormAI DATASET v1.0 Category: Recursive ; Style: ephemeral
#include<stdio.h>
int recursive_sum(int n){
    if(n == 0)
        return 0;
    return n + recursive_sum(n-1);
}

int main(){
    int n;
    printf("Enter a positive integer: ");
    scanf("%d",&n);
    if(n<1){
        printf("The integer should be a positive integer.");
    }
    else{
        int sum = recursive_sum(n);
        printf("The sum of first %d natural numbers is %d",n,sum);
    }
    return 0;
}