//FormAI DATASET v1.0 Category: Pattern printing ; Style: post-apocalyptic
#include<stdio.h>

int main(){

    int i, j;

    printf("POST-APOCALYPTIC C PATTERN\n");

    for(i=0; i<5; i++){
        for(j=0; j<=i; j++){
            printf("* ");
        }
        printf("\n");
    }
    for(i=4; i>=0; i--){
        for(j=0; j<=i; j++){
            printf("* ");
        }
        printf("\n");
    }
    for(i=0; i<5; i++){
        for(j=4; j>=i; j--){
            printf("* ");
        }
        printf("\n");
    }
    for(i=4; i>=0; i--){
        for(j=0; j<=i; j++){
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}