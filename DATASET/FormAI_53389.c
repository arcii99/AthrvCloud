//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: ephemeral
#include<stdio.h>

int main(){
    int num, count, i, flag;
    printf("Enter the number of prime numbers to generate: ");
    scanf("%d", &num);
    printf("The first %d prime numbers are: ", num);

    for(count=2; num>0; count++){
        flag=0; 
        for(i=2; i<count; i++){
            if(count%i==0){
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("%d ", count);
            num--;
        }
    }
    return 0;
}