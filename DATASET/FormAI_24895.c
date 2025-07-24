//FormAI DATASET v1.0 Category: Pattern printing ; Style: sophisticated
#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of lines you want to print: ");
    scanf("%d", &n);
    int space = n/2;
    int star = 1;
    
    // Printing upper half of C pattern
    for(int i=0; i<n/2; i++){
        for(int j=0; j<space; j++){
            printf(" ");
        }
        for(int j=0; j<star; j++){
            if(j == 0 || j == star-1){
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
        space--;
        star += 2;
    }
    
    // Printing lower half of C pattern
    for(int i=0; i<=n/2; i++){
        for(int j=0; j<space; j++){
            printf(" ");
        }
        for(int j=0; j<star; j++){
            if(j == 0 || j == star-1){
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
        space++;
        star -= 2;
    }
    return 0;
}