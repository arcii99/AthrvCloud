//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: statistical
#include<stdio.h>
#include<math.h>

int main(){
    int n,i,j,flag=0;
    printf("Enter a limit to generate prime numbers: ");
    scanf("%d",&n);
    printf("Generated prime numbers are: \n");
    for(i=2;i<=n;i++){
        flag=0; //Reset flag for every new number
        for(j=2;j<=sqrt(i);j++){
            if(i%j == 0){
                flag=1; //If divisible, set flag to 1
                break; //No need to check further
            }
        }
        if(flag == 0){
            printf("%d ",i); //If flag still 0, the number is prime
        }
    }
    return 0;
}