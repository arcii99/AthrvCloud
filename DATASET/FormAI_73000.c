//FormAI DATASET v1.0 Category: Error handling ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

int main(){
    int dividend, divisor, result;

    printf("Enter dividend: ");
    scanf("%d",&dividend);

    printf("Enter divisor: ");
    scanf("%d",&divisor);

    if(divisor == 0){
        printf("ERROR: Division by zero not possible.");
        exit(0);
    }

    result = dividend / divisor;
    printf("Result of division: %d",result);

    return 0;
}