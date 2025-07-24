//FormAI DATASET v1.0 Category: Recursive ; Style: sophisticated
#include<stdio.h>

int generatedFibonacci(int num) {
    if(num == 0 || num == 1) {
        return num;
    } else {
        return generatedFibonacci(num - 1) + generatedFibonacci(num - 2);
    }
}

void generateFibonacci(int n) {
    int i = 0;
    for(;i<n;i++) {
        printf("%d ",generatedFibonacci(i));
    }
}

int main() {
    int n;
    printf("Enter the number of terms to print in fibonacci series: ");
    scanf("%d",&n);
    if(n<=0) {
        printf("Please enter a valid number.\n");
        return 0;
    } else {
        generateFibonacci(n);
    }
    return 0;
}