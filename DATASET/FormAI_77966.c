//FormAI DATASET v1.0 Category: Recursive ; Style: random
#include<stdio.h>
#include<stdlib.h>

void printStars(int);

int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printStars(n);
    return 0;
}

void printStars(int num){
    if(num == 0){
        printf("\n");
        return;
    }
    printf("*");
    printStars(num-1);
    printf("*");
    printStars(num-1);
    printf("*");
}