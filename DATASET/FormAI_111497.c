//FormAI DATASET v1.0 Category: Recursive ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

void recursive(int n){
    printf("Current n = %d\n",n);
    if(n>=0){
        recursive(n-1);
    }
    printf("Returning n = %d\n",n);
}

int main(){
    int num;
    printf("Enter a number:");
    scanf("%d",&num);
    recursive(num);
    return 0;
}