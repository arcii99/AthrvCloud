//FormAI DATASET v1.0 Category: Arithmetic ; Style: irregular
#include<stdio.h>
int main(){
    int a, b, c, d, result;
    printf("Enter the value of a:");
    scanf("%d",&a);
    printf("Enter the value of b:");
    scanf("%d",&b);
    printf("Enter the value of c:");
    scanf("%d",&c);
    printf("Enter the value of d:");
    scanf("%d",&d);
    
    if((a>b) && (a>c) && (a>d)){
        result = (a*b)%c + d - (c*d)/(a-b);
        printf("Result: %d\n",result);
    }
    else if((b>a) && (b>c) && (b>d)){
        result = (b*c)%d + a - (c*a)/(b-d);
        printf("Result: %d\n",result);
    }
    else if((c>a) && (c>b) && (c>d)){
        result = (c*d)%a + b - (d*b)/(c-a);
        printf("Result: %d\n",result);
    }
    else{
        result = (d*a)%b + c - (a*c)/(d-b);
        printf("Result: %d\n",result);
    }
    return 0;
}