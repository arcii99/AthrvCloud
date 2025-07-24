//FormAI DATASET v1.0 Category: Prime Number Generator ; Style: introspective
#include<stdio.h>

int main(){
    int lower,upper,i,j,flag;
    printf("Enter the lower limit: ");
    scanf("%d",&lower); //taking lower limit from user
    printf("Enter the upper limit: ");
    scanf("%d",&upper); //taking upper limit from user
    printf("Prime numbers between %d and %d are: ",lower,upper);
    for(i=lower;i<=upper;i++){
        flag=0;
        for(j=2;j<i;j++){
            if(i%j==0){ //checking whether i is divisible by j or not
                flag=1;
                break;
            }
        }
        if(flag==0){
            printf("%d ",i); //print if i is prime number
        }
    }
    return 0;
}