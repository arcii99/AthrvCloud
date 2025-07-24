//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: romantic
#include<stdio.h>

int main(){
    
    printf("My Darling, let me generate some prime numbers just for you\n");
    printf("---------------------------------\n");
    int n, i, j, flag;
    printf("Enter the range of prime numbers: ");
    scanf("%d", &n);
    printf("--------------------------------\n");
    printf("Here are your prime numbers, my love:\n");
    for(i = 2; i <= n; i++){
        flag = 1;
        for(j = 2; j <= i/2; j++){
            if(i % j == 0){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            printf("%d ", i);
        }
    }
    printf("\n-----------------\n");
    printf("Hope you liked this, my love!\n");

    return 0;
}