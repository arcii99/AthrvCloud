//FormAI DATASET v1.0 Category: Pattern printing ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

int main() {

    int n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        for(int sp = n - i; sp > 0; sp--) {
            printf(" ");
        }
        
        for(int j = 1; j <= i; j++) {
            if(j % 2 == 0) {
                printf("w");
            }
            else {
                printf("b");
            }
                
        }
        
        for(int j = i - 1; j >= 1; j--) {
            if(j % 2 == 0) {
                printf("w");
            }
            else {
                printf("b");
            } 
        }
        
        printf("\n");
    }
    
    return 0;
}