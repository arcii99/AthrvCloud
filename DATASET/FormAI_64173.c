//FormAI DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include <stdio.h>

int main(){
    int size, i, j, k, l;
    printf("Enter the size of the pattern: ");
    scanf("%d", &size);

    // Top half of the pattern
    for(i=1; i<=size; i++){
        for(j=0; j<=size-i; j++){
            printf(" ");
        }
        for(k=1; k<=i; k++){
            printf("*");
        }
        for(l=i-1; l>=1; l--){
            printf("*");
        }
        printf("\n");
    }

    // Bottom half of the pattern
    for(i=size-1; i>=1; i--){
        for(j=0; j<=size-i; j++){
            printf(" ");
        }
        for(k=1; k<=i; k++){
            printf("*");
        }
        for(l=i-1; l>=1; l--){
            printf("*");
        }
        printf("\n");
    }

    printf("\nApocalyptic Pattern generated successfully!\n");
    return 0;
}