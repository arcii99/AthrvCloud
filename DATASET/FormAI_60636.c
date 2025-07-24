//FormAI DATASET v1.0 Category: Arithmetic ; Style: synchronous
#include<stdio.h>

int main(){
    int a, b, c;
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    c = a + b;
    printf("a + b = %d\n", c);
    
    c = a - b;
    printf("a - b = %d\n", c);

    c = a * b;
    printf("a * b = %d\n", c);

    c = a / b;
    printf("a / b = %d\n", c);

    c = a % b;
    printf("a mod b = %d\n", c);

    if(a > b){
        printf("a is greater than b\n");
    }
    else if(b > a){
        printf("b is greater than a\n");
    }
    else{
        printf("a and b are equal\n");
    }

    int i, sum = 0;

    for(i=1;i<=10;i++){
        sum = sum + i;
    }

    printf("The sum of first 10 natural numbers is: %d", sum);

    return 0;
}