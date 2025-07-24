//FormAI DATASET v1.0 Category: Recursive ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

int sum(int num){
    if(num == 1){
        return 1;
    }
    else{
        return num + sum(num-1);
    }
}

int main(){
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);

    if(n < 1){
        printf("Invalid input. Please enter a positive integer.");
        exit(0);
    }

    int total_sum = sum(n);
    printf("The sum of numbers from 1 to %d is %d.", n, total_sum);

    return 0;
}