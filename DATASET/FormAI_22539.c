//FormAI DATASET v1.0 Category: Pattern printing ; Style: curious
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Let's create a unique C pattern printing program!\n");
    int rows = 10;

    // Top half of the pattern
    for(int i=1; i<=rows/2; i++){
        for(int j=1; j<=i; j++){
            printf("%d", j);
        }
        for(int j=i; j<(rows/2)+1; j++){
            printf("0");
        }
        printf("\n");
    }

    // Middle line
    for(int i=1; i<=rows; i++){
        printf("%d", i%10);
    }
    printf("\n");

    // Bottom half of the pattern
    for(int i=rows/2; i>=1; i--){
        for(int j=1; j<=i; j++){
            printf("%d", j);
        }
        for(int j=i; j<(rows/2)+1; j++){
            printf("0");
        }
        printf("\n");
    }
    printf("Voila! The C pattern has been printed successfully!\n");

    return 0;
}