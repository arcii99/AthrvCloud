//FormAI DATASET v1.0 Category: Recursive ; Style: random
#include<stdio.h>
#include<stdlib.h>

int recursive_sum(int n){
    if (n == 0){
        return 0;
    }
    else {
        return n + recursive_sum(n-1);
    }
}

int power(int x, unsigned int y){
    if (y == 0){
        return 1;
    }
    else if (y % 2 == 0){
        return power(x, y/2)*power(x, y/2);
    }
    else {
        return x * power(x, y/2)*power(x, y/2);
    }
}

int main(){
    int num1 = 5;
    int num2 = 3;

    printf("%d + %d + %d = %d\n", num1, num2, num1+num2, recursive_sum(num1+num2));
    printf("%d^%d = %d\n", num1, num2, power(num1, num2));

    return 0;
}