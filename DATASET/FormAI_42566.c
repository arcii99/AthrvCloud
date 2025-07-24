//FormAI DATASET v1.0 Category: Scientific ; Style: surprised
#include<stdio.h>

int main(){
    int x, y, z;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of y: ");
    scanf("%d", &y);
    printf("Enter the value of z: ");
    scanf("%d", &z);
    printf("Calculating result...\n");
    float result = (x+y+z)/3.0;
    printf("Result : %.2f \nWow, surprise! The result is %s \n",result,result>15?"greater than 15":"less than or equal to 15");
    printf("Let's do some more surprise! \n");
    printf("\nEnter two numbers to add up with the result: \n");
    int a, b;
    scanf("%d %d", &a, &b);
    int final_result = result + a + b;
    printf("Final Result : %d \n",final_result);
    printf("%s \n",final_result%2==0?"Hey, the final result is even":"Whoa, the final result is odd");
    printf("Let's make it even more interesting! \n");
    printf("Enter a number to check if it is divisible by the final result: ");
    int i;
    scanf("%d",&i);
    printf("%s \n",i%final_result==0?"Bazinga, it is divisible by the final result":"Oops, it is not divisible by the final result");
    return 0;
}