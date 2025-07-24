//FormAI DATASET v1.0 Category: Pattern printing ; Style: Sherlock Holmes
#include <stdio.h>

int main() {
    int rows, i, j;
    printf("Enter the number of rows you want to print: ");
    scanf("%d", &rows);  
    int n = rows / 2;  
    for(i = 0; i <= n; i++){ 
        for(j = n-i; j>0; j--){
            printf(" ");
        }
        for(j = 0; j <= i; j++){
            printf("* ");
        }
        printf("\n");
    }
    for(i= n-1; i >= 0; i--){
        for(j = n-i; j>0; j--){
            printf(" ");
        }
        for(j = 0; j <= i; j++){
            printf("* ");
        }
        printf("\n");
    }
    printf("\nElementary my dear Watson!, the pattern has been printed!\n");
    return 0;
}