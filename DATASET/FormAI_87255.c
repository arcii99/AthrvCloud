//FormAI DATASET v1.0 Category: Pattern printing ; Style: ephemeral
#include <stdio.h>
int main(){
    int size, i, j, k;
    printf("Enter the size (odd number): ");
    scanf("%d", &size);
    getchar();
    if(size%2==0){
        printf("Invalid size!\n");
        return 0;
    }
    printf("\n");
    for(i=0; i<size/2; i++){
        for(j=0; j<i; j++){
            printf(" ");
        }
        for(k=0; k<size-2*i; k++){
            if(k==0 || k==size-2*i-1){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    for(i=0; i<size/2+1; i++){
        for(j=i; j<size/2; j++){
            printf(" ");
        }
        for(k=0; k<2*i+1; k++){
            if(k==0 || k==2*i){
                printf("*");
            }
            else{
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}