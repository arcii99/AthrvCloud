//FormAI DATASET v1.0 Category: Pattern printing ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

void printPattern(int n){
    int space = n-1;

    for(int i=0;i<n;i++){
        for(int j=0;j<space;j++){
            printf(" ");
        }

        for(int k=0;k<=i;k++){
            printf("%c ",65+k);
        }

        printf("\n");
        space--;
    }
    space = 1;
    for(int i=n-2;i>=0;i--){
        for(int j=0;j<space;j++){
            printf(" ");
        }

        for(int k=0;k<=i;k++){
            printf("%c ",65+k);
        }

        printf("\n");
        space++;
    }
}

int main(){
    int n = 5;
    printPattern(n);
    return 0;
}