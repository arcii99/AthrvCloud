//FormAI DATASET v1.0 Category: Pattern printing ; Style: synchronous
#include<stdio.h>

int main(){

    int length, i, j;
    printf("Enter the length of the pattern: ");
    scanf("%d", &length);

    // First part of the pattern
    for(i=1; i<=length; i++){
        for(j=1; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }

    // Second part of the pattern
    for(i=length-1; i>=1; i--){
        for(j=1; j<=i; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}