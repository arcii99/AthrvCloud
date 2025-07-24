//FormAI DATASET v1.0 Category: Recursive ; Style: sophisticated
#include<stdio.h>

int recursive_sum(int n);

int main(){
    int num, sum;

    printf("Enter the number: ");
    scanf("%d", &num);

    sum = recursive_sum(num);

    printf("The sum of numbers from 1 to %d is %d\n", num, sum);

    return 0;
}

int recursive_sum(int n){
    if(n == 0){
        return 0;
    }
    else{
        return n + recursive_sum(n-1);
    }
}