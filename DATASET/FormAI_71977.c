//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include<stdio.h>
#include<stdlib.h>

int divide(int a, int b){ 
    if(b == 0){
        fprintf(stderr, "Error: Division by zero!\n");
        exit(EXIT_FAILURE);
    }
    return a/b;
}

int main(){
    int a, b;
    printf("Enter numerator: ");
    scanf("%d",&a);
    printf("Enter denominator: ");
    scanf("%d",&b);
    int result = divide(a, b);
    printf("%d / %d = %d\n",a,b,result);
    return 0;
}